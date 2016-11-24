---
title: Math exam
number: 13
status: reviewed
difficulty: Hard
requirements: Standard library
authors: [manuel, richard]
lesson: 6
---

Write a program that asks the user to solve some simple mathematic tasks.

If the user answers wrong, the program should abort with an error.

**Experts:** At the end, print the time it took the user to answer all the questions.

###Hints###

Remember the *assert()* macro?

##Solution##

{% highlight C %}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

int main(void) {

    srand(time(NULL));

    for (int i = 5; i > 0; --i) {
        int a = rand() % 9 + 1;
        int b = rand() % 9 + 1;
        int s;

        printf("%d + %d = ", a, b);

        scanf("%d", &s);

        assert(s == a + b);

    }
    return 0;
}
{% endhighlight %}
