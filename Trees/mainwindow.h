#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsScene>
#include <QtGui>
#include <cmath>
#include "AbstractTree.h"
#include "AVL.h"
#include "RB_Tree.h"
#include "Treap.h"
#include "SplayTree.h"
#include "treenodeellipse.h"
#include "bettergraphicsscene.h"
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AVL_button_clicked();

    void on_RB_button_clicked();

    void on_Treap_button_clicked();

    void on_Splay_button_clicked();

    void on_add_button_clicked();

    void removeNode(int val);

    void on_clear_button_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_insertRandom_clicked();

private:
    Ui::MainWindow* ui;

    QGraphicsEllipseItem* ellipse1, *ellipse2;

    TreeNodeEllipse* point;

    QGraphicsScene *sceneAVL, *sceneSplay, *sceneRB, *sceneTreap;

    AVL* avl_tree;

    RB_Tree* rb_tree;

    Treap* treap;

    SplayTree* splay_tree;

    bool remove_mode;

    struct ret {
        int cur_pos;
        int max_right;
        int cur_y;

        ret(int cur, int max, int y)
            : cur_pos(cur), max_right(max), cur_y(y)
        {

        }
    };

    void repaintScene();

    ret redrawTree(AVL::node *tree, int current_x, int current_y, const int &delta_x = 50, const int &delta_y = 120);

    ret redrawTree(RB_Tree::node *tree, int current_x, int current_y, const int &delta_x = 50, const int &delta_y = 120);

    ret redrawTree(Treap::node *tree, int current_x, int current_y, const int &delta_x = 50, const int &delta_y = 120);

    ret redrawTree(SplayTree::node *tree, int current_x, int current_y, const int &delta_x = 50, const int &delta_y = 120);

};
#endif // MAINWINDOW_H
