#ifndef OPERATIONS_H
#define OPERATIONS_H

typedef struct{
    double num1;
    char op[10];
    double num2;
    double res;
}Operation;

extern const double PI;

double addition(double num1, double num2);
double subtraction(double num1, double num2);
double multiplication(double num1, double num2);
double division(double num1, double num2);
double power(double num1, double num2);
int int_remainder (int rnum1, int rnum2);
double sqroot(double num1);
long long factorial(double num1);
void store(Operation opp);
void delete_history(void);
void read_history(void);
double to_rad(double angle);
double to_deg(double angle);
void exponent(double power);
double trig(double num, char* op, double (*func)(double), int mo);
double rev_trig(double num, char* op, double (*func)(double), int mo);
double clean_zero(double x);
double mplus(double num);
double mminus(double num);
double show(double mem);
void clearmem(void);
void clean_input_buffer(void);
int read_double(double *number);
int read_int(int *num);

#endif