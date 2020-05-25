#ifndef FIRSTCLIENT_H
#define FIRSTCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <iostream>

class FirstClient : public QObject
{
    Q_OBJECT

public:
    explicit FirstClient(QObject *parent = nullptr);

public slots:
    void sockRead();
    void sockDisconnect();

private:
    QTcpSocket* m_socket;    

};

#endif // FIRSTCLIENT_H
