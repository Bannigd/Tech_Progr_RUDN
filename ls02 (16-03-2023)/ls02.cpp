/*
Тема 1 - Перечисления, Класс enum
Могут использоваться, например, для вывода ошибок,
    задать конкретный набор значений, которые может принимать переменная
    состояния
Тема 2 - Указатели
*/

enum class week {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

#include<iostream>

using namespace std;

int main() {
    int n, max, sum;
    cin >> n;
    int* ptr_array = new int[n];
    cin >> ptr_array[0];
    max = ptr_array[0];
    sum = ptr_array[0];

    for (int i = 1; i < n; i++) {
        cin >> ptr_array[i];
        if (max < ptr_array[i]) {
            max = ptr_array[i];
        }
        sum += ptr_array[i];
    }
    cout << "n = " << n << " max = " << max << " sum = " << sum << endl;
    delete[] ptr_array;
    return 0;
}