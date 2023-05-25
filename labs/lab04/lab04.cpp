#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Vector;
class Matrix;

class Vector {
private:
    vector<double> vectorElements;
public:
    Vector() {}
    Vector(vector<double> vectorElements) {
        this->vectorElements = vectorElements;
    }

    Vector& operator=(const Vector& Second) {
        this->vectorElements = Second.vectorElements;
        return *this;
    }
    Vector& setCoordinates() {
        int size;
        double coord;
        cin >> size;
        for (int i = 0;i < size;i++) {
            cin >> coord;
            this->vectorElements.push_back(coord);
        }
        return *this;
    }
    friend Vector operator+(Vector& v1, Vector& v2);
    friend Vector operator-(Vector& v1, Vector& v2);
    friend double operator*(Vector& v1, Vector& v2); // dot product
    friend Vector operator*(double number, Vector& V);
    friend Vector operator/(Vector& V, double number);


    friend Vector operator*(Matrix& Matrix1, Vector& rVector);
    friend Vector operator*(Vector& rVector, Matrix& Matrix1);


    Vector operator-() {
        vector<double> newVectorElements(this->vectorElements.size());
        for (size_t i = 0; i < this->vectorElements.size(); i++) {
            newVectorElements[i] = -this->vectorElements[i];
        }
        return Vector(newVectorElements);
    }

    void print() {
        for (size_t i = 0; i < this->vectorElements.size(); i++) {
            cout << this->vectorElements[i] << " ";
        }
        cout << endl;
    }

    ~Vector() {}

};

Vector operator+(Vector& v1, Vector& v2) {
    vector<double> newVectorElements(v1.vectorElements.size());
    for (size_t i = 0; i < v1.vectorElements.size(); i++) {
        newVectorElements[i] = v1.vectorElements[i] + v2.vectorElements[i];
    }
    return Vector(newVectorElements);
}

Vector operator-(Vector& v1, Vector& v2) {
    vector<double> newVectorElements(v1.vectorElements.size());
    for (size_t i = 0; i < v1.vectorElements.size(); i++) {
        newVectorElements[i] = v1.vectorElements[i] - v2.vectorElements[i];
    }
    return Vector(newVectorElements);
}

double operator*(Vector& v1, Vector& v2) {
    double dotProduct = 0.;
    for (size_t i = 0; i < v1.vectorElements.size(); i++) {
        dotProduct += v1.vectorElements[i] * v2.vectorElements[i];
    }
    return dotProduct;
}

Vector operator*(double number, Vector& V) {
    vector<double> newVectorElements(V.vectorElements.size());
    for (size_t i = 0; i < V.vectorElements.size(); i++) {
        newVectorElements[i] = number * V.vectorElements[i];
    }
    return Vector(newVectorElements);
}

Vector operator/(Vector& V, double number) {
    vector<double> newVectorElements(V.vectorElements.size());
    for (size_t i = 0; i < V.vectorElements.size(); i++) {
        newVectorElements[i] = V.vectorElements[i] / number;
    }
    return Vector(newVectorElements);

}


class Matrix {
private:
    vector<vector<double>> matrixElements;
    int numberOfRows, numberOfColumns;
    bool static checkSum(Matrix matrix1, Matrix matrix2);
public:

    Matrix() {}

    Matrix(vector<vector<double>> matrixElements) {
        this->matrixElements = matrixElements;
        this->numberOfRows = matrixElements.size();
        this->numberOfColumns = matrixElements[0].size();
    }

    Matrix& setElements() {
        double element;
        vector<double> row;
        cin >> this->numberOfRows;
        cin >> this->numberOfColumns;
        for (int i = 0;i < this->numberOfRows;i++) {
            for (int j = 0; j < this->numberOfColumns; j++) {
                cin >> element;
                row.push_back(element);
            }
            this->matrixElements.push_back(row);
            row.clear();
        }
        return *this;
    }

    int getNumberOfRows() {
        return this->numberOfRows;
    }
    int getNumberOfColumns() {
        return this->numberOfColumns;
    }

