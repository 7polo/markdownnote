#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class SettingDialog;
}

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = 0);
    ~SettingDialog();

private:
    Ui::SettingDialog *ui;

private slots:
    void slot_getEditorThemes(QString);
    void slot_editorThemeChange(QString);

    void slot_getPreviewThemes(QString);
    void slot_previewThemeChange(QString);

signals:
    void signal_editorThemeChange(QString);
    void signal_previewThemeChange(QString);
};

#endif // SETTINGDIALOG_H
