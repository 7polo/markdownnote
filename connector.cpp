#include "connector.h"
#include <QDebug>
Connector::Connector(QObject *parent) : QObject(parent)
{

}

void Connector::slot_edited(){
//    qDebug()<<"键入编辑"<<endl;
    emit signal_getEditeFlag();
}

void Connector::slot_getMarkdown(QString markdown){
//    qDebug()<<"收到来自js的回调"<<endl;
    emit signal_getMarkdown(markdown);
}


