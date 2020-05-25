#include "firstclient.h"

FirstClient::FirstClient(QObject *parent) : QObject(parent)
{
    qDebug() << "Start client";

    m_socket = new QTcpSocket(this);

    m_socket->connectToHost("127.0.0.1", 2323);

    connect(m_socket, &QTcpSocket::readyRead, this, &FirstClient::sockRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &FirstClient::sockDisconnect);

}

void FirstClient::sockRead()
{    
    while (m_socket->bytesAvailable() !=0) {

        QDataStream inStream(m_socket);
        inStream.setVersion(QDataStream::Qt_5_9);

        auto readFromServer = m_socket->readAll();

        QFile writeToFile("D:/Documents Qt/FirstClient/London_Jack-South_Sea_Tales_Client_Side.txt");
        if(writeToFile.open(QIODevice::WriteOnly | QIODevice::Append | QFile::Text)){

                writeToFile.write(readFromServer);

            }
            else{
                std::cerr << "Can not open file!" << std::endl;
                std::exit(EXIT_FAILURE);
            }

            writeToFile.close();
    }

}

void FirstClient::sockDisconnect()
{
    m_socket->deleteLater();

}
