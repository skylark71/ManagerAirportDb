#include "buyticketdialog.h"
#include "ui_buyticketdialog.h"

#include <QMessageBox>

BuyTicketDialog::BuyTicketDialog(QWidget *parent, Flight *mCurFlight,
                                 UsersBook *mUsersbook, TicketsBook *mTicketsbook,
                                 QVector<QPair<int, int>> *ticketAndPassenger) :
    QDialog(parent),
    ui(new Ui::BuyTicketDialog)
{
    ui->setupUi(this);
    this->mCurFlight = mCurFlight;
    this->mUsersbook = mUsersbook;
    this->mTicketsbook = mTicketsbook;
    this->ticketAndPassenger = ticketAndPassenger;
}

BuyTicketDialog::~BuyTicketDialog()
{
    delete ui;
}

void BuyTicketDialog::on_rejectButton_clicked()
{
    QDialog::reject();
}

void BuyTicketDialog::on_acceptButton_clicked()
{
    User *user;
    QPair<int, int> pair;
    QString login = ui->loginLine->text();
    int loginCursorPos = ui->loginLine->cursorPosition();
    QString midname = ui->midnameLine->text();
    int midnameCursorPos = ui->midnameLine->cursorPosition();
    QString name = ui->nameLine->text();
    int nameCursorPos = ui->nameLine->cursorPosition();
    QString passportNumber = ui->passportNumberLine->text();
    int passportNumberCursorPos = ui->passportNumberLine->cursorPosition();
    QString passportSerial = ui->passportSerialLine->text();
    int passportSerialCursorPos = ui->passportSerialLine->cursorPosition();
    QString surname = ui->surnameLine->text();
    int surnameCursorPos = ui->surnameLine->cursorPosition();
    if (Validators::loginValidator.validate(login, loginCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Логин не соответствует требованиям\n(5-20 символов без пробела)");
        return;
    }
    else if (Validators::midnameValidator.validate(midname, midnameCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Отчество не соответствует требованиям\n(Либо начинается с заглавной буквы и содержит\nне менее одной прописной буквы,\nлибо отсутствует)");
        return;
    }
    else if (Validators::nameValidator.validate(name, nameCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Имя не соответствует требованиям\n(Начинается с заглавной буквы и содержит\nне менее одной прописной буквы)");
        return;
    }
    else if (Validators::passportNumberValidator.validate(passportNumber, passportNumberCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Номер паспорта не соответствует требованиям\n(6 цифер)");
        return;
    }
    else if (Validators::passportSerialValidator.validate(passportSerial, passportSerialCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Серия паспорта не соответствует требованиям\n(4 цифры)");
        return;
    }
    else if (Validators::surnameValidator.validate(surname, surnameCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Фамилия не соответствует требованиям\n(Начинается с заглавной буквы и содержит\nне менее одной прописной буквы)");
        return;
    }
    else if (ui->dateDepartureLine->date() < QDate::currentDate())
    {
        ui->errorLabel->setText("Дата вылета не соответствует требованиям\n(Должна быть больше или равна текущей дате)");
        return;
    }
    else if (ui->dateDepartureLine->date() == QDate::currentDate() && mCurFlight->getDepartureTime() <= QTime::currentTime().addSecs(1800))
    {
        ui->errorLabel->setText("Время вылета не соответствует требованиям\n(Должно быть больше текущего времени +30мин)");
        return;
    }
    else
    {
        for (int i = 0; i < (*mUsersbook).size(); ++i)
        {
            user = (*mUsersbook)[i];
            if (user->getLogin() == ui->loginLine->text())
            {
                if (dynamic_cast<Passenger*>(user))
                {
                    if (user->getPassportSerial() == ui->passportSerialLine->text())
                    {
                        if (user->getPassportNumber() == ui->passportNumberLine->text())
                        {
                            if (user->getSurname() == ui->surnameLine->text())
                            {
                                if (user->getName() == ui->nameLine->text())
                                {
                                    if (user->getMidname() == ui->midnameLine->text())
                                    {
                                        pair.second = i;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    QMessageBox::warning(this, windowTitle(), "Пользователь с таким логином зарегистрирован\nи его личные данные не совпадают с указанными");
                    return;
                }
                else
                {
                    QMessageBox::warning(this, windowTitle(), "Пользователь с таким логином зарегистрирован\nи не является пассажиром");
                    return;
                }
            }
            else if (i == (*mUsersbook).size() - 1)
            {
                Passenger *passenger = new Passenger;
                passenger->setLogin(ui->loginLine->text());
                passenger->setSurname(ui->surnameLine->text());
                passenger->setName(ui->nameLine->text());
                passenger->setMidname(ui->midnameLine->text());
                passenger->setPassportSerial(ui->passportSerialLine->text());
                passenger->setPassportNumber(ui->passportNumberLine->text());
                passenger->setPassword("12345");
                (*mUsersbook).insert(*passenger);
                QMessageBox::information(this, windowTitle(), QString("Пассажир успешно зарегистрирован\nПассажиром успешно приобретён билет\n\n") +
                                         "Для входа в систему пассажиру предоставлены следующие данные:\nЛогин: " + ui->loginLine->text() +
                                         "\nПароль: 12345");
                pair.second = i;
            }
        }
        Ticket *ticket = new Ticket();
        ticket->setDepartureDate(ui->dateDepartureLine->date());
        ticket->setPassengerLogin(user->getLogin());
        ticket->setNumber((*mTicketsbook).size() + 1);
        ticket->setFlightNumber(mCurFlight->getNumber());
        if (mCurFlight->getDepartureTime().addSecs(1800) >= mCurFlight->getArrivalTime())
        {
            ticket->setArrivalDate(ui->dateDepartureLine->date().addDays(1));
        }
        else
        {
            ticket->setArrivalDate(ui->dateDepartureLine->date());
        }
        pair.first = (*mTicketsbook).size();
        (*mTicketsbook).insert(*ticket);
        ticketAndPassenger->push_back(pair);
        mCurFlight->setNumberTickets(mCurFlight->getNumberTickets() + 1);
        QMessageBox::information(this, windowTitle(), "Пассажиром успешно приобретён билет");
        QDialog::accept();
    }
}
