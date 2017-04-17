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

void Connector::slot_getEditorThemes(QString themes){
    qDebug()<<themes<<endl;
    emit signal_getEditorThemes(themes);
}

void Connector::slot_getPreviewThemes(QString themes){
    qDebug()<<themes<<endl;
    emit signal_getPreviewThemes(themes);
}



