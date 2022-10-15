/*
FILE: employee.cpp
CLASS IMPLEMENTED: employee
NAMESPACE: wmacnab_2_18
*/

#include "employee.h"

namespace wmacnab_2_18
{
    // CONSTRUCTOR
    employee::employee(std::string init_name = "", unsigned int init_id = 0, double init_wage = 0)
    {
        name = init_name;
        id = init_id;
        wage = init_wage;
    }

    // MODIFICATION METHODS
    void employee::give_raise(const double& p)
    {
        wage *= (1 + (p/100));
    }

    void employee::set_wage(const double& w)
    {
        wage = w;
    }

    // CONSTANT METHODS
    double employee::get_salary() const
    {
        return (wage * 2000);
    }

    double employee::get_paycheck(const double& hrs) const
    {
        double sum = 0;
        if (hrs > 80)
        {
            sum += (80 * wage);
            sum += (((hrs - 80) * wage) * 1.2);
        }
        else sum =+ hrs * wage;
        return sum;
    }
}