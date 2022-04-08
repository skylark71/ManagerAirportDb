#ifndef FLIGHT_H
#define FLIGHT_H

#include <QDataStream>
#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlDatabase>

class Flight
{
public:
    //! Конструктор по умолчанию
    Flight();
    //! Деструктор.
    ~Flight();
    //! Возвращает номер рейса.
    const int &getNumber() const;
    //! Устанавливает номер рейса.
    void setNumber(const int &number);
    //! Возвращает пункт отправления.
    const QString &getDeparturePoint() const;
    //! Устанавливает пункт отправления.
    void setDeparturePoint(const QString &departurePoint);
    //! Возвращает пункт назначения.
    const QString &getArrivalPoint() const;
    //! Устанавливает пункт назначения.
    void setArrivalPoint(const QString &arrivalPoint);
    //! Возвращает время вылета.
    const QTime &getDepartureTime() const;
    //! Устанавливает время вылета.
    void setDepartureTime(const QTime &departureTime);
    //! Возвращает время прибытия.
    const QTime &getArrivalTime() const;
    //! Устанавливает время прибытия.
    void setArrivalTime(const QTime &arrivalTime);
    //! Возвращает марку самолёта.
    const QString &getMark() const;
    //! Устанавливает марку самолёта.
    void setMark(const QString &mark);
    //! Возвращает число мест.
    const int &getNumberSeats() const;
    //! Устанавливает число мест.
    void setNumberSeats(const int &numberSeats);
    //! Возвращает число билетов.
    const int &getNumberTickets() const;
    //! Устанавливает число билетов.
    void setNumberTickets(const int &numberTickets);
    //! Сохраняет в базу данных.
    void setDB(const QString &departurePoint, const QString &arrivalPoint, const QTime &departureTime, const QTime &arrivalTime, const QString &mark, const int &numberSeats, const int &numberTickets);
    //! Получает данные из бд.
    void getDB();
    //! Сохраняет рейс в поток ost.
    void save(QDataStream &ost) const;
    //! Загружает рейс из потока ist.
    void load(QDataStream &ist);
private:
    //! Номер рейса
    int mNumber;
    //! Пункт отправления
    QString mDeparturePoint;
    //! Пункт назначения
    QString mArrivalPoint;
    //! Время вылета
    QTime mDepartureTime;
    //! Время прибытия
    QTime mArrivalTime;
    //! Марка самолёта
    QString mMark;
    //! Число мест
    int mNumberSeats;
    //! Число билетов
    int mNumberTickets = 0;
    //!  Объект бд
    QSqlDatabase db;
};

//! Реализация оператора << для вывода Flight в QDataStream.
inline QDataStream &operator<<(QDataStream &ost, const Flight &flight)
{
    flight.save(ost);
    return ost;
}

//! Реализация оператора >> для вввода Flight из QDataStream.
inline QDataStream &operator>>(QDataStream &ist, Flight &flight)
{
    flight.load(ist);
    return ist;
}

#endif // FLIGHT_H
