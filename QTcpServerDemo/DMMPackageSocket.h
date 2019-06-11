#pragma once

#include <QTcpSocket.h>
#include "DMMServer.h"

class DMMPackageSocket : public QObject
{
	Q_OBJECT

public:
	DMMPackageSocket(QTcpSocket *parent, DMMServer* pServer);
	~DMMPackageSocket();
	const QTcpSocket* Get() { return mpts; };
private:
	DMMServer* mdms;
	QByteArray mbuf;
	QTcpSocket* mpts;
private slots:
	void readyRead();
	
	void error(QAbstractSocket::SocketError);
};
