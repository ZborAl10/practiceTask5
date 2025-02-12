// прим.: проект работает на стандарте c++20, т.к. имеет функцию библиотеки format.

#include <iostream>
#include <string>
#include <vector>
#include <format>

using namespace std;

class Student {
    // поля класса
    string name;
    int age;
    int midmark;
    
    public:
    // конструктор класса
    Student(string _name, int _age, int _midmark) : 
        name(_name), age(_age), midmark(_midmark) {};

    // геттеры
    string getName() { return name; }
    int getAge() { return age; }
    int getMidMark() { return midmark; }

    // сеттеры
    void setName(string _name) { name = _name; }
    void setAge(int _age) { age = _age; }
    void setMidMark(int _midmark) { midmark = _midmark; }

    // метод вывода информации о студенте
    void PrintInfo();

    //метод подсчета оценки студента
    string CalculateMark();        
};

// реализация PrintInfo()
void Student::PrintInfo() {
    cout << "ФИО: " << getName() << '\n'
         << "Возраст: " << getAge() << '\n'
         << "Средний балл: " << getMidMark() << "\n\n";
}

// реализация CalculateMark()
string Student::CalculateMark() {
    string mark = "Неудовлетворительно";
    if (midmark > 8) mark = "Отлично";
    else if (midmark > 5) mark = "Хорошо";
    else if (midmark > 3) mark = "Удовлетворительно";
    return mark;
}

// дополнительный метод вывода оценок всех студентов
void PrintAllMarks(vector<Student> s) {
    cout << format("{:<35}|{:<15}|{}\n", "ФИО", "Средний балл", "Оценка");
    for (auto _s : s) {
        cout << format("{:<35}|{:<15}|{}\n", _s.getName(), _s.getMidMark(), _s.CalculateMark());
    }
    cout << '\n';
}

//тестирование возможностей класса и дополнительных функций
int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Student s1("Иванов Иван Иванович", 18, 5);
    Student s2("Петров Петр Петрович", 19, 9);
    Student s3("Сидоров Сидор Сидорович", 24, 2);
    Student s4("Зборовская Алиса Сергеевна", 22, 7);
    
    s1.PrintInfo();
    s2.PrintInfo();
    s3.PrintInfo();

    cout << "Я - " << s4.getName() << ", мне " << s4.getAge() << " года, и у меня " << s4.getMidMark() << " баллов.\n\n";

    cout << "У студента " << s1.getName() << " оценка - " << s1.CalculateMark() << ".\n\n";

    s3.setName("Сидоров Сид Сидорович");
    s2.setMidMark(10);
    s1.setAge(19);

    cout << "ОБНОВЛЕНАЯ ИНФОРМАЦИЯ:\n\n";
    s1.PrintInfo();
    s2.PrintInfo();
    s3.PrintInfo();

    vector<Student> s = {s1, s2, s3, s4};
    PrintAllMarks(s);

    system("pause");
    return 0;
}