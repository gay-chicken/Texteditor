/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "textarea.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widTop;
    QWidget *layoutWidget1;
    QHBoxLayout *hLayoutBtn;
    QPushButton *btnCreate;
    QPushButton *btnOpen;
    QPushButton *btnSave;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer;
    TextArea *textEdit;
    QWidget *widBottom;
    QWidget *layoutWidget2;
    QHBoxLayout *hLayoutLabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labPos;
    QComboBox *boxEncode;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        Widget->setMinimumSize(QSize(350, 350));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/notebook.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 801, 601));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widTop = new QWidget(layoutWidget);
        widTop->setObjectName("widTop");
        widTop->setMinimumSize(QSize(0, 40));
        widTop->setStyleSheet(QString::fromUtf8("background-color: rgb(41, 91, 255);"));
        layoutWidget1 = new QWidget(widTop);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 0, 801, 42));
        hLayoutBtn = new QHBoxLayout(layoutWidget1);
        hLayoutBtn->setObjectName("hLayoutBtn");
        hLayoutBtn->setContentsMargins(0, 0, 0, 0);
        btnCreate = new QPushButton(layoutWidget1);
        btnCreate->setObjectName("btnCreate");
        btnCreate->setStyleSheet(QString::fromUtf8("QPushButton { color: black; background-color: white; }\n"
"QPushButton:hover { color: blue; background-color: gray; }\n"
""));

        hLayoutBtn->addWidget(btnCreate);

        btnOpen = new QPushButton(layoutWidget1);
        btnOpen->setObjectName("btnOpen");
        btnOpen->setStyleSheet(QString::fromUtf8("QPushButton { color: black; background-color: white; }\n"
"QPushButton:hover { color: blue; background-color: gray; }\n"
""));

        hLayoutBtn->addWidget(btnOpen);

        btnSave = new QPushButton(layoutWidget1);
        btnSave->setObjectName("btnSave");
        btnSave->setStyleSheet(QString::fromUtf8("QPushButton { color: black; background-color: white; }\n"
"QPushButton:hover { color: blue; background-color: gray; }\n"
""));

        hLayoutBtn->addWidget(btnSave);

        btnClose = new QPushButton(layoutWidget1);
        btnClose->setObjectName("btnClose");
        btnClose->setMinimumSize(QSize(0, 0));
        btnClose->setStyleSheet(QString::fromUtf8("QPushButton { color: black; background-color: white; }\n"
"QPushButton:hover { color: blue; background-color: gray; }\n"
""));

        hLayoutBtn->addWidget(btnClose);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutBtn->addItem(horizontalSpacer);


        verticalLayout->addWidget(widTop);

        textEdit = new TextArea(layoutWidget);
        textEdit->setObjectName("textEdit");

        verticalLayout->addWidget(textEdit);

        widBottom = new QWidget(layoutWidget);
        widBottom->setObjectName("widBottom");
        widBottom->setMinimumSize(QSize(0, 30));
        widBottom->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        layoutWidget2 = new QWidget(widBottom);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, -20, 801, 71));
        hLayoutLabel = new QHBoxLayout(layoutWidget2);
        hLayoutLabel->setObjectName("hLayoutLabel");
        hLayoutLabel->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutLabel->addItem(horizontalSpacer_2);

        labPos = new QLabel(layoutWidget2);
        labPos->setObjectName("labPos");

        hLayoutLabel->addWidget(labPos);

        boxEncode = new QComboBox(layoutWidget2);
        boxEncode->addItem(QString());
        boxEncode->addItem(QString());
        boxEncode->addItem(QString());
        boxEncode->addItem(QString());
        boxEncode->addItem(QString());
        boxEncode->addItem(QString());
        boxEncode->addItem(QString());
        boxEncode->addItem(QString());
        boxEncode->addItem(QString());
        boxEncode->setObjectName("boxEncode");

        hLayoutLabel->addWidget(boxEncode);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        hLayoutLabel->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widBottom);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\346\226\207\344\273\266\347\274\226\350\276\221\345\231\250", nullptr));
        btnCreate->setText(QCoreApplication::translate("Widget", "\346\226\260\345\273\272", nullptr));
        btnOpen->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));
        btnSave->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230", nullptr));
        btnClose->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        textEdit->setPlaceholderText(QString());
        labPos->setText(QString());
        boxEncode->setItemText(0, QCoreApplication::translate("Widget", "UTF-8", nullptr));
        boxEncode->setItemText(1, QCoreApplication::translate("Widget", "UTF-16", nullptr));
        boxEncode->setItemText(2, QCoreApplication::translate("Widget", "UTF-16LE", nullptr));
        boxEncode->setItemText(3, QCoreApplication::translate("Widget", "UTF-16BE", nullptr));
        boxEncode->setItemText(4, QCoreApplication::translate("Widget", "UTF-32", nullptr));
        boxEncode->setItemText(5, QCoreApplication::translate("Widget", "UTF-32LE", nullptr));
        boxEncode->setItemText(6, QCoreApplication::translate("Widget", "UTF-32BE", nullptr));
        boxEncode->setItemText(7, QCoreApplication::translate("Widget", "Latin-1", nullptr));
        boxEncode->setItemText(8, QCoreApplication::translate("Widget", "\347\263\273\347\273\237\351\273\230\350\256\244", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
