#include <QCoreApplication>
#include <firstclient.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FirstClient client;


    return a.exec();
}
