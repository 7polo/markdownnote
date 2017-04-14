#include "nlabel.h"

NLabel::NLabel(QWidget *parent) : QLabel(parent)
{

}

void NLabel::mousePressEvent(QMouseEvent *event){
    //如果单击了就触发clicked信号
    if (event->button() == Qt::LeftButton){
        emit clicked();
    }
    QLabel::mousePressEvent(event);
}


