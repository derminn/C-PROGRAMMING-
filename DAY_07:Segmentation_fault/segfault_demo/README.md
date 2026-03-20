#segmentation fault demo

##Description
This program demonstrates a segmentation fault caused by dereferencing a NULL pointer.

##Cause of Crash 
The pointer 'ptr' is initialized to NULL and then dereferenced:
*ptr = 10;

This leads to invalid memory acces.

##GDB Analysis

-Program recieved SIGSEGV

![image alt](https://github.com/derminn/C-PROGRAMMING-/blob/2325a95e93f12102eecd673bf2345a98e29c6e54/DAY_07%3ASegmentation_fault/segfault_demo/run.png)



-Backtrace shows crash at line 6 in main()


![image alt](https://github.com/derminn/C-PROGRAMMING-/blob/b83c65e0b363846b7e18591a77fc5d29d1723ed6/DAY_07%3ASegmentation_fault/segfault_demo/bt.png)
