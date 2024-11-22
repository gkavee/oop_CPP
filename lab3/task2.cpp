#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Base {
protected:
    int value;

public:
    Base() : value(rand() % 100) {}
    
    Base(const Base& other) : value(other.value) {}
    
    virtual void showBehavior() {
        cout << "Base(простой вывод значения): " << value << endl;
    }
    
    virtual ~Base() {}
};

class Derived : public Base {
public:
    Derived() : Base() {}
    
    Derived(const Derived& other) : Base(other) {}
    
    void showBehavior() override {
        cout << "Derived(вывод значения * -1): " << value * -1 << endl;
    }
};

void add(vector<Base*>& storage, Base* obj) {
    if (dynamic_cast<Derived*>(obj)) {
        storage.push_back(new Derived(*dynamic_cast<Derived*>(obj)));
    } else {
        storage.push_back(new Base(*obj));
    }
}

int main() {
    srand(time(0));
    
    vector<Base*> storage;
    vector<Base*> tempObjects;
    
    cout << "Создание объектов:" << endl;
    for(int i = 0; i < 10; i++) {
        int randomNum = rand() % 100;
        Base* obj;
        
        if(randomNum % 2 == 0) {
            obj = new Base();
            cout << "Создан Base" << endl;
        } else {
            obj = new Derived();
            cout << "Создан Derived" << endl;
        }
        
        tempObjects.push_back(obj);
    }
    
    for(auto obj : tempObjects) {
        add(storage, obj);
    }
    
    cout << "\nДемонстрация поведения:" << endl;
    for(int i = 0; i < storage.size(); i++) {
        cout << "Объект " << i + 1 << ": ";
        storage[i]->showBehavior();
    }
    
    for(auto obj : tempObjects) {
        delete obj;
    }
    tempObjects.clear();
    
    for(auto obj : storage) {
        delete obj;
    }
    storage.clear();
    
    return 0;
}