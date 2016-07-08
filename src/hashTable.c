/* Shawn Hustins
 * ID: 0884015
 */

#include "hashTable.h"

int loadHash(List * hashmap, int buckets, size_t dataSize, freeData function) {
	
	for (int i = 0; i < buckets; ++i)
		check(!newList(&hashmap[i], dataSize, function), "Hash loading error");
	return 0;
	
error:
	return -1;
}


void unloadHash(List * hashmap, int buckets) {
	
	for (int i = 0; i < buckets; ++i)
		destroyList(&hashmap[i]);
}


int hashInsert(List * hashmap, int buckets, long long key, void * element) {
	
	return addTail(&hashmap[key % buckets], element);
}


void * hashProbe(List * hashmap, int buckets, long long key, 
											matchFunction compare) {
	
	Node * node = hashmap[key % buckets].head;
	if (node && compare) {
		do {
			if (compare(node->data, key)) return node->data;
		} while ((node = node->next));
	}
	return NULL;
}
