#ifndef PASSENGER_H
#define PASSENGER_H

#include "user.h"

class Passenger:public User
{
public:
    //! Конструктор по умолчанию.
    Passenger();
    //! Деструктор.
    ~Passenger();
};

#endif // PASSENGER_H
