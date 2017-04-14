#include "niconprovider.h"


NIconProvider::NIconProvider()
{
    dirIcon = new QIcon(":/icon/floder.svg");
    fileIcon = new QIcon(":/icon/md.svg");
}

NIconProvider::~NIconProvider(){
    delete dirIcon;
    delete fileIcon;
}

QIcon NIconProvider::icon(const QFileInfo & info) const
{

    QString str = info.filePath();
    //目录图标
    if(QFileInfo(info.filePath()).isDir())
        return *dirIcon;

    return *fileIcon;
}
