// lab2_t1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <locale.h>

using namespace std;

// Структура Учитель
struct Teacher
{
    string Fam;             // Фамилия
    string Name;            // Имя
    string Otch;            // Отчество
};

// Структура Уроки
struct Lessons
{
    string Name;            // Название предмета
    Teacher Teach;          // Учитель
};

// Структура Оценка
struct Mark
{
    int Value;              // Оценка
};

// Структура Ученик
struct Student
{
    string Fam;             // Фамилия
    string Name;            // Имя
    string Otch;            // Отчество
    Mark mas_Marks[20];     // Массив оценок
    Lessons mas_Less[20];   // Массив уроков
    int i;                  // Текущее кол-во уроков
};

// Структура Класс
struct Class_
{
    string Name;            // Название класса
    string year;            // Год обучения
    int i;                  // Текущее кол-во учеников
    Student mas_Stud[32];   // Массив учеников
};

// Инициализация структуры Учитель
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

// Инициализация структуры Уроки
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

// Инициализация структуры Оценка
void init_m(Mark& m)
{
    m.Value = 0;
}

// Ввод данных в структуру Оценка
int inp_Mark(Mark& m)
{
    string mark;
    cout << "Введите оценку: ";
    cin >> mark;
    m.Value = stoi(mark);
    cout << endl;

    return 0;
}

// Вывод данных из структуры
int out_Mark(Mark& m)
{
    cout << "Оценка: " << m.Value << endl;

    return 0;
}

// Инициализация структуры Ученик
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

// Ввод данных в структуру Ученик
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

// Ввод ФИО ученика в структуру
int inp_FIO_Stud(Student& st)
{
    cout << "Введите Фамилию ученика: ";
    cin >> st.Fam;
    cout << "Введите Имя ученика: ";
    cin >> st.Name;
    cout << "Введите Отчество ученика: ";
    cin >> st.Otch;

    return 0;
}

// Добавление к ученику урока
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

// Добавление к ученику урока и оценки
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

// Добавление к ученику оценки к конкретному предмету
int add_Mark_to_Stud(Student& st, Lessons& ls, Mark &m)
{
    int fl = 0;

    for (int i = 0; (i < 20) && (fl == 0); i++)
    {
        if (st.mas_Less[i].Name == ls.Name)
        {
            if (st.mas_Less[i].Teach.Fam == ls.Teach.Fam)
            {
                if (st.mas_Less[i].Teach.Name == ls.Teach.Name)
                {
                    if (st.mas_Less[i].Teach.Otch == ls.Teach.Otch)
                    {
                        st.mas_Marks[i] = m;
                        fl = 1;
                    }
                }
            }
        }
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
        int i = 0;
        while (st.mas_Less[i].Name != "")
        {
            cout << " * " << st.mas_Less[i].Name << " * " << st.mas_Marks[i].Value << " * " << endl;
            i++;
        }
    }

    return 0;
}

// Инициализация структуры Класс
void init_c(Class_& cl)
{
    cl.Name = "";
    cl.year = "";
    cl.i = 0;
    Student S;
    init_s(S);
    for (int i = 0; i < 32; i++)
    {
        cl.mas_Stud[i] = S;
    }
}

// Ввод данных в структуру Класс
int inp_Class_(Class_ &cl/*, Student *mas[32]*/)
{
    cout << "Введите название класса: ";
    cin >> cl.Name;
    cout << endl;
    cout << "Введите год обучения: ";
    cin >> cl.year;
    cout << endl;

    /*
    for (int i = 0; i < 32; i++)
    {
        cl.mas_Stud[i] = *mas[i];
    }
    */

    return 0;
}

// Добавление к классу ченика
int add_St_to_Cl(Class_ &cl, Student& st)
{
    int fl = 0;
    if (cl.i < 20)
    {
        cl.mas_Stud[cl.i] = st;
        cl.i++;
        fl = 1;
    }

    return fl;
}

// Выод данных из структуры Класс
// fl_out (0 или 1)
int out_Class_(Class_& cl, int fl_out)
{
    cout << "Название класса: " << cl.Name << endl;;
    cout << "Год обучения: " << cl.year << endl;
    cout << endl;
    cout << "Ученики:" << endl;

    if (fl_out == 0)
    {
        int i = 0;
        while (cl.mas_Stud[i].Fam != "")
        {
            out_Stud(cl.mas_Stud[i], 0);
            i++;
        }
    }
    else
    {
        int i = 0;
        while (cl.mas_Stud[i].Fam != "")
        {
            out_Stud(cl.mas_Stud[i], 1);
            i++;
        }
    }

    return 0;
}

