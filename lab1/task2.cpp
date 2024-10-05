#include <iostream>
#include <vector>
#include <string>

enum class BookType {
    Fiction,
    Technical
};

class Book {
public:
    Book(std::string author, std::string title, BookType type) 
        : author(author), title(title), type(type) {
        if (author.empty() || title.empty()) {
            throw std::invalid_argument("Автор и название книги не могут быть пустыми.");
        }
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getTitle() const {
        return title;
    }

    BookType getType() const {
        return type;
    }

private:
    std::string author;
    std::string title;
    BookType type;
};

void printBooks(const std::vector<Book>& library) {
    std::cout << "Книги в библиотеке:" << std::endl;
    for (const auto& book : library) {
        std::cout << "Автор: " << book.getAuthor() << ", Название: " << book.getTitle() 
                  << ", Тип: " << (book.getType() == BookType::Fiction ? "Художественная" : "Техническая") 
                  << std::endl;
    }
}

void countBooks(const std::vector<Book>& library) {
    int fictionCount = 0;
    int technicalCount = 0;

    for (const auto& book : library) {
        switch (book.getType()) {
            case BookType::Fiction:
                fictionCount++;
                break;
            case BookType::Technical:
                technicalCount++;
                break;
        }
    }

    std::cout << "Количество художественной литературы: " << fictionCount << std::endl;
    std::cout << "Количество технической литературы: " << technicalCount << std::endl;
}

int main() {
    std::vector<Book> library;

    library.emplace_back("Лев Толстой", "Война и мир", BookType::Fiction);
    library.emplace_back("Иван Бунин", "Собака", BookType::Fiction);
    library.emplace_back("Алан Тюринг", "Проблема вычислимости", BookType::Technical);
    library.emplace_back("Роберт Мартин", "Чистый код", BookType::Technical);
    library.emplace_back("Фёдор Достоевский", "Преступление и наказание", BookType::Fiction);
    library.emplace_back("Гарри Поттер", "Гарри Поттер и философский камень", BookType::Fiction);
    library.emplace_back("Джордж Оруэлл", "1984", BookType::Fiction);
    library.emplace_back("Николай Коперник", "О вращении небесных сфер", BookType::Technical);
    library.emplace_back("Дан Браун", "Код да Винчи", BookType::Fiction);
    library.emplace_back("Кен Тейлор", "Программирование на C++", BookType::Technical);
    library.emplace_back("Габриэль Гарсиа Маркес", "Сто лет одиночества", BookType::Fiction);
    library.emplace_back("Роберт Грейвс", "Я, Клавдий", BookType::Fiction);
    library.emplace_back("Исаак Ньютон", "Математические начала натуральной философии", BookType::Technical);

    printBooks(library);
    std::cout << std::endl;
    countBooks(library);

    return 0;
}
