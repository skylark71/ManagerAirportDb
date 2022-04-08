#ifndef COREDB_H
#define COREDB_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

class coredb
{
public:
    coredb();

private:
    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // COREDB_H
