#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    srand(time(0));
    ui->setupUi(this);

    remove_mode = false;
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    sceneAVL = new betterGraphicsScene;
    sceneSplay = new betterGraphicsScene;
    sceneRB = new betterGraphicsScene;
    sceneTreap = new betterGraphicsScene;
    ui->graphicsView->setScene(sceneAVL);

    connect(sceneAVL, SIGNAL(signal1(int)), this, SLOT(removeNode(int)));
    connect(sceneRB, SIGNAL(signal1(int)), this, SLOT(removeNode(int)));
    connect(sceneTreap, SIGNAL(signal1(int)), this, SLOT(removeNode(int)));
    connect(sceneSplay, SIGNAL(signal1(int)), this, SLOT(removeNode(int)));

    avl_tree = new AVL;
    rb_tree = new RB_Tree;
    treap = new Treap;
    splay_tree = new SplayTree;

    QRegExp number("(-)?[0-9]{1,10}");
    ui->num_add_edit->setValidator(new QRegExpValidator(number, this));

    QRegExp range("[0-9]{1,5}");
    ui->nodesCount->setValidator(new QRegExpValidator(range, this));
    ui->nodesMin->setValidator(new QRegExpValidator(range, this));
    ui->nodesMax->setValidator(new QRegExpValidator(range, this));

    QPen pen(Qt::black);
    pen.setCosmetic(true);
    pen.setWidth(2);
    QBrush brush(Qt::blue);
    QBrush brush1(Qt::red);
    QBrush bruh(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    ellipse1 = sceneAVL->addEllipse(0, 0, 700, 700, pen, bruh);
    sceneAVL->addEllipse(250, 300, 200, 200, pen, brush1);
    ellipse2 = sceneAVL->addEllipse(150, 200, 50, 50, pen, brush);
    sceneAVL->addEllipse(500, 200, 50, 50, pen, brush);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AVL_button_clicked()
{
    ui->graphicsView->setScene(sceneAVL);
    ui->current_tree_label->setText("AVL-Tree");
}

void MainWindow::on_RB_button_clicked()
{
    ui->graphicsView->setScene(sceneRB);
    ui->current_tree_label->setText("Red-Black Tree");
}

void MainWindow::on_Treap_button_clicked()
{
    ui->graphicsView->setScene(sceneTreap);
    ui->current_tree_label->setText("Treap");
}

void MainWindow::on_Splay_button_clicked()
{
    ui->graphicsView->setScene(sceneSplay);
    ui->current_tree_label->setText("Splay-Tree");
}

void MainWindow::repaintScene()
{
    sceneAVL->clear();
    sceneRB->clear();
    sceneTreap->clear();
    sceneSplay->clear();

    redrawTree(avl_tree->getRoot(), 0, 0);
    redrawTree(rb_tree->getRoot(), 0, 0);
    redrawTree(treap->getRoot(), 0, 0);
    redrawTree(splay_tree->getRoot(), 0, 0);
}

MainWindow::ret MainWindow::redrawTree(AVL::node *tree, int current_x, int current_y, const int& delta_x, const int &delta_y)
{
    if (tree == nullptr) {
        return ret(-1, -1, -1);
    }

    ret l = redrawTree(tree->left, current_x, current_y + delta_y);

    if (l.cur_pos != -1) {
        current_x = l.max_right + 20 + delta_x;
    } else {
        current_x += 20 + delta_x;
    }

    ret r = redrawTree(tree->right, current_x, current_y + delta_y);

    if (r.cur_pos != -1 && l.cur_pos != -1) {
        current_x = (l.cur_pos + r.cur_pos) / 2;
    }

    TreeNodeEllipse* new_ellepse = new TreeNodeEllipse(tree->value, TreeNodeEllipse::red);
    new_ellepse->setPos(current_x, current_y);
    sceneAVL->addItem(new_ellepse);
    if (l.cur_pos != -1) {
        QGraphicsLineItem* left_line = new QGraphicsLineItem(current_x + 30, current_y + 30,
                                                             l.cur_pos + 30, current_y + delta_y + 30);
        left_line->setPen(QPen(Qt::black));
        left_line->setZValue(-1);
        sceneAVL->addItem(left_line);
    }
    if (r.cur_pos != -1) {
        QGraphicsLineItem* right_line = new QGraphicsLineItem(current_x + 30, current_y + 30,
                                                             r.cur_pos + 30, current_y + delta_y + 30);
        right_line->setPen(QPen(Qt::black));
        right_line->setZValue(-1);
        sceneAVL->addItem(right_line);
    }

    return ret(current_x, std::max(current_x, std::max(l.max_right, r.max_right)), current_y);
}

MainWindow::ret MainWindow::redrawTree(RB_Tree::node *tree, int current_x, int current_y, const int& delta_x, const int &delta_y)
{
    if (tree == nullptr) {
        return ret(-1, -1, -1);
    }

    ret l = redrawTree(tree->left, current_x, current_y + delta_y);

    if (l.cur_pos != -1) {
        current_x = l.max_right + 20 + delta_x;
    } else {
        current_x += 20 + delta_x;
    }

    ret r = redrawTree(tree->right, current_x, current_y + delta_y);

    if (r.cur_pos != -1 && l.cur_pos != -1) {
        current_x = (l.cur_pos + r.cur_pos) / 2;
    }

    TreeNodeEllipse* new_ellepse = new TreeNodeEllipse(tree->value,
                                                       (tree->color == RB_Tree::red) ? RB_Tree::red : RB_Tree::black);
    new_ellepse->setPos(current_x, current_y);
    sceneRB->addItem(new_ellepse);
    if (l.cur_pos != -1) {
        QGraphicsLineItem* left_line = new QGraphicsLineItem(current_x + 30, current_y + 30,
                                                             l.cur_pos + 30, current_y + delta_y + 30);
        left_line->setPen(QPen(Qt::black));
        left_line->setZValue(-1);
        sceneRB->addItem(left_line);
    }
    if (r.cur_pos != -1) {
        QGraphicsLineItem* right_line = new QGraphicsLineItem(current_x + 30, current_y + 30,
                                                             r.cur_pos + 30, current_y + delta_y + 30);
        right_line->setPen(QPen(Qt::black));
        right_line->setZValue(-1);
        sceneRB->addItem(right_line);
    }

    return ret(current_x, std::max(current_x, std::max(l.max_right, r.max_right)), current_y);
}

MainWindow::ret MainWindow::redrawTree(Treap::node *tree, int current_x, int current_y, const int& delta_x, const int &delta_y)
{
    if (tree == nullptr) {
        return ret(-1, -1, -1);
    }

    ret l = redrawTree(tree->left, current_x, current_y + delta_y);

    if (l.cur_pos != -1) {
        current_x = l.max_right + 20 + delta_x;
    } else {
        current_x += 20 + delta_x;
    }

    ret r = redrawTree(tree->right, current_x, current_y + delta_y);

    if (r.cur_pos != -1 && l.cur_pos != -1) {
        current_x = (l.cur_pos + r.cur_pos) / 2;
    }

    TreeNodeEllipse* new_ellepse = new TreeNodeEllipse(tree->value, TreeNodeEllipse::red);
    new_ellepse->setPos(current_x, current_y);
    sceneTreap->addItem(new_ellepse);
    if (l.cur_pos != -1) {
        QGraphicsLineItem* left_line = new QGraphicsLineItem(current_x + 30, current_y + 30,
                                                             l.cur_pos + 30, current_y + delta_y + 30);
        left_line->setPen(QPen(Qt::black));
        left_line->setZValue(-1);
        sceneTreap->addItem(left_line);
    }
    if (r.cur_pos != -1) {
        QGraphicsLineItem* right_line = new QGraphicsLineItem(current_x + 30, current_y + 30,
                                                             r.cur_pos + 30, current_y + delta_y + 30);
        right_line->setPen(QPen(Qt::black));
        right_line->setZValue(-1);
        sceneTreap->addItem(right_line);
    }

    return ret(current_x, std::max(current_x, std::max(l.max_right, r.max_right)), current_y);
}

MainWindow::ret MainWindow::redrawTree(SplayTree::node *tree, int current_x, int current_y, const int& delta_x, const int &delta_y)
{
    if (tree == nullptr) {
        return ret(-1, -1, -1);
    }

    ret l = redrawTree(tree->left, current_x, current_y + delta_y);

    if (l.cur_pos != -1) {
        current_x = l.max_right + 20 + delta_x;
    } else {
        current_x += 20 + delta_x;
    }

    ret r = redrawTree(tree->right, current_x, current_y + delta_y);

    if (r.cur_pos != -1 && l.cur_pos != -1) {
        current_x = (l.cur_pos + r.cur_pos) / 2;
    }

    TreeNodeEllipse* new_ellepse = new TreeNodeEllipse(tree->value, TreeNodeEllipse::red);
    new_ellepse->setPos(current_x, current_y);
    sceneSplay->addItem(new_ellepse);
    if (l.cur_pos != -1) {
        QGraphicsLineItem* left_line = new QGraphicsLineItem(current_x + 30, current_y + 30,
                                                             l.cur_pos + 30, current_y + delta_y + 30);
        left_line->setPen(QPen(Qt::black));
        left_line->setZValue(-1);
        sceneSplay->addItem(left_line);
    }
    if (r.cur_pos != -1) {
        QGraphicsLineItem* right_line = new QGraphicsLineItem(current_x + 30, current_y + 30,
                                                             r.cur_pos + 30, current_y + delta_y + 30);
        right_line->setPen(QPen(Qt::black));
        right_line->setZValue(-1);
        sceneSplay->addItem(right_line);
    }

    return ret(current_x, std::max(current_x, std::max(l.max_right, r.max_right)), current_y);
}

void MainWindow::on_add_button_clicked()
{
    try {
        if (ui->num_add_edit->text().isEmpty()) throw -1;
        int input_number = ui->num_add_edit->text().toInt();
        ui->num_add_edit->clear();

        if (!avl_tree->insert(input_number)) throw -1.0;
        rb_tree->insert(input_number);
        treap->insert(input_number);
        splay_tree->insert(input_number);
        repaintScene();

    } catch (int err) {
        QMessageBox::warning(this,
                             "Error",
                             "Input is empty!\n"
                             "Please enter a valid number to insert.");

    } catch (double err) {
        QMessageBox::warning(this,
                             "Error",
                             "There is already such number in the tree!\n"
                             "Please enter a valid number to insert.");
    } catch (char err) {
        QMessageBox::warning(this,
                             "Error",
                             "Try lower number of nodes!\n"
                             "Please enter a valid number to insert.");
    }
}

void MainWindow::removeNode(int val)
{
    if (!remove_mode) return;
    avl_tree->remove(val);
    rb_tree->remove(val);
    treap->remove(val);
    splay_tree->remove(val);
    repaintScene();
}

void MainWindow::on_clear_button_clicked()
{
    avl_tree->clear();
    rb_tree->clear();
    treap->clear();
    splay_tree->clear();

    sceneAVL->clear();
    sceneRB->clear();
    sceneTreap->clear();
    sceneSplay->clear();

    QMessageBox::information(this, "Clear", "Cleared successfully!");
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1) {
        remove_mode = true;
        ui->graphicsView->setDragMode(QGraphicsView::NoDrag);
    } else {
        remove_mode = false;
        ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    }
}

