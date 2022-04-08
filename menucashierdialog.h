#ifndef MENUCASHIERDIALOG_H
#define MENUCASHIERDIALOG_H

#include "flight.h"
#include "usersbook.h"
#include "ticketsbook.h"
#include "buyticketdialog.h"

#include <QDialog>

namespace Ui {
class MenuCashierDialog;
}

class MenuCashierDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MenuCashierDialog(QWidget *parent = nullptr, Flight *mCurFlight = nullptr,
                               UsersBook *mUsersbook = nullptr, TicketsBook *mTicketsbook = nullptr);
    ~MenuCashierDialog();

private slots:
    void on_buyButton_clicked();

    void addPassengerToTable();

    void on_handOverButton_clicked();

private:
    Ui::MenuCashierDialog *ui;
    Flight *mCurFlight;
    UsersBook *mUsersbook;
    TicketsBook *mTicketsbook;
    BuyTicketDialog *mBuyTicketDualog;
    QVector<QPair<int, int>> ticketAndPassenger;
};

#endif // MENUCASHIERDIALOG_H
