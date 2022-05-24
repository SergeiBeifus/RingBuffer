//
// Created by User on 12.05.2022.
//

#include <ostream>
#include <istream>
#include "Daoi.h"
#include "DaoiException.h"

int &Daoi::operator[](int index) {//+
    return arr[index];
}//+

Daoi::Daoi() { //+
    this->n = 0;
    this->arr = new int[n];
}//+

Daoi::Daoi(int n) { //+
    this->n = n;
    this->arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
}//+

Daoi::Daoi(int n, int m) { //+
    this->n = n;
    this->arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = m;
    }
}//+


Daoi::Daoi(Daoi const &array) { //+
    this->n = array.n;
    this->arr = new int[n];
    for (int i = 0; i < n; i++) {
        this->arr[i] = array.arr[i];
    }
}//+

Daoi::Daoi(Daoi &&array) : arr(nullptr), n(0) {
    this->arr = array.arr;
    this->n = array.n;
    array.arr = nullptr;
    array.n = 0;
}

Daoi::~Daoi() {
    delete[] arr;
}

int Daoi::getSize() const { //+
    return n;
} //+

Daoi Daoi::resize(int newSize) {
    Daoi res = Daoi(newSize);
    if (newSize > n) {
        for (int i = 0; i < n; i++) {
            res[i] = arr[i];
        }
    } else if (newSize < n) {
        for (int i = 0; i < newSize; i++) {
            res[i] = arr[i];
        }
    }
    delete[] arr;
    return res;
}

bool Daoi::operator==(Daoi a) { //+
    if (a.n != this->n) { throw DaoiException("length arrays is not equals"); }

    for (int i = 0; i < a.n; i++) {
        if (a[i] != this->arr[i]) {
            return false;
        }
    }
    return true;
}//+

bool Daoi::operator!=(Daoi a) {
    if (a.n != this->n) { throw DaoiException("length arrays is not equals"); }

    for (int i = 0; i < a.n; i++) {
        if (a[i] == this->arr[i]) {
            return false;
        }
    }
    return true;
}//+

Daoi Daoi::operator+(Daoi a) { //+
    Daoi res = Daoi(a.getSize() + this->getSize());
    for (int i = 0; i < this->getSize(); i++) {
        res[i] = this->arr[i];
    }

    for (int i = this->getSize(); i < (a.getSize() + this->getSize()); i++) {
        res[i] = a[i - this->getSize()];
    }
    return res;
} //+

Daoi Daoi::operator=(Daoi &a) { //+
    Daoi copy = Daoi(a);
    delete[] arr;
    return copy;
}

Daoi &Daoi::operator=(Daoi &&a) {
    if (this == &a) { return *this; }
    std::swap(n, a.n);
    std::swap(arr, a.arr);
    return *this;
}

bool Daoi::operator>(Daoi a) {
    if (getSize() > a.n) {
        for (int i = 0; i < a.n; i++) {
            if (this->arr[i] > a.arr[i]) {
                return true;
            } else if (this->arr[i] < a.arr[i]) {
                return false;
            }
        }
        return true;
    } else {
        for (int i = 0; i < getSize(); i++) {
            if (this->arr[i] > a.arr[i]) {
                return true;
            } else if (this->arr[i] < a.arr[i]) {
                return false;
            }
        }
        return false;
    }
}

bool Daoi::operator<(Daoi a) {
    if (getSize() < a.n) {
        for (int i = 0; i < getSize(); i++) {
            if (this->arr[i] < a.arr[i]) {
                return true;
            } else if (this->arr[i] > a.arr[i]) {
                return false;
            }
        }
        return true;
    } else {
        for (int i = 0; i > a.getSize(); i++) {
            if (this->arr[i] < a.arr[i]) {
                return true;
            } else if (this->arr[i] > a.arr[i]) {
                return false;
            }
        }
        return false;
    }
}

bool Daoi::operator>=(Daoi a) {
    for (int i = 0; i < a.n; i++) {
        if (a[i] != this->arr[i]) {
            if (getSize() > a.n) {
                for (int i = 0; i < a.n; i++) {
                    if (this->arr[i] > a.arr[i]) {
                        return true;
                    } else if (this->arr[i] < a.arr[i]) {
                        return false;
                    }
                }
                return true;
            } else {
                for (int i = 0; i < getSize(); i++) {
                    if (this->arr[i] > a.arr[i]) {
                        return true;
                    } else if (this->arr[i] < a.arr[i]) {
                        return false;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool Daoi::operator<=(Daoi a) {
    for (int i = 0; i < a.n; i++) {
        if (a[i] != this->arr[i]) {
            if (getSize() < a.n) {
                for (int i = 0; i < getSize(); i++) {
                    if (this->arr[i] < a.arr[i]) {
                        return true;
                    } else if (this->arr[i] > a.arr[i]) {
                        return false;
                    }
                }
                return false;
            } else {
                for (int i = 0; i > a.getSize(); i++) {
                    if (this->arr[i] < a.arr[i]) {
                        return true;
                    } else if (this->arr[i] > a.arr[i]) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return true;
}


std::ostream &operator<<(std::ostream &os, const Daoi &p) { //+
    os << "\nSize: " << p.getSize() << "\n";
    for (int i = 0; i < p.getSize(); i++) {
        os << "[" << i << "]: " << p.arr[i] << "\n";
    }
    os << "\n";
    return os;
}

std::istream &operator>>(std::istream &in, Daoi &p) {//+
    in >> p.n;
    for (int i = 0; i < p.n; i++) {
        in >> p.arr[i];
    }
    return in;
}
