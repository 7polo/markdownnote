#ifndef NOTETREEVIEW_H
#define NOTETREEVIEW_H

#include <QTreeView>
#include <QFileSystemModel>
#include <QMenu>
#include <QHeaderView>
#include <QMessageBox>
#include <QInputDialog>
#include <niconprovider.h>

class NoteTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit NoteTreeView(QWidget *parent = 0);

    void showPopmenu();

private:
    QMenu *qMenu;
    QFileSystemModel *noteModel = NULL;
    QString parentPath;
    QModelIndex index;
signals:
    void signal_filePath(QString);
    void signal_setToc(QString);
    void signal_saveMarkdown();

public slots:
    void slot_loadDir(QString path);
    void slot_createFile();
    void slot_rename();
    void slot_deleteFile();
    void slot_sendselectedPath(QModelIndex index);
};

#endif // NOTETREEVIEW_H
