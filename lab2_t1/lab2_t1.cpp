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
    int i;                  // Текущее кол-во уроков
};

struct Class_
{
    string Name;            // Название класса
    string year;            // Год обучения
    Student mas_Stud[32];   // Массив учеников
};


void init_t(Teacher& t)
{
    t.Fam  = "";
    t.Name = "";
    t.Otch = "";
}

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

// Ввод учителя, передаем адрес, где будет храниться информация
int out_Teach(Teacher& t)
{
    cout << "ФИО учителя: " << t.Fam << " " << t.Name << " " << t.Otch << endl;

    return 0;
}


void init_l(Lessons& ls)
{
    ls.Name = "";
    Teacher t;
    init_t(t);
    ls.Teach = t;
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

// Вывод уроков, передаем адрес, где будет храниться информация
int out_Less(Lessons& ls)
{
    cout << "Название предмета: " << ls.Name << endl;
    out_Teach(ls.Teach);

    return 0;
}

void init_m(Mark& m)
{
    m.Value = 0;
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

void init_s(Student& st)
{
    st.Fam = "";
    st.Name = "";
    st.Otch = "";
    Lessons L;
    Mark M;
    init_l(L);
    init_m(M);
    st.i = 0;
    for (int i = 0; i < 20; i++)
    {
        st.mas_Less[i] = L;
    }

    for (int i = 0; i < 20; i++)
    {
        st.mas_Marks[i] = M;
    }
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

int add_Less_to_Stud(Student& st, Lessons& ls)
{
    int fl = 0;

    for (int i = 0; (i < 20) && (fl == 0); i++)
    {
        if (st.mas_Less[i].Name == "")
        {
            st.mas_Less[i] = ls;
            fl = 1;
        }
    }

    return fl;
}

int add_LM_to_Stud(Student& st, Lessons& ls, Mark &m)
{
    int fl = 0;

    for (int i = 0; (i < 20) && (fl == 0); i++)
    {
        if (st.mas_Less[i].Name == "")
        {
            st.mas_Less[i] = ls;
            st.mas_Marks[i] = m;
            fl = 1;
        }
    }

    return fl;
}

int add_Mark_to_Stud(Student& st, Mark &m, int n)
{
    int fl = 0;

    if (st.mas_Less[n].Name != "")
    {
        st.mas_Marks[n] = m;
        fl = 1;
    }

    return fl;
}

// Вывод ученика
// Передаем ученика и флаг для различного вывода уроков и оценок
// fl_out (0 или 1)
int out_Stud(Student& st, int fl_out)
{
    cout << "ФИО ученика: " << st.Fam << " " << st.Name << " " << st.Otch << endl;

    if (fl_out == 0)
    {
        cout << "Уроки:" << endl;
        for (int i = 0; i < 20; i++)
        {
            out_Less(st.mas_Less[i]);
        }
        cout << "Оценки:" << endl;
        for (int i = 0; i < 20; i++)
        {
            st.mas_Marks[i];
        }
    }
    else
    {
        cout << "Уроки:" << endl;
        for (int i = 0; i < 20; i++)
        {
            cout << " * " << st.mas_Less[i].Name << " * " << st.mas_Marks->Value << " * " << endl;
        }
    }

    return 0;
}


void init_c(Class_& cl)
{
    cl.Name = "";
    cl.year = "";
    Student S;
    init_s(S);
    for (int i = 0; i < 32; i++)
    {
        cl.mas_Stud[i] = S;
    }
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

// fl_out (0 или 1)
int out_Class_(Class_& cl, int fl_out)
{
    cout << "Название класса: " << cl.Name << endl;;
    cout << "Год обучения: " << cl.year << endl;
    cout << endl;
    cout << "Ученики:" << endl;

    if (fl_out == 0)
    {
        for (int i = 0; i < 32; i++)
        {
            out_Stud(cl.mas_Stud[i], 0);
        }
    }
    else
    {
        for (int i = 0; i < 32; i++)
        {
            out_Stud(cl.mas_Stud[i], 1);
        }
    }

    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");
    
    cout << "===================================================" << endl;
    Teacher t_Chem;
    Teacher *t_Biology = new Teacher;
    
    init_t(t_Chem);
    init_t(*t_Biology);

    cout << "Введите ФИО 2-ух учителей:" << endl;
    cout << endl;
    inp_Teach(t_Chem);
    out_Teach(t_Chem);

    cout << endl;

    inp_Teach(*t_Biology);
    out_Teach(*t_Biology);
    cout << "===================================================" << endl;

    cout << endl;
    cout << endl;

    cout << "===================================================" << endl;
    Lessons Chem;
    Lessons* Biology = new Lessons;

    init_l(Chem);
    init_l(*Biology);

    cout << "Введите 2 урока:" << endl;
    cout << endl;
    cout << "Для учителя - ";
    out_Teach(t_Chem);
    inp_Less(Chem, t_Chem);
    cout << "Вывод:" << endl;
    out_Less(Chem);

    cout << endl;

    cout << "Для учителя - ";
    out_Teach(*t_Biology);
    inp_Less(*Biology, *t_Biology);
    cout << "Вывод:" << endl;
    out_Less(*Biology);
    cout << "===================================================" << endl;

    cout << endl;
    cout << endl;

    cout << "===================================================" << endl;
    Student st1;
    Student* st2 = new Student;
    Student st3;

    init_s(st1);
    init_s(*st2);
    init_s(st3);

    cout << "Введите 3 ученика:" << endl;
    cout << endl;
    //inp_Stud(st1);
    cout << "===================================================" << endl;

}
