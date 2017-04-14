#ifndef NDIRFILTERMODEL_H
#define NDIRFILTERMODEL_H
#include <QSortFilterProxyModel>
#include <QFileSystemModel>

class NDirFilterModel:public QSortFilterProxyModel
{
public:
    NDirFilterModel();

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
};

#endif // NDIRFILTERMODEL_H
