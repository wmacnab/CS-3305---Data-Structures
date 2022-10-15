/*
FILE: poly.h
CLASS IMPLEMENTED: poly
NAMESPACE: wmacnab_4_poly
*/

#ifndef WMACNAB_POLY_H
#define WMACNAB_POLY_H
#include <cctype>
#include <climits> // Provides UINT_MAX
#include <iostream>

namespace wmacnab_4_poly
{
    class poly
    {
    public:
        // TYPEDEFS
        const static unsigned int INIT_MAX_COEF = 10;
        // CONSTRUCTORS
        poly();
        poly(double a0);
        poly(const poly& source);
        ~poly();
        // MODIFICATION METHODS
        void add_to_coef(double addend, unsigned int k);
        void assign_coef(double a, unsigned int k);
        void clear();
        void reserve(unsigned int n);
        // CONSTANT METHODS
        double coefficient(unsigned int k) const;
        unsigned int degree() const;
        unsigned int next_term(unsigned int k) const; // Returns next term with non-zero coef
        double eval(double x) const;
        double operator ()(double x) const;
        poly derivative() const;
        // OPERATOR OVERLAODS
        poly& operator =(const poly& source); // return poly& to enable chained = operations
        poly& operator =(double a0); // Prevents overhead of auto conversion to constructor
        // Operator overloads for +, -, /
    private:
        double *coef;
        unsigned int allocated;
        unsigned int current_degree;
        // HELPER METHODS
        void set_degree();
        double pow(double a, unsigned int k) const;
    };
    poly operator +(const poly& p1, const poly& p2);
    poly operator -(const poly& p1, const poly& p2);
    poly operator *(const poly& p1, const poly& p2);
    std::ostream& operator <<(std::ostream& outs, const poly& p);
}

#endif