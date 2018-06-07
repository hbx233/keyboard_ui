#include "backendtest.h"

backendTest::backendTest(QObject *parent):
    QObject(parent)
{
    connect(this,&backendTest::up,this,&backendTest::onUp);
    connect(this,&backendTest::down,this,&backendTest::onDown);
    connect(this,&backendTest::left,this,&backendTest::onLeft);
    connect(this,&backendTest::right,this,&backendTest::onRight);
    connect(this,&backendTest::space,this,&backendTest::onSpace);

}
int backendTest::currentIndex()
{
    return m_currentIndex;
}
int backendTest::choose()
{
    return m_choose;
}
void backendTest::setchoose(const int &c)
{
    m_choose = c;
    emit chooseChanged();
}
void backendTest::setcurrentIndex(const int &index)
{
    m_currentIndex = index;
    emit currentIndexChanged();
}
void backendTest::onUp()
{
    setcurrentIndex(m_currentIndex-10);
}
void backendTest::onDown()
{
    setcurrentIndex(m_currentIndex+10);
}
void backendTest::onLeft()
{
    setcurrentIndex(m_currentIndex-1);
}
void backendTest::onRight()
{
    setcurrentIndex(m_currentIndex+1);
}
void backendTest::onSpace()
{
    setchoose(1);
    setchoose(0);
}
