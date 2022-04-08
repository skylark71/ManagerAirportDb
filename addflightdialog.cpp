#include "addflightdialog.h"
#include "ui_addflightdialog.h"

#include <QMessageBox>

AddFlightDialog::AddFlightDialog(QWidget *parent, FlightsBook *mFlightsbook, int currentRow) :
    QDialog(parent),
    ui(new Ui::AddFlightDialog)
{
    ui->setupUi(this);
    this->mFlightsbook = mFlightsbook;
    this->currentRow = currentRow;
    if (currentRow != -1)
    {
        Flight* flight = (*mFlightsbook)[currentRow];
        ui->numberLine->setValue(flight->getNumber());
        ui->departurePointLine->setText(flight->getDeparturePoint());
        ui->arrivalPointLine->setText(flight->getArrivalPoint());
        ui->departureTimeLine->setTime(flight->getDepartureTime());
        ui->arrivalTimeLine->setTime(flight->getArrivalTime());
        ui->markLine->setText(flight->getMark());
        ui->numbersSeatsLine->setValue(flight->getNumberSeats());
    }
}

AddFlightDialog::~AddFlightDialog()
{
    delete ui;
}

void AddFlightDialog::on_acceptButton_clicked()
{
    QString departurePoint = ui->departurePointLine->text();
    int departurePointCursorPos = ui->departurePointLine->cursorPosition();
    QString arrivalPoint = ui->arrivalPointLine->text();
    int arrivalPointCursorPos = ui->arrivalPointLine->cursorPosition();
    QString mark = ui->markLine->text();
    int markCursorPos = ui->markLine->cursorPosition();
    if (Validators::departurePointValidator.validate(departurePoint, departurePointCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Пункт отправления не соответствует требованиям\n(г. Название или п. Название или\nc. Название или д. Название)");
        return;
    }
    else if (Validators::arrivalPointValidator.validate(arrivalPoint, arrivalPointCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Пункт назначения не соответствует требованиям\n(г. Название или п. Название или\nc. Название или д. Название)");
        return;
    }
    else if (Validators::markValidator.validate(mark, markCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Марка не соответствует требованиям");
        return;
    }
    else
    {
        for (int i = 0; i < (*mFlightsbook).size(); ++i)
        {
            if ((*mFlightsbook)[i]->getNumber() == ui->numberLine->value() && i != currentRow)
            {
                QMessageBox::warning(this, windowTitle(), "Рейс с таким номером уже существует");
                return;
            }
        }
        Flight* flight = new Flight();
        flight->setNumber(ui->numberLine->value());
        flight->setDeparturePoint(ui->departurePointLine->text());
        flight->setArrivalPoint(ui->arrivalPointLine->text());
        flight->setDepartureTime(ui->departureTimeLine->time());
        flight->setArrivalTime(ui->arrivalTimeLine->time());
        flight->setMark(ui->markLine->text());
        flight->setNumberSeats(ui->numbersSeatsLine->value());
        if (currentRow == -1)
        {
            (*mFlightsbook).insert(*flight);
            QMessageBox::warning(this, windowTitle(), "Рейс успешно добавлен");
        }
        else
        {
            (*mFlightsbook).edit(currentRow, *flight);
            QMessageBox::warning(this, windowTitle(), "Рейс успешно изменён");
        }
        QDialog::accept();
    }

}

void AddFlightDialog::on_rejectButton_clicked()
{
    QDialog::reject();
}
