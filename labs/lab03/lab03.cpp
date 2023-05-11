/*
    Реализовать класс матрицы размера N*M (произвольный)
    и описать с помощью переопределения (overload) операторов базовые операции с матрицами:
    - Сложение/вычитание матрицы
    - Произведение 2х матриц
    - умножение матрицы на число
*/

#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

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
    

    ~Matrix() {}

};

bool Matrix::checkSum(Matrix matrix1, Matrix matrix2) {
    return matrix1.getNumberOfColumns() == matrix2.getNumberOfColumns() && matrix1.getNumberOfRows() == matrix2.getNumberOfRows();
}

Matrix operator+(Matrix& M1, Matrix& M2) {
    vector<vector<double>> newMatrixElements = M1.matrixElements;
    if (!M1.checkSum(M1, M2)){
        throw "Matrix sizes dont match to perform addition\n";
    } ;

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


int main() {
    Matrix* M1 = new Matrix({ {1.,2., 7.},
                              {3.,4., 8.},
                              {5.,6., 9.} });
    Matrix* M2 = new Matrix();
    Matrix* M3 = new Matrix();
    Matrix* M4 = new Matrix();
    Matrix* M5 = new Matrix();
    cout << "M1: ";
    cout << M1->getNumberOfRows() << " " << M1->getNumberOfColumns() << endl;
    M1->print();
    
    try {
        cout << "M2: ";
        M2->setElements();
        cout << M2->getNumberOfRows() << " " << M2->getNumberOfColumns() << endl;
    }
    catch (const char* error_message) {
        cout << error_message;
    }
    
    try {
        cout << "M3: ";
        *M3 = *M1 + *M2;
        cout << M3->getNumberOfRows() << " " << M3->getNumberOfColumns() << endl;
        M3->print();
    }
    catch (const char* error_message) {
        cout << error_message;
    }
    
    try {
        cout << "M4: ";
        *M4 = *M1 - *M2;
        cout << M4->getNumberOfRows() << " " << M4->getNumberOfColumns() << endl;
        M4->print();
    }
    catch (const char* error_message) {
        cout << error_message;
    }
    
    try {
        cout << "M5: ";
        *M5 = *M1 * *M2;
        cout << M5->getNumberOfRows() << " " << M5->getNumberOfColumns() << endl;
        M5->print();
    }
    catch (const char* error_message) {
        cout << error_message;
    }
    delete M1;
    delete M2;
    delete M3;
    delete M4;
    delete M5;
}
