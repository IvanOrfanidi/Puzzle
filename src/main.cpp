#include "../include/mainwindow.h"
#include <QApplication>
#include <cstdint>
#include <iostream>
#include <string>

const std::string VERSION = "1.0.1";

std::string parseCommand(int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-v" || arg == "--version") {
            return VERSION;
        }
    }
    return "";
}

int main(int argc, char* argv[])
{
    const auto msgOut = parseCommand(argc, argv);
    if (msgOut.length()) {
        std::cout << msgOut << std::endl;
        return EXIT_SUCCESS;
    }

    QApplication appl(argc, argv);
    MainWindow windows;
    windows.show();
    return appl.exec();
}
