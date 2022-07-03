/**********************************************************
 *  Execution: echo 1 2 3 4 5 | ./main
 *             ./main < input.txt
 *  
 *  Outputs an input list of integers in reverse order
 *  
 *  Class code for testing our Doubly-Linked List (DLList)
 *  for CISP 430 Data Structures at American River College.
 *  Edit input and template type to char or other data
 *  type to experiment. This main is not an exhaustive test
 *  of this data structure.
 *  
 *  $ echo 1 2 3 4 5 | ./main
 *  5 4 3 2 1
 *********************************************************/

#include <iostream>
#include <string>
#include "DLList.h"

int main()
{
    DLList<int>* v = new DLList<int>();
    int input;
    while (std::cin >> input)
    {
        v->InsertBefore(input);
    }

    while (!v->IsEmpty())
    {
        std::cout << v->Item() << " "; 
        v->Delete();
    }
    std::cout << std::endl;

    return 0;
}

