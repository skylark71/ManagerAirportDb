#include "flight.h"

Flight::Flight()
{
    db = QSqlDatabase::addDatabase("QSQLITE"); //добавляем базу конкретного типа
    db.setHostName("localhost"); //в общем случае, может быть локалхостом
    db.setDatabaseName("./airport.db"); //QString path - путь к базе
}

Flight::~Flight()
{
}

const int &Flight::getNumber() const
{
    return mNumber;
}

void Flight::setNumber(const int &number)
{
    mNumber = number;
}

const QString &Flight::getDeparturePoint() const
{
    return mDeparturePoint;
}

void Flight::setDeparturePoint(const QString &departurePoint)
{
    mDeparturePoint = departurePoint;
}

const QString &Flight::getArrivalPoint() const
{
    return mArrivalPoint;
}

void Flight::setArrivalPoint(const QString &arrivalPoint)
{
    mArrivalPoint = arrivalPoint;
}

const QTime &Flight::getDepartureTime() const
{
    return mDepartureTime;
}

void Flight::setDepartureTime(const QTime &departureTime)
{
    mDepartureTime = departureTime;
}

const QTime &Flight::getArrivalTime() const
{
    return mArrivalTime;
}

void Flight::setArrivalTime(const QTime &arrivalTime)
{
    mArrivalTime = arrivalTime;
}

const QString &Flight::getMark() const
{
    return mMark;
}

void Flight::setMark(const QString &mark)
{
    mMark = mark;
}

const int &Flight::getNumberSeats() const
{
     return mNumberSeats;
}

void Flight::setNumberSeats(const int &numberSeats)
{
    mNumberSeats = numberSeats;
}

const int &Flight::getNumberTickets() const
{
    return mNumberTickets;
}

void Flight::setNumberTickets(const int &numberTickets)
{
    mNumberTickets = numberTickets;
}

void Flight::setDB(const QString &departurePoint, const QString &arrivalPoint, const QTime &departureTime, const QTime &arrivalTime, const QString &mark, const int &numberSeats, const int &numberTickets)
{
    mDeparturePoint = departurePoint;
    mArrivalPoint = arrivalPoint;
    mDepartureTime = departureTime;
    mArrivalTime = arrivalTime;
    mMark = mark;
    mNumberSeats = numberSeats;
    mNumberTickets = numberTickets;

    /*
    CREATE TABLE "flights" (
    "index"	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    "departurepoint"	TEXT,
    "arrivalpoint"	TEXT,
    "departuretime"	TEXT,
    "arrivaltime"	TEXT,
    "mark"	TEXT,
    "numberseats"	INTEGER,
    "numbertickets"	INTEGER
     */
    QSqlQuery sqlQuery(db); //cоздаем объект запроса
    sqlQuery.prepare("INSERT INTO flights (departurepoint, arrivalpoint, departuretime, arrivaltime, mark, numberseats, numbertickets)"
                      "VALUES (?, ?, ?, ?, ?, ?, ?);");
        sqlQuery.addBindValue(mDeparturePoint);
        sqlQuery.addBindValue(mArrivalPoint);
        sqlQuery.addBindValue(mDepartureTime);
        sqlQuery.addBindValue(mArrivalTime);
        sqlQuery.addBindValue(mMark);
        sqlQuery.addBindValue(mNumberSeats);
        sqlQuery.addBindValue(mNumberTickets);
        sqlQuery.exec();
}

void Flight::getDB()
{
    QSqlQuery query;
    query.exec("SELECT * FROM flights");
    while (query.next()) {
        mDeparturePoint = query.value(1).toString();
        mArrivalPoint = query.value(2).toString();
        mDepartureTime = query.value(3).toTime();
        mArrivalTime = query.value(4).toTime();
        mMark = query.value(5).toString();
        mNumberSeats = query.value(6).toInt();
        mNumberTickets = query.value(7).toInt();
    }
}

void Flight::save(QDataStream &ost) const
{
    ost << mNumber << mDeparturePoint << mArrivalPoint
        << mDepartureTime << mArrivalTime << mMark
        << mNumberSeats << mNumberTickets;
}

void Flight::load(QDataStream &ist)
{
    ist >> mNumber >> mDeparturePoint >> mArrivalPoint
        >> mDepartureTime >> mArrivalTime >> mMark
        >> mNumberSeats >> mNumberTickets;
}
