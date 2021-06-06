/* Chef Header File */
#pragma once
#include "employee.h"

class Chef : public Employee {
    string empCookExp;

   public:
    Chef(istream &in);

    void print(ostream &out) const override;
    void calcSalary(const double budget, const double profit);

    string getEmpCookExp() { return empCookExp; }
    void setEmpCookExp(string _cook_exp) { empCookExp = _cook_exp; }
};

Chef::Chef(istream &in) : Employee(in) {
    empClass = 'C';
    empSalary = 3000;

    cout << "Chef's cooking experience: ";
    in >> empCookExp;

    cout << "*New chef created*\n\n";
}

void Chef::print(ostream &out) const {
    Employee::print(out);

    if (moneyGained > 0) {
        out << " + " << moneyGained
            << " GEL (profit) = " << empSalary + moneyGained << " GEL\n";
    } else
        out << "\n";

    out << "Cooking Experience: " << empCookExp << "\n\n";
}

void Chef::calcSalary(const double budget, const double profit) {
    if (budget < SALARY_BUDGET || profit < 0) {
        Employee::calcSalary(budget, profit);
    } else {
        moneyGained = profit * 0.2;
    }
}