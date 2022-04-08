#ifndef TICKETSBOOK_H
#define TICKETSBOOK_H

#include "book.h"
#include "ticket.h"

class TicketsBook : public Book<Ticket>
{
public:
    //! Конструктор по умолчанию.
    TicketsBook();
};

#endif // TICKETSBOOK_H
