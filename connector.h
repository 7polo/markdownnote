#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <QTextBrowser>

class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(QObject *parent = 0);
    void setTocView(QTextBrowser *view);

private:
    QTextBrowser * tocView = NULL;

signals:
    //js
    void sendMarkdownContent(QString markdown);
    void sendLivePreview(bool);
    void sendPreview(bool);
    void sendChangeEditorTheme(QString);
    void sendChangePreviewTheme(QString);
    void signal_getMarkdown();

public slots:
    void slot_getToc(QString toc);
    void slot_getMarkdown(QString markdownText);
};

#endif // CONNECTOR_H
