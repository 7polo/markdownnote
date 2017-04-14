#ifndef NLABEL_H
#define NLABEL_H

#include <QLabel>
#include <QMouseEvent>

class NLabel : public QLabel
{
    Q_OBJECT
public:
    explicit NLabel(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked();//点击事件
};

#endif // NLABEL_H
