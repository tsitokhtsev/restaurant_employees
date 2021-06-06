/* Waiter Header File */
#pragma once
#include "employee.h"

class Waiter : public Employee {
    double empTip = 0;
    int empWorkExp;

   public:
    Waiter(istream &in);

    void print(ostream &out) const override;
    void calcSalary(const double budget, const double profit) override;

    int getEmpWorkExp() { return empWorkExp; }
    void setEmpWorkExp(int _work_exp) { empWorkExp = _work_exp; }
};

Waiter::Waiter(istream &in) : Employee(in) {
    empClass = 'W';
    empSalary = 1000;

    cout << "Waiter's work experience (in years): ";
    in >> empWorkExp;

    cout << "*New waiter created*\n\n";
}

void Waiter::print(ostream &out) const {
    Employee::print(out);

    if (empTip > 0) out << " + " << empTip << " GEL (tip)";

    if (moneyGained != 0 || empTip != 0) {
        out << " = " << empSalary + moneyGained + empTip << " GEL\n"
            << "Work Experience: " << empWorkExp << " year(s)\n\n";
    } else {
        out << "\n\n";
    }
}

void Waiter::calcSalary(const double budget, const double profit) {
    cout << "Enter tip for " << empName << ": ";
    cin >> empTip;

    if (budget < SALARY_BUDGET || profit < 0) {
        Employee::calcSalary(budget, profit);
    } else {
        moneyGained = 0;
    }
}