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
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
public slots:
    void handler(QPushButton* button);
    void handlerButton1();
    void handlerButton2();
    void handlerButton3();
    void handlerButton4();
    void handlerButton5();
    void handlerButton6();
    void handlerButton7();
    void handlerButton8();
    void handlerButton9();
    void handlerButton10();
    void handlerButton11();
    void handlerButton12();
    void handlerButton13();
    void handlerButton14();
    void handlerButton15();

private:
    static constexpr auto BUTTON_SIZE = 120;
    Ui::MainWindow* _form;
};

#endif // MAINWINDOW_H
