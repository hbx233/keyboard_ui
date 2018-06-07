#include "backend.h"
#include <cmath>
BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{
    serialInit();
}

BackEnd::~BackEnd()
{
}
void BackEnd::serialInit()
{
    _serialport=nullptr;
    //connect(this,&BackEnd::clicked,this,&BackEnd::onClicked);
    connect(this,&BackEnd::openSerialPort,this,&BackEnd::onOpenSerialPort);
    connect(this,&BackEnd::setGoodInitThreshold,this,&BackEnd::onSetGoodInitThreshold);

}

void BackEnd::onSetGoodInitThreshold(QString value)
{
    if(value.toInt()>100)
        goodInitIntensity=value.toInt();
    //qDebug("change");
    std::cout<<goodInitIntensity<<std::endl;
}

//read data from the serial port
void BackEnd::readSerialPort()
{
    QByteArray _readData = _serialport->readAll();
    //bool ok;
    if(!_readData.isEmpty())
    {
        for(int i=0;i<_readData.count();i++)
        {
            int temp = (int)(unsigned char)_readData.at(i);
            //ui->textBrowser->insertPlainText(QString::number(temp,10)+" ");
            if(low8==0)
            {
                recover_number =  temp * 256;
                low8=1;
            }
            else if(low8==1)
            {
                recover_number += temp;
                low8=0;
                ReceivedNumber();
            }

        }
    }
}
void BackEnd::ReceivedNumber()
{
    switch (coordinateCount) {
    case 0:
        recover_coordinate(0)=recover_number;// row
        coordinateCount++;
        break;
    case 1:
        recover_coordinate(1)=recover_number;// column
        coordinateCount++;
        break;
    case 2:
        recover_intensity = recover_number;// intensity
        setintensityDisplay(recover_intensity);
        coordinateCount=0;
        emit receivedCoordinate();
        break;
    default:
        break;
        }
}


void BackEnd::onReceivedCoordinate()
{
    switch(state)
    {

    case INITIALIZE:  //do initialization every time when iris center is redetected after closed eyes
                      //in order to stablize the starting point for every choose
    {
        //qDebug("INIT");
        if(recover_intensity<goodInitIntensity) //if cannot detect iris center, reinitialize
        {
            state = INITIALIZE;
            break;
        }
        else  // if detect iris center with great confidence, initialization complete and go to next state.
        {
            initCoordinate = recover_coordinate;
            pastCoordinate = recover_coordinate;
            disparity = Eigen::Vector2i(0,0);
            state = CENTRAL;
            break;
        }
    }
    case CENTRAL:
    {
        //qDebug("CENTRAL");
        if(recover_intensity<closeIntensity) //determin if eye is closed in current frame
        {
            lost++;
            if(lost>=chooseThreshold)
            {
                state=CLOSED;
                setchoose(1);
                setchoose(0);
                lost=0;
            }
            break;

        }
        else
        {
            lost=0;
            currCoordinate = setCurrCoordinate();
            setrowCoordinate(currCoordinate(0));
            setcolCoordinate(currCoordinate(1));
            pastCoordinate = currCoordinate;
            disparity = (currCoordinate - initCoordinate);
            //if(std::abs(disparity(1))>=std::abs(disparity(0)))//move in horizontal direction
            //{
                if(disparity(1)>moveThreshold)
                {
                    leftNum=0;
                    rightNum++;
                    if(rightNum>0)
                    {
                        moveRight();
                        rightNum=0;
                    }
                    state = MOVE;
                }
                else if(disparity(1)<-moveThreshold)
                {
                    rightNum=0;
                    leftNum++;
                    if(leftNum>0)
                    {
                        moveLeft();
                        leftNum=0;
                    }

                    state = MOVE;
                }
                else
                {
                    state=CENTRAL;
                    leftNum=0;
                    rightNum=0;
                }

            //}
            /*else
            {
                if(disparity(0)>moveThreshold)
                {
                    moveDown();
                    state=MOVE;
                }
                else if(disparity(0)<-moveThreshold)
                {
                    moveUp();
                    state=MOVE;
                }
                else
                    state=CENTRAL;
            }*/
            break;


        }
    }
    case CLOSED:
    {
        //qDebug("CLOSED");
        if(recover_intensity>openIntensity)
        {
            state=INITIALIZE;
            break;
        }
        else
        {
            state=CLOSED;
            break;
        }
    }
    case MOVE:
    {
        currCoordinate = setCurrCoordinate();
        setrowCoordinate(currCoordinate(0));
        setcolCoordinate(currCoordinate(1));
        pastCoordinate=currCoordinate;
        disparity = (currCoordinate - initCoordinate);
        if(recover_intensity>=goodInitIntensity+400 || (std::abs(disparity(0))<moveThreshold && std::abs(disparity(1))<moveThreshold))
        {
            state = CENTRAL;break;
        }
        else{
            state = MOVE;break;
        }
    }



    }
    //pastCoordinate=currCoordinate;
    setkeyState(state);

}
//filter, used to set current coordinate
Eigen::Vector2i BackEnd::setCurrCoordinate()
{
    disparity_set = recover_coordinate-pastCoordinate;
    if(std::abs(disparity_set(0))>=maxFilterThreshold || std::abs(disparity_set(1))>=maxFilterThreshold)
        return pastCoordinate;
    else
        return recover_coordinate; //

}
void BackEnd::move(Eigen::Vector2i disparity)
{
    if(std::abs(disparity(0))<=std::abs(disparity(1)))
    {
        if(disparity(1)<0)
            moveLeft();
        else
            moveRight();
    }
    else
    {
        if(disparity(0)<0)
            moveUp();
        else
            moveDown();
    }
}
int BackEnd::currentIndex()
{
    return m_currentIndex;
}
int BackEnd::choose()
{
    return m_choose;
}
int BackEnd::serialPortState()
{
    return m_serialPortState;
}
int BackEnd::keyState()
{
    return m_keyState;
}
void BackEnd::setcurrentIndex(const int &index)
{
    m_currentIndex = index;
    emit currentIndexChanged();
}
void BackEnd::setchoose(const int &c)
{
    m_choose = c;
    emit chooseChanged();
}
void BackEnd::setserialPortState(const int &state)
{
    m_serialPortState=state;
    emit serialPortStateChanged();

}
void BackEnd::setkeyState(const int &state)
{
    m_keyState=state;
    emit keyStateChanged();
}

