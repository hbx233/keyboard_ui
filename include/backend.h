#ifndef BACKEND_H
#define BACKEND_H
#include <iostream>
#include <QSerialPort>
#include <QTimer>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <eigen3/Eigen/Core>
#include <algorithm>
#include <functional>
class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setcurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(int choose READ choose WRITE setchoose NOTIFY chooseChanged)
    Q_PROPERTY(int serialPortState READ serialPortState WRITE setserialPortState NOTIFY serialPortStateChanged)
    Q_PROPERTY(int keyState READ keyState WRITE setkeyState NOTIFY keyStateChanged)
    Q_PROPERTY(int rowCoordinate READ rowCoordinate WRITE setrowCoordinate NOTIFY rowCoordinateChanged)
    Q_PROPERTY(int colCoordinate READ colCoordinate WRITE setcolCoordinate NOTIFY colCoordinateChanged)
    Q_PROPERTY(int intensityDisplay READ intensityDisplay WRITE setintensityDisplay NOTIFY intensityDisplayChanged)

public:
    explicit BackEnd(QObject *parent = 0);
    ~BackEnd();
    void serialInit();
    enum TypeState{
        INITIALIZE=-1,
        CENTRAL=1,
        MOVE = 2,
        CLOSED=0
    };
    TypeState state=INITIALIZE;
public:
    /*Control variables passed to QML engine*/
    int currentIndex();
    void setcurrentIndex(const int &index);
    int choose();
    void setchoose(const int &c);
    int serialPortState();
    void setserialPortState(const int &state);
    int keyState();
    void setkeyState(const int &state);
    /*END of Control variables*/

    /*Display Coordinate and intensity*/
    int rowCoordinate();
    void setrowCoordinate(const int &rowCoor);
    int colCoordinate();
    void setcolCoordinate(const int &colCoor);
    int intensityDisplay();
    void setintensityDisplay(const int &intensity);
    /*END of Display Coordinate*/



signals:
    //void clicked();//only for test
    void openSerialPort(); //signal to open serial port, emited from QML
    void receivedCoordinate();

    void setGoodInitThreshold(QString value);

    /*Control variables Changed Signals*/
    void currentIndexChanged(); //currentIndex
    void chooseChanged();  //choose
    void serialPortStateChanged();
    void keyStateChanged();
    /*END of Control Changed Signals*/

    /*Display coordinate and intensity Changed Signals*/
    void rowCoordinateChanged();
    void colCoordinateChanged();
    void intensityDisplayChanged();
    /*End of Display coordinate and intensity Changed Signals*/

private slots:
    void readSerialPort();
    //void onClicked();
    void onOpenSerialPort(); // slot respond to openSerialPort
    void onReceivedCoordinate(); //

    void onSetGoodInitThreshold(QString value);

private:
    void ReceivedNumber();
    void move(Eigen::Vector2i disparity);
    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    Eigen::Vector2i setCurrCoordinate();

private:
    //Filter, midden filter
    std::vector<Eigen::Vector2i> coordinateArray;
    Eigen::Vector2i M_Filter(Eigen::Vector2i);



private:
    QSerialPort *_serialport;
    //used for control
    int low8=0; //higher 8bit or lower 8bit
    int coordinateCount=0;//used when assigning the recover_number to recover_coordinate and recover_intensity

    int closeIntensity=500; //intensity threshold for determining whether the eye closed
    int openIntensity=800; // intensity threshold for determining wheter the eye is open and recover from the CLOSED state
    int goodInitIntensity=1000; //intensity threshold for determining wheter it is a good initial frame,
                                //large intensity means good initialization
    //int moveBackThreshold=60;
    int lost=0;//continuous losted frame
    int chooseThreshold=3;//frame number threshold for determining the closure of eye
    int moveThreshold=30; //threshold for change currentIndex
    int maxFilterThreshold=100;

    //recover 16bits number and then coordinate from received 8bits
    int recover_number; //number recovered from higher 8bits and lower 8bits
    Eigen::Vector2i recover_coordinate;
    int recover_intensity;

    //coordinate and disparity that are used to do calculation
    Eigen::Vector2i currCoordinate; //currCoordinate(0) is row coordinate, currCoordinate(1) is column coordinate
    Eigen::Vector2i pastCoordinate;
    Eigen::Vector2i initCoordinate;
    Eigen::Vector2i disparity;
    Eigen::Vector2i disparity_set;

    int rightNum=0;
    int leftNum=0;

    /*index choose and state control variables*/
    int m_currentIndex=25; // current index of the alphabet
    int m_choose=0;  // choose == 1 means choose current index
    int m_serialPortState=0; //serial port state, which will be send to QML to indicate the user whether the serial port is successfully opend
    int m_keyState=0;
    /*END*/

    /*Coordinate and intensity display*/
    int m_rowCoordinate=0;
    int m_colCoordinate=0;
    int m_intensityDisplay=0;
    /*END*/
    //0:pending 1:successfully opened ready to type -1:Failed


};

#endif // BACKEND_H
