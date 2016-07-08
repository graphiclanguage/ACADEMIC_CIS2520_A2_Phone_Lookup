/* Shawn Hustins
 * ID: 0884015
 */

#ifndef _hash_h_
#define _hash_h_

#include "linkedList.h"

typedef void * (*matchFunction)(void *, long long); 


int loadHash(List * hashmap, int buckets, size_t dataSize, freeData function);


void unloadHash(List * hashmap, int buckets);


int hashInsert(List * hashmap, int buckets, long long key, void * element);


void * hashProbe(List * hashmap, int buckets, long long key, 
											matchFunction compare);

#endif