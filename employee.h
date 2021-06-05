/* Employee Header File */
#pragma once

#include <cmath>
#include <iostream>

using namespace std;

class Employee {
   protected:
    const double SALARY_BUDGET = 14000;

    string empName;
    int empID;
    char empClass;
    double empSalary;
    double moneyGained = 0;

   public:
    Employee(istream &in);

    virtual void print(ostream &out) const;
    virtual void calcSalary(const double budget, const double profit) = 0;

    /* Getters */
    double getSalaryBudget() const { return SALARY_BUDGET; }
    string getEmpName() const { return empName; }
    int getEmpID() const { return empID; }
    char getEmpClass() const { return empClass; }
    double getEmpSalary() const { return empSalary; }

    /* Setters */
    void setEmpName(string _name) { empName = _name; }
    void setEmpID(int _id) { empID = _id; }
    void setEmpClass(char _class) { empClass = _class; }
    void setEmpSalary(double _salary) { empSalary = _salary; }
};

Employee::Employee(istream &in) {
    cout << "Employee's name: ";
    in >> empName;

    cout << "Employee's ID: ";
    in >> empID;
}

void Employee::print(ostream &out) const {
    out << "Name: " << empName << "\n"
        << "Employee ID: " << empID << "\n";

    string printEmpClass;
    switch (empClass) {
        case 'O':
            printEmpClass = "Owner";
            break;
        case 'C':
            printEmpClass = "Chef";
            break;
        case 'W':
            printEmpClass = "Waiter";
            break;
        default:
            printEmpClass = "Undefined";
            break;
    }

    out << "Employee Class: " << printEmpClass << "\n"
        << "Salary: " << empSalary << " GEL";
}