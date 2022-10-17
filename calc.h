#ifndef DZ37_CALC_H
#define DZ37_CALC_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class CallerMainWindow : public QMainWindow {
Q_OBJECT

public:

    QLineEdit* lineEdit = nullptr;
    QLineEdit* lineEdit_2 = nullptr;
    QLineEdit* lineEdit_3 = nullptr;
    QLineEdit* lineEdit_action = nullptr;
    QLineEdit* lineActual = nullptr;

    bool minus_f = false, comma_f= false, action_f = false, result_f = false;

    CallerMainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}


public slots:
    void add0() { if (!result_f)lineActual ->setText(lineActual->text() + "0");};
    void add1() { if (!result_f)lineActual ->setText(lineActual->text() + "1");};
    void add2() { if (!result_f)lineActual ->setText(lineActual->text() + "2");};
    void add3() { if (!result_f)lineActual ->setText(lineActual->text() + "3");};
    void add4() { if (!result_f)lineActual ->setText(lineActual->text() + "4");};
    void add5() { if (!result_f)lineActual ->setText(lineActual->text() + "5");};
    void add6() { if (!result_f)lineActual ->setText(lineActual->text() + "6");};
    void add7() { if (!result_f)lineActual ->setText(lineActual->text() + "7");};
    void add8() { if (!result_f)lineActual ->setText(lineActual->text() + "8");};
    void add9() { if (!result_f)lineActual ->setText(lineActual->text() + "9");};
    void addpm() {
        if (!result_f)
            if (!minus_f)
            {
                lineActual ->setText("-" + lineActual->text());
                minus_f = true;
            }
            else
            {
                lineActual ->setText(lineActual->text().remove(0,1));
                minus_f = false;
            }
    };
    void addcomma() {
        if (!comma_f && !result_f)
        {
            lineActual ->setText(lineActual->text() + ".");
            comma_f = true;
        }
    };
    void plus() {
        if (!action_f && !result_f) {
            lineEdit_action->setText("+");
            action_f = true;
            minus_f = false;
            comma_f = false;
            lineActual = lineEdit_2;
        }
    };
    void minus() {
        if (!action_f && !result_f) {
            lineEdit_action->setText("-");
            action_f = true;
            minus_f = false;
            comma_f = false;
            lineActual = lineEdit_2;
        }
    };
    void multiplay() {
        if (!action_f && !result_f) {
            lineEdit_action->setText("*");
            action_f = true;
            minus_f = false;
            comma_f = false;
            lineActual = lineEdit_2;
        }
    };
    void divide() {
        if (!action_f && !result_f) {
            lineEdit_action->setText("/");
            action_f = true;
            minus_f = false;
            comma_f = false;
            lineActual = lineEdit_2;
        }
    };
    void result() {
        result_f = true;
        double a = QString(lineEdit->text()).toDouble();
        double b = QString(lineEdit_2->text()).toDouble();
        if (lineEdit_action->text() == "+")
        {
            lineEdit_3->setText(QString::number(a+b));
        }
        if (lineEdit_action->text() == "-")
        {
            lineEdit_3->setText(QString::number(a-b));
        }
        if (lineEdit_action->text() == "*")
        {
            lineEdit_3->setText(QString::number(a*b));
        }
        if (lineEdit_action->text() == "/")
        {
            if (b==0) lineEdit_3 ->setText("ERROR");
            else
                lineEdit_3->setText(QString::number(a/b));
        }
    };
    void cancel() {
        action_f = false;
        minus_f = false;
        comma_f = false;
        result_f = false;
        lineActual = lineEdit;
        lineEdit->setText("");
        lineEdit_2->setText("");
        lineEdit_3->setText("");
        lineEdit_action->setText("");
    };
};

#endif //DZ37_CALC_H
