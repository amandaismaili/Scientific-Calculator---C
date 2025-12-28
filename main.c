#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "operations.h"

const double PI = 3.141592653589793;
int angle_mode = 0;
static double last_res = 0.0;

int main() {
    int choice;
    double num1, num2, answ;

    printf("Welcome to the calculator. Choose what operation do you wish to do.\n");
    printf("----------------\n");
    printf("1. Addition (+)\n2. Subtraction (-)\n3. Multiplication (*)\n4. Division(/)\n5. Power (*)\n6. Remainder\n7. Factorial(!)\n");
    printf("8. Square Root\n9. Trigonometry section\n10. Natural logarithm(Ln) \n11. Logarithm (log)\n12. E exponential\n13. View History\n");
    printf("14. M+\n15. M-\n16. MR\n17. MC\n18. Delete history\n");
    printf("----------------\n");
    
    while (1){
        printf("Choice: ");
        while (!read_int(&choice)) printf("Enter a valid number: ");

        if (choice < 1 || choice > 18){
            printf("Invalid input.\n");
            continue;
        }

        if(choice >=1 && choice <=5){
            printf("After choosing the operator, enter neccesary numbers. \n");
            printf("Number 1: ");
            while(!read_double(&num1)) printf("Enter a valid number: ");
            printf("Number 2: ");
            while(!read_double(&num2)) printf("Enter a valid number: ");
        } else if (choice ==7 || choice == 8 || choice == 10 || choice == 11 || choice == 12) {
            printf("Number: ");
            while(!read_double(&num1)) printf("Enter a valid number: ");
        }

        switch(choice) {
            case 1:
                answ = addition(num1, num2);
                printf("The answer is %.2f.\n", answ);
                Operation adding = {num1, "+", num2, answ};
                store(adding);
                last_res = answ;
                break;
            case 2:
                answ = subtraction(num1, num2);
                printf("The answer is %.2f.\n", answ);
                Operation subtracting = {num1, "-", num2, answ};
                store(subtracting);
                last_res = answ;
                break;
            case 3:
                answ = multiplication(num1, num2);
                printf("The answer is %.2f.\n", answ);
                Operation mult = {num1, "*", num2, answ};
                store(mult);
                last_res = answ;
                break;
            case 4:
                if (num2 == 0){
                    printf("Error: division by 0.\n");
                }
                else {
                    answ = division(num1, num2);
                    printf("The answer is %.2f.\n", answ);
                    Operation div = {num1, "/", num2, answ};
                    store(div);
                    last_res = answ;
                }
                break;
            case 5:
                answ = power(num1, num2);
                printf("The answer is %.2f.\n", answ);
                Operation poww = {num1, "^", num2, answ};
                store(poww);
                last_res = answ;
                break;
            case 6:
                int rnum1, rnum2;
                printf("Enter number 1: ");
                while (!read_int(&rnum1)) printf("Enter a valid number: ");
                printf("Enter number 2: ");
                while (!read_int(&rnum2)) printf("Enter a valid number: ");
                if (rnum2 == 0) {
                    printf("Cannot find remainder of division by 0.\n");
                    break;
                }
                int ransw = int_remainder(rnum1, rnum2);

                printf("The answer is %d.\n",ransw);

                Operation rem = {(double)rnum1, "%", (double)rnum2, (double)ransw};
                store(rem);
                last_res = (double)ransw;
                break;
            case 7:
                if (num1 < 0 || (int)num1 != num1) printf("Cannot compute this factorial.\n"); 
                else {
                answ = factorial((int)num1);
                printf("The answer is %.0lf.\n", answ);
                Operation fact = {num1, "!", 0, (double)answ};
                store(fact);
                last_res = answ;
                }
                break;
            case 8:
                if (num1 < 0){
                    printf("Error: cannot calculate sqrt of negative number.\n");
                }
                else{
                    answ = sqroot(num1);
                    printf("The answer is %.2lf.\n", answ);
                    Operation root = {num1, "sqrt", 0, answ};
                    store(root);
                    last_res = answ;
                }
                break;
            case 9:
                int chc, mode; double tnum;
                printf("Trigonometry section:\n1. Sin\n2. Cos\n3. Tan\n4. Asin\n5. Acos\n6. Atan\n");

                printf("Choice: ");
                while (!read_int(&chc)) printf("Enter a valid number: ");

                printf("Degree(default) (0) or rads (1): ");
                while (!read_int(&mode)) printf("Enter a valid number: ");
                angle_mode = mode;
                
                if (chc>=1 && chc<=3) printf("Enter angle: ");
                else if (chc>=4 && chc<=6) printf("Enter the sin/cos/tan value: ");
                while (!read_double(&tnum)) printf("Enter a valid number: ");

                switch(chc){
                    case 1: last_res = trig(tnum, "sin", sin, angle_mode); break;
                    case 2: last_res = trig(tnum, "cos", cos, angle_mode); break;
                    case 3:
                        double angle = angle_mode ? tnum : to_rad(tnum);
                        if (fabs(cos(tnum)) < 1e-9) {
                            printf("Tan is undefined for this angle.\n");
                            break;
                        }
                        last_res = trig(tnum, "tan", tan, angle_mode);
                        break;
                    case 4: last_res = trig(tnum, "asin", asin, angle_mode); break;
                    case 5: last_res = rev_trig(tnum, "acos", acos, angle_mode); break;
                    case 6: last_res = rev_trig(tnum, "atan", atan, angle_mode); break;
                }
                break;
            case 10:
                if (num1 <= 0){
                    printf("Error: cannot calculate ln of a negative number.\n");
                }
                else{
                    answ = log(num1);
                    printf("The answer is %.2lf.\n", answ);
                    Operation lnn = {num1, "ln", 0, answ};
                    store(lnn);
                    last_res = answ;
                }
                break;
            case 11:
                if (num1 <= 0){
                    printf("Error: cannot calculate log negative number.\n");
                }
                else{
                    answ = log10(num1);
                    printf("The answer is %.2lf.\n", answ);
                    Operation logg = {num1, "log", 0, answ};
                    store(logg);
                    last_res = answ;
                }
                break;
            case 12:
                exponent(num1);
                break;
            case 13:
                printf("-----Previous history------\n");
                read_history();
                break;
            case 14:
                mplus(last_res);
                break;
            case 15:
                mminus(last_res);
                break;
            case 16:
                last_res = show(last_res);
                break;
            case 17:
                clearmem();
                break;
            case 18:
                delete_history();
                printf("History cleared successfully.\n");
                break;
            default: printf("Invalid choice.\n");
        }

        clean_input_buffer();

        char again[10];
        do {
            printf("Do you want to go again?(y/n): ");
            fgets(again, sizeof(again), stdin);
            } while (again[0] != 'y' && again[0] != 'n'); 

        if (again[0] == 'n') break;
    }
    return 0;
}