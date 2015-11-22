---
title: A simple math parser
number: 29
status: reviewed
difficulty: Very Hard
requirements: All you lerned in this course
authors: [manuel, richard]
lesson: [1,2,3,4,5,6,7,8,9,10]
---

All the "calculators" we have done so far only allowed input of one operation
at once. Write a program that can process an arbitrary mathematical expression
containing +, -, \*, / and modulo as well as brackets.

Use the **Reverse polish notation** to evaluate expressions: *3 + 4* becomes
*3 4 +*. For more information, see the [Wikipedia
article](https://en.wikipedia.org/wiki/Reverse_Polish_notation).

Mathematical expressions in **infix notation** can be converted to RPN by using
the [Shunting-yard
algorithm](https://en.wikipedia.org/wiki/Shunting-yard_algorithm).

**Example**
Input: (3 + 4) * 5

Output: 35

For simplicity, you can assume that math expressions are not longer than 255
bytes.

**Experts:** Support expressions of arbitrary length and give useful feedback,
if the input string contains errors. Also implement the ^ operator.

###Hints###

Converting the input to RPN and evaluating RPN can be done simultaneously.

**Experts:** be careful when implementing ^, its associativity is different
than the other operators'.
