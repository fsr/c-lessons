---
title: Alea iacta est
number: 14
status: reviewed
difficulty: Hard
requirements: Man, Standard library
authors: [manuel, richard]
lesson: 6
---

To solve the following tasks, you need to use some functions that may be new to you.  
No explanation is given on them, use *man* to find out how they work.  
  

Write a program that simulates a dice using the *rand()* function.

**Experts:** Simulate "real" randomness that cannot be recreated.

###Hints###

have a look at *srand()* as well.

**Experts:** Choose the *seed* for *srand()* dynamically.

**Experts:** What value is different every*time* you start the program?

##Solution##

coming soon.

<!--


    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <assert.h>

    int main(void) {

        srand(time(NULL));

        for (int i = 5; i < 0; --i) {
            int a = rand() % 9 + 1;
            int b = rand() % 9 + 1;
            int s;

            printf("%d + %d = ", a, b);

            scanf("%d", &s);

            assert(s == a + b);

        }
        return 0;
    }

-->