void BackEnd::moveUp()
{
    if(m_currentIndex-10<1)
        setcurrentIndex(50+(m_currentIndex-10));
    else
        setcurrentIndex(m_currentIndex-10);
}
void BackEnd::moveDown()
{
    if(m_currentIndex+10>50)
        setcurrentIndex(m_currentIndex+10-50);
    else
        setcurrentIndex(m_currentIndex+10);
}
void BackEnd::moveLeft()
{
    if(m_currentIndex-1<1)
        setcurrentIndex(50-(m_currentIndex-1));
    else
        setcurrentIndex(m_currentIndex-1);
}
void BackEnd::moveRight()
{
    if(m_currentIndex+1>50)
        setcurrentIndex(m_currentIndex+1-50);
    else
        setcurrentIndex(m_currentIndex+1);
}




//Open and Set up the Serial Port
void BackEnd::onOpenSerialPort()
{

    // !!!!!!!!!ATTENTION!!!!!!!!!!!!!!
    //at first, _serialport is a nullptr, you need to allocate a new QSerialPort
    _serialport = new QSerialPort;

    //set name of the serial port
    QString portname = "ttyUSB0";
    portname = "/dev/"+portname;
    _serialport->setPortName(portname);
    //connect the readyRead() signal
    connect(_serialport,&QSerialPort::readyRead,this,&BackEnd::readSerialPort);
    //connect(this,&BackEnd::receivedNumber,this,&BackEnd::onReceivedNumber);
    connect(this,&BackEnd::receivedCoordinate,this,&BackEnd::onReceivedCoordinate);
    qDebug("Clicked");



    //open the seiral port
    if(_serialport->open(QIODevice::ReadOnly))
    {
       //QMessageBox::information(this, tr("Info"), tr("successfully Opened  ") + portname, QMessageBox::Ok);
        setserialPortState(1);
        qDebug("success");
       //set baud rate of the serial port
       _serialport->setBaudRate(QSerialPort::Baud9600);



       //Set Data bit to 8 bits
       _serialport->setDataBits(QSerialPort::Data8);

       //Set stop bit
       _serialport->setStopBits(QSerialPort::OneStop);

       //Set Flow Control to False
       _serialport->setFlowControl(QSerialPort::NoFlowControl);

       //Set Parity
       _serialport->setParity(QSerialPort::NoParity);


    }
    else
    {
        setserialPortState(-1);
        qDebug("Faild");
    }

}

/*Display Coordinate and Intensity value*/
int BackEnd::rowCoordinate()
{
    return m_rowCoordinate;
}
void BackEnd::setrowCoordinate(const int &rowCoor)
{
    m_rowCoordinate = rowCoor;
    emit rowCoordinateChanged();
}
int BackEnd::colCoordinate()
{
    return m_colCoordinate;
}
void BackEnd::setcolCoordinate(const int &colCoor)
{
    m_colCoordinate = colCoor;
    emit colCoordinateChanged();
}
int BackEnd::intensityDisplay()
{
    return m_intensityDisplay;
}
void BackEnd::setintensityDisplay(const int &intensity)
{
    m_intensityDisplay = intensity;
    emit intensityDisplayChanged();
}
/*END Display Coordinate and Intensity value*/
