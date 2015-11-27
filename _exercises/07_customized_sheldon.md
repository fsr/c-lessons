---
title: Customized Sheldon
number: 7
status: reviewed
difficulty: easy
requirements: variables, input/output, loops
authors: [manuel, richard]
lesson: 4
---
Write a program, that lets the user decide how often *"Knock, knock, knock - Penny?"* is printed.

**Experts:** Let the program additionally ask how often Sheldon knocks each time. Take care, that the first "Knock" starts with a Capital K.

###Hints###

**Experts:** You can use loops inside loops

**Experts:** You should use a different index for the inner loop


##Solution##

{% highlight C %}
#include <stdio.h>

int main(void) {
    int count;
    int knock;

    printf("How often shall sheldon try to knock? ");
    scanf("%d", &count);
    printf("And how often shall he knock each time? ");
    scanf("%d", &knock);

    while (count-- > 0) {
        int i;
        for (i = 0; i < knock; ++i)
            if (i == 0)
                printf("Knock");
            else
                printf(", knock");

        if (knock > 0)
            printf(" - ");

        printf("Penny?\n");
    }
    return 0;
}
{% endhighlight %}
