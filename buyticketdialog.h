#ifndef BUYTICKETDIALOG_H
#define BUYTICKETDIALOG_H

#include "flight.h"
#include "usersbook.h"
#include "ticketsbook.h"
#include "validators.h"

#include <QDialog>

namespace Ui {
class BuyTicketDialog;
}

class BuyTicketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BuyTicketDialog(QWidget *parent = nullptr, Flight *mCurFlight = nullptr,
                             UsersBook *mUsersbook = nullptr, TicketsBook *mTicketsbook = nullptr,
                             QVector<QPair<int, int>> *ticketAndPassenger = nullptr);
    ~BuyTicketDialog();

private slots:
    void on_rejectButton_clicked();

    void on_acceptButton_clicked();

private:
    Ui::BuyTicketDialog *ui;
    Flight *mCurFlight;
    UsersBook *mUsersbook;
    TicketsBook *mTicketsbook;
    QVector<QPair<int, int>> *ticketAndPassenger;
};

#endif // BUYTICKETDIALOG_H
