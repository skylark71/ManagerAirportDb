#include "authorisationdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyleSheet("QDialog {background-color: #f9ed69;}"
                        "QLineEdit {border: 2px black; border-radius: 3px; background-color: #f08a5d; color: black}"
                        "QSpinBox {border: 2px black; border-radius: 3px; background-color: #f08a5d; color: black}"
                        "QDateEdit {border: 2px black; border-radius: 3px; background-color: #f08a5d; color: black}"
                        "QTimeEdit {border: 2px black; border-radius: 3px; background-color: #f08a5d; color: black}"
                        "QPushButton {border: 2px black; border-radius: 5px; background-color: #b83b5e; padding: 5px; color: cyan}"
                        "QPushButton:pressed {background-color: #78273e}"
                        "QTableWidget {background-color: #f08a5d; alternate-background-color: #e07a5d}"
                        "QHeaderView:section {background-color: #6a2c70; color: cyan}");
    AuthorisationDialog window;
    window.show();
    return a.exec();
}
