#ifndef TICKETDIALOG_H
#define TICKETDIALOG_H

#include "flight.h"
#include "ticket.h"
#include "user.h"

#include <QDialog>

namespace Ui {
class TicketDialog;
}

class TicketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TicketDialog(QWidget *parent = nullptr, Ticket *ticket = nullptr,
                          Flight *flight = nullptr, User *mCurUser = nullptr);
    ~TicketDialog();

private:
    Ui::TicketDialog *ui;
};

#endif // TICKETDIALOG_H
