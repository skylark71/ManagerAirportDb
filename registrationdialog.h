#ifndef REGISTRATIONDIALOG_H
#define REGISTRATIONDIALOG_H

#include "usersbook.h"
#include "validators.h"
#include <QDialog>

namespace Ui {
class RegistrationDialog;
}

class RegistrationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationDialog(QWidget *parent = nullptr, UsersBook *mUsersbook = nullptr);
    ~RegistrationDialog();

private slots:
    void on_registrationButton_clicked();

    void on_authorisationButton_clicked();

private:
    Ui::RegistrationDialog *ui;
    UsersBook *mUsersbook;
};

#endif // REGISTRATIONDIALOG_H
