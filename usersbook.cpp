#include "usersbook.h"

UsersBook::UsersBook() : Book()
{
}

void UsersBook::save(QDataStream &ostadmin, QDataStream &ostcashier, QDataStream &ostpassenger) const
{
    // Цикл по всем элементам
    for (User *n : mCollection)
    {
        if(dynamic_cast<Admin*>(n) != nullptr)
        {
            // Выводим элемент в поток
            ostadmin << *n;
            // Если возникла ошибка, запускаем исключительную ситуацию
            if (ostadmin.status() == QDataStream::WriteFailed)
            {
                throw std::runtime_error("Write to the stream failed");
            }
        }
        if(dynamic_cast<Cashier*>(n) != nullptr)
        {
            // Выводим элемент в поток
            ostcashier << *n;
            // Если возникла ошибка, запускаем исключительную ситуацию
            if (ostcashier.status() == QDataStream::WriteFailed)
            {
                throw std::runtime_error("Write to the stream failed");
            }
        }
        if(dynamic_cast<Passenger*>(n) != nullptr)
        {
            // Выводим элемент в поток
            ostpassenger << *n;
            // Если возникла ошибка, запускаем исключительную ситуацию
            if (ostpassenger.status() == QDataStream::WriteFailed)
            {
                throw std::runtime_error("Write to the stream failed");
            }
        }
    }
}

void UsersBook::load(QDataStream &istadmin, QDataStream &istcashier, QDataStream &istpassenger)
{
    // Удаляем все элементы
    mCollection.clear();
    // Пока в потоке есть данные
    while (!istadmin.atEnd())
    {
        Admin* n = new Admin;
        // Читаем очередной элемент из потока
        istadmin >> *n;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (istadmin.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error("Corrupt data were read from the stream");
        }
        // Вставляем прочитанный элемент в конец вектора.
        mCollection.push_back(n);
    }
    while (!istcashier.atEnd())
    {
        Cashier* n = new Cashier;
        // Читаем очередной элемент из потока
        istcashier >> *n;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (istcashier.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error("Corrupt data were read from the stream");
        }
        // Вставляем прочитанный элемент в конец вектора.
        mCollection.push_back(n);
    }
    while (!istpassenger.atEnd())
    {
        Passenger* n = new Passenger;
        // Читаем очередной элемент из потока
        istpassenger >> *n;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (istpassenger.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error("Corrupt data were read from the stream");
        }
        // Вставляем прочитанный элемент в конец вектора.
        mCollection.push_back(n);
    }
}
