---
title: Calculator
number: 5
status: reviewed
difficulty: medium
requirements: variables, input/output, conditions
authors: [manuel, richard]
lesson: 3
---
Write a Program, that takes two numbers and an operator (+, -, /, *, %) as input and prints the result.

**Experts:** The program should also accept the words *add, substract, multiply, divide* and *remainder* as operators.

###Hints###
**Experts:** Look at the difference between the words.

**Experts:** How many letters do you have to check?

<!--
###Solution###

{% highlight C %}
#include <stdio.h>

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
            printf("%f + %f = %f\n", a, b, a + b);
            break;
        case 's':
        case 'S':
        case '-':
            printf("%f - %f = %f\n", a, b, a - b);
            break;
        case 'm':
        case 'M':
        case '*':
            printf("%f * %f = %f\n", a, b, a * b);
            break;
        case 'd':
        case 'D':
        case '/':
            if (b == 0)
                printf("Error: Division by zero.\n");
            else
                printf("%f / %f = %f\n", a, b, a / b);

            break;
        case 'r':
        case 'R':
        case '%':
            if (b == 0)
                printf("Error: Division by zero.\n");
            else
                printf("%f %% %f = %d\n", a, b, (int)a % (int)b);

            break;
        default:
            printf("Error: wrong operator.");
    }

    return 0;
}
{% endhighlight %}
-->
