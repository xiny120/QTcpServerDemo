#include "DMMThread.h"
#include "DMMServer.h"
#include "QTcpServerDemo.h"

DMMThread::DMMThread(QObject *parent)
	: QThread(parent){
	mpDemo = qobject_cast<QTcpServerDemo *>(parent);
}

DMMThread::~DMMThread()
{
}

void DMMThread::run() {
	DMMServer dms(mpDemo);
	dms.Start(L"", 82);
	exec();
}