---
title: Saving lines in calculator
number: 10
status: reviewed
difficulty: Easy
requirements: functions
authors: [manuel, richard]
lesson: 5
---

Take the calculator task and unburden the switch by adding functions for each operation.

Now delete the *substract* and the *divide* function (and find a way the calculator works anyway).

**Experts:** add the functionality to exponentiate. Implement the *exponentiate* function by calling the *multiply* function or by using recursion.

###Hints###

How can you substract through addition?

You can pass any expression as a parameter.

##Solution##

<!--
{% highlight C %}
#include <stdio.h>

void printAdd(float a, float b);
void printMultiply(float a, float b);
void printRemainder(float a, float b);

int main(void) {
    float a = 0;
    float b = 0;
    char o = 0;

    printf("Enter first number:");
    scanf("%f", &a);

    printf("Enter 2nd number:");
    scanf("%f", &b);

    printf("Enter operand:");
    scanf("\n%c", &o);

    switch (o) {
        case 'a':
        case 'A':
        case '+':
            printAdd(a, b);
            break;
        case 's':
        case 'S':
        case '-':
            printAdd(a, -b);
            break;
        case 'm':
        case 'M':
        case '*':
            printMultiply(a, b);
            break;
        case 'd':
        case 'D':
        case '/':
            if (b == 0)
                printf("Error: Division by zero.\n");
            else
                printMultiply(a, (1/b));
            break;
        case 'r':
        case 'R':
        case '%':
            printRemainder((int)a, (int)b);
            break;
        default:
            printf("Error: wrong operator.");
    }

    return 0;
}

void printAdd(float a, float b) {
    printf("%f\n", a + b);
}

void printMultiply(float a, float b) {
    printf("%f\n", a * b);
}

void printRemainder(int a, int b) {
    if (b == 0) {
        printf("Error: Division by zero.\n");
        return;
    }
    printf("%d\n", a % b);
}
{% endhighlight %}
-->
