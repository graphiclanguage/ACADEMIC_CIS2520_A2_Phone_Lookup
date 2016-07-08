/* Shawn Hustins
 * ID: 0884015
 */

#include "revPhoneLookup.h"

int main(int argc, char * argv[]) {
	
	//program startup
	List sortedList;
	List hashmap[NUM_BUCKETS];
														// Hashmap holds same
	newList(&sortedList, sizeof(Form), freeForm); 		// data as sorted list.
	loadHash(hashmap, NUM_BUCKETS, sizeof(Form), NULL); // Only freed via list
	
	printf("Reverse Phone Lookup App, enter 'h' for a list of commands.\n");
	printf("> ");
	
	char buffer[64];
	char * arg = NULL;
	
	while (strcmp(fgets(buffer, 64, stdin), "q\n")) {
		buffer[strlen(buffer) - 1] = '\0'; // Eliminate newline from argument
		arg = strchr(buffer, ' '); // Pull additional arguments
		
		switch (buffer[0]) {
			case 'l': // Load: load data file
				loadData(arg, &sortedList, hashmap);
				break;
				
			case 'a': // Add: add single entry
				addEntry(arg, &sortedList, hashmap);
				break;
				
			case 'p': // Print: print all entries
				printList(arg, &sortedList);
				break;
				
			case 's': // Search: lookup entry
				searchEntry(arg, hashmap);
				break;
				
			case 'h': // Help: print options
				helpMsg();
				break;
				
			default:
				printf("Unknown command, enter 'h' or 'help' "
						"for a list of accepted\ncommands.\n");
		}
		printf("> ");
	}
	
	destroyList(&sortedList);
	unloadHash(hashmap, NUM_BUCKETS);
	
	return 0;
}
