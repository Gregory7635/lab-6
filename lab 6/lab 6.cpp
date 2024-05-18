#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
#include <string>
class Library {
private:
    std::unordered_map<std::string, int> books; // используем unordered_map для хранения количества экземпляров книг

public:
    void add_book(const std::string& author, const std::string& title, int year, int num_copies) {
        std::string key = author;
        books[key] += num_copies;
        std::cout << "Книга '" << title << "' успешно добавлена в библиотеку" << std::endl;
        write_to_file(author, title, year, num_copies);  // Запись информации о книге в файл
    }

    void remove_book(const std::string& author, const std::string& title) {
        std::string key = author;
        if (books.find(key) != books.end() && books[key] > 0) {
            books[key]--;
            std::cout << "Книга '" << title << "' успешно списана из библиотеки" << std::endl;
        }
        else {
            std::cout << "Книги '" << title << "' нет в наличии в библиотеке" << std::endl;
        }
    }

    void display_books_by_author() {
        for (const auto& entry : books) {
            std::cout << "Автор: " << entry.first << ", Количество экземпляров: " << entry.second << std::endl;
        }
    }

    void display_books_by_year() {
        // Для примера, учитывая что год издания у всех книг одинаковый
        for (const auto& entry : books) {
            std::cout << "Год издания: 2022, Автор: " << entry.first << ", Количество экземпляров: " << entry.second << std::endl;
        }
    }

    void write_to_file(const std::string& author, const std::string& title, int year, int num_copies) {
        std::ofstream file("library_books.txt", std::ios_base::app);  // Открываем файл для добавления записей
        if (file.is_open()) {
            file << "Книга: " << title << "  Автор: " << author << "  Год издания: " << year << "  Количество экземпляров: " << num_copies << std::endl;
            file.close();
        }
        else {
            std::cerr << "Не удалось открыть файл для записи" << std::endl;
        }
    }
};

int main() {
    Library library;
    int choice;
    setlocale(LC_ALL, "RU");
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить книгу\n";
        std::cout << "2. Списать книгу\n";
        std::cout << "3. Вывести книги по авторам\n";
        std::cout << "4. Вывести книги по годам издания\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            std::string author, title;
            int year, num_copies;
            std::cout << "Введите автора: ";
            std::cin.ignore();
            std::getline(std::cin, author);
            std::cout << "Введите название книги: ";
            std::getline(std::cin, title);
            std::cout << "Введите год издания: ";
            std::cin >> year;
            std::cout << "Введите количество экземпляров: ";
            std::cin >> num_copies;

            library.add_book(author, title, year, num_copies);
            break;
        }
        case 2: {
            std::string author, title;
            std::cout << "Введите автора: ";
            std::cin.ignore();
            std::getline(std::cin, author);
            std::cout << "Введите название книги: ";
            std::getline(std::cin, title);

            library.remove_book(author, title);
            break;
        }
        case 3: {
            library.display_books_by_author();
            break;
        }
        case 4: {
            library.display_books_by_year();
            break;
        }
    } 
} while (choice != 0);

return 0;
}
