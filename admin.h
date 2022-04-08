#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"

class Admin:public User
{
public:
    //! Конструктор по умолчанию.
    Admin();
    //! Деструктор.
    ~Admin();
};

#endif // ADMIN_H
