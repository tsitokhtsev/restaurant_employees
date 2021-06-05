/* Driver */
#include <fstream>
#include <iostream>
#include <list>

#include "chef.h"
#include "employee.h"
#include "owner.h"
#include "waiter.h"

using namespace std;

int main() {
    /* Pointer and list initialization */
    Employee *emp;
    list<Employee *> empList;

    /* Creating employee objects from file... */
    ifstream ifs("employees.txt");

    emp = new Owner(ifs);
    empList.push_back(emp);

    emp = new Chef(ifs);
    empList.push_back(emp);

    emp = new Waiter(ifs);
    empList.push_back(emp);

    /* ...and using 'cin' */
    emp = new Chef(cin);
    empList.push_back(emp);

    emp = new Waiter(cin);
    empList.push_back(emp);

    emp = new Waiter(cin);
    empList.push_back(emp);

    /* Printing out employee details to console and file after monthly profit */
    ofstream ofs("output.txt");
    list<Employee *>::iterator it;

    cout << "MONTH 1\n";
    ofs << "MONTH 1\n";
    cout << "-------\n";
    ofs << "-------\n";

    /* Entering profit and tips */
    double profit;

    cout << "Enter restaurant profit: ";
    cin >> profit;
    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        if (emp->getEmpClass() == 'W') {
            cout << "Enter tip for " << emp->getEmpName() << ": ";
            double tip;
            cin >> tip;
            emp->calcSalary(tip);
        } else {
            emp->calcSalary(profit);
        }
    }
    cout << endl;

    /* Printing out */
    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        emp->print(ofs);
        emp->print(cout);
    }

    cout << "MONTH 2\n";
    ofs << "MONTH 2\n";
    cout << "-------\n";
    ofs << "-------\n";

    /* Entering profit and tips */
    cout << "Enter restaurant profit: ";
    cin >> profit;
    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        if (emp->getEmpClass() == 'W') {
            cout << "Enter tip for " << emp->getEmpName() << ": ";
            double tip;
            cin >> tip;
            emp->calcSalary(tip);
        } else {
            emp->calcSalary(profit);
        }
    }
    cout << endl;

    /* Printing out */
    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        emp->print(ofs);
        emp->print(cout);
    }

    cout << "MONTH 3\n";
    ofs << "MONTH 3\n";
    cout << "-------\n";
    ofs << "-------\n";

    /* Entering profit and tips */
    cout << "Enter restaurant profit: ";
    cin >> profit;
    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        if (emp->getEmpClass() == 'W') {
            cout << "Enter tip for " << emp->getEmpName() << ": ";
            double tip;
            cin >> tip;
            emp->calcSalary(tip);
        } else {
            emp->calcSalary(profit);
        }
    }
    cout << endl;

    /* Printing out */
    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        emp->print(ofs);
        emp->print(cout);
    }
}