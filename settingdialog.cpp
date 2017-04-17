#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QDebug>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);

    connect(ui->editorThemes,SIGNAL(currentIndexChanged(QString)),this, SLOT(slot_editorThemeChange(QString)));
    connect(ui->previewThemes,SIGNAL(currentIndexChanged(QString)),this, SLOT(slot_previewThemeChange(QString)));
}

SettingDialog::~SettingDialog()
{
    delete ui;
}

void SettingDialog::slot_getEditorThemes(QString themes){

    QStringList editorThemes = themes.split(",");
    if (ui->editorThemes->count() != 0)
        ui->editorThemes->clear();
    ui->editorThemes->addItems(editorThemes);
}

void SettingDialog::slot_editorThemeChange(QString theme){

    emit signal_editorThemeChange(theme);
}

void SettingDialog::slot_getPreviewThemes(QString themes){
    qDebug()<<"主题"<<themes<<endl;
    QStringList editorThemes = themes.split(",");
    if (ui->previewThemes->count() != 0)
        ui->previewThemes->clear();
    ui->previewThemes->addItems(editorThemes);
}

void SettingDialog::slot_previewThemeChange(QString theme){
    emit signal_previewThemeChange(theme);
}
