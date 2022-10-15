/*
Name: William MacNab
Date: 10 September 2021
Book: Data Structures and Other Objects Using C++ by Michael Main and Walter Savitch
Programming project: Chapter 2, Programming Project 18
Programming project statement:
Specify, design, and implement a class called employee . The class has data mem-
bers for the employee's name, ID number, and salary based on an hourly wage. Member func-
tions include computing the yearly salary and increasing the salary by a certain percentage. Add
additional data members to store biweekly paycheck information and calculate overtime (for over 40
hours per week) for each paycheck.
*/

/*
FILE: employee.h
CLASS IMPLEMENTED: employee
NAMESPACE: wmacnab_2_18
*/

#ifndef WMACNAB_EMPLOYEE_H
#define WMACNAB_EMPLOYEE_H
#include <string>

namespace wmacnab_2_18
{
    class employee
    {
    public:
        // CONSTRUCTORS
        employee(std::string init_name = "", unsigned int init_id = 0, double init_wage = 0);

        // MODIFICATION METHODS
        void give_raise(const double& p);
        void set_wage(const double& w);

        // CONSTANT METHODS
        double get_salary() const;
        double get_paycheck(const double& hrs) const;
    private:
        std::string name;
        unsigned int id;
        double wage, yr_salary, biwk_pay;
    };
}

#endif