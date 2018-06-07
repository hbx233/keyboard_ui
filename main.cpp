#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlComponent>
#include "include/backend.h"
#include "include/backendtest.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlEngine engine;

    //BackEnd backend;
    BackEnd backend;
    engine.rootContext()->setContextProperty("backend", &backend);
    QQmlComponent component(&engine,QUrl(QStringLiteral("qrc:/main.qml")));


    component.create();

    return app.exec();
}

