/* Shawn Hustins
 * ID: 0884015
 */

#ifndef _hash_h_
#define _hash_h_

#include "linkedList.h"

typedef void * (*matchFunction)(void *, long long); 

/*
 * loadHash
 * IN:	 *hashmap - pointer for caller to hold hashmap
 * 		 buckets - the desired hashmap size
 * 		 dataSize - the desired size of the data being stored
 * 		 function - pointer to the function required to free data not directly
 * 					stored in list node (can be NULL if unnecessary)
 * OUT:	 return 0 on success
 * 		 return -1 on failure (non-natural data size)
 * POST: initializes the list for each hash table bucket
 */
int loadHash(List * hashmap, int buckets, size_t dataSize, freeData function);

/*
 * unloadHash
 * IN:	 *hashmap -  pointer to hashmap
 * 		 buckets - the hashmap size
 * OUT:	 N/A
 * POST: frees all data from entire hashmap
 */
void unloadHash(List * hashmap, int buckets);

/*
 * hashInsert
 * IN:	 *hashmap - pointer to hashmap
 * 		 buckets - size of hashmap
 * 		 key - integer piece of data to be hashed
 * 		 *element - pointer to data being stored
 * OUT:	 return 0 on success
 * 		 returns -1 on error (memory error, list DNE)
 * POST: stores element in it's respective hashmap bucket based on key
 */
int hashInsert(List * hashmap, int buckets, long long key, void * element);

/*
 * hashProbe
 * IN:	 *hashmap - pointer to hashmap
 * 		 buckets - size of hashmap
 * 		 key - integer piece of data to find which hash to look in
 * 		 compare - pointer to the function required to test if each list
 * 				   element matches the search queery
 * OUT:	 returns element if found
 * 		 returns NULL if not found
 * POST: searches hashmap to see if the item searched exists, returns the item
 * 		 if it does or NULL if it doesn't
 */
void * hashProbe(List * hashmap, int buckets, long long key, 
											matchFunction compare);

#endif