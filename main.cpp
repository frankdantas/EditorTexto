#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <backend.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    qmlRegisterType<Backend>("com.teste.backend", 1,0,"Backend");
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("editortexto", "Main");

    return app.exec();
}
