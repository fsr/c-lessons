---
title: Power and faculty
number: 8
status: reviewed
difficulty: medium
requirements: variables, input/output, loops
authors: [manuel, richard]
lesson: 4
---

Write a program that takes two numbers *a, b* from the user and calculates *a^b* and *b^a*

**Experts:** Write a program that calculates the factorial of the user input.

###Hints###

**Experts:** The factor changes in each step.

##Solution##


    #include <stdio.h>

    int main(void) {
        int a;
        int b;
        int sol;
        printf("Insert two numbers seperated by space: ");
        scanf("%d %d", &a, &b);
        sol = 1;
        /* a^b */
        for (int i = b; i > 0; --i)
            sol *= a;
        printf("a^b:\t%d\n", sol);

        /* b^a */
        sol = 1;
        for (int i = a; i > 0; --i)
            sol *= b;
        printf("b^a:\t%d\n", sol);

        /* a! */
        for(sol = 1; a > 1; --a)
            sol *= a;
        printf("a!:\t%d\n", sol);

        /* b! */
        for(sol = 1; b > 1; --b)
            sol *= b;
        printf("b!:\t%d\n", sol);

        return 0;
    }

