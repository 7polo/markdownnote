#ifndef NDIRTREEVIEW_H
#define NDIRTREEVIEW_H

#include <QTreeView>
#include <QFileSystemModel>
#include <QInputDialog>
#include <QMessageBox>
#include <QMenu>
#include <ndirfiltermodel.h>
#include <niconprovider.h>


class NDirTreeview : public QTreeView
{
    Q_OBJECT
public:
    explicit NDirTreeview(QWidget *parent = 0);
    ~NDirTreeview();
    void setRootPath(QString path);
    void showPopMenu();


signals:
    void signal_selectedDir(QString );


public slots:
    void slot_selectDir(QModelIndex );
    void slot_mkDir();
    void slot_mkChildDir();
    void slot_rmDir();
    void slot_createFile();
    void slot_rename();

private:
    QFileSystemModel *dirModel;
    NDirFilterModel *proxyModel;
    QModelIndex index;
    QMenu *qMenu;

    void creatDir(bool flag);
};

#endif // NDIRTREEVIEW_H
