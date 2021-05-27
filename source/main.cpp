#include <QApplication>
#include <cstdint>
#include <include/mainwindow.h>
#include <iostream>
#include <project_version.h>
#include <string>

std::string parseCommand(int argc, char* argv[])
{
    for (int i = 0; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-v" || arg == "--version") {
            return PROJECT_VERSION;
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
