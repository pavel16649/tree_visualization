/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "bettergraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    betterGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QPushButton *AVL_button;
    QPushButton *RB_button;
    QPushButton *Treap_button;
    QPushButton *Splay_button;
    QLabel *current_tree_label;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *num_add_edit;
    QPushButton *add_button;
    QCheckBox *checkBox;
    QPushButton *clear_button;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *nodesCount;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *nodesMin;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *nodesMax;
    QPushButton *insertRandom;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1270, 940);
        MainWindow->setMinimumSize(QSize(1270, 940));
        MainWindow->setMaximumSize(QSize(1270, 940));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI Emoji"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 90, 1051, 851));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        graphicsView = new betterGraphicsView(layoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(809, 790));

        verticalLayout_2->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        AVL_button = new QPushButton(layoutWidget);
        AVL_button->setObjectName(QString::fromUtf8("AVL_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(AVL_button->sizePolicy().hasHeightForWidth());
        AVL_button->setSizePolicy(sizePolicy1);
        AVL_button->setFont(font);

        horizontalLayout->addWidget(AVL_button);

        RB_button = new QPushButton(layoutWidget);
        RB_button->setObjectName(QString::fromUtf8("RB_button"));
        sizePolicy1.setHeightForWidth(RB_button->sizePolicy().hasHeightForWidth());
        RB_button->setSizePolicy(sizePolicy1);
        RB_button->setMinimumSize(QSize(50, 0));
        RB_button->setFont(font);

        horizontalLayout->addWidget(RB_button);

        Treap_button = new QPushButton(layoutWidget);
        Treap_button->setObjectName(QString::fromUtf8("Treap_button"));
        sizePolicy1.setHeightForWidth(Treap_button->sizePolicy().hasHeightForWidth());
        Treap_button->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI Emoji"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        Treap_button->setFont(font1);

        horizontalLayout->addWidget(Treap_button);

        Splay_button = new QPushButton(layoutWidget);
        Splay_button->setObjectName(QString::fromUtf8("Splay_button"));
        sizePolicy1.setHeightForWidth(Splay_button->sizePolicy().hasHeightForWidth());
        Splay_button->setSizePolicy(sizePolicy1);
        Splay_button->setFont(font);

        horizontalLayout->addWidget(Splay_button);


        verticalLayout_2->addLayout(horizontalLayout);

        current_tree_label = new QLabel(centralwidget);
        current_tree_label->setObjectName(QString::fromUtf8("current_tree_label"));
        current_tree_label->setGeometry(QRect(390, 10, 321, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI Semilight"));
        font2.setPointSize(28);
        current_tree_label->setFont(font2);
        current_tree_label->setAlignment(Qt::AlignCenter);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1080, 130, 171, 341));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        num_add_edit = new QLineEdit(layoutWidget1);
        num_add_edit->setObjectName(QString::fromUtf8("num_add_edit"));

        verticalLayout->addWidget(num_add_edit);

        add_button = new QPushButton(layoutWidget1);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        add_button->setFont(font);

        verticalLayout->addWidget(add_button);

        checkBox = new QCheckBox(layoutWidget1);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setFont(font);

        verticalLayout->addWidget(checkBox);

        clear_button = new QPushButton(layoutWidget1);
        clear_button->setObjectName(QString::fromUtf8("clear_button"));
        clear_button->setFont(font);

        verticalLayout->addWidget(clear_button);


        verticalLayout_4->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        nodesCount = new QLineEdit(layoutWidget1);
        nodesCount->setObjectName(QString::fromUtf8("nodesCount"));

        horizontalLayout_2->addWidget(nodesCount);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        nodesMin = new QLineEdit(layoutWidget1);
        nodesMin->setObjectName(QString::fromUtf8("nodesMin"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nodesMin->sizePolicy().hasHeightForWidth());
        nodesMin->setSizePolicy(sizePolicy2);
        nodesMin->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(nodesMin);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        nodesMax = new QLineEdit(layoutWidget1);
        nodesMax->setObjectName(QString::fromUtf8("nodesMax"));
        sizePolicy2.setHeightForWidth(nodesMax->sizePolicy().hasHeightForWidth());
        nodesMax->setSizePolicy(sizePolicy2);
        nodesMax->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_4->addWidget(nodesMax);


        verticalLayout_3->addLayout(horizontalLayout_4);

        insertRandom = new QPushButton(layoutWidget1);
        insertRandom->setObjectName(QString::fromUtf8("insertRandom"));

        verticalLayout_3->addWidget(insertRandom);


        verticalLayout_4->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Tree visualization", nullptr));
        AVL_button->setText(QCoreApplication::translate("MainWindow", "AVL-tree", nullptr));
        RB_button->setText(QCoreApplication::translate("MainWindow", "Red-Black tree", nullptr));
        Treap_button->setText(QCoreApplication::translate("MainWindow", "Treap", nullptr));
        Splay_button->setText(QCoreApplication::translate("MainWindow", "Splay-tree", nullptr));
        current_tree_label->setText(QCoreApplication::translate("MainWindow", "AVL-Tree", nullptr));
        add_button->setText(QCoreApplication::translate("MainWindow", "Insert node", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Remove mode", nullptr));
        clear_button->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "nodes", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "from", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "to", nullptr));
        insertRandom->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
