#include "ticketdialog.h"
#include "ui_ticketdialog.h"

TicketDialog::TicketDialog(QWidget *parent, Ticket *ticket,
                           Flight *flight, User *mCurUser) :
    QDialog(parent),
    ui(new Ui::TicketDialog)
{
    ui->setupUi(this);
    ui->titleLine->setValue(ticket->getNumber());
    ui->arrivalPointLine->setText(flight->getArrivalPoint());
    ui->dateAndTimeArrivalLine->setDate(ticket->getArrivalDate());
    ui->dateAndTimeArrivalLine->setTime(flight->getArrivalTime());
    ui->dateAndTimeDepartureLine->setDate(ticket->getDepartureDate());
    ui->dateAndTimeDepartureLine->setTime(flight->getDepartureTime());
    ui->departurePointLine->setText(flight->getDeparturePoint());
    ui->midnameLine->setText(mCurUser->getMidname());
    ui->nameLine->setText(mCurUser->getName());
    ui->numberLine->setValue(flight->getNumber());
    ui->passportNumberLine->setText(mCurUser->getPassportNumber());
    ui->passportSerialLine->setText(mCurUser->getPassportSerial());
    ui->surnameLine->setText(mCurUser->getSurname());
}

TicketDialog::~TicketDialog()
{
    delete ui;
}
