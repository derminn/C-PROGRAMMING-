##Overview :
This demonstrates the implementation of singly linked list in c ,covering core operations,memory management ,and pointer handling.

##Linked List :
-A linked list is a dynamic data structure where elements(nodes) are stored in non-contiguous memory ,connected using pointers.
-The entire list is held together by the next pointer.If the pointer is lost , the rest of the list vanishes into the void.

##Concepts Covered :
-Self-referential structures (struct Node)
-Dynamic memory allocation (malloc, free)
-Pointer-to-pointer (Node **head)
-Linked list traversal
-Memory safety practices

##Insights :
-Linked lists rely entirely on pointers, not memory order
-Node **head is required when modifying the head
-prepend is faster than append (O(1) vs O(n))
-The three-pointer technique is used for reversing
-Memory management is as important as logic in C

