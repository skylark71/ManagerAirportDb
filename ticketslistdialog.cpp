#include "ticketslistdialog.h"
#include "ui_ticketslistdialog.h"

TicketsListDialog::TicketsListDialog(QWidget *parent, User *mCurUser,
                                     FlightsBook *mFlightbook, TicketsBook *mTicketsbook) :
    QDialog(parent),
    ui(new Ui::TicketsListDialog)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mFlightsbook = mFlightbook;
    this->mTicketsbook = mTicketsbook;
    // Конструирование таблицы
    for (int i = 0; i < (*mTicketsbook).size(); ++i)
    {
        if (mCurUser->getLogin() == (*mTicketsbook)[i]->getPassengerLogin())
        {
            Ticket ticket = *(*mTicketsbook)[i];
            QTableWidgetItem *item_numberFlight = new QTableWidgetItem(QString::number(ticket.getFlightNumber()));
            int j = 0;
            while (ticket.getFlightNumber() != (*mFlightbook)[j]->getNumber())
            {
                ++j;
            }
            Flight flight = *(*mFlightsbook)[j];
            QTableWidgetItem *item_departureDate = new QTableWidgetItem(ticket.getDepartureDate().toString("dd.MM.yyyy"));
            QTableWidgetItem *item_arrivalPoint = new QTableWidgetItem(flight.getArrivalPoint());
            ui->ticketsTableWidget->insertRow(i);
            ui->ticketsTableWidget->setItem(i, 0, item_numberFlight);
            ui->ticketsTableWidget->setItem(i, 1, item_departureDate);
            ui->ticketsTableWidget->setItem(i, 2, item_arrivalPoint);
            tickets.push_back(QPair<int, int>(i, j));
        }
    }
    ui->ticketsTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

TicketsListDialog::~TicketsListDialog()
{
    delete ui;
}

void TicketsListDialog::on_ticketsTableWidget_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    Ticket *ticket = (*mTicketsbook)[tickets[row].first];
    Flight *flight = (*mFlightsbook)[tickets[row].second];
    mTicketDialog = new TicketDialog(this, ticket, flight, mCurUser);
    mTicketDialog->open();
}
