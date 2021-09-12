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



// Ввод учителя, передаем адрес, где будет храниться информация
int inp_Teach(Teacher &t)
{
    cout << "Введите Фамилию учителя: ";
    cin >> t.Fam;
    cout << "Введите имя учителя: ";
    cin >> t.Name;
    cout << "Введите отчество учителя: ";
    cin >> t.Otch;

    return 0;
}


// Ввод уроков, передаем адрес, где будет храниться информация и адрес учителя
int inp_Less(Lessons &ls, Teacher &t)
{
    cout << "Введите название предмета: ";
    cin >> ls.Name;
    cout << endl;
    ls.Teach = t;

    return 0;
}


int inp_Mark(Mark& m)
{
    string mark;
    cout << "Введите оценку: ";
    cin >> mark;
    m.Value = stoi(mark);
    cout << endl;

    return 0;
}

int out_Mark(Mark& m)
{
    cout << "Оценка: " << m.Value << endl;

    return 0;
}


int inp_Stud(Student &st, Mark *mas_m[20], Lessons *mas_l[20])
{
    cout << "Введите Фамилию ученика: ";
    cin >> st.Fam;
    cout << "Введите Имя ученика: ";
    cin >> st.Name;
    cout << "Введите Отчество ученика: ";
    cin >> st.Otch;

    for (int i = 0; i < 20; i++)
    {
        st.mas_Less[i] = *mas_l[i];
    }

    for (int i = 0; i < 20; i++)
    {
        st.mas_Marks[i] = *mas_m[i];
    }

    return 0;
}


int inp_Class_(Class_ &cl, Student *mas[32])
{
    cout << "Введите название класса: ";
    cin >> cl.Name;
    cout << endl;
    cout << "Введите год обучения: ";
    cin >> cl.year;
    cout << endl;

    for (int i = 0; i < 32; i++)
    {
        cl.mas_Stud[i] = *mas[i];
    }

    return 0;
}



int main()
{
    ;
}
