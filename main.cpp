/* Driver File */
#include <fstream>
#include <iostream>
#include <list>

#include "chef.h"
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

    /* Printing out employee details to console and file */
    ofstream ofs("output.txt");
    cout << "RESTAURANT STAFF\n";
    cout << "----------------\n";
    ofs << "RESTAURANT STAFF\n";
    ofs << "----------------\n";
    list<Employee *>::iterator it;
    for (it = empList.begin(); it != empList.end(); it++) {
        emp = *it;
        emp->print(ofs);
        emp->print(cout);
    }

    /* Printing out employee details after monthly profit */
    double budget = emp->getSalaryBudget(), profit;

    for (int i = 1; i <= 3; i++) {
        cout << "MONTH " << i << "\n";
        ofs << "MONTH " << i << "\n";
        cout << "-------\n";
        ofs << "-------\n";

        /* Entering profit and tips */
        cout << "Enter restaurant profit: ";
        cin >> profit;
        budget += profit;

        /* If budget gets less then zero, restaurant goes bankrupt */
        if (budget <= 0) {
            cout << "\n*RESTAURANT WENT BANKRUPT*\n";
            ofs << "\n*RESTAURANT WENT BANKRUPT*\n";
            return 0;
        }

        /* Calling calcSalary() for every employee */
        for (it = empList.begin(); it != empList.end(); it++) {
            emp = *it;
            emp->calcSalary(budget, profit);
        }
        cout << endl;

        /* Printing out employee details to console and file */
        cout << "BUDGET: " << budget << "\n\n";
        ofs << "BUDGET: " << budget << "\n\n";

        for (it = empList.begin(); it != empList.end(); it++) {
            emp = *it;
            emp->print(ofs);
            emp->print(cout);
        }
    }
}