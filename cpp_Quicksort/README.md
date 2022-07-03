Homemade Quicksort
===================

Overview
--------
This assignment is part of David Fox's CISP 430 class at American 
River College (ARC). This API provides for a quicksort algorithm 
comparable to the built-in `qsort` ("comparable" is generous here!)


Motivation
----------
No student of computer science can finish their lower division 
programming courses without having tried their hand at the fastest
general sorting algorithm! There are a number of ways to *implement* the
algorithm, however. For our class this semester, we used the approach as
presented by this dance:

http://www.youtube.com/watch?v=ywWBy6J5gz8


Challenges
----------
There were two options or progressions for this assignment. The easier
approach was to `typedef` a specific type and develop your algorithm 
knowing that you can identify the bytes of your objects. This final
version will align with the built-in `qsort` by taking void pointers.
The difficulty here is in understanding exactly how you identify shifts
in the array and how to copy over blocks of memory in the area. Once
you have mastered dealing with those difficulties, the problem appears
quite trivial! Isn't that true for all solutions, though? 

