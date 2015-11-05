---
title: Array printing function
number: 17
status: reviewed
difficulty: Medium
requirements: Arrays, loops
authors: [manuel, richard]
lesson: 7
---

Write a function that prints an Integer array.

**Experts:** Write a function that prints an integer matrix.

###Hints###

Don't forget, *sizeof* is no help here.

**Experts:** Loopception.

##Solution##

coming soon.

<!--

    #include <stdio.h>

    void printIntegerArray(int arr[], int size);
    void printIntegerMatrix(int arr[][5], int m, int n);

    int main(void) {
        int intA[] = {0,1,2,3,4,5};
        int intM[][5] = {\{0,1,2,3,4}, {5,6,7,8,9}, {10,11,12,13,14}};
        printIntegerArray(intA, 6);
        printIntegerMatrix(intM, 3, 5);
        return 0;
    }

    void printIntegerArray(int arr[], int size) {
        for (int i = 0; i < size; i++)
            printf("%d\t", arr[i]);
        printf("\n");
    }

    void printIntegerMatrix(int arr[][5], int m, int n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                printf("%d\t", arr[i][j]);
            printf("\n");
        }
    }

-->
