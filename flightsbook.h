#ifndef FLIGHTSBOOK_H
#define FLIGHTSBOOK_H

#include "book.h"
#include "flight.h"

class FlightsBook : public Book<Flight>
{
public:
    //! Конструктор по умолчанию
    FlightsBook();
};

#endif // FLIGHTSBOOK_H
