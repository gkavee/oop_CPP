#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Detail {
protected:
    string name;
    int id;
    
    Detail(string n, int i) : name(n), id(i) {}
    Detail() : name(""), id(0) {}

public:
    virtual void print() {
        cout << "Деталь: " << name << ", ID: " << id << endl;
    }
    
    friend Detail* createDetail(string n, int i);
    friend class Assembly;
};

class Assembly : public Detail {
protected:
    int partCount;
    
    Assembly(string n, int i, int p) : Detail(n, i), partCount(p) {}
    Assembly() : Detail(), partCount(0) {}

public:
    void print() override {
        cout << "Сборка: " << name << ", ID: " << id << ", Количество деталей: " << partCount << endl;
    }
    
    friend Assembly* createAssembly(string n, int i, int count);
};

Detail* createDetail(string n, int i) {
    return new Detail(n, i);
}

Assembly* createAssembly(string n, int i, int count) {
    return new Assembly(n, i, count);
}

int main() {
    vector<Detail*> storage;
    
    storage.push_back(createDetail("Процессор", 1));
    storage.push_back(createDetail("Материнская плата", 2));
    storage.push_back(createDetail("Оперативная память", 3));
    storage.push_back(createDetail("Жесткий диск", 4));
    storage.push_back(createDetail("SSD накопитель", 5));
    storage.push_back(createDetail("Блок питания", 6));
    storage.push_back(createDetail("Видеокарта", 7));
    storage.push_back(createDetail("Корпус", 8));
    storage.push_back(createDetail("Кулер процессора", 9));
    
    storage.push_back(createAssembly("ПК", 10, storage.size()));
    
    for (auto item : storage) {
        item->print();
    }
    
    for (auto item : storage) {
        delete item;
    }
    
    return 0;
}