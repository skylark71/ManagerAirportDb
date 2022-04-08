#ifndef MENUDIALOG_H
#define MENUDIALOG_H

#include "flightsbook.h"
#include "ticketsbook.h"
#include "usersbook.h"

#include "accountdialog.h"
#include "menuadmindialog.h"
#include "ticketslistdialog.h"

#include <QDialog>

namespace Ui {
class MenuDialog;
}

class MenuDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuDialog(QWidget *parent = nullptr, User *mCurUser = nullptr, UsersBook *mUsersbook = nullptr,
                        FlightsBook *mFlightsbook = nullptr, TicketsBook *mTicketsbook = nullptr);
    ~MenuDialog();

private slots:
    void on_accountButton_clicked();

    void on_ticketsButton_clicked();

    void on_adminButton_clicked();

    void slotShow();

private:
    Ui::MenuDialog *ui;
    UsersBook *mUsersbook;
    FlightsBook *mFlightsbook;
    TicketsBook *mTicketsbook;
    User *mCurUser;
    AccountDialog *mAccountDialog;
    MenuAdminDialog *mMenuAdminDialog;
    TicketsListDialog *mTicketsListDialog;
};

#endif // MENUDIALOG_H
