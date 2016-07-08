/* Shawn Hustins
 * ID: 0884015
 */

#include "revPhoneLookup.h"

int addSorted(List * list, Form * data) {
	
	if (!list->head) return addHead(list, data);
	
	Node * curr = list->head;
	Node * last = list->head;
	const char * newEntry = data->last;
	int length = strlen(newEntry) - 1;
	
	while (curr) {
		char * currEntry = ((Form *)((Node *)curr)->data)->last;
		int shortest = length;
		if ((strlen(currEntry) - 1) < length)
			shortest = strlen(currEntry) - 1;
		
		for (int i = 0; i < shortest; ++i) {
			if (newEntry[i] == currEntry[i]) // equal letters
				continue;
			if (newEntry[i] > currEntry[i])  // further in alphabet
				break;
			
			if (curr == list->head) {
				list->head = (Node *)newNode(list, data);
				check(list->head, "Unable to add to list.");
				list->head->next = curr;
			} else {
				last->next = (Node *)newNode(list, data);
				check(last->next, "Unable to add to list.");
				last->next->next = curr;
			}
			
			return 0;
		} // end for loop
		
		last = curr;
		curr = curr->next;
	} // end while loop
	
	last->next = (Node *)newNode(list, data);
	check(last->next, "Unable to add to list.");
	
	return 0;
	
error:
	return -1;
}


void * newNode(List * list, void * data) {
	
	Node * new = calloc(1, sizeof(Node));
	check(new, "Memory error.");
			
	new->data = calloc(1, list->dataSize);
	check(new->data, "Memory error.");
			
	memcpy(new->data, data, list->dataSize);
	
	new->next = NULL;
	
	return new;
	
error:
	return NULL;
}


void * comparePhone(void * data, long long key) {
	
	Form * form = (Form *)data;
	if (form->number == key) return form;
	return NULL;
}


void freeForm(void * data) {
	
	Form * form = (Form *)data;
	
	free(form->first);
	free(form->last);
}