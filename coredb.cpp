#include "coredb.h"

coredb::coredb()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./tetsDB.db");
    if(db.open()) {
        qDebug("open");
    } else {
        qDebug("no open");
    }

    QSqlQuery a_query;
        // DDL query
        QString str = "CREATE TABLE my_table ("
                "number integer PRIMARY KEY NOT NULL, "
                "address VARCHAR(255), "
                "age integer"
                ");";
        bool b = a_query.exec(str);
        if (!b) {
            qDebug() << "Вроде не удается создать таблицу, провертье карманы!";
        }
}
