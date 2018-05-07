#ifndef LIST_H
#define LIST_H

#include <algorithm>
#include <stdexcept>

#include <tlistiterator.h>

template <class T>
struct TListItem
{
    TListItem(T v) :
        Right(nullptr),
        val(v) {}
    TListItem* Right;
    T val;
};


template <class T>
class TList
{
public:
    TList();
    T      Pop(const size_t n); // throws
    T&     operator[] (const size_t n); // throws
    // Works Corectly on n = GetSize() and n = 0
    bool   InsertBefore(T val, size_t n);
    size_t GetSize();
    void TakeAway(TList &from, size_t first_i, size_t n);

    TListIterator<TListItem<T>, T> begin();
    TListIterator<TListItem<T>, T> end();
private:
    size_t Size;
    TListItem<T> *base;

};

#endif // LIST_H