int random(int a, int b)
{
    if (a > 0) return a + rand() % (b - a);
    else return a + rand() % (abs(a) + b);
}

void MainWindow::on_insertRandom_clicked()
{
    try {
        if (ui->nodesCount->text().isEmpty()) throw -1;
        if (ui->nodesMin->text().isEmpty()) throw -1;
        if (ui->nodesMax->text().isEmpty()) throw -1;

        int node_count = ui->nodesCount->text().toInt();
        if (node_count > 32000) throw '1';
        int min = ui->nodesMin->text().toInt();
        int max = ui->nodesMax->text().toInt();
        if (max > 32767) max = 32767;
        if (max - min <= node_count) throw -1.0;
        while (node_count) {
            int new_val = random(min, max);
            if (avl_tree->insert(new_val)) {
                rb_tree->insert(new_val);
                treap->insert(new_val);
                splay_tree->insert(new_val);
                --node_count;
            }
        }
        repaintScene();

    } catch (int err) {
        QMessageBox::warning(this,
                             "Error",
                             "Input is empty!\n"
                             "Please enter valid numbers.");

    } catch (double err) {
        QMessageBox::warning(this,
                             "Error",
                             "Try wider range!\n"
                             "Please enter valid numbers.");
    } catch (char err) {
        QMessageBox::warning(this,
                             "Error",
                             "Too many nodes to insert!\n"
                             "Please enter a valid number to insert.");
    }
}
