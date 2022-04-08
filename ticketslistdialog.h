#ifndef TICKETSLISTDIALOG_H
#define TICKETSLISTDIALOG_H

#include "flightsbook.h"
#include "ticketsbook.h"

#include "ticketdialog.h"

#include <QDialog>

namespace Ui {
class TicketsListDialog;
}

class TicketsListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TicketsListDialog(QWidget *parent = nullptr, User *mCurUser = nullptr,
                               FlightsBook *mFlightsbook = nullptr, TicketsBook *mTicketsbook = nullptr);
    ~TicketsListDialog();

private slots:
    void on_ticketsTableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::TicketsListDialog *ui;
    User *mCurUser;
    FlightsBook *mFlightsbook;
    TicketsBook *mTicketsbook;
    TicketDialog *mTicketDialog;
    QVector<QPair<int, int>> tickets;
};

#endif // TICKETSLISTDIALOG_H