    void print() {
        for (int i = 0;i < this->numberOfRows;i++) {
            for (int j = 0; j < this->numberOfColumns; j++) {
                cout << this->matrixElements[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix& operator=(const Matrix& Second) {
        this->matrixElements = Second.matrixElements;
        this->numberOfColumns = Second.numberOfColumns;
        this->numberOfRows = Second.numberOfRows;
        return *this;
    }

    Matrix& operator-() {
        for (int i = 0;i < this->numberOfColumns;i++) {
            for (int j = 0; j < this->numberOfRows; j++) {
                this->matrixElements[i][j] = -this->matrixElements[i][j];
            }
        }
        return *this;
    }

    friend Matrix operator+(Matrix& M1, Matrix& M2);
    friend Matrix operator-(Matrix& M1, Matrix& M2);
    friend Matrix operator*(double number, Matrix& M);
    friend Matrix operator*(Matrix& M1, Matrix& M2);


    friend Vector operator*(Matrix& Matrix1, Vector& rVector);
    friend Vector operator*(Vector& rVector, Matrix& Matrix1);

    ~Matrix() {}

};

bool Matrix::checkSum(Matrix matrix1, Matrix matrix2) {
    return matrix1.getNumberOfColumns() == matrix2.getNumberOfColumns() && matrix1.getNumberOfRows() == matrix2.getNumberOfRows();
}

Matrix operator+(Matrix& M1, Matrix& M2) {
    vector<vector<double>> newMatrixElements = M1.matrixElements;
    if (!M1.checkSum(M1, M2)) {
        throw "Matrix sizes dont match to perform addition\n";
    };

    for (int i = 0;i < M1.numberOfRows;i++) {
        for (int j = 0; j < M1.numberOfColumns; j++) {
            newMatrixElements[i][j] += M2.matrixElements[i][j];
        }
    }
    return Matrix(newMatrixElements);
}

Matrix operator-(Matrix& M1, Matrix& M2) {
    vector<vector<double>> newMatrixElements = M1.matrixElements;
    if (!M1.checkSum(M1, M2)) {
        throw "Matrix sizes dont match to perform substraction\n";
    }

    for (int i = 0;i < M1.numberOfRows;i++) {
        for (int j = 0; j < M1.numberOfColumns; j++) {
            newMatrixElements[i][j] -= M2.matrixElements[i][j];
        }
    }
    return Matrix(newMatrixElements);
}

Matrix operator*(Matrix& M1, Matrix& M2) {
    vector<vector<double>> newMatrixElements;
    vector<double> row;
    double element;
    if (M1.numberOfColumns != M2.numberOfRows) {
        throw "Matrix sizes dont match to perform multiplication\n";
    }
    for (int i = 0;i < M1.numberOfRows;i++) {
        for (int j = 0; j < M2.numberOfColumns; j++) {
            element = 0;
            for (int k = 0; k < M1.numberOfColumns; k++) {
                element += M1.matrixElements[i][k] * M2.matrixElements[k][j];
            }
            row.push_back(element);
        }
        newMatrixElements.push_back(row);
        row.clear();
    }
    return Matrix(newMatrixElements);
}
Matrix operator*(double number, Matrix& M) {
    vector<vector<double>> newMatrixElements = M.matrixElements;

    for (int i = 0;i < M.numberOfRows;i++) {
        for (int j = 0; j < M.numberOfColumns; j++) {
            newMatrixElements[i][j] *= number;
        }
    }
    return Matrix(newMatrixElements);
}


Vector operator*(Matrix& Matrix1, Vector& rVector) {
    if (rVector.vectorElements.size() != Matrix1.matrixElements[1].size()) {
        throw "Size dont match";
    }
    vector<double> NewVectorElements(rVector.vectorElements.size(), 0);

    for (size_t i = 0; i < NewVectorElements.size(); i++) {
        for (size_t j = 0; j < NewVectorElements.size(); j++) {
            NewVectorElements[i] += Matrix1.matrixElements[i][j] * rVector.vectorElements[j];
        }
    }
    return Vector(NewVectorElements);
}


Vector operator*(Vector& rVector, Matrix& Matrix1) {
    if (rVector.vectorElements.size() != Matrix1.matrixElements[1].size()) {
        throw "Size dont match";
    }
    vector<double> NewVectorElements(rVector.vectorElements.size(), 0);

    for (size_t i = 0; i < NewVectorElements.size(); i++) {
        for (size_t j = 0; j < NewVectorElements.size(); j++) {
            NewVectorElements[i] += rVector.vectorElements[j] * Matrix1.matrixElements[j][i];
        }
    }
    return Vector(NewVectorElements);
}

int main() {
    Vector* Vector1 = new Vector({ 1.,0.,0. });
    Matrix* Matrix1 = new Matrix({ {1.,2., 3.},
                                   {4.,5., 6.},
                                   {7.,8., 9.} });

    Vector* VectorResult1 = new Vector();
    Vector* VectorResult2 = new Vector();

    try {
        *VectorResult1 = *Matrix1 * *Vector1;
    }
    catch (const char* error_message) {
        cout << error_message;
    }
    
    try {
        *VectorResult2 = *Vector1 * *Matrix1;
    }
    catch (const char* error_message) {
        cout << error_message;
    }

    VectorResult1->print();
    VectorResult2->print();
    delete Vector1;
    delete Matrix1;
    delete VectorResult1;
    delete VectorResult2;
    return 0;
}