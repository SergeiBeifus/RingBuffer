//
// Created by User on 19.05.2022.
//

#ifndef UNTITLED3_AS_H
#define UNTITLED3_AS_H


#pragma once
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>
template<typename T>
struct Item
{
    std::string key;
    T value;

    Item(std::string n, T a) : key(n), value(a) { }
};

template<typename T>
class Hash_Table {
private:
    std::vector<std::list<Item<T>*>*> table;
    std::vector<Item<T>*> doplist;
    int hash(std::string key);
public:
    Hash_Table();
    Hash_Table(const int capacity);
    ~Hash_Table();

    void push(std::string key, T value);
    void pop(std::string elem);
    Item<T>* search(std::string elem);
    void clear();
    bool isEmpty() const;

    class Iterator
    {
    private:
        const Hash_Table<T>& tab;
//std::vector<Item<T>*>::const_iterator current;
        std::vector<Item<T>*> current;
    public:
        Iterator(const Hash_Table<T>& tab); //: tab(tab)
        bool finish() const;
        void next();
        void start();
        Item<T>* getValue() const;
    };
};



#endif //UNTITLED3_AS_H
