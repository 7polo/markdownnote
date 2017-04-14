#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebEngineView>
#include <QFileSystemModel>
#include <ndirfiltermodel.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){


    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setMouseTracking(true);
    ui->setupUi(this);

    connector = new Connector();
    connector->setTocView(ui->tocView);

    //窗口信号槽
    connect(ui->titlebar,SIGNAL(signal_move(QPoint&)),this, SLOT(slot_moveWindow(QPoint&)));
    connect(ui->titlebar, SIGNAL(signal_maxWindow()),this,SLOT(slot_maxWindow()));
    connect(ui->titlebar,SIGNAL(signal_minWindow()), this,SLOT(slot_minWindow()));
    connect(ui->titlebar,SIGNAL(signal_closeWindow()), this,SLOT(slot_close()));
    connect(ui->titlebar, SIGNAL(signal_doubleClick()),this,SLOT(slot_fullScreen()));

    connect(ui->dirTreeView,SIGNAL(signal_selectedDir(QString)),ui->fileTreeView,SLOT(slot_loadDir(QString)));
    connect(ui->fileTreeView,SIGNAL(signal_filePath(QString)),ui->editorView,SLOT(slot_loadMarkdonwText(QString)));
    setRootPath(); //载入根目录

    ui->editorView->link(connector);
}


MainWindow::~MainWindow()
{
    delete ui;
}

//移动窗口
void MainWindow::slot_moveWindow(QPoint &p){
     this->move(this->pos()+p);

}
//最大化
void MainWindow::slot_maxWindow(){
    if (this->isMaximized())
        this->showNormal();
    else if(!this->isMinimized() && !this->isMaximized())
        this->showMaximized();
}

void MainWindow::slot_minWindow(){
    this->showMinimized();
}
void MainWindow::slot_fullScreen(){
    if (this->isFullScreen())
        this->showNormal();
    else
        this->showFullScreen();
}

//关闭
void MainWindow::slot_close(){
    this->close();
}

void MainWindow::setRootPath(){
    QString path = "/home/apologizebao/文档/我的笔记";

    QString dirName = QInputDialog::getText(this, tr("创建目录"), tr("目录名称"));
    if (!dirName.isEmpty()) {
        if (QFileInfo(dirName).isDir())
             ui->dirTreeView->setRootPath(dirName);
    }

    ui->dirTreeView->setRootPath(path);
}



void MainWindow::on_dirTreeView_customContextMenuRequested(const QPoint &pos)
{
    ui->dirTreeView->showPopMenu();
}

void MainWindow::on_fileTreeView_customContextMenuRequested(const QPoint &pos)
{
    ui->fileTreeView->showPopmenu();
}
