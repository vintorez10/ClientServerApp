#include <QCoreApplication>
#include "firstserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FirstServer server;


    return a.exec();
}
