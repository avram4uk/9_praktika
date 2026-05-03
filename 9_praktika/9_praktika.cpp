#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
const int SIZE = 20;

string tall[5]; //переменная для хранения списка самых высоких девочек
string list_of_names[SIZE]; //переменная для хранения списка учеников в лексикографическом порядке
string same_month[SIZE]; //переменная для хранения списка учеников, имеющих месяц рожднеия в текущем месяце

struct children {
	char name[20];
	char gender;
	int height;
	int year_of_birth;
	char month_of_birth[10];
};

children* init() {
	children* ch = new children[SIZE];
	ch[0] = { "Ivanov Ivan", 'm', 150, 9 , "June" };
	ch[1] = { "Matveev Artem", 'm', 153,10 , "February" };
	ch[2] = { "Pupkin Vasya", 'm', 145, 9, "March" };
	ch[3] = { "Fazulov Ivan", 'm', 128, 7, "May" };
	ch[4] = { "Veselov Fedor", 'm', 157, 11, "July" };
	ch[5] = { "Parshukov Anton", 'm', 170, 15, "October" };
	ch[6] = { "Valeeva Nastya", 'f', 149, 13, "November" };
	ch[7] = { "Dugin Kirill", 'm', 136, 12, "December" };
	ch[8] = { "Andreev Anton", 'm', 139, 13, "March" };
	ch[9] = { "Ilkhsam Tagiev", 'm', 157, 14, "October" };
	ch[10] = { "Valeeva Kamila", 'f', 134, 13, "September" };
	ch[11] = { "Azlagorov Firamir", 'm', 161, 12, "April" };
	ch[12] = { "Romanova Alica", 'f', 135, 14, "August" };
	ch[13] = { "Nazarova Alina", 'f', 120, 10, "May" };
	ch[14] = { "Nazarov Oleg", 'm', 163, 13, "February" };
	ch[15] = { "Kureeva Olga", 'f', 141, 11, "January" };
	ch[16] = { "Eremina Kristina", 'f', 152, 14, "July" };
	ch[17] = { "Savelyeva Sonya", 'f', 144, 10, "December" };
	ch[18] = { "Jeffry Epshtein", 'm', 158, 12, "November" };
	ch[19] = { "Egorova Arina", 'f', 126, 11, "October" };
	return ch;
}

void print(children a[SIZE], string child_name) {  //Вывести все данные по конкретному ученику
	for (int i = 0; i < SIZE; i++) {
		if (a[i].name == child_name) {
			printf("\n%s %c %d %d %s\n", a[i].name, a[i].gender, a[i].height, a[i].year_of_birth, a[i].month_of_birth);
		}
	}
}

float mid(children b[SIZE]) {  //Вывести средний рост мальчиков
	float count = 0;
	short size_new = SIZE;
	for (int i = 0; i < SIZE; i++) {
		if (b[i].gender == 'm')
			count += b[i].height;
		else
			size_new -= 1;
	}
	return count / size_new;
}

void tallest(children c[SIZE]) {  //Перенести в отдельный массив 5 самых высоких девочек
	extern string tall[];
	int max[SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < SIZE; i++) {
		if (c[i].gender == 'f') {
			max[i] = c[i].height;
		}
	}
	int t;
	for (int a = 1; a < SIZE; a++) {
		for (int b = (SIZE - 1); b >= a; b--) {
			if (max[b - 1] > max[b]) {
				t = max[b - 1];
				max[b - 1] = max[b];
				max[b] = t;
			}
		}
	}

	for (int j = SIZE - 1; j > 14; j--) {
		for (int i = 0; i < SIZE; i++) {
			if (c[i].height == max[j] && c[i].gender == 'f') {
				tall[19 - j] = c[i].name;
				break;
			}
		}
	}
}

void sorted(children d[SIZE]) {  //Отсортировать список учеников в лексикографическом порядке
	extern string list_of_names[];
	for (int i = 0; i < SIZE; i++) {
		list_of_names[i] = d[i].name;
	}
	string t;
	for (int a = 1; a < SIZE; a++) {
		for (int b = (SIZE - 1); b >= a; b--) {
			if (list_of_names[b - 1] > list_of_names[b]) {
				t = list_of_names[b - 1];
				list_of_names[b - 1] = list_of_names[b];
				list_of_names[b] = t;
			}
		}
	}
}

void change(children& e) { //Функция изменяет поля структуры, в качестве аргумента передаётся структура по индексу
	string a, t, u;
	char f[10];
	char b;
	int c, d;
	cout << endl << "Введите новое имя: ";
	cin >> a >> t;
	u = a + ' ' + t;
	for (int i = 0; i < size(u); i++) {
		e.name[i] = u[i];
	}
	cout << "Введите пол: ";
	cin >> b;
	e.gender = b;
	cout << "Введите рост: ";
	cin >> c;
	e.height = c;
	cout << "Введите год рождения: ";
	cin >> d;
	e.year_of_birth = d;
	cout << "Введите месяц рождения: ";
	cin >> f;
	for (int i = 0; i < 10; i++) {
		e.month_of_birth[i] = f[i];
	}
}

void same(children f[SIZE], string month) {  //Функция для определения детей с одинаковым днём рождения
	extern string same_month[];
	int j = 0;
	for (int i = 0; i < SIZE; i++) {
		if (f[i].month_of_birth == month) {
			same_month[j] = f[i].name;
			j++;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	children* child;
	child = init();
	printf("средний рост мальчиков: %.2f", mid(child));

	tallest(child);

	cout << endl << "------------------------------" << endl << "Список пяти самых высоких девочек:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << endl << tall[i];
	}
	cout << endl << "------------------------------" << endl;


	cout << endl << "------------------------------" << endl << "Список детей в лексикографическом порядке:" << endl;
	sorted(child);
	for (int i = 0; i < SIZE; i++) {
		cout << endl << list_of_names[i];
	}
	cout << endl << "------------------------------" << endl;

	string q, w, z;
	cout << "Введите имя ученика, данные которого нужно вывести: ";
	cin >> q >> w;
	z = q + ' ' + w;
	cout << endl << "------------------------------" << endl << "Полная информация о " << z << ":" << endl;
	print(child, z);
	cout << "------------------------------" << endl;


	same(child, "October");
	cout << endl << "------------------------------" << endl << "Список учеников с совпадающим месяцем рождения:" << endl;
	for (int i = 0; i < SIZE; i++) {
		if (same_month[i] != "")
			cout << endl << same_month[i];
	}
	cout << endl << "------------------------------";


	int id;
	cout << endl << "Введите id ученика, у которого нужно изменить данные: ";
	cin >> id;
	change(child[id]);
	cout << "Ученик с id " << id << " был изменён";

	return 0;
}
