#include "menucashierdialog.h"
#include "ui_menucashierdialog.h"

#include <QMessageBox>

MenuCashierDialog::MenuCashierDialog(QWidget *parent, Flight *mCurFlight,
                                     UsersBook *mUsersbook, TicketsBook *mTicketsbook) :
    QDialog(parent),
    ui(new Ui::MenuCashierDialog)
{
    ui->setupUi(this);
    this->mCurFlight = mCurFlight;
    this->mUsersbook = mUsersbook;
    this->mTicketsbook = mTicketsbook;
    ui->numberLine->setValue(mCurFlight->getNumber());
    // Конструирование таблицы
    for (int i = 0; i < (*mTicketsbook).size(); ++i)
    {
        if (mCurFlight->getNumber() == (*mTicketsbook)[i]->getFlightNumber())
        {
            int j = 0;
            while ((*mTicketsbook)[i]->getPassengerLogin() != (*mUsersbook)[j]->getLogin())
            {
                ++j;
            }
            User *user = (*mUsersbook)[j];
            QTableWidgetItem *item_surname = new QTableWidgetItem(user->getSurname());
            QTableWidgetItem *item_name = new QTableWidgetItem(user->getName());
            QTableWidgetItem *item_midname = new QTableWidgetItem(user->getMidname());
            QTableWidgetItem *item_passportSerial = new QTableWidgetItem(user->getPassportSerial());
            QTableWidgetItem *item_passportNumber = new QTableWidgetItem(user->getPassportNumber());
            int row = ui->passengersTableWidget->rowCount();
            ui->passengersTableWidget->insertRow(row);
            ui->passengersTableWidget->setItem(row, 0, item_surname);
            ui->passengersTableWidget->setItem(row, 1, item_name);
            ui->passengersTableWidget->setItem(row, 2, item_midname);
            ui->passengersTableWidget->setItem(row, 3, item_passportSerial);
            ui->passengersTableWidget->setItem(row, 4, item_passportNumber);
            ticketAndPassenger.push_back(QPair<int, int>(i, j));
        }
    }
    ui->passengersTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MenuCashierDialog::~MenuCashierDialog()
{
    delete ui;
}

void MenuCashierDialog::addPassengerToTable()
{
    int row = ui->passengersTableWidget->rowCount();
    User *user = (*mUsersbook)[ticketAndPassenger[row].second];
    QTableWidgetItem *item_surname = new QTableWidgetItem(user->getSurname());
    QTableWidgetItem *item_name = new QTableWidgetItem(user->getName());
    QTableWidgetItem *item_midname = new QTableWidgetItem(user->getMidname());
    QTableWidgetItem *item_passportSerial = new QTableWidgetItem(user->getPassportSerial());
    QTableWidgetItem *item_passportNumber = new QTableWidgetItem(user->getPassportNumber());
    ui->passengersTableWidget->insertRow(row);
    ui->passengersTableWidget->setItem(row, 0, item_surname);
    ui->passengersTableWidget->setItem(row, 1, item_name);
    ui->passengersTableWidget->setItem(row, 2, item_midname);
    ui->passengersTableWidget->setItem(row, 3, item_passportSerial);
    ui->passengersTableWidget->setItem(row, 4, item_passportNumber);
    ui->passengersTableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

void MenuCashierDialog::on_buyButton_clicked()
{
    if (mCurFlight->getNumberSeats() == mCurFlight->getNumberTickets())
    {
        QMessageBox::warning(this, windowTitle(), "Невозможно купить билет.\nВсе места заняты.");
        return;
    }
    mBuyTicketDualog = new BuyTicketDialog(this, mCurFlight, mUsersbook, mTicketsbook, &ticketAndPassenger);
    connect(mBuyTicketDualog, SIGNAL(accepted()), this, SLOT(addPassengerToTable()));
    mBuyTicketDualog->open();
}

void MenuCashierDialog::on_handOverButton_clicked()
{
    int currentRow = ui->passengersTableWidget->currentRow();
    if (currentRow != -1) {
        mCurFlight->setNumberTickets(mCurFlight->getNumberTickets() - 1);
        (*mTicketsbook).erase(ticketAndPassenger[currentRow].first);
        ui->passengersTableWidget->removeRow(currentRow);
    }
    else {
        QMessageBox::warning(this, windowTitle(), "Не выбран ни один пассажир");
    }
}
