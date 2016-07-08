/* Shawn Hustins
 * ID: 0884015
 */

#ifndef _revPhoneLookup_h_
#define _revPhoneLookup_h_

#include "linkedList.h"
#include "hashTable.h"

#define NUM_BUCKETS 50

typedef struct {
	char * first;
	char * last;
	long long number;
} Form;

/* The following functions can be found in src/modules.c *********************/

void loadData(char * filePath, List * sortedList, List * hashmap);

void printList(char * output, List * sortedList);

void addEntry(char * arg, List * sortedList, List * hashmap);

void searchEntry(char * arg, List * hashmap);

void helpMsg();

/* The following functions can be found in src/specialFunctions.c ************/

int addSorted(List * list, Form * data);

void * newNode(List * list, void * data);

void * comparePhone(void * data, long long key);

void freeForm(void * data);

#endif