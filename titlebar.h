#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QMouseEvent>
#include <QDebug>
#include <QPixmap>
#include <user.h>

namespace Ui {
class Titlebar;
}

class Titlebar : public QWidget
{
    Q_OBJECT

public:
    explicit Titlebar(QWidget *parent = 0);
    ~Titlebar();

protected:
    void mousePressEvent(QMouseEvent *e);       //--鼠标按下事件
    void mouseMoveEvent(QMouseEvent *e);    //--鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *e); //--鼠标释放（松开）事件
    void mouseDoubleClickEvent(QMouseEvent *e); //--鼠标双击事件

private:
    Ui::Titlebar *ui;
    QPoint mLastMousePosition; //鼠标坐标
    bool mMoving;

private slots:
    void solt_labelClick();
    void slot_loadUser(User &);
    void modeChange(bool);

signals:
    void signal_move(QPoint &);
    void signal_doubleClick();
    void signal_maxWindow();
    void signal_minWindow();
    void signal_settingDialog();//发送信号,显示设置面板
    void signal_closeWindow();

    void signal_modeChange(bool); //模式改变
};

#endif // TITLEBAR_H
