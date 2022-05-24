//
// Created by User on 16.05.2022.
//

#ifndef UNTITLED3_RINGBUFFER_H
#define UNTITLED3_RINGBUFFER_H

#include <stdio.h>
#include <stdlib.h>



class RingBuffer {
int n;
int *arr;
int end, start; //end - конец очереди(сюда добавляются элементы), start- её начало(от сюда можно взять элемент)

public:
    RingBuffer(int n);
    ~RingBuffer();
    int getSize() const;
    void pushEnd(int elem);
    int popStart();
    int getStart() const;
    void makeEmpty();
    bool empty() const;

    class RBIterator {
        int i=0;
        RingBuffer& a;
        bool flag = false;
    public:

        RBIterator(RingBuffer &a);

        void start(); // начать перебор элементов
        void next(); // перейти к следующему элементу
        bool finish(); // проверка, все ли проитерировано
        int getValue(); // получить очередной элемент очереди
    };
};


#endif //UNTITLED3_RINGBUFFER_H
