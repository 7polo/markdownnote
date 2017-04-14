#include "ndirfiltermodel.h"
#include <QDebug>
NDirFilterModel::NDirFilterModel()
{

}

bool NDirFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    if(!sourceModel()) return false;

    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);
    QFileSystemModel *model = static_cast<QFileSystemModel*>(sourceModel());
    QString str = model->fileName(index);
    QFileInfo fileInfo = model->fileInfo(index);
//    qDebug()<<"过滤"<<fileInfo.filePath()<<endl;
    // .imgs 为默认图片资源目录
    if (fileInfo.isDir() && !fileInfo.fileName().contains(".imgs"))
        return true;
    return false;
}
