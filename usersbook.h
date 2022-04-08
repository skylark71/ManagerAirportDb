#ifndef USERSBOOK_H
#define USERSBOOK_H

#include "book.h"
#include "user.h"
#include "passenger.h"
#include "admin.h"
#include "cashier.h"

class UsersBook : public Book<User>
{
public:
    //! Конструктор по умолчанию
    UsersBook();
    //! Сохраняет книжку в поток ost.
    void save(QDataStream &ostadmin, QDataStream &ostcashier, QDataStream &ostpassenger) const;
    //! Загружает книжку из потока ist.
    void load(QDataStream &istadmin, QDataStream &istcashier, QDataStream &istpassenger);
};

#endif // USERSBOOK_H
