#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

template<typename... Args>
void print(const Args&... args) {
    ((std::cout << args << ' '), ...);
    std::cout << std::endl;
}

class Human {
    float dna;

public:
    string name;
    Human(const string& n) : name(n) {
        print("\nCreating Human: ", name);
    }

    void walk(float speed) {
        print("Walking.. at ", speed, "km/h");
    }
    void walk(int distance) {
        print("Walking.. for ", distance, "km");
    }
    void owalk();

    ~Human() {
        print("\n-----",name,"is Removed!");
    }
};

void Human::owalk() {
    print("Outside walking..");
}

class SubHuman : public Human {
public:
    string weapon;
    SubHuman(const string& n) : Human(n) {
        weapon = "Cape";
    }
    void fly() {
        print("Now I'm flying");
    }
};

int main() {
    print("HI HUIHUIHUI");

    string a = "aaaa";
    print("hhaaaha", a);

    Human hu("h");
    hu.walk(4.5f);
    hu.walk(20);
    hu.owalk();

    Human* hu2 = new Human("a");
    hu2->walk(4);

    SubHuman subhu("hahahsubhu");
    subhu.walk(7100.0f);
    print(subhu.weapon);

    delete hu2;
    return 0;
}
