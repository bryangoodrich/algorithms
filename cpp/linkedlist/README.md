Doubly Linked Lists
===================

Overview
--------
This API provides for a doubly linked list (i.e., a list that can go
forwards and backwards) that drops into a "NULL space" either 'before'
the first (head) element or 'after' the last element in the list. 

An improvement to this API would be to incorporate an iterator for an
easier approach to traversing the list and printing out the contents.

This project does not attempt to better the existing STL list types. 
As a Java alternative, see the Java Queue API for a Deque, a 
Randomized Queue (random sample iterators), and a k-subset:
https://github.com/bryangoodrich/algs4-queues

This is an update to my CISP 430 Data Structures class assignment from
American River College taught by the great David Fox. In particular,
I have converted it to a template class, using what I learned from
Fox's CISP 400 C++ class; the final project had us create our own
vector implementation using templates.

API
===========

Constructor
-----------
```
DLList ( )    // Create an empty List
~DLLisst ( )  // Unallocate List space
```

List Checks
-----------
```
bool IsEmpty ( ) const    // True, if List is empty
bool EndOfList ( ) const  // True, if cursor not in List space
```

Cursor Movements
----------------
```
void Head ( )      // Move cursor to head Node
void Next ( )      // Move cursor to next Node in List
void Previous ( )  // Move cursor to previous Node in List
```

Item Changes
------------
```
T Item ( )             // Return template type T Item from current List item
void Delete ( )        // Remove Node at cursor
void InsertBefore ( )  // Insert template type T Item before cursor
void InsertAfter ( )   // Insert template type T Item after cursor
```

