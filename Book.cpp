#include "Book.h"

Book::Book() { //Пустой конструктор
	std::string fio = "";
	std::string title = "";
	std::string publisher = "";
	int year = 0;
	int count_page = 0;
}
Book::Book(const Book& bk) { // Конструктор копирования
	fio = bk.fio;
	title = bk.title;
	publisher = bk.publisher;
	year = bk.year;
	count_page = bk.count_page;
}
Book::Book(Book&& bk){ // Конструктор перемещения
	std::swap(fio, bk.fio);
	std::swap(title, bk.title);
	std::swap(publisher, bk.publisher);
	std::swap(year, bk.year);
	std::swap(count_page, bk.count_page);
}
Book& Book::operator = (const Book& bk) { // Перегрузка операций
	if (this != &bk) {
		fio = bk.fio;
		title = bk.title;
		publisher = bk.publisher;
		year = bk.year;
		count_page = bk.count_page;
	}
	return *this;
}
Book& Book::operator = (Book&& bk){
	if (this != &bk) {
		std::swap(fio, bk.fio);
		std::swap(title, bk.title);
		std::swap(publisher, bk.publisher);
		std::swap(year, bk.year);
		std::swap(count_page, bk.count_page);
	}
	return *this;
}
bool Book::operator > (const Book& bn) { // Перегрузка операций сравнения
	return title > bn.title;
}
bool Book::operator >= (const Book& bn) {
	return title >= bn.title;
}
bool Book::operator < (const Book& bn) {
	return title < bn.title;
}
bool Book::operator <= (const Book& bn) {
	return title <= bn.title;
}
Book::~Book() {};

void Book::set(std::string fio, std::string title, std::string publisher, int year, int count_page) {  // Инициализтор
	this->fio = fio;
	this->title = title;
	this->publisher = publisher;
	this->year = year;
	this->count_page = count_page;
}
std::ofstream& operator << (std::ofstream& fout, Book& bk) { // Дружественная функции вставки в поток
	fout << "FIO: " << bk.fio << "\n";
	fout << "Title: " << bk.title << "\n";
	fout << "Publisher: " << bk.publisher << "\n";
	fout << "Year: " << bk.year << "\n";
	fout << "Number of pages: " << bk.count_page << "\n";
	return fout;
}
void Book::print() const {  // Вывод на печать
	std::cout << "FIO: " << fio << std::endl;
	std::cout << "Title: " << title << std::endl;
	std::cout << "Publisher: " << publisher << std::endl;
	std::cout << "Year: " << year << std::endl;
	std::cout << "Number of pages: " << count_page << std::endl;
}
