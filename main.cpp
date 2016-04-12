#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ddview.h"
#include "ddquickview.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    YbQuickView view;
    view.setFlags(Qt::FramelessWindowHint);
    view.setHasMouse(false);
#ifdef USE_YOUZAN
    view.setMaximumWidth(500);
    view.setMaximumHeight(460);
#ifdef Q_OS_MACX
    view.setSourceAndRegsiterObj(QUrl::fromLocalFile("../../../youzan/main.qml"));
#else
    view.setSourceAndRegsiterObj(QUrl::fromLocalFile("youzan/main.qml"));
#endif
#elif USE_DRIVER
#ifdef Q_OS_MACX
    view.setSourceAndRegsiterObj(QUrl::fromLocalFile("../../../Driver/DDDriverView.qml"));
#else
    view.setSourceAndRegsiterObj(QUrl::fromLocalFile("Driver/DDDriverView.qml"));
#endif
#else
    view.setSourceAndRegsiterObj(QUrl::fromLocalFile("XunLei/DDXunLei.qml"));
#endif
    view.show();
    return app.exec();
}
