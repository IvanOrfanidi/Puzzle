#include <include/mainwindow.h>
#include <include/ui_mainwindow.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , _form(new Ui::MainWindow)
{
    _form->setupUi(this);

    // Fixed form size
    this->setFixedSize(this->width(), this->height());

    // One button visible disable
    _form->pushButton_0->setVisible(false);

    // Binding buttons with signals
    QObject::connect(_form->pushButton_1, SIGNAL(clicked()), this, SLOT(handlerButton1()));
    QObject::connect(_form->pushButton_2, SIGNAL(clicked()), this, SLOT(handlerButton2()));
    QObject::connect(_form->pushButton_3, SIGNAL(clicked()), this, SLOT(handlerButton3()));
    QObject::connect(_form->pushButton_4, SIGNAL(clicked()), this, SLOT(handlerButton4()));
    QObject::connect(_form->pushButton_5, SIGNAL(clicked()), this, SLOT(handlerButton5()));
    QObject::connect(_form->pushButton_6, SIGNAL(clicked()), this, SLOT(handlerButton6()));
    QObject::connect(_form->pushButton_7, SIGNAL(clicked()), this, SLOT(handlerButton7()));
    QObject::connect(_form->pushButton_8, SIGNAL(clicked()), this, SLOT(handlerButton8()));
    QObject::connect(_form->pushButton_9, SIGNAL(clicked()), this, SLOT(handlerButton9()));
    QObject::connect(_form->pushButton_10, SIGNAL(clicked()), this, SLOT(handlerButton10()));
    QObject::connect(_form->pushButton_11, SIGNAL(clicked()), this, SLOT(handlerButton11()));
    QObject::connect(_form->pushButton_12, SIGNAL(clicked()), this, SLOT(handlerButton12()));
    QObject::connect(_form->pushButton_13, SIGNAL(clicked()), this, SLOT(handlerButton13()));
    QObject::connect(_form->pushButton_14, SIGNAL(clicked()), this, SLOT(handlerButton14()));
    QObject::connect(_form->pushButton_15, SIGNAL(clicked()), this, SLOT(handlerButton15()));
}

MainWindow::~MainWindow()
{
    delete _form;
}

void MainWindow::handler(QPushButton* button)
{
    const QRect target = _form->pushButton_0->geometry();
    const int top = target.top();
    const int left = target.left();

    const int topUp = button->geometry().top() + BUTTON_SIZE;
    const int leftUp = button->geometry().left() + BUTTON_SIZE;
    const int topDown = button->geometry().top() - BUTTON_SIZE;
    const int leftDown = button->geometry().left() - BUTTON_SIZE;

    bool isNeighbors = false;
    if ((top == topUp || top == topDown) && left == button->geometry().left()) {
        isNeighbors = true;
    } else if ((left == leftUp || left == leftDown) && top == button->geometry().top()) {
        isNeighbors = true;
    }

    // If buttons is neighbors, then swap them
    if (isNeighbors) {
        _form->pushButton_0->setGeometry(button->geometry());
        button->setGeometry(target);
    }
}

void MainWindow::handlerButton1()
{
    handler(_form->pushButton_1);
}

void MainWindow::handlerButton2()
{
    handler(_form->pushButton_2);
}

void MainWindow::handlerButton3()
{
    handler(_form->pushButton_3);
}

void MainWindow::handlerButton4()
{
    handler(_form->pushButton_4);
}

void MainWindow::handlerButton5()
{
    handler(_form->pushButton_5);
}

void MainWindow::handlerButton6()
{
    handler(_form->pushButton_6);
}

void MainWindow::handlerButton7()
{
    handler(_form->pushButton_7);
}

void MainWindow::handlerButton8()
{
    handler(_form->pushButton_8);
}

void MainWindow::handlerButton9()
{
    handler(_form->pushButton_9);
}

void MainWindow::handlerButton10()
{
    handler(_form->pushButton_10);
}

void MainWindow::handlerButton11()
{
    handler(_form->pushButton_11);
}

void MainWindow::handlerButton12()
{
    handler(_form->pushButton_12);
}

void MainWindow::handlerButton13()
{
    handler(_form->pushButton_13);
}

void MainWindow::handlerButton14()
{
    handler(_form->pushButton_14);
}

void MainWindow::handlerButton15()
{
    handler(_form->pushButton_15);
}
