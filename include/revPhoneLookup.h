/* Shawn Hustins
 * ID: 0884015
 */

#ifndef _revPhoneLookup_h_
#define _revPhoneLookup_h_

#include "linkedList.h"
#include "hashTable.h"

#define NUM_BUCKETS 100	// hashmap size

typedef struct {
	char * first;		// first name
	char * last;		// last name
	long long number;	// phone number
} Form;

/* The following functions can be found in src/modules.c *********************/

/*
 * loadData
 * Takes the user specified file and parses it to sorted list and table
 */
void loadData(char * filePath, List * sortedList, List * hashmap);

/*
 * printList
 * Prints out all the data in sorted order. If no output file is specified as
 * an argument, data is printed to stdout
 */
void printList(char * output, List * sortedList);

/*
 * addEntry
 * Takes user sspecified argument, parses it as a Form and adds it to the table
 * and sorted list
 */
void addEntry(char * arg, List * sortedList, List * hashmap);

/*
 * searchEntry
 * Takes user specified argument and searches hash table for entry
 */
void searchEntry(char * arg, List * hashmap);

/*
 * helpMsg
 * Displays a simple messsage describing program usage
 */
void helpMsg();

/* The following functions can be found in src/specialFunctions.c ************/

/*
 * addSorted
 * Takes data form and adds it to the list in alphabetized order by last name
 */
int addSorted(List * list, Form * data);

/*
 * newNode
 * Allocates memory for just a single node
 */
void * newNode(List * list, void * data);

/*
 * comparePhone
 * Compares the key in the form, the phone number, with the key being searched
 */
void * comparePhone(void * data, long long key);

/*
 * freeForm
 * Frees memory dynamically allocated within form, ie. first and last name
 */
void freeForm(void * data);

#endif