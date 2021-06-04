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
    emp = new Chef(ifs);
    empList.push_back(emp);

    emp = new Chef(ifs);
    empList.push_back(emp);

    emp = new Waiter(ifs);
    empList.push_back(emp);

    emp = new Waiter(ifs);
    empList.push_back(emp);

    /* Printing out starting details about employees */
    ofstream ofs("output.txt");
    list<Employee *>::iterator it;
    cout << "<<< RESTAURANT EMPLOYEES >>>\n\n";
    ofs << "<<< RESTAURANT EMPLOYEES >>>\n\n";
    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        emp->print(cout);
        emp->print(ofs);
    }

    /* Printing out details to file and console after monthly profit */

    /* <<< MONTH 1 >>> */
    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        emp->print(ofs);
    }
    ofs << "--------------------------------\n\n";

    cout << "Enter restaurant profit: ";
    double profit;
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

    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        emp->print(cout);
    }
    cout << "--------------------------------\n\n";
}