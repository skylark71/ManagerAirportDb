#ifndef ACCOUNTDIALOG_H
#define ACCOUNTDIALOG_H
#include "usersbook.h"
#include "validators.h"

#include <QDialog>

namespace Ui {
class AccountDialog;
}

class AccountDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AccountDialog(QWidget *parent = nullptr, User *mCurUser = nullptr, UsersBook *mUsersbook = nullptr);
    ~AccountDialog();

private slots:
    void on_OKButton_clicked();

private:
    Ui::AccountDialog *ui;
    User *mCurUser;
    UsersBook *mUsersbook;
};

#endif // ACCOUNTDIALOG_H
