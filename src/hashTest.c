/* Shawn Hustins
 * ID: 0884015
 */

#include <stdio.h>
#include <stdlib.h>
#include "hashTable.h"
#include "dbg.h"

#define NUM_BUCKETS 10

typedef struct {
	char * word;
	long long num;
} Form;

void freeString(void * data);
void * compare(void * data, long long key);


int main () {
	
	List hashmap[NUM_BUCKETS];
	int rc = 0;
	
	loadHash(hashmap, NUM_BUCKETS, sizeof(Form), freeString);

/*****************************************************************************/	
	printf("--------Hash loading successful--------\n\n");
/*****************************************************************************/

	char * words[5] = { "Hello", "World", "Shawn", "Black", "White" };
	long long keys[5] = { 1234, 554, 1110, 100593, 99944 };
	
	for (int i = 0; i < 5; ++i) {
		char * word = calloc(6, sizeof(char));
		strcpy(word, words[i]);
		Form test = {.word = word, .num = keys[i]};
		printf("Form to load: {%lld, '%s'}\n", test.num, test.word);
		rc = hashInsert(hashmap, NUM_BUCKETS, keys[i], &test);
		check(rc == 0, "Hash insertion error.");
	}
	
	Form empty = {.word = NULL, .num = 0};
	
	rc = hashInsert(NULL, NUM_BUCKETS, 10, &empty);
	printf("\nTest insert to nowhere, returns '%s'\n",
					rc == 0 ? "Success" : "Failure");
	
	rc = hashInsert(hashmap, NUM_BUCKETS, 50, NULL);
	printf("Test insert of nothing, returns '%s'\n\n",
					rc == 0 ? "Success" : "Failure");
	
/*****************************************************************************/
	printf("--------Hash inserting successful--------\n\n");
/*****************************************************************************/

	for (int i = 0; i < 5; ++i) {
		void * data = hashProbe(hashmap, NUM_BUCKETS, keys[i], compare);
		if (data) {
			Form test = *(Form *)data;
			printf("%lld key returns: {%lld, '%s'}\n", keys[i], 
										test.num, test.word);
		} else {
			printf("Nothing found for key %lld\n", keys[i]);
		}
	}
	
	void * data = hashProbe(hashmap, NUM_BUCKETS, 999, compare);
	printf("\nTest probe empty bucket, returns %p\n", data);
	
	data = hashProbe(hashmap, NUM_BUCKETS, 44444, compare);
	printf("Test probe with unused key, returns %p\n\n", data);

/*****************************************************************************/
	printf("--------Hash probing successful--------\n\n");
/*****************************************************************************/

	unloadHash(hashmap, NUM_BUCKETS);
	
/*****************************************************************************/
	printf("--------Hash terminating successful--------\n");
/*****************************************************************************/
	
	return 0;
	
error:
	unloadHash(hashmap, NUM_BUCKETS);
	return -1;
}


void freeString(void * data) {
	
	free(*(char **)data);
}


void * compare(void * data, long long key) {
	
	Form form = *(Form *)data;
	if (key == form.num) return data;
	return NULL;
}
