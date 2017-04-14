#ifndef MARKDOWNEDITOR_H
#define MARKDOWNEDITOR_H

#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebChannel>
#include <QIODevice>
#include <QMessageBox>
#include <QFile>
#include <QUrl>

#include <connector.h>

class MarkdownEditor : public QWebEngineView
{
    Q_OBJECT
public:
    explicit MarkdownEditor(QWidget *parent = 0);
    void link(Connector *connector);
private:
    Connector* connector;
signals:


public slots:
    void slot_loadMarkdonwText(QString markdownText);

};

#endif // MARKDOWNEDITOR_H
