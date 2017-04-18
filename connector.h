#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QTextBrowser>

class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(QObject *parent = 0);

signals:
    //ui-signal
    void signal_getMarkdown(QString markdown); //被转发信号
    void signal_getEditeFlag(); //被编辑信号
    void signal_getEditorThemes(QString);
    void signal_getPreviewThemes(QString);

    //js
    void sendChangeMode(bool);
    void sendLivePreview(bool);
    void sendLoadMarkdown(QString markdown);
    void sendGetMarkdown();
    void sendChangeEditorTheme(QString);
    void sendChangePreviewTheme(QString);
    void sendInsertMarkdown(QString);

public slots:

    void slot_getMarkdown(QString markdown);//转发 signal_getMarkdown 信号至编辑器
    void slot_edited(); //被编辑了
    void slot_getEditorThemes(QString);
    void slot_getPreviewThemes(QString);

};

#endif // CONNECTOR_H
