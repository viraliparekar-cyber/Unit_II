#include <iostream>   // Includes the input/output stream library
#include <string>     // Provides the string data type
#include <utility>    // Provides std::move()

// Base class
class Person
{
protected:
    std::string name;  // Stores the name of the person

public:
    // Constructor of Person class
    explicit Person(std::string personName)
        : name(std::move(personName))
    {
    }

    // Function to display the person's name
    void displayName() const
    {
        std::cout << "Name: " << name << '\n';
    }
};

// Derived class Student inherits from Person
class Student : public Person
{
private:
    int rollNumber;  // Stores the student's roll number

public:
    // Constructor of Student class
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll)
    {
    }

    // Function to display student information
    void displayStudent() const
    {
        displayName();  // Calls the displayName() function inherited from Person

        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

int main()
{
    // Creates a Student object with name "Amit" and roll number 101
    Student student("Amit", 101);

    // Calls the function to display student information
    student.displayStudent();

    return 0;  // Indicates successful execution of the program
}
