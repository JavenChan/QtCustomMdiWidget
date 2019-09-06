/********************************************************************************
** Form generated from reading UI file 'jv_mdi_widgetigczCT.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef JV_MDI_WIDGETIGCZCT_H
#define JV_MDI_WIDGETIGCZCT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mdi_dragger.h>

QT_BEGIN_NAMESPACE

class Ui_JVMdiWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_border;
    QVBoxLayout *verticalLayout;
    MdiDragger *widget_title;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QLabel *title;
    QToolButton *maxBtn;
    QToolButton *closeBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QWidget *JVMdiWidget)
    {
        if (JVMdiWidget->objectName().isEmpty())
            JVMdiWidget->setObjectName(QStringLiteral("JVMdiWidget"));
        JVMdiWidget->resize(452, 362);
        JVMdiWidget->setMinimumSize(QSize(160, 160));
        JVMdiWidget->setMaximumSize(QSize(16777215, 16777215));
        JVMdiWidget->setMouseTracking(true);
        JVMdiWidget->setFocusPolicy(Qt::ClickFocus);
        JVMdiWidget->setStyleSheet(QLatin1String("background-color: rgb(160, 160, 160);\n"
"color: rgb(176, 177, 180);"));
        verticalLayout_2 = new QVBoxLayout(JVMdiWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_border = new QWidget(JVMdiWidget);
        widget_border->setObjectName(QStringLiteral("widget_border"));
        widget_border->setMaximumSize(QSize(16777215, 16777215));
        widget_border->setFocusPolicy(Qt::NoFocus);
        widget_border->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(widget_border);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(4, 4, 4, 2);
        widget_title = new MdiDragger(widget_border);
        widget_title->setObjectName(QStringLiteral("widget_title"));
        widget_title->setMinimumSize(QSize(0, 30));
        widget_title->setMaximumSize(QSize(16777215, 30));
        horizontalLayout = new QHBoxLayout(widget_title);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget_title);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/res/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(30, 30));
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        title = new QLabel(widget_title);
        title->setObjectName(QStringLiteral("title"));
        title->setMinimumSize(QSize(100, 0));
        title->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        title->setFont(font);
        title->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        title->setMargin(6);

        horizontalLayout->addWidget(title);

        maxBtn = new QToolButton(widget_title);
        maxBtn->setObjectName(QStringLiteral("maxBtn"));
        maxBtn->setMinimumSize(QSize(24, 24));
        maxBtn->setMaximumSize(QSize(30, 30));
        maxBtn->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/res/images/max.png"), QSize(), QIcon::Normal, QIcon::Off);
        maxBtn->setIcon(icon1);
        maxBtn->setIconSize(QSize(30, 30));
        maxBtn->setAutoRaise(true);

        horizontalLayout->addWidget(maxBtn);

        closeBtn = new QToolButton(widget_title);
        closeBtn->setObjectName(QStringLiteral("closeBtn"));
        closeBtn->setMinimumSize(QSize(24, 24));
        closeBtn->setMaximumSize(QSize(30, 30));
        closeBtn->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/res/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeBtn->setIcon(icon2);
        closeBtn->setIconSize(QSize(30, 30));
        closeBtn->setAutoRaise(true);

        horizontalLayout->addWidget(closeBtn);


        verticalLayout->addWidget(widget_title);

        widget = new QWidget(widget_border);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 120));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        verticalLayout_2->addWidget(widget_border);


        retranslateUi(JVMdiWidget);

        QMetaObject::connectSlotsByName(JVMdiWidget);
    } // setupUi

    void retranslateUi(QWidget *JVMdiWidget)
    {
        JVMdiWidget->setWindowTitle(QApplication::translate("JVMdiWidget", "JVMdiWidget", nullptr));
        pushButton->setText(QString());
        title->setText(QApplication::translate("JVMdiWidget", "Nobita", nullptr));
        maxBtn->setText(QApplication::translate("JVMdiWidget", "O", nullptr));
        closeBtn->setText(QApplication::translate("JVMdiWidget", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JVMdiWidget: public Ui_JVMdiWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // JV_MDI_WIDGETIGCZCT_H
