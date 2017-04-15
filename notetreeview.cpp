#include "notetreeview.h"
#include <QDebug>

NoteTreeView::NoteTreeView(QWidget *parent) : QTreeView(parent)
{
    qMenu = new QMenu();
    qMenu->addAction(QString("新建笔记"),this, SLOT(slot_createFile()));
    qMenu->addAction(QString("重命名"),this,SLOT(slot_rename()));
    qMenu->addAction(QString("删除笔记"),this, SLOT(slot_deleteFile()));
    this->setIconSize(QSize(22,22));

    connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(slot_sendselectedPath(QModelIndex)));
}

void NoteTreeView::showPopmenu(){
    if (qMenu != NULL){
       qMenu->exec(QCursor::pos());
    }
}

void NoteTreeView::slot_loadDir(QString path){


    if (noteModel!= NULL)
        delete noteModel;

    this->noteModel = new QFileSystemModel(this);
    noteModel->setIconProvider(new NIconProvider());
    this->setModel(noteModel);
    QStringList filterList;
    filterList<<"*.md"; //过滤的格式
    this->noteModel->setFilter(QDir::Files);
    this->noteModel->setNameFilterDisables(false);
    this->noteModel->setNameFilters(filterList);


    this->setRootIndex(noteModel->setRootPath(path));
    this->setColumnHidden(1,true);
    this->setColumnHidden(2,true);
    this->setColumnHidden(3,true);


    if (parentPath.compare(path)!=0){
        //说明父目录发生变化
        parentPath = path;
        emit signal_filePath(parentPath);
    }

    qDebug()<<"父目录"<<parentPath<<endl;
}
void NoteTreeView::slot_rename(){

}

//删除目录
void NoteTreeView::slot_deleteFile()
{
    QModelIndex index = this->currentIndex();
    if (!index.isValid())
            return;

    bool ok = noteModel->remove(index);
    if (!ok)
       QMessageBox::information(this,tr("Remove"),tr("Failed to remove %1").arg(noteModel->fileName(index)));
}

void NoteTreeView::slot_sendselectedPath(QModelIndex selectIndex){
    if (index != selectIndex){
         index = selectIndex;
         QString path = noteModel->filePath(index);
         qDebug()<<"发送选中的笔记路径"<<path<<endl;
         emit signal_filePath(path);
    }
}

//创建文件
void NoteTreeView::slot_createFile(){


    if (parentPath.isEmpty())
        return;

    QString fileName = QInputDialog::getText(this, tr("Create Markdown File"), tr("file name"));
    if (!fileName.isEmpty()) {

        if (!fileName.endsWith(".md"))
                fileName.append(".md");

        QFile file(parentPath + "/" + fileName );
        if (!file.exists()){
            file.open( QIODevice::WriteOnly );
            file.close();
        }else
            QMessageBox::information(this, tr("Create File"), tr("Failed to create the file"));
    }
}
