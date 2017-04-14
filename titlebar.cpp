#include "titlebar.h"
#include "ui_titlebar.h"

Titlebar::Titlebar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Titlebar){
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);

    connect(ui->maxLabel,SIGNAL(clicked()), this, SLOT(solt_labelClick()));
    connect(ui->minLabel,SIGNAL(clicked()), this, SLOT(solt_labelClick()));
    connect(ui->closeLabel,SIGNAL(clicked()), this, SLOT(solt_labelClick()));
    connect(ui->settingLabel,SIGNAL(clicked()), this, SLOT(solt_labelClick()));
}

Titlebar::~Titlebar(){

    delete ui;
}

void Titlebar::mouseMoveEvent(QMouseEvent *event){

    if( event->buttons().testFlag(Qt::LeftButton) && mMoving){
        //p为偏移量
        QPoint p = event->globalPos() - mLastMousePosition;
                emit signal_move(p);
        mLastMousePosition = event->globalPos();

    }
}

void Titlebar::mouseReleaseEvent(QMouseEvent *event){

    mMoving = event->button() == Qt::LeftButton?false:true;
    this->setCursor(Qt::ArrowCursor);
}

void Titlebar::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton){
        this->setCursor(Qt::ClosedHandCursor);
        mMoving = true;
        mLastMousePosition = event->globalPos();
    }
}

void Titlebar::mouseDoubleClickEvent(QMouseEvent *e){
    emit signal_doubleClick();
}

void Titlebar::solt_labelClick(){
      NLabel *label = qobject_cast<NLabel *>(QObject::sender());
      if (label == ui->closeLabel)
          emit signal_closeWindow();

      else if(label == ui->maxLabel){
          if (label->toolTip().contains("最大化")){
                label->setToolTip("还原");
          }else
              label->setToolTip("最大化");

          emit signal_maxWindow();
      }

      else if (label == ui->minLabel)
          emit signal_minWindow();

      else if (label == ui->settingLabel)
          emit signal_settingDialog();

}

//载入用户信息的
void Titlebar::slot_loadUser(User &user){
    ui->userLabel->setText(user.getName());
    if (!user.getIconPath().isEmpty()){
        ui->iconLabel->setPixmap(QPixmap(user.getIconPath()));
    }
}
