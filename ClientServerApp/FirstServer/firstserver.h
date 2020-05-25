#ifndef FIRSTSERVER_H
#define FIRSTSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <iostream>


class FirstServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit FirstServer(QObject* parent  = nullptr);
    void writeForSocket();

public slots:
    void incomingConnection(qintptr handle) override;
    void disconectedClient();

private:
    QTcpSocket* m_socket;

};

#endif // FIRSTSERVER_H
