#ifndef BACKENDTEST_H
#define BACKENDTEST_H


#include <QKeyEvent>

class backendTest : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setcurrentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(int choose READ choose WRITE setchoose NOTIFY chooseChanged)
public:
    explicit backendTest(QObject *parent=0);
    int currentIndex();
    void setcurrentIndex(const int &index);
    int choose();
    void setchoose(const int &c);
signals:
    void currentIndexChanged();
    void chooseChanged();
    void up();
    void down();
    void left();
    void right();
    void space();
private slots:
    void onUp();
    void onDown();
    void onLeft();
    void onRight();
    void onSpace();
private:
    int m_currentIndex=2;
    int m_choose=0;



};

#endif // BACKENDTEST_H