// Функция по нахождению лучших учеников в классе
int Best_Stud_inClass(Class_& cl)
{
    double mas_m[32];
    int exit = 0;

    for (int i = 0; i < 32; i++)
    {
        mas_m[i] = 0;
    }

    int i = 0;
    int k = 0;
    int sum = 0;
    while (cl.mas_Stud[i].Fam != "")
    {
        int j = 0;
        k = 0;
        sum = 0;
        while (cl.mas_Stud[i].mas_Less[j].Name != "")
        {
            sum += cl.mas_Stud[i].mas_Marks[j].Value;
            k++;
        }
        mas_m[i] = double(sum) / k;
        i++;
    }

    if (i == 0)
        exit = -1;
    else
    {
        double maxM = 0;
        maxM = mas_m[0];
        for (int j = 0; j < i; j++)
        {
            if (maxM > mas_m[j])
                maxM = mas_m[j];
        }

        for (int j = 0; j < i; j++)
        {
            if (mas_m[j] == maxM)
                out_Stud(cl.mas_Stud[j], 1);
        }
    }

    return exit;
}

// Функция по нахождению худших учеников в классе
int Bed_Stud_inClass(Class_& cl)
{
    double mas_m[32];
    int exit = 0;

    for (int i = 0; i < 32; i++)
    {
        mas_m[i] = 0;
    }

    int i = 0;
    int k = 0;
    int sum = 0;
    while (cl.mas_Stud[i].Fam != "")
    {
        int j = 0;
        k = 0;
        sum = 0;
        while (cl.mas_Stud[i].mas_Less[j].Name != "")
        {
            sum += cl.mas_Stud[i].mas_Marks[j].Value;
            k++;
        }
        mas_m[i] = double(sum) / k;
        i++;
    }

    if (i == 0)
        exit = -1;
    else
    {
        double minM = 0;
        minM = mas_m[0];
        for (int j = 0; j < i; j++)
        {
            if (minM < mas_m[j])
                minM = mas_m[j];
        }

        for (int j = 0; j < i; j++)
        {
            if (mas_m[j] == minM)
                out_Stud(cl.mas_Stud[j], 1);
        }
    }

    return exit;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");
    
    cout << "========================Тест структуры Учитель===========================" << endl;
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

    cout << "========================Тест структуры Уроки===========================" << endl;
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

    cout << "=======================Тест структуры Ученик и Оценки============================" << endl;
    Student st1;
    Student* st2 = new Student;
    Student st3;

    init_s(st1);
    init_s(*st2);
    init_s(st3);

    cout << "Введите 3 ученика:" << endl;
    cout << endl;
    cout << "Первый ученик:" << endl;
    inp_FIO_Stud(st1);

    cout << endl;
    cout << "Выберите, какие уроки у первого ученика:" << endl;
    cout << endl;
    out_Less(Chem);
    string str = "";
    cout << "Добавить этот предмет ученику? (д - добавить, другой набор символов - нет): ";
    cin >> str;
    if (str == "д")
    {
        if (add_Less_to_Stud(st1, Chem))
        {
            cout << "Урок добавлен!" << endl;
            cout << endl;
            cout << "Добавить оценку (1,2,3,4,5 - добавить, другой набор символов - нет):" << endl;
            str = "";
            cin >> str;
            Mark mr;
            init_m(mr);
            mr.Value = stoi(str);
            if ((mr.Value >= 1) || (mr.Value <= 5))
            {
                if (add_Mark_to_Stud(st1, Chem, mr))
                    cout << "Оценка добавлена!" << endl;
                else
                    cout << "Оценка не добавлена!" << endl;

            }
        }
        else
            cout << "Урок не добавлен!" << endl;
    }
    else
        cout << "Урок не добавлен!" << endl;
    cout << endl;
    cout << endl;
    cout << "Вывод:" << endl;
    out_Stud(st1, 1);

    cout << endl;
    cout << "Выберите, какие уроки у первого ученика:" << endl;
    cout << endl;
    out_Less(*Biology);
    str = "";
    cout << "Добавить этот предмет ученику? (д - добавить, другой набор символов - нет): ";
    cin >> str;
    if (str == "д")
    {
        if (add_Less_to_Stud(st1, *Biology))
        {
            cout << "Урок добавлен!" << endl;
            cout << endl;
            cout << "Добавить оценку (1,2,3,4,5 - добавить, другой набор символов - нет):" << endl;
            str = "";
            cin >> str;
            Mark mr;
            init_m(mr);
            mr.Value = stoi(str);
            if ((mr.Value >= 1) || (mr.Value <= 5))
            {
                if (add_Mark_to_Stud(st1, *Biology, mr))
                    cout << "Оценка добавлена!" << endl;
                else
                    cout << "Оценка не добавлена!" << endl;

            }
        }
        else
            cout << "Урок не добавлен!" << endl;
    }
    else
        cout << "Урок не добавлен!" << endl;
    cout << endl;
    cout << endl;
    cout << "Вывод:" << endl;
    out_Stud(st1, 1);

    cout << endl;
    cout << "Второй ученик:" << endl;
    inp_FIO_Stud(*st2);
    cout << endl;
    cout << "Выберите, какие уроки у первого ученика:" << endl;
    out_Less(Chem);
    str = "";
    cout << "Добавить этот предмет ученику? (д - добавить, другой набор символов - нет): ";
    cin >> str;
    if (str == "д")
    {
        if (add_Less_to_Stud(*st2, Chem))
        {
            cout << "Урок добавлен!" << endl;
            cout << endl;
            cout << "Добавить оценку (1,2,3,4,5 - добавить, другой набор символов - нет):" << endl;
            str = "";
            cin >> str;
            Mark mr;
            init_m(mr);
            mr.Value = stoi(str);
            if ((mr.Value >= 1) || (mr.Value <= 5))
            {
                if (add_Mark_to_Stud(*st2, Chem, mr))
                    cout << "Оценка добавлена!" << endl;
                else
                    cout << "Оценка не добавлена!" << endl;

            }
        }
        else
            cout << "Урок не добавлен!" << endl;
    }
    else
        cout << "Урок не добавлен!" << endl;
    cout << endl;
    cout << endl;
    cout << "Вывод:" << endl;
    out_Stud(*st2, 1);

    cout << endl;
    cout << "Выберите, какие уроки у первого ученика:" << endl;
    cout << endl;
    out_Less(*Biology);
    str = "";
    cout << "Добавить этот предмет ученику? (д - добавить, другой набор символов - нет): ";
    cin >> str;
    if (str == "д")
    {
        if (add_Less_to_Stud(*st2, *Biology))
        {
            cout << "Урок добавлен!" << endl;
            cout << endl;
            cout << "Добавить оценку (1,2,3,4,5 - добавить, другой набор символов - нет):" << endl;
            str = "";
            cin >> str;
            Mark mr;
            init_m(mr);
            mr.Value = stoi(str);
            if ((mr.Value >= 1) || (mr.Value <= 5))
            {
                if (add_Mark_to_Stud(*st2, *Biology, mr))
                    cout << "Оценка добавлена!" << endl;
                else
                    cout << "Оценка не добавлена!" << endl;

            }
        }
        else
            cout << "Урок не добавлен!" << endl;
    }
    else
        cout << "Урок не добавлен!" << endl;
    cout << endl;
    cout << endl;
    cout << "Вывод:" << endl;
    out_Stud(*st2, 1);

    cout << endl;
    cout << "Третий ученик:" << endl;
    inp_FIO_Stud(st3);
    cout << endl;
    cout << "Выберите, какие уроки у первого ученика:" << endl;
    out_Less(Chem);
    str = "";
    cout << "Добавить этот предмет ученику? (д - добавить, другой набор символов - нет): ";
    cin >> str;
    if (str == "д")
    {
        if (add_Less_to_Stud(st3, Chem))
        {
            cout << "Урок добавлен!" << endl;
            cout << endl;
            cout << "Добавить оценку (1,2,3,4,5 - добавить, другой набор символов - нет):" << endl;
            str = "";
            cin >> str;
            Mark mr;
            init_m(mr);
            mr.Value = stoi(str);
            if ((mr.Value >= 1) || (mr.Value <= 5))
            {
                if (add_Mark_to_Stud(st3, Chem, mr))
                    cout << "Оценка добавлена!" << endl;
                else
                    cout << "Оценка не добавлена!" << endl;

            }
        }
        else
            cout << "Урок не добавлен!" << endl;
    }
    else
        cout << "Урок не добавлен!" << endl;
    cout << endl;
    cout << endl;
    cout << "Вывод:" << endl;
    out_Stud(st3, 1);

    cout << endl;
    cout << "Выберите, какие уроки у первого ученика:" << endl;
    cout << endl;
    out_Less(*Biology);
    str = "";
    cout << "Добавить этот предмет ученику? (д - добавить, другой набор символов - нет): ";
    cin >> str;
    if (str == "д")
    {
        if (add_Less_to_Stud(st3, *Biology))
        {
            cout << "Урок добавлен!" << endl;
            cout << endl;
            cout << "Добавить оценку (1,2,3,4,5 - добавить, другой набор символов - нет):" << endl;
            str = "";
            cin >> str;
            Mark mr;
            init_m(mr);
            mr.Value = stoi(str);
            if ((mr.Value >= 1) || (mr.Value <= 5))
            {
                if (add_Mark_to_Stud(st3, *Biology, mr))
                    cout << "Оценка добавлена!" << endl;
                else
                    cout << "Оценка не добавлена!" << endl;

            }
        }
        else
            cout << "Урок не добавлен!" << endl;
    }
    else
        cout << "Урок не добавлен!" << endl;
    cout << endl;
    cout << endl;
    cout << "Вывод:" << endl;
    out_Stud(st3, 1);
    
   

    cout << "===================================================" << endl;

    cout << endl;
    cout << endl;

    cout << "=======================Тест структуры Класс============================" << endl;
    cout << "Создайте 2 класса учеников:" << endl;
    cout << endl;
    Class_ cl1;
    Class_* cl2 = new Class_;

    init_c(cl1);
    init_c(*cl2);

    cout << "Введите данные для первого класса" << endl;
    inp_Class_(cl1);
    cout << endl;
    out_Stud(st1, 1);
    cout << "Добавить данного ученика в класс? (д - добавить, другой набор символов - нет): ";
    str = "";
    cin >> str;
    if (str == "д")
    {
        if (add_St_to_Cl(cl1, st1))
        {
            cout << "Ученик добавлен!" << endl;
            cout << endl;
        }
        else
            cout << "Ученик не добавлен!" << endl;
    }
    else
        cout << "Ученик не добавлен!" << endl;
    cout << endl;

    cout << endl;
    out_Stud(*st2, 1);
    cout << "Добавить данного ученика в класс? (д - добавить, другой набор символов - нет): ";
    str = "";
    cin >> str;
    if (str == "д")
    {
        if (add_St_to_Cl(cl1, *st2))
        {
            cout << "Ученик добавлен!" << endl;
            cout << endl;
        }
        else
            cout << "Ученик не добавлен!" << endl;
    }
    else
        cout << "Ученик не добавлен!" << endl;
    cout << endl;

    cout << endl;
    out_Stud(st3, 1);
    cout << "Добавить данного ученика в класс? (д - добавить, другой набор символов - нет): ";
    str = "";
    cin >> str;
    if (str == "д")
    {
        if (add_St_to_Cl(cl1, st3))
        {
            cout << "Ученик добавлен!" << endl;
            cout << endl;
        }
        else
            cout << "Ученик не добавлен!" << endl;
    }
    else
        cout << "Ученик не добавлен!" << endl;
    cout << endl;
    cout << endl;
    cout << "Вывод класаа №2" << endl;
    out_Class_(cl1, 1);

    cout << endl;
    cout << endl;
    cout << endl;


    cout << "Введите данные для второго класса" << endl;
    inp_Class_(*cl2);
    cout << endl;
    out_Stud(st1, 1);
    cout << "Добавить данного ученика в класс? (д - добавить, другой набор символов - нет): ";
    str = "";
    cin >> str;
    if (str == "д")
    {
        if (add_St_to_Cl(*cl2, st1))
        {
            cout << "Ученик добавлен!" << endl;
            cout << endl;
        }
        else
            cout << "Ученик не добавлен!" << endl;
    }
    else
        cout << "Ученик не добавлен!" << endl;
    cout << endl;

    cout << endl;
    out_Stud(*st2, 1);
    cout << "Добавить данного ученика в класс? (д - добавить, другой набор символов - нет): ";
    str = "";
    cin >> str;
    if (str == "д")
    {
        if (add_St_to_Cl(*cl2, *st2))
        {
            cout << "Ученик добавлен!" << endl;
            cout << endl;
        }
        else
            cout << "Ученик не добавлен!" << endl;
    }
    else
        cout << "Ученик не добавлен!" << endl;
    cout << endl;

    cout << endl;
    out_Stud(st3, 1);
    cout << "Добавить данного ученика в класс? (д - добавить, другой набор символов - нет): ";
    str = "";
    cin >> str;
    if (str == "д")
    {
        if (add_St_to_Cl(*cl2, st3))
        {
            cout << "Ученик добавлен!" << endl;
            cout << endl;
        }
        else
            cout << "Ученик не добавлен!" << endl;
    }
    else
        cout << "Ученик не добавлен!" << endl;
    cout << endl;
    cout << endl;
    cout << "Вывод класаа №2" << endl;
    cout << endl;
    out_Class_(*cl2, 1);

    cout << "===================================================" << endl;

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "************************Функция поиска лучших учеников в классе***************************" << endl;

    cout << "Лучшие ученики класса №1:" << endl;
    Best_Stud_inClass(cl1);
    cout << endl;
    cout << endl;
    cout << "Лучшие ученики класса №2:" << endl;
    Best_Stud_inClass(*cl2);

    cout << "***************************************************" << endl;

    cout << endl;
    cout << endl;
    cout << endl;

    cout << "************************Функция поиска худших учеников в классе***************************" << endl;

    cout << "Худшие ученики класса №1:" << endl;
    Bed_Stud_inClass(cl1);
    cout << endl;
    cout << endl;
    cout << "Худшие ученики класса №2:" << endl;
    Bed_Stud_inClass(*cl2);

    cout << "***************************************************" << endl;
}
