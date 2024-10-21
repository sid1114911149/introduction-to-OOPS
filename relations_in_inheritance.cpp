#include <iostream>
#include <string>
using namespace std;

// Base class Employee
class Employee {
protected:
    string name;
    int id;
    double salary;

public:
    // Constructor
    Employee(const string& empName = "", int empId = 0, double empSalary = 0.0) 
        : name(empName), id(empId), salary(empSalary) {}

    // Method to input employee details
    virtual void inputDetails() {
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Salary: ";
        cin >> salary;
        cin.ignore(); // to handle the newline after salary input
    }

    // Virtual method to display employee details
    virtual void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: $" << salary << endl;
    }

    // Virtual destructor
    virtual ~Employee() {}
};

// Derived class Manager
class Manager : public Employee {
private:
    int numEmployeesManaged;

public:
    // Constructor
    Manager(const string& mgrName = "", int mgrId = 0, double mgrSalary = 0.0, int numEmployees = 0)
        : Employee(mgrName, mgrId, mgrSalary), numEmployeesManaged(numEmployees) {}

    // Method to input manager-specific details
    void inputDetails() override {
        Employee::inputDetails();  // Input general employee details
        cout << "Enter Number of Employees Managed: ";
        cin >> numEmployeesManaged;
        cin.ignore();  // Handle newline after number input
    }

    // Method to display manager-specific details
    void displayDetails() const override {
        Employee::displayDetails();  // Display general employee details
        cout << "Number of Employees Managed: " << numEmployeesManaged << endl;
    }
};

// Derived class Engineer
class Engineer : public Employee {
private:
    string department;

public:
    // Constructor
    Engineer(const string& engName = "", int engId = 0, double engSalary = 0.0, const string& dept = "")
        : Employee(engName, engId, engSalary), department(dept) {}

    // Method to input engineer-specific details
    void inputDetails() override {
        Employee::inputDetails();  // Input general employee details
        cout << "Enter Department: ";
        getline(cin, department);  // Use getline to handle spaces in department name
    }

    // Method to display engineer-specific details
    void displayDetails() const override {
        Employee::displayDetails();  // Display general employee details
        cout << "Department: " << department << endl;
    }
};

int main() {
    // Creating Manager object
    Manager mgr;
    cout << "Enter Manager Details:" << endl;
    mgr.inputDetails();
    
    // Creating Engineer object
    Engineer eng;
    cout << "\nEnter Engineer Details:" << endl;
    eng.inputDetails();

    // Display Manager and Engineer details
    cout << "\nManager Information:" << endl;
    mgr.displayDetails();
    
    cout << "\nEngineer Information:" << endl;
    eng.displayDetails();

    return 0;
}