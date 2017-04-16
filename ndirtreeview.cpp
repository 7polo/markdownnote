#include "ndirtreeview.h"
#include <QDebug>
NDirTreeview::NDirTreeview(QWidget *parent) : QTreeView(parent)
{

    dirModel = new QFileSystemModel(this);
    proxyModel = new NDirFilterModel();
    proxyModel->setSourceModel(dirModel);
    this->setModel(proxyModel);
     dirModel->setIconProvider(new NIconProvider());
    this->setColumnHidden(1,true);
    this->setColumnHidden(2,true);
    this->setColumnHidden(3,true);
    this->setIconSize(QSize(22, 22));

     qMenu = new QMenu(this);
     qMenu->addAction(QString("新建笔记"),this, SLOT(slot_createFile()));
     qMenu->addAction(QString("新建子目录"), this, SLOT(slot_mkChildDir()));
     qMenu->addAction(QString("创建同级目录"), this, SLOT(slot_mkDir()));
     qMenu->addAction(QString("重命名"),this,SLOT(slot_rename()));
     qMenu->addAction(QString("删除目录"), this, SLOT(slot_rmDir()));

     connect(this,SIGNAL(clicked(QModelIndex)),this,SLOT(slot_selectDir(QModelIndex)));
}

NDirTreeview::~NDirTreeview(){
    delete proxyModel;
    delete dirModel;
}

void NDirTreeview::setRootPath(QString path){
    //"/home/apologizebao/文档/我的笔记"

    this->setRootIndex(proxyModel->mapFromSource(dirModel->setRootPath(path)));
}

void NDirTreeview::showPopMenu(){
    if (qMenu != NULL){
        qMenu->exec(QCursor::pos());
    }
}

void NDirTreeview::slot_selectDir(QModelIndex selectIndex){

    if (index != selectIndex){
         index = selectIndex;
         this->expand(index);
         QString path = dirModel->filePath(proxyModel->mapToSource(selectIndex));
         qDebug()<<"发送"<<path<<endl;
         emit signal_selectedDir(path);
    }
}


void NDirTreeview::creatDir(bool flag){

    QModelIndex itemIndex = proxyModel->mapToSource(this->currentIndex());
    if (!itemIndex.isValid())
       return;

    QString dirName = QInputDialog::getText(this, tr("创建目录"), tr("目录名称"));
    if (!dirName.isEmpty()) {
         bool result = false;
         result = flag?dirModel->mkdir(itemIndex.parent(), dirName).isValid():dirModel->mkdir(itemIndex, dirName).isValid();

         if (!result)
             QMessageBox::information(this, tr("创建目录"), tr("创建失败"));
    }

    this->expand(proxyModel->mapFromSource(itemIndex));
}

//创建同级目录
void NDirTreeview::slot_mkDir()
{
    creatDir(true);
}

//创建子集目录
void NDirTreeview::slot_mkChildDir(){

    creatDir(false);
}

//创建文件
void NDirTreeview::slot_createFile(){
    qDebug()<<"创建文件"<<endl;

    QModelIndex itemIndex = proxyModel->mapToSource(this->currentIndex());
    if (!itemIndex.isValid())
            return;

    QString fileName = QInputDialog::getText(this, tr("Create Markdown File"), tr("file name"));
    if (!fileName.isEmpty()) {

        if (!fileName.endsWith(".md"))
                fileName.append(".md");

        QFile file((dirModel->filePath(itemIndex)+"/"+fileName ));
        if (!file.exists()){
            file.open( QIODevice::WriteOnly );
            file.close();
        }else
            QMessageBox::information(this, tr("Create File"), tr("Failed to create the file"));
    }
}

//重命名
void NDirTreeview::slot_rename(){

//    QModelIndex itemIndex = proxyModel->mapToSource(this->currentIndex());
//    if (!itemIndex.isValid())
//            return;

//    QString filePath = dirModel->filePath(itemIndex);
//    QFileInfo fileinfo(filePath);
//    bool isFile = fileinfo.isFile();
//    QString newFileName = QInputDialog::getText(this, tr("重命名"), isFile?tr("新的文件名"):tr("新的目录名"));

//    if (!newFileName.isEmpty()){
//        bool result= false;
//        if (isFile){
//            if (!newFileName.endsWith(".md"))
//                newFileName.append(".md");
//            newFileName = dirModel->filePath(itemIndex.parent())+"/"+newFileName;
//            result = QFile::rename ( filePath, newFileName);

//        }else{
//            newFileName = dirModel->filePath(itemIndex.parent())+"/"+newFileName;
//            result = QDir(filePath).rename ( filePath, newFileName);
//        }

//        if (!result)
//            QMessageBox::information(this, tr("重命名"), tr("重命名失败"));
//        else
//            this->setCurrentIndex(proxyModel->mapFromSource(itemIndex));
//    }
}

//删除目录
void NDirTreeview::slot_rmDir()
{
    QModelIndex index = proxyModel->mapToSource(this->currentIndex());
    if (!index.isValid())
            return;

    bool ok;
    if (dirModel->fileInfo(index).isDir())
       ok = dirModel->rmdir(index);
    else{
       ok = dirModel->remove(index);
    }

    if (!ok)
       QMessageBox::information(this,tr("Remove"),tr("Failed to remove %1").arg(dirModel->fileName(index)));
}
