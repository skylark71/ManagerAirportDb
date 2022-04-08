#include "ticket.h"

Ticket::Ticket()
{
    db = QSqlDatabase::addDatabase("QSQLITE"); //добавляем базу конкретного типа
    db.setHostName("localhost"); //в общем случае, может быть локалхостом
    db.setDatabaseName("./airport.db"); //QString path - путь к базе
}

Ticket::~Ticket()
{
}

const int &Ticket::getNumber() const
{
    return mNumber;
}

void Ticket::setNumber(const int &number)
{
    mNumber = number;
}

const int &Ticket::getFlightNumber() const
{
    return mFlightNumber;
}

void Ticket::setFlightNumber(const int &flightNumber)
{
    mFlightNumber = flightNumber;
}

const QString &Ticket::getPassengerLogin() const
{
    return mPassengerLogin;
}

void Ticket::setPassengerLogin(const QString &passengerLogin)
{
    mPassengerLogin = passengerLogin;
}

const QDate &Ticket::getDepartureDate() const
{
    return mDepartureDate;
}

void Ticket::setDepartureDate(const QDate &departureDate)
{
    mDepartureDate = departureDate;
}

const QDate &Ticket::getArrivalDate() const
{
    return mArrivalDate;
}

void Ticket::setArrivalDate(const QDate &arrivalDate)
{
    mArrivalDate = arrivalDate;
}

void Ticket::setDB(const int &number, int &flightNumber, QString &passengerLogin, QDate &departureDate, QDate &arrivalDate)
{
    mNumber = number;
    mFlightNumber = flightNumber;
    mPassengerLogin = passengerLogin;
    mDepartureDate = departureDate;
    mArrivalDate = arrivalDate;

    /*
    CREATE TABLE "tickets" (
    "index"	INTEGER PRIMARY KEY AUTOINCREMENT,
    "flightnumber"	INTEGER,
    "passengerlogin"	TEXT,
    "departuredate"	TEXT,
    "arrivaldate"	TEXT
    );
    */

    QSqlQuery sqlQuery(db); //cоздаем объект запроса
    sqlQuery.prepare("INSERT INTO tickets (flightnumber, passengerlogin, departuredate, arrivaldate)"
                      "VALUES (?, ?, ?, ?);");
        sqlQuery.addBindValue(mFlightNumber);
        sqlQuery.addBindValue(mPassengerLogin);
        sqlQuery.addBindValue(mDepartureDate);
        sqlQuery.addBindValue(mArrivalDate);
        sqlQuery.exec();
}

void Ticket::getDB()
{
    QSqlQuery query;
    query.exec("SELECT * FROM tickets");
    while (query.next()) {
        mFlightNumber = query.value(1).toInt();
        mPassengerLogin = query.value(2).toString();
        mDepartureDate = query.value(3).toDate();
        mArrivalDate = query.value(4).toDate();
    }
}

void Ticket::save(QDataStream &ost) const
{
    ost << mNumber << mFlightNumber << mPassengerLogin << mDepartureDate << mArrivalDate;
}

void Ticket::load(QDataStream &ist)
{
    ist >> mNumber >> mFlightNumber >> mPassengerLogin >> mDepartureDate >> mArrivalDate;
}
