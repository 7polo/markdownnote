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

    //js
    void sendChangeMode(bool);
    void sendLivePreview(bool);
    void sendLoadMarkdown(QString markdown);
    void sendGetMarkdown();

    //js

    void sendChangeEditorTheme(QString);
    void sendChangePreviewTheme(QString);

public slots:

    void slot_getMarkdown(QString markdown);//转发 signal_getMarkdown 信号至编辑器
    void slot_edited(); //被编辑了

};

#endif // CONNECTOR_H
