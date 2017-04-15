#include "markdowneditor.h"

MarkdownEditor::MarkdownEditor(QWidget *parent) : QWebEngineView(parent)
{
    this->connector = new Connector();
    QWebEnginePage *page = new QWebEnginePage(this);
    this->setPage(page);
    QWebChannel *channel = new QWebChannel(this);
    channel->registerObject(QStringLiteral("connector"), connector);
    page->setWebChannel(channel);
    this->load(QUrl("qrc:/markdown/index.html"));

    connect(connector,SIGNAL(signal_getEditeFlag()),this,SLOT(slot_edited()));
    connect(connector,SIGNAL(signal_getMarkdown(QString)),this,SLOT(slot_saveMarkdown(QString)));
}

//接受父窗口的ctrl+s键盘事件信号
void MarkdownEditor::slot_CtrlandS(){
    qDebug()<<"发送获取markdown的信号"<<endl;
    emit connector->sendGetMarkdown();
}

void MarkdownEditor::slot_edited(){
    isSaved = false;
    qDebug()<<"编辑器被编辑了"<<endl;
}

//改变模式
void MarkdownEditor::slot_changeMode(bool flag){
    emit connector->sendChangeMode(flag);
}

//开启实时预览
void MarkdownEditor::slot_livePrivew(bool flag){
    emit connector->sendLivePreview(flag);
}

//根据路径载入
void MarkdownEditor::slot_loadMarkdown(QString filePath){

    if (!isSaved){
        qDebug()<<"尚未保存"<<curFilePath<<endl;
        qDebug()<<"下一个打开的是"<<filePath<<endl;
        nextFilePath = filePath;
        emit connector->sendGetMarkdown();
        return;
    }

    if (!filePath.endsWith(".md")){

        if (!isEmpty){
            isSaved = true;
            curFilePath="";
            nextFilePath="";
            emit connector->sendLoadMarkdown("");
            isEmpty = true;
            qDebug()<<"文件不合法,清空编辑器"<<endl;
        }
        return;
    }

    QString markdownText;
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        QMessageBox::warning(this,"错误","文件打开失败",QMessageBox::Yes);
    else{
        curFilePath = filePath;

        if (curFilePath.compare(nextFilePath)==0)
            nextFilePath = ""; //置空,无下一个要打开的

        QTextStream in(&file);
        markdownText = in.readAll();
        file.close();
        emit connector->sendLoadMarkdown(markdownText);
        isEmpty = false;
        isSaved = true; //载入的,初始认为已经保存
    }
}

//保存文件
void MarkdownEditor::slot_saveMarkdown(QString markdown){


    if (!curFilePath.isEmpty()){ //当前文件名不为空时
        QFile file(curFilePath);
          if ( file.open(QIODevice::WriteOnly | QIODevice::Text) ) {
              QTextStream out( &file );
              out<<markdown;
              file.close();
              isSaved = true;
              qDebug()<<curFilePath<<" 已经保存..."<<endl;

              //如果下一个要打开的文件是合法的则打开
              if (!nextFilePath.isEmpty()){
                  qDebug()<<"打开下一个文件"<<nextFilePath<<endl;
                  slot_loadMarkdown(nextFilePath);
              }
          }
    }else{
        qDebug()<<"文件名不能为空"<<endl;
    }
}




