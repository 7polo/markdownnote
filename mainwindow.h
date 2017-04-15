#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <connector.h>
#include <QKeyEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    void setRootPath();
    Connector* connector;

protected:
    void keyPressEvent(QKeyEvent *event);
public slots:
    //窗口处理
    void slot_moveWindow(QPoint &); //移动窗口
    void slot_maxWindow();
    void slot_minWindow();
    void slot_close();
    void slot_fullScreen();

private slots:
    void on_dirTreeView_customContextMenuRequested(const QPoint &pos);
    void on_fileTreeView_customContextMenuRequested(const QPoint &pos);
    void slot_modeChange(bool flag);
signals:
};

#endif // MAINWINDOW_H
