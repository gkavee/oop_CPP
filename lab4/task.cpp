#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Person {
public:
    std::string name; 
    short age; 

    virtual void printInfo() {
        std::cout << "Имя: " << name << ", Возраст: " << age << std::endl;
    }

    Person(const std::string& name, int age) : name(name), age(age) {
        if (age < 0 || age > 120) {
            throw std::overflow_error("Возраст выходит за допустимый диапазон (0-120)");
        }
    }

    virtual ~Person() {} 
};

class Preschooler : public Person {
public:
    std::string kindergarten; 

    Preschooler(const std::string& name, int age, const std::string& kindergarten)
        : Person(name, age), kindergarten(kindergarten) {}

    void printInfo() override {
        Person::printInfo();
        std::cout << "Детский сад: " << kindergarten << std::endl;
    }
};

class Schooler : public Person {
public:
    std::string school; 

    Schooler(const std::string& name, int age, const std::string& school)
        : Person(name, age), school(school) {}

    void printInfo() override {
        Person::printInfo();
        std::cout << "Школа: " << school << std::endl;
    }
};

class Student : public Person {
public:
    std::string university;

    Student(const std::string& name, int age, const std::string& university)
        : Person(name, age), university(university) {}

    void printInfo() override {
        Person::printInfo();
        std::cout << "Университет: " << university << std::endl;
    }
};

class Employee : public Person {
public:
    std::string company;

    Employee(const std::string& name, int age, const std::string& company)
        : Person(name, age), company(company) {}

    void printInfo() override {
        Person::printInfo();
        std::cout << "Компания: " << company << std::endl;
    }
};

template <typename T>
class PointerArray {
private:
    std::vector<T*> arr; 

public:
    PointerArray(int size) : arr(size, nullptr) {}

    T*& operator[](int index) {
        if (index < 0 || index >= arr.size()) {
            throw std::out_of_range("Индекс вне диапазона");
        }
        return arr[index];
    }

    ~PointerArray() {
        for (T* ptr : arr) {
            delete ptr;
        }
    }

    int size() const { return arr.size(); }
};


int main() {
    try {
        PointerArray<Person> people(5);

        people[0] = new Preschooler("Арина", 5, "Детский сад 'Желтый ручеек'");
        people[1] = new Schooler("Артем", 10, "Школа №14");
        people[2] = new Student("Ольга", 20, "МГТУ Станкин");
        people[3] = new Employee("Дмитрий", 30, "Google");
        
        int lastPersonAge;
        std::cout << "Введите возраст пятого человека: " << std::endl;
        std::cin >> lastPersonAge;

        try {
            people[5] = new Employee("Максим", lastPersonAge, "Яндекс");
        } catch (const std::overflow_error& e) {
            std::cerr << "Ошибка переполнения при создании последнего экземпляра: " << e.what() << std::endl;
        }

    } catch (const std::out_of_range& e) {
        std::cerr << "Ошибка выхода за границы массива: " << e.what() << std::endl;
    }

    return 0;
}
