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
    QObject::connect(_form->pushButton_1, SIGNAL(clicked()), this, SLOT(handleButton1()));
    QObject::connect(_form->pushButton_2, SIGNAL(clicked()), this, SLOT(handleButton2()));
    QObject::connect(_form->pushButton_3, SIGNAL(clicked()), this, SLOT(handleButton3()));
    QObject::connect(_form->pushButton_4, SIGNAL(clicked()), this, SLOT(handleButton4()));
    QObject::connect(_form->pushButton_5, SIGNAL(clicked()), this, SLOT(handleButton5()));
    QObject::connect(_form->pushButton_6, SIGNAL(clicked()), this, SLOT(handleButton6()));
    QObject::connect(_form->pushButton_7, SIGNAL(clicked()), this, SLOT(handleButton7()));
    QObject::connect(_form->pushButton_8, SIGNAL(clicked()), this, SLOT(handleButton8()));
    QObject::connect(_form->pushButton_9, SIGNAL(clicked()), this, SLOT(handleButton9()));
    QObject::connect(_form->pushButton_10, SIGNAL(clicked()), this, SLOT(handleButton10()));
    QObject::connect(_form->pushButton_11, SIGNAL(clicked()), this, SLOT(handleButton11()));
    QObject::connect(_form->pushButton_12, SIGNAL(clicked()), this, SLOT(handleButton12()));
    QObject::connect(_form->pushButton_13, SIGNAL(clicked()), this, SLOT(handleButton13()));
    QObject::connect(_form->pushButton_14, SIGNAL(clicked()), this, SLOT(handleButton14()));
    QObject::connect(_form->pushButton_15, SIGNAL(clicked()), this, SLOT(handleButton15()));
}

MainWindow::~MainWindow()
{
    delete _form;
}

void MainWindow::handleAll(QPushButton* button)
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

void MainWindow::handleButton1()
{
    handleAll(_form->pushButton_1);
}

void MainWindow::handleButton2()
{
    handleAll(_form->pushButton_2);
}

void MainWindow::handleButton3()
{
    handleAll(_form->pushButton_3);
}

void MainWindow::handleButton4()
{
    handleAll(_form->pushButton_4);
}

void MainWindow::handleButton5()
{
    handleAll(_form->pushButton_5);
}

void MainWindow::handleButton6()
{
    handleAll(_form->pushButton_6);
}

void MainWindow::handleButton7()
{
    handleAll(_form->pushButton_7);
}

void MainWindow::handleButton8()
{
    handleAll(_form->pushButton_8);
}

void MainWindow::handleButton9()
{
    handleAll(_form->pushButton_9);
}

void MainWindow::handleButton10()
{
    handleAll(_form->pushButton_10);
}

void MainWindow::handleButton11()
{
    handleAll(_form->pushButton_11);
}

void MainWindow::handleButton12()
{
    handleAll(_form->pushButton_12);
}

void MainWindow::handleButton13()
{
    handleAll(_form->pushButton_13);
}

void MainWindow::handleButton14()
{
    handleAll(_form->pushButton_14);
}

void MainWindow::handleButton15()
{
    handleAll(_form->pushButton_15);
}
