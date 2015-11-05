---
title: Pretty Output
number: 12
status: reviewed
difficulty: Medium
requirements: man, standard library
authors: [manuel, richard]
lesson: 6
---

To solve the following tasks, you need to use some functions that may be new to you.  
No explanation is given on them, use *man* to find out how they work.  
  

Write a program that outputs a function table like the following:

 * In the first row, print all values *x* from 1 to 10.
 * In the second row, print *1/x* from 1 to 10.

Play around with the format string of *printf()* to create a nice table-like output.

**Experts:** Print a multiplication table instead (from *1\*1* to *10\*10*)

##Solution##

coming soon.

<!--

    #include <stdio.h>

    int main(void) {
        printf("x   |");

        for (int i = 1; i <= 10; i++)
            printf("%5d    |", i);

        printf("\n");
        printf("---------------------------------------------------------------------------------------------------------\n");
        printf("1/x |");

        for (int i = 1; i <= 10; i++)
            printf(" %5.2f   |", 1.0 / i);

        printf("\n");

        return 0;
    }

**Experts:**


    #include <stdio.h>

    int main(void) {

        printf("%4c  |", ' ');

        for (int i = 1; i <= 10; i++)
            printf("%4d  |", i);

        printf("\n-----------------------------------------------------------------------------\n");

        for (int i = 1; i <= 10; i++) {
            printf("%4d  |", i);
            for(int j = 1; j <= 10; j++)
                printf("%4d  |", i * j);
            printf("\n");
        }

        return 0;
    }


-->
