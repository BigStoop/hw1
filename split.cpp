/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // Base case, if "in" is empty exit
  if (in == nullptr) {
    return;
  }

  // Sets new node to current header
  Node* curr = in;
  // Moves to the next node in "in"  (for recursion)
  in = in->next;

  // Sorts curr node into either evens or odds
  if (curr->value % 2 == 0) {
    curr->next = evens; 
    evens = curr;
  }
  else {
    curr->next = odds;
    odds = curr;
  }

  // Recursie step
  split(in, odds, evens);

}

/* If you needed a helper function, write it here */
