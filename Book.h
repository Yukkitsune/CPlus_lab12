#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <list>
#include <algorithm>
class Book {
	std::string fio; // Основные переменные класса
	std::string title;
	std::string publisher;
	int year = 0;
	int count_page = 0;
public:
	Book(); //Пустой конструктор
	Book(const Book& bk); // Конструктор копирования
	Book(Book&& bk); // Конструктор перемещения
	void print() const; // Вывод на печать
	void set(std::string fio, std::string title, std::string publisher, int year, int count_page); // Инициализтор
	Book& operator = (const Book& bk); // Перегрузка операций
	Book& operator = (Book&& bk);
	~Book(); // Деструктор
	friend std::ofstream& operator <<(std::ofstream& out, Book& bk); // Дружественная функции вставки в поток
	friend bool sort_deque(const Book& ob1, const Book& ob2); // Дружественная функция сортировки
	bool operator > (const Book& bn); // Перегрузка операций сравнения
	bool operator < (const Book& bn);
	bool operator >= (const Book& bn);
	bool operator <= (const Book& bn);
};
