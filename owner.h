/* Owner Header File */
#pragma once
#include "employee.h"

class Owner : public Employee {
   public:
    Owner(istream &in);

    void print(ostream &out) const override;
    void calcSalary(const double budget, const double profit);
};

Owner::Owner(istream &in) : Employee(in) {
    empClass = 'O';
    empSalary = 5000;

    cout << "*New owner created*\n" << endl;
}

void Owner::print(ostream &out) const {
    Employee::print(out);

    if (moneyGained < 0) {
        out << " - " << -moneyGained << " GEL (loss)";
    } else {
        out << " + " << moneyGained << " GEL";
        if (moneyGained > 0) out << " (profit)";
    }
    
    out << " = " << empSalary + moneyGained << " GEL\n\n";
}

void Owner::calcSalary(const double budget, const double profit) {
    if (budget <= SALARY_BUDGET) {
        moneyGained =
            ceil((budget * empSalary / SALARY_BUDGET - empSalary) * 100) / 100;
    } else if (profit <= 0) {
        moneyGained = 0;
    } else {
        moneyGained = profit * 0.6;
    }
}