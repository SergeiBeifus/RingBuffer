//
// Created by User on 16.05.2022.
//


#include <iostream>
#include "RingBuffer.h"

RingBuffer::RingBuffer(int a) {
    if (a > 0) {
        this->n = a + 1;
        this->arr = new int[a + 1];
        end = 0;
        start = 0;
    } else {
        throw "n less than zero";
    }
}

RingBuffer::~RingBuffer() {
    delete[] arr;
    arr = nullptr;
}

void RingBuffer::pushEnd(int elem) {
    if (end + start < n - 1) {
        arr[end] = elem;
        end = (end + 1) % n;
    } else {
        throw "array over flow";
    }
}


int RingBuffer::popStart() {
    int res = start;
    if (start != end) {
        start = (start + 1) % n;
    } else {
        throw "array is void";
    }
    return arr[res];
}

int RingBuffer::getStart() const {
    if (!empty()) {
        return arr[start];
    } else {
        throw "error";
    }

}

int RingBuffer::getSize() const {
    return abs(end - start);
}

void RingBuffer::makeEmpty() {
    start = 0;
    end = 0;
}

bool RingBuffer::empty() const {
    return (start == end);
}

RingBuffer::RBIterator::RBIterator(RingBuffer &a) : a(a) {}

void RingBuffer::RBIterator::start() {
    if (!a.empty()) {
        flag = true;
    }else{
        throw "array is empty";
    }
}

void RingBuffer::RBIterator::next() {
    if(flag && i < (a.n -1)){
        i++;
    }else{
        throw "you is not start, or you have reached the end of the array";
    }
}

bool RingBuffer::RBIterator::finish() {
    if(flag) {
        return (i == (a.n - 1));
    }else{
        throw "you is not start, or array is empty";
    }
}

int RingBuffer::RBIterator::getValue() {
    if(flag) {return a.arr[i];}
    else{
        throw "you is not start, or array is empty";
    }
}

