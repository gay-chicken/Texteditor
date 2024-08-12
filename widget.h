#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QDebug>
#include <QIODevice>
#include <QTextStream>
#include <QString>
#include <QStringConverter>
#include <iostream>
#include <windows.h>
#include <QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_btnCreate_clicked();

    void on_btnOpen_clicked();

    void on_btnSave_clicked();

    void on_btnClose_clicked();

    void on_boxEncode_activated(int index);

    void on_textEdit_cursorPositionChanged();

private:
    QFile file;
    QShortcut *cutOpen;
    QShortcut *cutSave;
    QShortcut *cutZoomIn;
    QShortcut *cutZoomOut;
    QTextStream stream;
    QStringList history;
    Ui::Widget *ui;
};
#endif // WIDGET_H
