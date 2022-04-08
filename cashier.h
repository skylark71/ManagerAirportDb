#ifndef CASHIER_H
#define CASHIER_H

#include "user.h"

class Cashier:public User
{
public:
    //! Конструктор по умолчанию.
    Cashier();
    //! Деструктор.
    ~Cashier();
};

#endif // CASHIER_H
