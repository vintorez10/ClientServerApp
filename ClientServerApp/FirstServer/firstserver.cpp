#include "firstserver.h"

FirstServer::FirstServer(QObject* parent) : QTcpServer(parent)
{

    if(this->listen(QHostAddress::Any, 2323)){
        qDebug() << "Server is start a port: " << this->serverPort();
    }
    else {
        qDebug() << "Server is not started! ";
    }


}

void FirstServer::incomingConnection(qintptr handle)
{    
    m_socket = new QTcpSocket(this);
    m_socket->setSocketDescriptor(handle);

    qDebug() << handle << " Client conected";

    emit writeForSocket();

    connect(m_socket, &QTcpSocket::disconnected, this, &FirstServer::disconectedClient);

}

void FirstServer::writeForSocket()
{
    QFile readFromFile("D:/Documents Qt/FirstServer/London_Jack-South_Sea_Tales_From_Server.txt");

    if(readFromFile.open(QIODevice::ReadOnly | QFile::Text)){

        QByteArray blockSize;

        QDataStream outStream(&blockSize, QIODevice::WriteOnly);
        outStream.setVersion(QDataStream::Qt_5_9);        

        //reading to the stream
        outStream << qint64(0) << readFromFile.readAll();

        auto dataFromFile = readFromFile.readAll();
        blockSize.append(dataFromFile);

        outStream.device()->seek(0);

        //size of the block to sent
        outStream << static_cast<qint64>(blockSize.size() - sizeof (qint64));

        qint64 count = 0;

        //writing blocks to the socket until the 'counter' is equal to the size of the file being passed
        while(count != blockSize.size()){

            qint64 sizeFile = m_socket->write(blockSize);
            count += sizeFile;

          }
        qDebug() << "Data from file was sended to client!";

      }
    else{
        std::cerr << "Can not open file!" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    readFromFile.close();
}

void FirstServer::disconectedClient()
{
    qDebug() << "Client disconnected";
    m_socket->deleteLater();
}
