*******************************************************************************
Shawn Hustins															0884015
CIS 2520 DE										  	   A2: Reverse Phone Lookup
July 8 2016
*******************************************************************************


************
Compilation
************

make targets:
	all: builds test and program
	
	test: builds both following tests
	
	hashTest: builds bin/hashTest
	
	listTest: builds bin/listTest
	
	program: builds bin/phoneLookup
	
	clean: removes build artifacts (executables and objects)


***********************
Running the program(s)
***********************

$ ./bin/hashTest
	Runs a test of the hash table class
	
$ ./bin/listTest
	Runs a test of the linked list class
	
$ ./bin/phoneLookup {filePath}
	Runs the reverse phone lookup application. filePath should point to a input
	file of name/phone number entries as outlined in A2 Spec. filePath is
	optional
	
phoneLookup Program Commands:
	'a'/'add'    : Add a single name/num entry
				   > add {firstName} {lastName} {number}

	'h'/'help'   : List all program options

	'l'/'load'   : Load data file
				   > load {filePath}

	'p'/'print'  : Print all stored entries, prints to
				   stdout if no output file is specified
				   > print {filePath}

	'q'/'quit'   : Quit application

	's'/'search' : Search for the holder of a phone number
				   > search {number}


*****************
Known Limitations
*****************

Duplicate Entries:
	Duplicate phone number entries can be added and printed but a search for
	a number that exists more than once will only return the oldest of the
	duplicate entries
	

**********
References
**********

A2 Spec

Found in include/dbg.h:
	Shaw, Zed (2015) Zed's Awesome Debug Macros [source code] Addison-Wesley


*******************************
Academic Integrity Pledge
*******************************

I have exclusive control over this submission via my password.
By including this file with my submitted files, I certify that:

1) I have read and understood the University policy on academic integrity;
2) I have completed the Computing with Integrity Tutorial on Moodle; and
3) I have achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own.

I have appropriately acknowledged any and all material (data, images, ideas or
words) that I have used, whether directly quoted or paraphrased.  Furthermore,
I certify that this assignment was prepared by me specifically for this course.
