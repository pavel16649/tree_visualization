QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AVL.cpp \
    AbstractTree.cpp \
    RB_Tree.cpp \
    SplayTree.cpp \
    Treap.cpp \
    abstractnode.cpp \
    avl_node.cpp \
    bettergraphicsscene.cpp \
    bettergraphicsview.cpp \
    main.cpp \
    mainwindow.cpp \
    rb_node.cpp \
    splaynode.cpp \
    treenodeellipse.cpp

HEADERS += \
    AVL.h \
    AbstractTree.h \
    RB_Tree.h \
    SplayTree.h \
    Treap.h \
    abstractnode.h \
    avl_node.h \
    bettergraphicsscene.h \
    bettergraphicsview.h \
    mainwindow.h \
    rb_node.h \
    splaynode.h \
    treenodeellipse.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

