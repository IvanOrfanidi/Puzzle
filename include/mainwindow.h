#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
public slots:
    void handleAll(QPushButton* button);
    void handleButton1();
    void handleButton2();
    void handleButton3();
    void handleButton4();
    void handleButton5();
    void handleButton6();
    void handleButton7();
    void handleButton8();
    void handleButton9();
    void handleButton10();
    void handleButton11();
    void handleButton12();
    void handleButton13();
    void handleButton14();
    void handleButton15();

private:
    static constexpr auto BUTTON_SIZE = 120;
    Ui::MainWindow* _form;
};

#endif // MAINWINDOW_H
