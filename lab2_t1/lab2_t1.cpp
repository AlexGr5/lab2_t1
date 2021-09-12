// lab2_t1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <locale.h>

using namespace std;

struct Teacher
{
    string Fam;             // Фамилия
    string Name;            // Имя
    string Otch;            // Отчество
};

struct Lessons
{
    string Name;            // Название предмета
    Teacher Teach;          // Учитель
};

struct Mark
{
    int Value;              // Оценка
};

struct Student
{
    string Fam;             // Фамилия
    string Name;            // Имя
    string Otch;            // Отчество
    Mark mas_Marks[20];     // Массив оценок
    Lessons mas_Less[20];   // Массив уроков
};

struct Class_
{
    string Name;            // Название класса
    string year;            // Год обучения
    Student mas_Stud[32];   // Массив учеников
};


int main()
{
    ;
}
