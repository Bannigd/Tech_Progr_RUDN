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
    Vector() {}
    Vector(vector<double> coordinates) {
        this->coordinates = coordinates;
    }

    Vector& operator=(const Vector& Second) {
        this->coordinates = Second.coordinates;
        return *this;
    }
    Vector& setCoordinates() {
        int size;
        double coord;
        cin >> size;
        for (int i = 0;i < size;i++) {
            cin >> coord;
            this->coordinates.push_back(coord);
        }
        return *this;
    }
    friend Vector operator+(Vector& v1, Vector& v2);
    friend Vector operator-(Vector& v1, Vector& v2);
    friend double operator*(Vector& v1, Vector& v2); // dot product

    friend Vector operator*(double number, Vector& V);
    friend Vector operator/(Vector& V, double number);

    Vector operator-() {
        vector<double> new_coordinates(this->coordinates.size());
        for (size_t i = 0; i < this->coordinates.size(); i++) {
            new_coordinates[i] = -this->coordinates[i];
        }
        return Vector(new_coordinates);
    }

    void print() {
        for (size_t i = 0; i < this->coordinates.size(); i++) {
            cout << this->coordinates[i] << " ";
        }
        cout << endl;
    }

    double length() {
        return sqrt(*this * *this);
    }

    double angleTo(Vector& V) {
        return acos(*this * V / (this->length() * V.length()));
    }

    ~Vector() {}

};

Vector operator+(Vector& v1, Vector& v2) {
    vector<double> new_coordinates(v1.coordinates.size());
    for (size_t i = 0; i < v1.coordinates.size(); i++) {
        new_coordinates[i] = v1.coordinates[i] + v2.coordinates[i];
    }
    return Vector(new_coordinates);
}

Vector operator-(Vector& v1, Vector& v2) {
    vector<double> new_coordinates(v1.coordinates.size());
    for (size_t i = 0; i < v1.coordinates.size(); i++) {
        new_coordinates[i] = v1.coordinates[i] - v2.coordinates[i];
    }
    return Vector(new_coordinates);
}

double operator*(Vector& v1, Vector& v2) {
    double dotProduct = 0.;
    for (size_t i = 0; i < v1.coordinates.size(); i++) {
        dotProduct += v1.coordinates[i] * v2.coordinates[i];
    }
    return dotProduct;
}

Vector operator*(double number, Vector& V) {
    vector<double> new_coordinates(V.coordinates.size());
    for (size_t i = 0; i < V.coordinates.size(); i++) {
        new_coordinates[i] = number * V.coordinates[i];
    }
    return Vector(new_coordinates);
}

Vector operator/(Vector& V, double number) {
    vector<double> new_coordinates(V.coordinates.size());
    for (size_t i = 0; i < V.coordinates.size(); i++) {
        new_coordinates[i] = V.coordinates[i] / number;
    }
    return Vector(new_coordinates);

}

int main() {

    Vector* Vector1 = new Vector({ 1.,1.,1.,1. });
    Vector* Vector2 = new Vector();
    Vector2->setCoordinates();
    Vector* VectorSum = new Vector();
    Vector* VectorSubs = new Vector();
    Vector* VectorNumberMul = new Vector();
    Vector* VectorNumberDiv = new Vector();
    Vector* VectorUnaryMinus = new Vector();
    *VectorSum = *Vector1 + *Vector2;
    *VectorSubs = *Vector1 - *Vector2;
    *VectorNumberMul = 10 * *Vector1;
    *VectorNumberDiv = *Vector2 / 10;
    *VectorUnaryMinus = -*Vector1;
    Vector1->print();
    Vector2->print();
    VectorSum->print();
    VectorSubs->print();
    VectorNumberMul->print();
    VectorNumberDiv->print();
    VectorUnaryMinus->print();
    double dotP = *Vector1 * *Vector1;
    double angle = Vector1->angleTo(*Vector2), Vector1Length = Vector1->length();
    cout << dotP << " " << angle << " " << Vector1Length << " " << endl;
    delete Vector1;
    delete Vector2;
    delete VectorSum;
    delete VectorSubs;
    delete VectorNumberMul;
    delete VectorNumberDiv;
    delete VectorUnaryMinus;
    return 0;
}




