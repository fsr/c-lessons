---
title: Hangman
number: 28
status: reviewed
difficulty: Very Hard
requirements: All you lerned in this course
authors: [manuel, richard]
lesson: [1,2,3,4,5,6,7,8,9,10]
---

Write a simple hangman game! Everytime the player is wrong,
add a new part to the gallows / the hanging man and print it to the terminal:

       -----    
       |/  o
       |  ^W^
       |  / \       word: game o_e_
       |            wrong: hfnwitc
     -----   
    /     \
   /       \
==============

**Experts:** Have a list of possible words in the source code and let the program randomly choose one at the start.

###Hints###

**strncmp()** compares two strings. 
