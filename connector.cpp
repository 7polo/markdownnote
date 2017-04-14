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

void Connector::slot_getMarkdown(QString markdownText){

}

void Connector::setTocView(QTextBrowser *view){
    this->tocView = view;
}
