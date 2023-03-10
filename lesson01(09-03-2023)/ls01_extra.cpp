#include<iostream>
#include<string>
using namespace std;

class Animal {
protected:
    string name;
    string class_is;
    string food;
    string sound;
    string color;
    /*
    0-very small
    ...
    10 -very big
    */
    unsigned short size;
    unsigned short age;
public:
    Animal(string name, string class_is, string food, string sound, string color, unsigned short size, unsigned short age) {
        this->name = name;
        this->class_is = class_is;
        this->sound = sound;
        this->food = food;
        this->color = color;
        this->size = size;
        this->age = age;
    }
    void print_name() {
        cout << this->name << " ";
    }
    void breathe() {
        print_name();
        cout << "inhales... exhales..." << endl;
    }
    void eat() {
        print_name();
        cout << "eats " << this->food << endl;
    }
    void eat(string unusual_food) {
        print_name();
        cout << "eats " << unusual_food << " . It's bad." << endl;
    }
    void eat(short portion_count) {
        print_name();
        cout << "eats " << portion_count << " times." << endl;
    }
    void make_sound() {
        print_name();
        cout << "says: " << this->sound << endl;
    }

    ~Animal() {
        print_name();
        cout << "passed away." << endl;
    }
};

class Mamal: public Animal {
protected:
    ;
};

class Bird: public Animal {
protected:
    unsigned short wings_size; // from 0 to 10, 10 - max
public:
    Bird(string name, string class_is, string food, string sound, string color, unsigned short size, unsigned short age, unsigned short wings_size): Animal(name, class_is, food, sound, color, size, age) {
        this->wings_size = wings_size;
    }
    ~Bird() {
        print_name();
        cout << "passed away." << endl;
    }
    void fly() {
        print_name();
        cout << "flies" << endl;
    }
    void fly(short distance) {
        print_name();
        cout << "flied " << distance << "m." << endl;
    }
    ~Bird() {
        print_name();
        cout << "passed away." << endl;
    }
};

class Penguin: public Bird {
protected:
public:
    Penguin(string name, string class_is, string food, string sound, string color, unsigned short size, unsigned short age, unsigned short wings_size) : Bird(name, class_is, food, sound, color, size, age, wings_size) {

    } 
    void fly() {
        print_name();
        cout << "cannot fly" << endl;
    }
    void swim() {
        print_name();
        cout << "swims" << endl;
    }
    void swim(short distance) {
        print_name();
        cout << "swam " << distance << " m." << endl;
    }
    ~Penguin(){
        print_name();
        cout << "passed away" << endl;
    }
};

int main() {
    return 0;
}
