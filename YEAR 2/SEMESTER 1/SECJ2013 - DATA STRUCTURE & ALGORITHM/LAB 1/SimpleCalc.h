#ifndef SIMPLECALC_H
#define SIMPLECALC_H

class SimpleCalc {
    private: 
    double num1;
    double num2;

    public:
    SimpleCalc(double n1, double n2);

    double add();
    double substract();
    double multiply();
    double divide();
};

#endif 