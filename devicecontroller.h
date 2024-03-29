#ifndef DEVICECONTROLLER_H
#define DEVICECONTROLLER_H

#include <QObject>
#include <QTcpSocket>
class DeviceController : public QObject
{
    Q_OBJECT
public:
    explicit DeviceController(QObject *parent = nullptr);
    void connectToDevice(QString _ip, int _port);
    void disconnect();
    QAbstractSocket::SocketState state();
    bool isConnected();
    void send(QString message);

signals:
    void connected();
    void disconnected();
    void stateChanged(QAbstractSocket::SocketState);
    void errorOccurred(QAbstractSocket::SocketError);
    void dataReady(QByteArray);

private slots:
    void socket_stateChanged(QAbstractSocket::SocketState state);
    void socket_readyRead();
private:
    QTcpSocket socket;
    QString ip;
    int port;
};

#endif // DEVICECONTROLLER_H
