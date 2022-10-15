/*
FILE: poly.cpp
CLASS IMPLEMENTED: poly
NAMESPACE: wmacnab_4_poly
*/

#include <algorithm> // Provides std::copy()
#include <cmath> // Provides std::pow()
#include "poly.h"

namespace wmacnab_4_poly
{
    // TYPEDEFS
    static unsigned int INIT_MAX_COEF = poly::INIT_MAX_COEF;
    // CONSTRUCTORS
    poly::poly()
    {
        coef = new double[INIT_MAX_COEF + 1];
        allocated = INIT_MAX_COEF + 1;
        //current_degree = 0;
        set_degree();
    }
    poly::poly(double a0)
    {
        coef = new double[INIT_MAX_COEF + 1];
        allocated = INIT_MAX_COEF + 1;
        //current_degree = 0;
        set_degree();
        coef[0] = a0;
    }
    poly::poly(const poly& source)
    {
        allocated = source.allocated;
        coef = new double[allocated];
        std::copy(source.coef, source.coef + source.allocated, coef);
        //current_degree = source.current_degree;
        set_degree();
    }
    poly::~poly()
    {
        delete [] coef;
    }
    // MODIFICATION METHODS
    void poly::add_to_coef(double addend, unsigned int k)
    {
        if (k >= allocated) reserve(k + 1);
        coef[k] += addend;
        set_degree();
    }
    void poly::assign_coef(double a, unsigned int k)
    {
        if (k >= allocated) reserve(k + 1);
        coef[k] = a;
        set_degree();
    }
    void poly::clear()
    {
        for (unsigned int i = 0; i <= degree() && i < allocated; ++i) coef[i] = 0;
        set_degree();
    }
    void poly::reserve(unsigned int n)
    {
        if (n <= allocated) return; // Already have that much allocated
        double *bigger_array = new double[n];
        std::copy(coef, coef + allocated, bigger_array);
        delete [] coef;
        coef = bigger_array;
        allocated = n;
    }
    // CONSTANT METHODS
    double poly::coefficient(unsigned int k) const
    {
        if (k >= allocated) return 0;
        return coef[k];
    }
    unsigned int poly::degree() const { return current_degree; }
    unsigned int poly::next_term(unsigned int k) const
    {
        for (unsigned int i = k + 1; i < degree(); ++i)
        {
            if (coef[i] != 0) return i;
        }
        return UINT_MAX;
    }
    double poly::eval(double x) const
    {
        double result = 0;
        for (unsigned int i = 1; i <= degree(); ++i)
        {
            if (coefficient(i) != 0) result += pow(coefficient(i) * x, i);
        }
        result += coefficient(0);
        return result;
    }
    double poly::operator ()(double x) const
    {
        return eval(x);
    }
    poly poly::derivative() const
    {
        poly d(*this);
        d.clear();
        for (unsigned int i = 1; i <= degree(); ++i)
        {
            if (coef[i] != 0)
            {
                d.coef[i - 1] = i * coefficient(i);
            }
        }
        d.set_degree();
        return d;
    }
    // OPERATOR OVERLOAD METHODS
    poly& poly::operator =(const poly& source)
    {
        if (this == &source) return *this; // Assigning to itself
        if (allocated < source.allocated) reserve(source.allocated);
        clear();
        std::copy(source.coef, source.coef + allocated, coef);
        set_degree();
        return *this;
    }
    poly& poly::operator =(double a0)
    {
        clear();
        set_degree();
        coef[0] = a0;
        return *this;
    }
    // OPERATOR OVERLOAD FUNCTIONS
    poly operator +(const poly& p1, const poly& p2)
    {
        poly sum;
        (p1.degree() > p2.degree()) ? sum.reserve(p1.degree()) : sum.reserve(p2.degree());
        for (unsigned int i = 0; i <= p1.degree() + 1 && i <= p2.degree() + 1; ++i)
        {
            sum.assign_coef(p1.coefficient(i) + p2.coefficient(i), i);
        }
        return sum;
    }
    poly operator -(const poly& p1, const poly& p2)
    {
        poly dif;
        (p1.degree() > p2.degree()) ? dif.reserve(p1.degree()) : dif.reserve(p2.degree());
        for (unsigned int i = 0; i <= p1.degree() && i <= p2.degree(); ++i)
        {
            dif.assign_coef(p1.coefficient(i) - p2.coefficient(i), i);
        }
        return dif;
    }
    poly operator *(const poly& p1, const poly& p2)
    {
        poly p;
        return p;
    }
    std::ostream& operator <<(std::ostream& outs, const poly& p)
    {
        for (unsigned int i = p.degree(); i > 0; --i)
        {
            if (p.coefficient(i) != 0)
            {
                if (p.coefficient(i) != 1) outs << p.coefficient(i);
                if (i > 0) outs << "x";
                if (i > 1) outs << "^" << i;
                outs << " + ";
            }
        }
        if (p.coefficient(0) != 0) outs << p.coefficient(0);
        else outs << "\b\b ";
        return outs;
    }
    // HELPER METHODS
    void poly::set_degree()
    {
        for (unsigned int i = allocated - 1; i != 0; --i)
        {
            if (coef[i] != 0)
            {
                current_degree = i;
                return;
            }
        }
    }
    double poly::pow(double a, unsigned int k) const
    {
        if (k == 0) return 1;
        return a * pow(a, k - 1);
    }
}