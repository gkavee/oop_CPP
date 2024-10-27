#include <iostream>
#include <string>
using namespace std;

class Publication {
protected:
    string title;
    float price;
public:
    void getdata() {
        cout << "Введите название: ";
        cin.clear();
        getline(cin, title);
        cout << "Введите цену: ";
        cin >> price;
    }

    void putdata() const {
        cout << "Название: " << title << endl;
        cout << "Цена: " << price << endl;
    }

    string getTitle() const {
        return title;
    }

    float getPrice() const {
        return price;
    }
};

class Sales {
protected:
    float sales[3];
public:
    Sales() {
        for(int i = 0; i < 3; i++) {
            sales[i] = 0.0;
        }
    }

    void getdata() {
        for (int i = 0; i < 3; ++i) {
            cout << "Введите продажу за " << i + 1 << "-й месяц: ";
            cin >> sales[i];
        }
    }

    void putdata() const {
        for (int i = 0; i < 3; ++i) {
            cout << "Продажи за " << i + 1 << "-й месяц: " << sales[i] << endl;
        }
    }

    float totalSales() const {
        float total = 0.0;
        for (int i = 0; i < 3; ++i) {
            total += sales[i];
        }
        return total;
    }
};

class Book : public Publication, public Sales {
private:
    int pageCount;
public:
    Book() : pageCount(0) {}

    void getdata() {
        Publication::getdata();
        cout << "Введите количество страниц: ";
        cin >> pageCount;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Количество страниц: " << pageCount << endl;
        Sales::putdata();
    }
};

class Audio : public Publication, public Sales {
private:
    float duration;
public:
    Audio() : duration(0.0) {}

    void getdata() {
        Publication::getdata();
        cout << "Введите время записи в минутах: ";
        cin >> duration;
        Sales::getdata();
    }

    void putdata() const {
        Publication::putdata();
        cout << "Время записи: " << duration << " минут" << endl;
        Sales::putdata();
    }

    float getPlayTime() const {
        return duration;
    }
};

int main() {
    Book myBook;
    Audio myAudio;
    system("chcp 1251");
    
    cout << "Введите данные для книги:" << endl;
    myBook.getdata();
    cin.ignore();

    cout << "\nВведите данные для аудио записи:" << endl;
    myAudio.getdata();

    cout << "\nВывод данных о книге:" << endl;
    myBook.putdata();
    cout << "\nВывод данных о аудио записи:" << endl;
    myAudio.putdata();

    if (myBook.getTitle() != myAudio.getTitle()) {
        cout << "\nНазвание аудиокниги не соответствует названию книги." << endl;
    }
    else {
        cout << "\nАудиокнига имеет такое же название что и книга." << endl;
    }

    float bookTotalSales = myBook.totalSales() * myBook.getPrice();
    float audioTotalSales = myAudio.totalSales() * myAudio.getPrice();

    cout << "\nПрибыль от продаж книги: " << bookTotalSales << endl;
    cout << "Прибыль от продаж аудиокниги: " << audioTotalSales << endl;

    return 0;
}