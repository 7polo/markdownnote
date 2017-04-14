#include "markdowneditor.h"

MarkdownEditor::MarkdownEditor(QWidget *parent) : QWebEngineView(parent)
{

}

void MarkdownEditor::link(Connector *connector){

    this->connector = connector;

    QWebEnginePage *page = new QWebEnginePage(this);
    this->setPage(page);
    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject(QStringLiteral("connector"), connector);
    page->setWebChannel(channel);

    this->load(QUrl("qrc:/markdown/index.html"));


}

void MarkdownEditor::slot_loadMarkdonwText(QString filePath){

    QString markdownText;
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::warning(this,"Warnning","can't open",QMessageBox::Yes);
    else{
        curFilePath = filePath;
        QTextStream in(&file);
        markdownText = in.readAll();
        file.close();
        emit connector->sendMarkdownContent(markdownText);
    }
}


//保存文件
void MarkdownEditor::slot_saveToFile(QString markdown){
    qDebug()<<"保存文件3:"<<curFilePath<<endl;

    if (!curFilePath.isEmpty()){ //当前文件名不为空时
        QFile file(curFilePath);
          if ( file.open(QIODevice::WriteOnly | QIODevice::Text) ) {
              QTextStream out( &file );
              out<<markdown;
              file.close();
          }
    }else{
        qDebug()<<"文件名不能为空"<<endl;
    }
}




