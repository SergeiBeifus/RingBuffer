//
// Created by User on 12.05.2022.
//

#ifndef UNTITLED3_DAOI_H
#define UNTITLED3_DAOI_H

class Daoi {
private:
    int n;
    int *arr;
public:
    int &operator[](int index);
    Daoi();
    Daoi(int n);
    Daoi(int n, int m);
    Daoi(Daoi const &array);
    Daoi(Daoi&& array);
    ~Daoi();
    Daoi resize(int newsize);
    int getSize() const;
    bool operator==(Daoi a);
    bool operator!=(Daoi a);
    Daoi operator+(Daoi a);
    Daoi operator=(Daoi& a);
    Daoi& operator=(Daoi&& a);
    bool operator>(Daoi a);
    bool operator<(Daoi a);
    bool operator>=(Daoi a);
    bool operator<=(Daoi a);

    friend std::ostream &operator<<(std::ostream &os, const Daoi &p);
    friend std::istream &operator>>(std::istream &in, Daoi &p);
};


#endif //UNTITLED3_DAOI_H
