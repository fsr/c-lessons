---
title: The rabbit problem
number: 9
status: reviewed
difficulty: Hard
requirements: variables, input/output, loops
authors: [manuel, richard]
lesson: 4
---

Write a program, that prints the *n*th fibonacci number.

 * A fibonacci number is the sum of its two predecessors in the fibonacci sequence
 * The fibonacci sequence starts with 0,1,...

**Experts:** Also calculate the sum of all fibonacci numbers *<= n*

###Hints###

One variable is not enough to store all the information you need to calculate the next fibonacci number.

##Solution##

    #include <stdio.h>

    int main(void) {
        int n;
        int a = 0;
        int b = 1;
        int sum = 1;
        printf("Which fibonacci number should I calculate for you? ");
        scanf("%d", &n);

        if(n < 1) {
            printf("Seriously?\n");
            return 0;
        }
        if(n == 1)
            b = 0;
        while(--n > 1) {
            int tmp = a + b;
            a = b;
            b = tmp;
            sum += b;
        }
        printf("The fibonacci number is %d.\n", b);
        printf("The sum is %d.\n", sum);
        return 0;
    }

