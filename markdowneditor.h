#ifndef MARKDOWNEDITOR_H
#define MARKDOWNEDITOR_H

#include <QWebEngineView>
#include <QWebEnginePage>
#include <QApplication>
#include <QWebChannel>
#include <QKeyEvent>
#include <QIODevice>
#include <QMessageBox>
#include <QClipboard>
#include <QFile>
#include <QUrl>

#include <connector.h>

class MarkdownEditor : public QWebEngineView
{
    Q_OBJECT
public:
    explicit MarkdownEditor(QWidget *parent = 0);

private:
    Connector* connector;
    QString curFilePath; //当前文件路径
    QString nextFilePath; //下一个想要打开的文件路径
    bool isSaved = true;
    bool isEmpty = false;
signals:
    void signal_editorThemes(QString);
    void signal_previewThemes(QString);

public slots:
    //ctrl+s
    void slot_CtrlandS();
    void slot_CtrlandE();
    //与connector相关
    void slot_changeMode(bool); //改变模式
    void slot_livePrivew(bool flag);//实时预览
    void slot_loadMarkdown(QString filePath); //根据路径载入markdown内容
    void slot_edited(); //编辑器被编辑
    void slot_saveMarkdown(QString markdown); //保存文件

    void slot_EditorThemes(QString themes);
    void slot_edtiorThemeChange(QString);

    void slot_PreviewThemes(QString);
    void slot_previewThemeChange(QString);

    void slot_changeLivePreview(bool);

};

#endif // MARKDOWNEDITOR_H
