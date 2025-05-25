#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    // Make input and display virtual for polymorphism
    virtual void input() {
        cout << "Enter name and age: ";
        cin >> name >> age;
    }

    virtual void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    // Virtual destructor for safe polymorphic deletion (good practice)
    virtual ~Person() {}
};

class Student : public Person {
    string course;
    int marks;
    int year;

public:
    void input() override {
        Person::input();
        cout << "Enter course: ";
        cin >> course;
        cout << "Enter marks: ";
        cin >> marks;
        cout << "Enter year: ";
        cin >> year;
    }

    void display() override {
        Person::display();
        cout << "Course: " << course << ", Marks: " << marks << ", Year: " << year << endl;
    }
};

class Employee : public Person {
    string department;
    int salary;

public:
    void input() override {
        Person::input();
        cout << "Enter department: ";
        cin >> department;
        cout << "Enter salary: ";
        cin >> salary;
    }

    void display() override {
        Person::display();
        cout << "Department: " << department << ", Salary: " << salary << endl;
    }
};

int main() {
    Person* p;    // base class pointer for runtime polymorphism
    Student s;
    Employee e;

    cout << "Enter student details:\n";
    p = &s;
    p->input();

    cout << "\nEnter employee details:\n";
    p = &e;
    p->input();

    cout << "\nStudent Details:\n";
    p = &s;
    p->display();

    cout << "\nEmployee Details:\n";
    p = &e;
    p->display();

    return 0;
}
