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
        QTextStream in(&file);
        markdownText = in.readAll();
        file.close();
        emit connector->sendMarkdownContent(markdownText);
    }
}




