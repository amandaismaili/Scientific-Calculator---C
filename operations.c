#include <stdio.h>
#include <math.h>
#include <string.h>
#include "operations.h"

double memory = 0.0;

double addition(double num1, double num2) {
    return num1 + num2;
}

double subtraction(double num1, double num2) {
    return num1 - num2;
}

double multiplication(double num1, double num2) {
    return num1 * num2;
}

double division(double num1, double num2) {
    return num1 / num2;
}

double power(double num1, double num2) {
    return pow(num1, num2);
}

int int_remainder (int rnum1, int rnum2) {
    return rnum1 % rnum2;
}

double sqroot(double num1) {
    return sqrt(num1);
}

long long factorial (double num1){
    long long a = 1;
    for(int i = 1; i<=num1; i++){
        a*=i;
    }
    return a;
}

void store(Operation opp){
    FILE *pF = fopen("history.txt", "a");

    if (pF == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    if (strcmp(opp.op, "sqrt") == 0 ||strcmp(opp.op, "sin") == 0 || strcmp(opp.op, "cos") == 0 || strcmp(opp.op, "tan") == 0 
        || strcmp(opp.op, "asin") == 0 || strcmp(opp.op, "acos") == 0 || strcmp(opp.op, "atan") == 0 || strcmp(opp.op, "ln") == 0 || strcmp(opp.op, "log10") == 0){
        fprintf(pF, "%s(%.2f) = %.2f\n", opp.op, opp.num1, opp.res);
    } else if (strcmp(opp.op, "!") == 0) {
        fprintf(pF, "%.0f! = %.0f\n", opp.num1, opp.res);
    } else if (strcmp(opp.op, "e") == 0){
        fprintf(pF, "%s^ %.2f = %.2f\n", opp.op, opp.num1, opp.res);
    } 
    else {
        fprintf(pF, "%.2f %s %.2f = %.2f\n", opp.num1, opp.op, opp.num2, opp.res);
    }

    fclose(pF);
}

void read_history(void){
    FILE *pF = fopen("history.txt", "r");

    if(!pF){
        printf("No history found.\n");
        return;
    }

    char line[250];
    int found = 0;
    while (fgets(line, 250, pF) != NULL){
        printf("%s", line);
        found = 1;
    } 
    if (!found) printf("No history recorded yet.\n");
    fclose(pF);
}

void delete_history(void){
    FILE *pF = fopen("history.txt", "w");

    if (!pF){
        printf("No history found.\n");
        return;
    }

    fclose(pF);
}

double to_rad(double angle) {
    return angle * PI / 180.0;
}

double to_deg(double angle) {
    return angle * 180.0 / PI;
}

void exponent(double power) {
    double answ = exp(power);
    printf("The answer is %.2lf.\n", answ);

    Operation expp; 
    expp.num1 = power;
    expp.num2 = 0;
    expp.res = answ;
    strcpy(expp.op, "e");
    store(expp); 
}

double trig(double num, char* op, double (*func)(double), int mo){
    double answ = !mo ? func(to_rad(num)) : func(num);
    answ = clean_zero(answ);
    printf("The answer is %.2lf.\n", answ);
 
    Operation trigo;
    trigo.num1 = num;
    trigo.num2 = 0;
    trigo.res = answ;
    strcpy(trigo.op, op);
    store(trigo); 
    return answ;
}

double rev_trig(double num, char* op, double(*func)(double), int mo){
    if (strcmp(op, "asin") == 0 || strcmp(op, "acos") == 0){
        if (num < -1 || num > 1) {
            printf("Input must be between -1 and 1.\n");
                return 1;
        }
    }

    double answ = func(num);
    double final = !mo ? to_deg(answ) : answ;
    final = clean_zero(final);

    printf("The answer is %.2lf.\n", final);

    Operation revtrig;
    revtrig.num1 = num;
    revtrig.num2 = 0;
    revtrig.res = final;
    strcpy(revtrig.op, op);

    store(revtrig);
    return final;
}

double clean_zero(double x) {
    return (fabs(x) < 1e-9) ? 0.0 : x;
}

double mplus(double num){
    memory +=num;
    printf("Added to memory: %.2lf.\n", memory);
}

double mminus(double num){
    memory -= num;
    printf("Subtracted from memory: %.2lf.\n", memory);
}
 
double show(double mem){
    printf("Memory recalled: %.2lf.\n", mem);
    return mem;
}

void clearmem(void){
    memory = 0.0;
    printf("Memory cleared.\n");
}

void clean_input_buffer(void){
    int ch;
    while(((ch = getchar()) != '\n') && (ch != EOF));
}

int read_double(double *number){
    int status = scanf("%lf", number);
    if (status != 1){
        clean_input_buffer();
        return 0;
    }
    return 1;
}

int read_int(int *num){
    int status = scanf("%d", num);
    if (status != 1){
        clean_input_buffer();
        return 0;
    }
    return 1;
}