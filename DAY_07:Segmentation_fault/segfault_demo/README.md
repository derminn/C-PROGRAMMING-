#segmentation fault demo

##Description
This program demonstrates a segmentation fault caused by dereferencing a NULL pointer.

##Cause of Crash 
The pointer 'ptr' is initialized to NULL and then dereferenced:
*ptr = 10;

This leads to invalid memory acces.

##GDB Analysis
-Program recieved SIGSEGV

