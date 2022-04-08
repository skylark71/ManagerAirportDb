#include "menuadmindialog.h"
#include "ui_menuadmindialog.h"

#include <QMessageBox>

MenuAdminDialog::MenuAdminDialog(QWidget *parent, User *mCurUser, UsersBook *mUsersbook) :
    QDialog(parent),
    ui(new Ui::MenuAdminDialog)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    // Конструирование таблицы
    for (int i = 0; i < (*mUsersbook).size(); ++i)
    {
        User *user = (*mUsersbook)[i];
        QTableWidgetItem *item_login = new QTableWidgetItem(user->getLogin());
        QTableWidgetItem *item_root;
        if (dynamic_cast<Admin*>(user) != nullptr)
        {
            item_root = new QTableWidgetItem("Администратор");
        }
        else if (dynamic_cast<Cashier*>(user) != nullptr)
        {
            item_root = new QTableWidgetItem("Кассир");
        }
        else
        {
            item_root = new QTableWidgetItem("Пассажир");
        }
        ui->usersTableWidget->insertRow(i);
        ui->usersTableWidget->setItem(i, 0, item_login);
        ui->usersTableWidget->setItem(i, 1, item_root);
    }
    ui->usersTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MenuAdminDialog::~MenuAdminDialog()
{
    delete ui;
}

void MenuAdminDialog::on_addButton_clicked()
{
    mRegistrationDialog = new RegistrationDialog(this, mUsersbook);
    connect(mRegistrationDialog, SIGNAL(accepted()), this, SLOT(addUserToTable()));
    mRegistrationDialog->open();
}

void MenuAdminDialog::on_delButton_clicked()
{
    int currentRow = ui->usersTableWidget->currentRow();
    if (currentRow != -1 && (ui->usersTableWidget->item(currentRow, 1))->text() != "Администратор") {
        (*mUsersbook).erase(currentRow);
        ui->usersTableWidget->removeRow(currentRow);
    }
    else {
        QMessageBox::warning(this, windowTitle(), "Не выбран ни один пользователь или выбран администратор");
    }
}

void MenuAdminDialog::on_riseButton_clicked()
{
    int currentRow = ui->usersTableWidget->currentRow();
    User *user = (*mUsersbook)[currentRow];
    if (currentRow != -1) {
        if (dynamic_cast<Admin*>(user) != nullptr)
        {
            QMessageBox::warning(this, windowTitle(), "Невозможно повысить пользователя");
        }
        else if (dynamic_cast<Cashier*>(user))
        {
            Admin *admin = new Admin;
            admin->setDateLogin(user->getDateLogin());
            admin->setLogin(user->getLogin());
            admin->setMidname(user->getMidname());
            admin->setName(user->getName());
            admin->setPassportNumber(user->getPassportNumber());
            admin->setPassportSerial(user->getPassportSerial());
            admin->setPassword(user->getPassword());
            admin->setSurname(user->getSurname());
            (*mUsersbook).edit(currentRow, *admin);
            QTableWidgetItem *item_root = new QTableWidgetItem("Администратор");
            ui->usersTableWidget->setItem(currentRow, 1, item_root);

        }
        else if (dynamic_cast<Passenger*>(user))
        {
            Cashier *cashier = new Cashier;
            cashier->setDateLogin(user->getDateLogin());
            cashier->setLogin(user->getLogin());
            cashier->setMidname(user->getMidname());
            cashier->setName(user->getName());
            cashier->setPassportNumber(user->getPassportNumber());
            cashier->setPassportSerial(user->getPassportSerial());
            cashier->setPassword(user->getPassword());
            cashier->setSurname(user->getSurname());
            (*mUsersbook).edit(currentRow, *cashier);
            QTableWidgetItem *item_root = new QTableWidgetItem("Кассир");
            ui->usersTableWidget->setItem(currentRow, 1, item_root);
        }
    }
    else {
        QMessageBox::warning(this, windowTitle(), "Не выбран ни один пользователь");
    }
}

void MenuAdminDialog::addUserToTable()
{
    int row = ui->usersTableWidget->rowCount();
    User *user = (*mUsersbook)[row];
    QTableWidgetItem *item_login = new QTableWidgetItem(user->getLogin());
    QTableWidgetItem *item_root = new QTableWidgetItem("Пассажир");
    ui->usersTableWidget->insertRow(row);
    ui->usersTableWidget->setItem(row, 0, item_login);
    ui->usersTableWidget->setItem(row, 1, item_root);
    ui->usersTableWidget->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
}

void MenuAdminDialog::on_lowerButton_clicked()
{
    int currentRow = ui->usersTableWidget->currentRow();
    User *user = (*mUsersbook)[currentRow];
    if (currentRow != -1) {
        if (dynamic_cast<Passenger*>(user) != nullptr)
        {
            QMessageBox::warning(this, windowTitle(), "Невозможно понизить пользователя");
        }
        else if (dynamic_cast<Cashier*>(user))
        {
            Passenger *passenger = new Passenger;
            passenger->setDateLogin(user->getDateLogin());
            passenger->setLogin(user->getLogin());
            passenger->setMidname(user->getMidname());
            passenger->setName(user->getName());
            passenger->setPassportNumber(user->getPassportNumber());
            passenger->setPassportSerial(user->getPassportSerial());
            passenger->setPassword(user->getPassword());
            passenger->setSurname(user->getSurname());
            (*mUsersbook).edit(currentRow, *passenger);
            QTableWidgetItem *item_root = new QTableWidgetItem("Пассажир");
            ui->usersTableWidget->setItem(currentRow, 1, item_root);
        }
        else if (dynamic_cast<Admin*>(user))
        {
            Cashier *cashier = new Cashier;
            cashier->setDateLogin(user->getDateLogin());
            cashier->setLogin(user->getLogin());
            cashier->setMidname(user->getMidname());
            cashier->setName(user->getName());
            cashier->setPassportNumber(user->getPassportNumber());
            cashier->setPassportSerial(user->getPassportSerial());
            cashier->setPassword(user->getPassword());
            cashier->setSurname(user->getSurname());
            (*mUsersbook).edit(currentRow, *cashier);
            QTableWidgetItem *item_root = new QTableWidgetItem("Кассир");
            ui->usersTableWidget->setItem(currentRow, 1, item_root);
        }
    }
    else {
        QMessageBox::warning(this, windowTitle(), "Не выбран ни один пользователь");
    }
}
