/*
    Реализовать класс математического вектора размера N (произвольный)
    и описать с помощью переопределения (overload) операторов базовые операции с векторами
*/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Vector {
private:
    vector<double> coordinates;
public:

    Vector(vector<double> coordinates) {
        this->coordinates = coordinates;
        cout << "Memory allocated\n";
    }

    Vector operator+(Vector& Second) {
        vector<double> new_coordinates(this->coordinates.size());
        for (size_t i = 0; i < this->coordinates.size(); i++) {
            new_coordinates[i] = this->coordinates[i] + Second.coordinates[i];
        }
        return Vector(new_coordinates);
    }

    Vector operator-(Vector& Second) {
        vector<double> new_coordinates(this->coordinates.size());
        for (size_t i = 0; i < this->coordinates.size(); i++) {
            new_coordinates[i] = this->coordinates[i] - Second.coordinates[i];
        }
        return Vector(new_coordinates);
    }

    Vector operator-() {
        vector<double> new_coordinates(this->coordinates.size());
        for (size_t i = 0; i < this->coordinates.size(); i++) {
            new_coordinates[i] = -this->coordinates[i];
        }
        return Vector(new_coordinates);
    }

    Vector operator*(double number) {
        vector<double> new_coordinates(this->coordinates.size());
        for (size_t i = 0; i < this->coordinates.size(); i++) {
            new_coordinates[i] = this->coordinates[i] * number;
        }
        return Vector(new_coordinates);
    }

    Vector operator/(double number) {
        vector<double> new_coordinates(this->coordinates.size());
        for (size_t i = 0; i < this->coordinates.size(); i++) {
            new_coordinates[i] = this->coordinates[i] / number;
        }
        return Vector(new_coordinates);
    }

    double operator*(Vector& Second) {
        double dotProduct = 0.;
        for (size_t i = 0; i < this->coordinates.size(); i++) {
            dotProduct += this->coordinates[i] * Second.coordinates[i];
        }
        return dotProduct;
    }

    double length() {
        return sqrt(*this * *this);
    }


    double angleTo(Vector& V) {
        return acos(*this * V / (this->length() * V.length()));
    }


    void print() {
        for (size_t i = 0; i < this->coordinates.size(); i++) {
            cout << this->coordinates[i] << " ";
        }
        cout << endl;
    }

    ~Vector() {
        cout << "Memory deallocated\n";
    }
};

int main() {

    Vector Vector1 = Vector({ 1.,1.,1.,1. });
    Vector Vector2 = Vector({ 2.,3.,4.,5. });
    Vector VectorSum = Vector1 + Vector2 + Vector2;
    Vector VectorSubs = Vector1 - Vector2;
    Vector VectorNumberMul = Vector1 * 10;
    Vector VectorNumberDiv = Vector2 / 10;
    Vector VectorUnaryMinus = -Vector1;
    Vector1.print();
    Vector2.print();
    VectorSum.print();
    VectorSubs.print();
    VectorNumberMul.print();
    VectorNumberDiv.print();
    VectorUnaryMinus.print();

    cout << Vector1.length() << endl << Vector1.angleTo(VectorNumberMul);
    return 0;
}




