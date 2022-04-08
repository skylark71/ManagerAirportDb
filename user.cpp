#include "user.h"

User::User()
{
    db = QSqlDatabase::addDatabase("QSQLITE"); //добавляем базу конкретного типа
    db.setHostName("localhost"); //в общем случае, может быть локалхостом
    db.setDatabaseName("./airport.db"); //QString path - путь к базе
}

User::~User()
{
}

const QString &User::getLogin() const
{
    return mLogin;
}

void User::setLogin(const QString &login)
{
    mLogin = login;
}

const QString &User::getPassword() const
{
    return mPassword;
}

void User::setPassword(const QString &password)
{
    mPassword = password;
}

const QString &User::getSurname() const
{
    return mSurname;
}

void User::setSurname(const QString &surname)
{
    mSurname = surname;
}

const QString &User::getName() const
{
    return mName;
}

void User::setName(const QString &name)
{
    mName = name;
}

const QString &User::getMidname() const
{
    return mMidname;
}

void User::setMidname(const QString &midname)
{
    mMidname = midname;
}

const QString &User::getPassportSerial() const
{
    return mPassportSerial;
}

void User::setPassportSerial(const QString &passportSerial)
{
    mPassportSerial = passportSerial;
}

const QString &User::getPassportNumber() const
{
    return mPassportNumber;
}

void User::setPassportNumber(const QString &passportNumber)
{
    mPassportNumber = passportNumber;
}

const QDate &User::getDateLogin() const
{
    return mDateLogin;
}

void User::setDateLogin(const QDate &dateLogin)
{
    mDateLogin = dateLogin;
}

void User::setDB(const QString &login, const QString &password, const QString &surname, const QString &name, const QString &midname, const QString &passportSerial, const QString &passportNumber)
{
    /*
    CREATE TABLE "users" (
    "id"	INTEGER PRIMARY KEY AUTOINCREMENT,
    "login"	TEXT NOT NULL,
    "password"	TEXT NOT NULL,
    "surname"	TEXT,
    "name"	TEXT,
    "midname"	TEXT,
    "passportserial"	INTEGER,
    "passportnumber"	INTEGER
    */

    mLogin = login;
    mPassword = password;
    mSurname = surname;
    mName = name;
    mMidname = midname;
    mPassportSerial = passportSerial;
    mPassportNumber = passportNumber;

    QSqlQuery sqlQuery(db);
    sqlQuery.prepare("INSERT INTO users (login, password, surname, name, midname, passportserial, passportnumber) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?);");
    sqlQuery.addBindValue(mLogin);
    sqlQuery.addBindValue(mPassword);
    sqlQuery.addBindValue(mSurname);
    sqlQuery.addBindValue(mName);
    sqlQuery.addBindValue(mMidname);
    sqlQuery.addBindValue(mPassportSerial);
    sqlQuery.addBindValue(mPassportNumber);
    sqlQuery.exec();
}

void User::getDB()
{
    QSqlQuery query;
    query.exec("SELECT * FROM users");
    while (query.next()) {
        mLogin = query.value(1).toString();
        mPassword = query.value(2).toString();
        mSurname = query.value(3).toString();
        mName = query.value(4).toString();
        mMidname = query.value(5).toString();
        mPassportSerial = query.value(6).toString();
        mPassportNumber = query.value(7).toString();
    }
}

void User::save(QDataStream &ost) const
{
    ost << mLogin << mPassword << mSurname
        << mName << mMidname << mPassportSerial
        << mPassportNumber << mDateLogin;
}

void User::load(QDataStream &ist)
{
    ist >> mLogin >> mPassword >> mSurname
        >> mName >> mMidname >> mPassportSerial
        >> mPassportNumber >> mDateLogin;
}
