OS Coding Assignment 2

Jonathan Zajac
Operating Systems
11/20/22

In this assignment, we are assigned to implement the bankers algorithm. I implemented this by using two dimensional arrays to store a processees max, allocation, need and available. This program will tell you whether the system is or is not in a safe state and then give you the safe sequence. 

To compile use:
$ gcc banker.c -o banker
$ ./banker

Output is: 
System is not in safe state; safe sequence is: P1, P3, P4, P0, P2
