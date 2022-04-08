#include "registrationdialog.h"
#include "ui_registrationdialog.h"

#include "menuadmindialog.h"

#include <QMessageBox>

RegistrationDialog::RegistrationDialog(QWidget *parent, UsersBook *mUsersbook) :
    QDialog(parent),
    ui(new Ui::RegistrationDialog)
{
    ui->setupUi(this);
    this->mUsersbook = mUsersbook;
    if (static_cast<MenuAdminDialog*>(parent) != nullptr)
    {
        ui->authorisationButton->hide();
    }

    QSqlDatabase db; //создаем объект нашей базы
    db = QSqlDatabase::addDatabase("QSQLITE"); //добавляем базу конкретного типа
    db.setDatabaseName("./airport.db"); //QString path - путь к базе
}

RegistrationDialog::~RegistrationDialog()
{
    delete ui;
}

void RegistrationDialog::on_registrationButton_clicked()
{
    QString login = ui->loginLine->text();
    int loginCursorPos = ui->loginLine->cursorPosition();
    QString password = ui->passwordLine->text();
    int passwordCursorPos = ui->passwordLine->cursorPosition();
    if (Validators::loginValidator.validate(login, loginCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Логин не соответствует требованиям\n(5-20 символов без пробела)");
        return;
    }
    else if (Validators::passwordValidator.validate(password, passwordCursorPos) != QValidator::Acceptable)
    {
        ui->errorLabel->setText("Пароль не соответствует требованиям\n(5-20 символов без пробела)");
        return;
    }
    else if (ui->passwordLine->text() != ui->repeatPasswordLine->text())
    {
        ui->errorLabel->setText(tr("Пароль не совпадает с повтором пароля"));
        return;
    }
    else
    {
        for (int i = 0; i < (*mUsersbook).size(); ++i)
        {
            if ((*mUsersbook)[i]->getLogin() == ui->loginLine->text())
            {
                ui->errorLabel->setText(tr("Пользователь с такими данными уже зарегистрирован"));
                return;
            }
        }
        User* user = new Passenger();
        user->setLogin(ui->loginLine->text());
        user->setPassword(ui->passwordLine->text());
        (*mUsersbook).insert(*user);
        QMessageBox::warning(this, windowTitle(), "Пользователь успешно зарегистрирован");
        QDialog::accept();
    }
}

void RegistrationDialog::on_authorisationButton_clicked()
{
    QDialog::accept();
}
