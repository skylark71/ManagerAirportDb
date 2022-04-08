#ifndef MENUADMINDIALOG_H
#define MENUADMINDIALOG_H

#include "usersbook.h"

#include "registrationdialog.h"

#include <QDialog>

namespace Ui {
class MenuAdminDialog;
}

class MenuAdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuAdminDialog(QWidget *parent = nullptr, User *mCurUser = nullptr, UsersBook *mUsersbook = nullptr);
    ~MenuAdminDialog();

private slots:
    void on_addButton_clicked();

    void on_delButton_clicked();

    void on_riseButton_clicked();

    void addUserToTable();

    void on_lowerButton_clicked();

private:
    Ui::MenuAdminDialog *ui;
    User *mCurUser;
    UsersBook *mUsersbook;
    RegistrationDialog *mRegistrationDialog;
};

#endif // MENUADMINDIALOG_H
