#include<iostream>

using namespace std;

class Square {
private:
    int x, y, a;
    int S;
public:

    Square operator+(Square& Second) {
        return Square(this->x + Second.x, this->y + Second.y, this->a + Second.a);
    }
    Square(int x, int y, int a) {
        this->x = x;
        this->y = y;
        this->a = a;
        S = a*a;
    }
    void printData(){
        cout << this->x << " " << this->y << " " << this->a << " " << this->S << endl; 
    }
    ~Square(){}
};


int main() {
    Square a = Square(1, 1, 1);
    Square b = Square(2, 2, 2);
    Square c = Square(0, 0, 0);
    c = a + b;

    a.printData();
    b.printData();
    c.printData();
    
    return 0;
}

