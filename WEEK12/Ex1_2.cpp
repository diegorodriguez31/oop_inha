#include <iostream>
using namespace std;

class Fruit{
private:
    string name;
    string color;
public:
    Fruit() {
    name = "Fruit";
    color = "unknown";
    }
    ~Fruit() {
            cout << "Fruit destructor called." << endl;
    }
    string getName(){return name;}
    string getColor(){return color;}
    void setName(string name){this->name = name;}
    void setColor(string color){this->color = color;}
};

class Apple : public Fruit {
public:
    Apple(string color) {
        setName("Apple");
        setColor(color);
    }
};

class Banana : public Fruit {
public:
    Banana() : Fruit() {
        setName("Banana");
        setColor("yellow");
    }
    Banana(string color) {
        setName("Banana");
        setColor(color);
    }
};

class RedBanana : public Banana {
public:
    RedBanana() : Banana("red") {
        setName("RedBanana");
    }
};

int main() {
    Apple a{"red"};
    Banana b;
    RedBanana c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    return 0;
}