#include "./View/Window.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Window window;
    window.resize(1024,600);
    window.show();
    return a.exec();
}
