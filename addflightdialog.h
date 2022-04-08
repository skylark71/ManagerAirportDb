#ifndef ADDFLIGHTDIALOG_H
#define ADDFLIGHTDIALOG_H

#include "flightsbook.h"
#include "validators.h"

#include <QDialog>

namespace Ui {
class AddFlightDialog;
}

class AddFlightDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddFlightDialog(QWidget *parent = nullptr, FlightsBook *mFlightsbook = nullptr, int currentRow = -1);
    ~AddFlightDialog();

private slots:
    void on_acceptButton_clicked();

    void on_rejectButton_clicked();

private:
    Ui::AddFlightDialog *ui;
    FlightsBook *mFlightsbook;
    int currentRow;
};

#endif // ADDFLIGHTDIALOG_H
