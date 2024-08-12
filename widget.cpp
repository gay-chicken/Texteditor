#include "widget.h"
#include "./ui_widget.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QRadioButton>
#include <QTemporaryFile>
#include <QWheelEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    cutOpen = new QShortcut(QKeySequence("Ctrl+O"), this);
    cutSave = new QShortcut(QKeySequence("Ctrl+S"), this);
    cutZoomIn = new QShortcut(QKeySequence("Ctrl+="), this);
    cutZoomOut = new QShortcut(QKeySequence("Ctrl+-"), this);
    ui->setupUi(this);
    this->setLayout(ui->verticalLayout);
    ui->widBottom->setLayout(ui->hLayoutLabel);

    ui->textEdit->setFocus();

    QObject::connect(cutOpen, &QShortcut::activated, this, [=](){
        Widget::on_btnOpen_clicked();
    });
    QObject::connect(cutSave, &QShortcut::activated, this, [=](){
        Widget::on_btnSave_clicked();
    });
    QObject::connect(cutZoomIn, &QShortcut::activated, this, [=](){
        QFont font = ui->textEdit->font();
        int pointsize = font.pointSize();
        if (pointsize == -1) return;

        font.setPointSize(pointsize + 1);
        ui->textEdit->setFont(font);
    });
    QObject::connect(cutZoomOut, &QShortcut::activated, this, [=](){
        QFont font = ui->textEdit->font();
        int pointsize = font.pointSize();
        if (pointsize == -1) return;

        font.setPointSize(pointsize - 1);
        ui->textEdit->setFont(font);
    });

}

Widget::~Widget()
{
    delete ui;
    delete cutOpen;
    delete cutSave;
}

void Widget::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::warning(this, "退出", "确定离开么？", QMessageBox::Yes | QMessageBox::No);
    switch(ret) {
    case QMessageBox::Yes:
        event->accept();
        break;
    case QMessageBox::No:
    default:
        event->ignore();
    }
}

void Widget::on_btnCreate_clicked()
{
    QString filename;
    QStringList paths;
    QFileDialog fileDialog;

    if (file.isOpen()) {
        file.close();
        ui->textEdit->clear();
    }

    fileDialog.setFilter(QDir::Files);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setNameFilter("Text (*.txt)");
    fileDialog.setDefaultSuffix(".txt");
    fileDialog.setHistory(history);
    fileDialog.setWindowTitle("新建文件");
    fileDialog.exec();
    paths = fileDialog.selectedFiles();
    if (paths.isEmpty()) return;
    filename = paths.first();

    file.setFileName(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        std::cerr << "Failed open file!";
        return ;
    }
    this->setWindowTitle(filename + " - 文件编辑器");

}


void Widget::on_btnOpen_clicked()
{
    QString filename;
    QStringList paths;
    QFileDialog fileDialog;

    fileDialog.setFileMode(QFileDialog::ExistingFile);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setNameFilter("Text (*.txt)");
    fileDialog.setHistory(history);
    fileDialog.exec();
    paths = fileDialog.selectedFiles();
    if (paths.isEmpty()) return;
    filename = paths.first();

    if (file.isOpen()) file.close();
    file.setFileName(filename);
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        std::cerr << "Failed open file!";
        return ;
    }

    this->setWindowTitle(filename + " - 文件编辑器");
    on_boxEncode_activated(ui->boxEncode->currentIndex());
}


void Widget::on_btnSave_clicked()
{
    QString content;
    QString filename;
    QStringList paths;
    QFileDialog fileDialog;


    if (ui->textEdit->toPlainText() == "") return;

    if (!file.isOpen()) {
        fileDialog.setFilter(QDir::Files);
        fileDialog.setFileMode(QFileDialog::AnyFile);
        fileDialog.setAcceptMode(QFileDialog::AcceptSave);
        fileDialog.setNameFilter("Text (*.txt)");
        fileDialog.setDefaultSuffix(".txt");
        fileDialog.setHistory(history);
        fileDialog.exec();
        paths = fileDialog.selectedFiles();
        if (paths.isEmpty()) return;
        filename = paths.first();

        file.setFileName(filename);
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            std::cerr << "Failed open file!";
            return ;
        }
        this->setWindowTitle(filename + " - 文件编辑器");
    }

    file.seek(0);
    stream.setDevice(&file);

    content = ui->textEdit->toPlainText();
    stream << content;

    file.flush();
}


void Widget::on_btnClose_clicked()
{
    ui->textEdit->clear();
    if (!file.isOpen()) return;

    file.close(); 
    this->setWindowTitle("文件编辑器");
}

void Widget::on_boxEncode_activated(int index)
{
    QString content;

    if (!file.isOpen()) return;

    stream.setDevice(&file);
    auto encoding = QStringConverter::encodingForName(
                                                ui->boxEncode->currentText().toStdString().c_str());
    if (!encoding) {
        encoding = QStringConverter::System;
    }
    ui->textEdit->clear();
    file.seek(0);
    stream.setEncoding(encoding.value());

    while(!stream.atEnd()) {
        content = stream.read(128);
        ui->textEdit->append(content);
    }
}


void Widget::on_textEdit_cursorPositionChanged()
{
    QBrush brush(Qt::yellow);
    QTextCursor cursor =  ui->textEdit->textCursor();
    QTextEdit::ExtraSelection ext;
    QList<QTextEdit::ExtraSelection> select;

    ui->labPos->setText(QString("第%1行 第%2列").arg(cursor.blockNumber() + 1).arg(cursor.columnNumber() + 1));

    ext.cursor = cursor;
    ext.format.setBackground(brush);
    ext.format.setProperty(QTextFormat::FullWidthSelection, true);
    select.append(ext);
    ui->textEdit->setExtraSelections(select);
}

