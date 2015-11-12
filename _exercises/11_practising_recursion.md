---
title: Practising recursion
number: 11
status: reviewed
difficulty: Hard
requirements: functions, recursions
authors: [manuel, richard]
lesson: 5
---
Write a function that calculates the factorial of a given number *n!* recursively.

**Experts:** The function shall calculate *fib(n)* instead of *n!*.

###Hints###

For which n is the result of *n!* clear?

Check for such *n* at the start of the function!

For all other *n*, you need a recursive call.

**Experts:** In one statement, you can call a function multiple times

##Solution##

    #include <stdio.h>

    int fak(int n);

    int main(void) {
        int n;
        printf("Gimme numba: ");
        scanf("%d", &n);

        printf("fak(%d) = %d\n", n, fak(n));
        return 0;
    }

    int fak(int n) {
        if (n == 1)
            return 1;

        return n * fak(n - 1);
    }

**Experts:**


    #include <stdio.h>

    int fib(int n);

    int main(void) {
        int n;
        printf("fib(?): ");
        scanf("%d", &n);

        if (n < 0)
            printf("Srsly? -.-\n");

        printf("fib(%d) = %d\n", n, fib(n));
        return 0;
    }

    int fib(int n) {
        if (n <= 1)
            return n;

        return fib(n - 1) + fib(n - 2);
    }
