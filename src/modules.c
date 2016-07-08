/* Shawn Hustins
 * ID: 0884015
 */

#include "revPhoneLookup.h"

void loadData(char * filePath, List * sortedList, List * hashmap) {
	
	FILE * database = NULL;
	check(filePath, "No file path specified.");
	check(filePath[0] != '\0', "No file path specified.");
	
	++filePath;
	database = fopen(filePath, "r");
	check(database, "Unable to load file.");
	
	char buffer;
	char token[25];
	int entryNum = 0;
	int index = 0;
	Form form = {.first = NULL, .last = NULL, .number = 0};
	
	while ((buffer = fgetc(database)) != EOF) {
		if (buffer == ',') {
			
			token[index] = '\0';
			switch  (entryNum) {
				case 0:
					form.first = calloc(strlen(token) + 1, sizeof(char));
					strcpy(form.first, token);
					break;
				case 1:
					form.last = calloc(strlen(token) + 1, sizeof(char));
					strcpy(form.last, token);
					break;
				default:
					sentinel("No more than two commas may appear on a line.");
			}
			memset(&token[0], 0, sizeof(char));
			index = 0;
			++entryNum;
			
		} else if (buffer == '\n') {
			
			token[index] = '\0';
			form.number = atoll(token);
			while (form.number > 9999999999)
				form.number /= 10;
				
			addSorted(sortedList, &form);
			hashInsert(hashmap, NUM_BUCKETS, form.number, &form);
			
			memset(&token[0], 0, sizeof(char));
			index = 0;
			entryNum = 0;
			
		} else {
			token[index] = buffer;
			++index;
		}
	}
	
	form.number = atoll(token);
	while (form.number > 9999999999)
				form.number /= 10;
					
	if (form.number) {
		addSorted(sortedList, &form);
		hashInsert(hashmap, NUM_BUCKETS, form.number, &form);
	}
	
	printf("Data from file: '%s' successfully loaded.\n", filePath);
	fclose(database);
	
	return;
	
error:
	if (database) fclose(database);
	printf("Error loading data from file: '%s'.\n"
		   "Ensure file path is correct and file is properly formatted:"
		   "\n\"{first},{last},{number}\\n\"\n",
		   filePath);
	return;
}


void printList(char * output, List * sortedList) {
	
	FILE * stream = NULL;
	if (output) {
		if (output[0] != '\0') {
			++output;
			stream = fopen(output, "w+");
		}
	}
	
	if (!output)
		printf("________________________________"
			   "____________________________\n\n");
	
	Node * curr = sortedList->head;
	
	while (curr) {
		Form form = *(Form *)curr->data;
		if (output) {
			fprintf(stream, "%s,%s,%lld\n", form.first, form.last, 
														form.number);
		} else {
			printf("%-16.18s %-16.18s: %-10lld\n", form.first, form.last,
														    form.number);
		}
		curr = curr->next;
	}
	
	if (!output)
		printf("________________________________"
			   "____________________________\n\n");
	
	if (output)
		printf("List successfully printed to file '%s'\n", output);
	
	if (stream) fclose(stream);
	
}


void addEntry(char * arg, List * sortedList, List * hashmap) {
	
	check(arg, "No info specified.");
	check(arg[0] != '\0', "No info specified.");
	
	char * first = ++arg;
	int i = 0;
	
	for (; first[i] != ' '; ++i)
		check(first[i] != '\0', "Not enough info specified.");
	
	first[i] = '\0';
	check(first[++i] != '\0', "Not enough info specified.");
	
	char * last = &(first[i]);
	
	for (i = 0; last[i] != ' '; ++i)
		check(last[i] != '\0', "Not enough info specified.");
	
	last[i] = '\0';
	check(last[++i] != '\0', "Not enough info specified.");
	
	char * strnum = &(last[i]);
	
	for (i = 0; i < 10; ++i)
		check(strnum[i] != '\0', "Not enough info specified.");
	
	Form form = {.first = NULL, .last = NULL, .number = 0};
	
	form.first = calloc(strlen(first) + 1, sizeof(char));
	strcpy(form.first, first);
	
	form.last = calloc(strlen(last) + 1, sizeof(char));
	strcpy(form.last, last);
	
	form.number = atoll(strnum);
	while (form.number > 9999999999)
				form.number /= 10;
	
	addSorted(sortedList, &form);
	hashInsert(hashmap, NUM_BUCKETS, form.number, &form);
	
	printf("Entry successfully added.\n");
	
	return;
	
error:
	printf("Not enough information specified for new entry.\n");
	return;
}


void searchEntry(char * arg, List * hashmap) {
	
	check(arg, "No number specified.");
	check(arg[0] != '\0', "No number specified.");
	++arg;
	
	long long number = atoll(arg);
	check(number != 0, "No number specified.");
	
	Form * form = hashProbe(hashmap, NUM_BUCKETS, number, comparePhone);
	check(form, "Number not found.");
	
	printf("Entry found: \n"
		   "%s %s: %lld\n", form->first, form->last, form->number);
	
	return;
	
error:
	printf("Number '%s' not found.\n", arg);
	return;
}


void helpMsg() {
	
	printf("___________________________________________________________\n"
		   "\nReverse Phone Lookup Options: \n\n"
		   "'a'/'add'    : Add a single name/num entry\n"
		   "               > add {firstName} {lastName} {number}\n\n"
		   "'h'/'help'   : List all program options\n\n"
		   "'l'/'load'   : Load data file\n"
		   "               > load {filePath}\n\n"
		   "'p'/'print'  : Print all stored entries, prints to\n"
		   "               stdout if no output file is specified\n"
		   "               > print {filePath}\n\n"
		   "'q'/'quit'   : Quit application\n\n"
		   "'s'/'search' : Search for the holder of a phone number\n"
		   "               > search {number}\n"
		   "___________________________________________________________\n\n");
	
}