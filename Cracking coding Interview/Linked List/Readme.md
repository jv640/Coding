# In this folder i am only mentioning questions because these questions were easy and also i have coded them in my another repository name 30-Days-challange

## Questions
Q-1       Remove Dups: Write code to remove duplicates from an unsorted linked list.
          FOLLOW UP
          How would you solve this problem if a temporary buffer is not allowed? 
Approach  create a hash and for follow up approach we can sort it first using merge sort and then apply remove duplicate from sorted list which is easy

Q-2       Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list
Approach  First find size of list then modify your k value take mode and subtract it from n. then run a pointer k times and make next of this as head and pull null in its next

Q-3       Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) 
          of a singly linked list, given only access to that node.
Approach  Use two pointer approach (snail and rabbit)

Q-4       Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit. 
          The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a function that adds the two numbers and 
          returns the sum as a linked list.
Approach  first reverse numbers then add and take care of carry in each step

Q-5       Palindrome: Implement a function to check if a linked list is a palindrome. 
Approach  split list into 2 by breaking it from half and reverse the other half then check wether 2 list are same or not.

Q-6       Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. 
          Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) 
          as the jth node of the second linked list, then they are intersecting.
Approach  take two pointers each at one list and run them until one get null whenever any of one gets null point it to other list's head and run again then they will meet at intersection

Q-7       Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
          DEFINITION
          Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
Approach  Use 2 pointer slow fast approach
