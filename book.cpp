#include "book.h"

template<class T>
Book<T>::Book()
{
}

template<class T>
int Book<T>::size() const
{
    return mCollection.size();
}

template<class T>
T* Book<T>::operator[](int idx) const
{
    return mCollection[idx];
}

template<class T>
void Book<T>::save(QDataStream &ost) const
{
    // Цикл по всем элементам
    for (const T *n : mCollection)
    {
        // Выводим элемент в поток
        ost << *n;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ost.status() == QDataStream::WriteFailed)
        {
            throw std::runtime_error("Write to the stream failed");
        }
    }
}

template<class T>
void Book<T>::load(QDataStream &ist)
{
    // Удаляем все элементы
    mCollection.clear();
    // Пока в потоке есть данные
    while (!ist.atEnd())
    {
        T* n = new T;
        // Читаем очередной элемент из потока
        ist >> *n;
        // Если возникла ошибка, запускаем исключительную ситуацию
        if (ist.status() == QDataStream::ReadCorruptData)
        {
            throw std::runtime_error("Corrupt data were read from the stream");
        }
        // Вставляем прочитанный элемент в конец вектора.
        mCollection.push_back(n);
    }
}

template<class T>
void Book<T>::insert(T &element)
{
    // Вставляем элемент в конец вектора
    mCollection.push_back(&element);
}

template<class T>
void Book<T>::erase(int idx)
{
    // Удаляем из вектора элемент с индексом idx
    mCollection.erase(std::next(mCollection.begin(), idx));
}

template<class T>
void Book<T>::edit(int index, T &element)
{
    mCollection[index] = &element;
}
