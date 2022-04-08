#include "accountdialog.h"
#include "ui_accountdialog.h"

AccountDialog::AccountDialog(QWidget *parent, User *mCurUser, UsersBook *mUsersbook) :
    QDialog(parent),
    ui(new Ui::AccountDialog)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    ui->loginLine->setText(mCurUser->getLogin());
    ui->midnameLine->setText(mCurUser->getMidname());
    ui->nameLine->setText(mCurUser->getName());
    ui->passportNumberLine->setText(mCurUser->getPassportNumber());
    ui->passportSerialLine->setText(mCurUser->getPassportSerial());
    ui->surnameLine->setText(mCurUser->getSurname());
    ui->passwordLine->setText(mCurUser->getPassword());
    if (dynamic_cast<Admin*>(mCurUser) != nullptr)
    {
        ui->rootLine->setText("Администратор");
    }
    else if (dynamic_cast<Cashier*>(mCurUser) != nullptr)
    {
        ui->rootLine->setText("Кассир");
    }
    else
    {
        ui->rootLine->setText("Пассажир");
    }
}

AccountDialog::~AccountDialog()
{
    delete ui;
}

void AccountDialog::on_OKButton_clicked()
{
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
    else
    {
        for (int i = 0; i < mUsersbook->size(); ++i)
        {
            if (ui->loginLine->text() == (*mUsersbook)[i]->getLogin() && mCurUser != (*mUsersbook)[i])
            {
                ui->errorLabel->setText("Пользователь с таким логином уже существует");
                return;
            }
        }
        mCurUser->setLogin(ui->loginLine->text());
        mCurUser->setMidname(ui->midnameLine->text());
        mCurUser->setName(ui->nameLine->text());
        mCurUser->setPassportNumber(ui->passportNumberLine->text());
        mCurUser->setPassportSerial(ui->passportSerialLine->text());
        mCurUser->setPassword(ui->passwordLine->text());
        mCurUser->setSurname(ui->surnameLine->text());
        QDialog::accept();
    }
}
