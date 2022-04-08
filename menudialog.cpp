#include "menudialog.h"
#include "ui_menudialog.h"

MenuDialog::MenuDialog(QWidget *parent, User *mCurUser, UsersBook *mUsersbook,
                       FlightsBook *mFlightsbook, TicketsBook *mTicketsbook) :
    QDialog(parent),
    ui(new Ui::MenuDialog)
{
    ui->setupUi(this);
    this->mCurUser = mCurUser;
    this->mUsersbook = mUsersbook;
    this->mFlightsbook = mFlightsbook;
    this->mTicketsbook = mTicketsbook;
    if (dynamic_cast<Admin*>(mCurUser) == nullptr)
    {
        ui->adminButton->hide();
    }
    if (dynamic_cast<Passenger*>(mCurUser) == nullptr)
    {
        ui->ticketsButton->hide();
    }
}

MenuDialog::~MenuDialog()
{
    delete ui;
}

void MenuDialog::on_accountButton_clicked()
{
    mAccountDialog = new AccountDialog(this, mCurUser, mUsersbook);
    this->hide();
    connect(mAccountDialog, SIGNAL(accepted()), this, SLOT(slotShow()));
    connect(mAccountDialog, SIGNAL(rejected()), this, SLOT(slotShow()));
    mAccountDialog->open();
}

void MenuDialog::on_ticketsButton_clicked()
{
    mTicketsListDialog = new TicketsListDialog(this, mCurUser, mFlightsbook, mTicketsbook);
    this->hide();
    connect(mTicketsListDialog, SIGNAL(rejected()), this, SLOT(slotShow()));
    mTicketsListDialog->open();
}

void MenuDialog::on_adminButton_clicked()
{
    mMenuAdminDialog = new MenuAdminDialog(this, mCurUser, mUsersbook);
    this->hide();
    connect(mMenuAdminDialog, SIGNAL(rejected()), this, SLOT(slotShow()));
    mMenuAdminDialog->open();
}

void MenuDialog::slotShow()
{
    this->show();
}
