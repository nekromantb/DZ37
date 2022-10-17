#include <QApplication>
#include <QPushButton>
#include "./ui_calc.h"
#include "calc.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CallerMainWindow window(nullptr);
    Ui::MainWindow calc;
    calc.setupUi(&window);
    window.lineEdit = calc.lineEdit;
    window.lineEdit_2 = calc.lineEdit_2;
    window.lineEdit_3 = calc.lineEdit_3;
    window.lineEdit_action = calc.lineEdit_action;
    window.lineActual = calc.lineEdit;
    window.resize(640, 480);
    window.show();
    return QApplication::exec();
}
