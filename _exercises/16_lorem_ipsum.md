---
title: Lorem Ipsum
number: 16
status: reviewed
difficulty: Medium
requirements: Arrays, C-Strings
authors: [manuel, richard]
lesson: 7
---

Write a program that prints the following text by iterating through an array.


    Lorem ipsum dolor sit amet, consetetur sadipscing elitr,
    sed diam nonumy eirmod tempor invidunt ut labore et
    dolore magna aliquyam erat, sed diam voluptua. At vero
    eos et accusam et justo duo dolores et ea rebum.

###Hints###

You can copy the text from [http://loremipsum.de](http://loremipsum.de)

You'll need a bunch of *'* and *,*

##Solution##

coming soon.

<!--

    #include <stdio.h>

    int main(void) {
        char loremipsum[] = {'l','o','r','e','m',' ','i','p','s','u','m','\n'};

        for(int i = 0; i < (sizeof loremipsum / sizeof loremipsum[0]); i++)
            printf("%c",loremipsum[i]);

        return 0;
    }

-->
