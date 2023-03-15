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

    void print_name() {
        cout << this->name << " ";
    }

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
    void breathe() {
        print_name();
        cout << "inhales... exhales..." << endl;
    }
    void eat() {
        print_name();
        cout << "eats " << this->food << endl;
    }
    void eat(string food) {
        if (food != this->food) {
            print_name();
            cout << "eats " << food << ". It's bad." << endl;
        }
        eat();
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
    bool fur;
    unsigned short fur_length; // from 0 to 10, 10 - max
public:
    Mamal(string name, string class_is, string food, string sound, string color, unsigned short size, unsigned short age, bool fur, unsigned short fur_length): Animal(name, class_is, food, sound, color, size, age) {
        this->fur = fur;
        this->fur_length = fur_length;
    }
    void drop_fur() {
        print_name();
        cout << "drops fur." << endl;
    }
    void run() {
        print_name();
        cout << "runs" << endl;
    }
    void run(unsigned short distance) {
        print_name();
        cout << "runs " << distance << " m." << endl;
    }
    ~Mamal() {}
};

class Fish: public Animal {
protected:
public:
    Fish(string name, string class_is, string food, string sound, string color, unsigned short size, unsigned short age): Animal(name, class_is, food, sound, color, size, age) {};
    void swim() {
        print_name();
        cout << "swims" << endl;
    }
    void swim(short distance) {
        print_name();
        cout << "swam " << distance << " m." << endl;
    }
    void lay_eggs() {
        print_name();
        cout << "layed eggs." << endl;
    }

    ~Fish() {}
};

class Bird: public Animal {
protected:
    unsigned short wings_size; // from 0 to 10, 10 - max
public:
    Bird(string name, string class_is, string food, string sound, string color, unsigned short size, unsigned short age, unsigned short wings_size): Animal(name, class_is, food, sound, color, size, age) {
        this->wings_size = wings_size;
    }
    void fly() {
        print_name();
        cout << "flew" << endl;
    }
    void fly(short distance) {
        print_name();
        cout << "flew " << distance << " m." << endl;
    }
    ~Bird() {}
};

class Penguin: public Bird {
protected:
public:
    Penguin(string name, string class_is, string food, string sound, string color, unsigned short size, unsigned short age, unsigned short wings_size): Bird(name, class_is, food, sound, color, size, age, wings_size) {

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
    ~Penguin() {}
};

int main() {
    Bird* crow = new Bird("Blanche", "bird", "dead meat", "Kaarrr", "black", 1, 7, 5);
    Penguin* penguin = new Penguin("Alex", "bird", "fish", "squeak", "white", 1, 4, 3);
    Fish* fish = new Fish("Nemo", "fish", "Plankton", "bubble pop", "silver", 4, 1);
    crow->fly();
    crow->fly(400);
    crow->eat("dead meat");
    penguin->fly();
    penguin->swim(100);
    penguin->eat(10);
    fish->make_sound();
    fish->swim(4000);
    fish->lay_eggs();
    fish->eat("Plankton");
    delete penguin;
    delete crow;
    delete fish;
        return 0;
}
