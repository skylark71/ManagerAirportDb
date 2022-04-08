#ifndef USER_H
#define USER_H

#include <QDataStream>
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlDatabase>

class User
{
public:
    //! Конструктор по умолчанию.
    User();
    //! Деструктор.
    ~User();
    //! Возвращает логин пользователя.
    const QString &getLogin() const;
    //! Устанавливает логин пользователя.
    void setLogin(const QString &login);
    //! Возвращает пароль пользователя.
    const QString &getPassword() const;
    //! Устанавливает пароль пользователя.
    void setPassword(const QString &password);
    //! Возвращает фамилию пользователя.
    const QString &getSurname() const;
    //! Устанавливает фамилию пользователя.
    void setSurname(const QString &surname);
    //! Возвращает имя пользователя.
    const QString &getName() const;
    //! Устанавливает имя пользователя.
    void setName(const QString &name);
    //! Возвращает отчество пользователя.
    const QString &getMidname() const;
    //! Устанавливает отчество пользователя.
    void setMidname(const QString &midname);
    //! Возвращает серию паспорта пользователя.
    const QString &getPassportSerial() const;
    //! Устанавливает серию паспорта пользователя.
    void setPassportSerial(const QString &passportSerial);
    //! Возвращает номер паспорта пользователя.
    const QString &getPassportNumber() const;
    //! Устанавливает номер паспорта пользователя.
    void setPassportNumber(const QString &passportSerial);
    //! Возвращает дату последнего входа пользователя.
    const QDate &getDateLogin() const;
    //! Устанавливает дату последнего входа пользователя.
    void setDateLogin(const QDate &dateLogin);
    //! Сохраняет данные в БД.
    void setDB(const QString &login, const QString &password, const QString &surname, const QString &name, const QString &midname, const QString &passportSerial, const QString &passportNumber);
    //! Получает данные из БД.
    void getDB();
    //! Сохраняет пользователя в поток ost.
    virtual void save(QDataStream &ost) const;
    //! Загружает пользователя из потока ist.
    virtual void load(QDataStream &ist);
protected:
    //! Логин пользователя
    QString mLogin;
    //! Пароль пользователя
    QString mPassword;
    //! Фамилия пользователя
    QString mSurname;
    //! Имя пользователя
    QString mName;
    //! Отчество пользователя
    QString mMidname;
    //! Серия паспорта пользователя
    QString mPassportSerial = "0000";
    //! Номер паспорта пользователя
    QString mPassportNumber = "000000";
    //! Дата последнего входа пользователя
    QDate mDateLogin = QDate::currentDate();
    //! Объект базы данных
    QSqlDatabase db;
};

//! Реализация оператора << для вывода User в QDataStream.
inline QDataStream &operator<<(QDataStream &ost, const User &user)
{
    user.save(ost);
    return ost;
}

//! Реализация оператора >> для вввода User из QDataStream.
inline QDataStream &operator>>(QDataStream &ist, User &user)
{
    user.load(ist);
    return ist;
}

#endif // USER_H
