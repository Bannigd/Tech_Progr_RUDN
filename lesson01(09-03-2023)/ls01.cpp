#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

class Animal {
protected:
    string name;
    string class_is;
    string sound;
    string food;
    string color;
    /*
    0-ver small
    ...
    10 -very big
    */
    unsigned short size;
public:
    // это конструктор
    Animal(string name, string class_is, string sound, string food, string color, unsigned short size){
        this->name = name;
        this->class_is = class_is;
        this->sound = sound;
        this->food = food;
        this->color = color;
        this->size = size;    
    }
    void breathe(){
        cout << "inhale " << "exhale" << endl;
    }
    void meal(){
        cout << "ate " << this->food << endl;
    }
    void meal(string unusual_food){
        cout << "ate " << unusual_food << endl;
    }
    void meal(short time){
        cout << "ate " << this->food << time<< " times" << endl;
    }
    void make_sound(){
        cout << "says: " << this->sound << endl;
    }

    // это деструктор
    ~Animal(){
        cout << this->name << " was killed" << endl;
    }
};

class Elephant : public Animal{
private:
    unsigned short tusk_size;
    const bool wool = false;
public:
    Elephant(string name, string class_is, string sound, string food, string color, unsigned short size, unsigned short tusk_size):Animal(name, class_is, sound, food, color, size){
        this->tusk_size = tusk_size;
    }
    void breathe(){
        Animal::breathe();
        cout << this->name << " make it one more time" << endl;
    }
    void water_in_trunk(){
        cout << "набрал воды в хобот" << endl;
    }
    ~Elephant(){
        cout << "was killed" << endl;
    }
};

class Cow : public Animal{
private:
    unsigned short horns_size;
    unsigned short milk_bucket_count;
    const bool wool = false;
public:
    Cow(string name, string class_is, string sound, string food, string color, unsigned short size, unsigned short horns_size, unsigned short milk_bucket_count):Animal(name, class_is, sound, food, color, size){
        this->horns_size = horns_size;
        this->milk_bucket_count = milk_bucket_count;
    }
    void breathe(){
        Animal::breathe();
        cout << this->name << " make it one more time" << endl;
    }
    void milk(){
        cout << "give " << this->milk_bucket_count << " at noon" << endl;
    }
    ~Cow(){
        cout << "was killed" << endl;
    }
};

int main(int argc, char const *argv[])
{
    SetConsoleOutputCP(CP_UTF8);
    Cow *cow = new Cow("Burenka","mamal", "moo", "grass", "multi", 4, 6, 2);
    Elephant *elephant = new Elephant("Jambo", "mamal", "BLOWING", "Grass and foliage", "grey", 9, 10);
    cow->breathe();
    cow->make_sound();
    cow->milk();
    cow->meal();
    cow->meal("apple");
    elephant->breathe();
    elephant->make_sound();
    elephant->water_in_trunk();
    elephant->meal();
    delete elephant;
    delete cow;
    return 0;
}
