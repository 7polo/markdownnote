#include "connector.h"
#include <QDebug>
Connector::Connector(QObject *parent) : QObject(parent)
{

}

void Connector::slot_getToc(QString toc){
    qDebug()<<"获取大纲"<<toc<<endl;
    if (tocView != NULL){
        tocView->setHtml(toc);
    }else{
        qDebug()<<"?"<<endl;
    }
}

//发送信号signal_saveMarkdown,会回调这个函数
void Connector::slotSaveMarkdown(QString markdown){
       emit signalEditorSave(markdown);
}

void Connector::setTocView(QTextBrowser *view){
    this->tocView = view;
}
