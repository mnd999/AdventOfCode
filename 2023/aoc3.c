#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_LINES 140
#define LINE_LENGTH 141

struct Number {
	int row;
	int start;
	int end;
	int value;
	struct Number *next;
};

struct Number *lineToNumbers(char *line, int lineNo);
struct Number *end(struct Number *num);
int isValid(struct Number *num, char lines[NUM_LINES][LINE_LENGTH+1]);            

int main() {

  char lines[NUM_LINES][LINE_LENGTH+1];

	for (int i=0; i<NUM_LINES;i++) {
		char* str_read = fgets(lines[i],LINE_LENGTH+1, stdin);

	}



	struct Number *first = lineToNumbers(lines[0], 0);
	struct Number *current = first;
  	for (int l=1; l < NUM_LINES; l++) {
		struct Number *cur = lineToNumbers(lines[l], l);
		if (cur != NULL) end(first)->next = cur;
		else printf("was null %d\n", l); 
		
	}

	long sum = 0;
	while(current != NULL) {
		/*printf("line: %d: %d\n", current->row, current->value); */
    if (isValid(current, lines) == 1) {
			printf("%d is valid\n", current->value);
			sum += current->value;
		} else printf("%d not valid\n", current->value);
		current = current->next;
	}
	printf("Total: %ld\n", sum);


	return 0;

}

int isValid(struct Number *num, char lines[NUM_LINES][LINE_LENGTH+1]) {
  int valid = 0;
	
	if (num->start != 0) {
		/* printf("%d, %s %d\n", num->row, lines[num->row], num->start);*/
		if (lines[num->row][num->start-1] != '.') valid =1; 
  }

	if (num->end != LINE_LENGTH-2) {
    	/* printf("%d, %s %d\n", num->row, lines[num->row], num->end); */ 
	 if (lines[num->row][num->end+1] != '.') valid=1;
	} 

	int start = num->start -1;
	if (start < 0) start = 0;

	int end = num->end + 1;
	if (end == LINE_LENGTH-1) end--;

	if (num->row > 0) {
		for (int i=start; i<=end; i++) {
			char c = lines[num->row-1][i];
			/* printf("%c", c); */ 
			if(!isdigit(c) && c != '.') valid=1;
		}
		/* printf("]\n"); */
	}
	
	if (num->row < NUM_LINES-1) {
		for (int i=start; i<=end; i++) {
			char c = lines[num->row+1][i];
			if(!isdigit(c) && c != '.') valid=1;
		}
	}


	return valid;
}

struct Number *end(struct Number *num) {
	struct Number *current = num;
	while (current->next != NULL) {
		current = current->next;
	}
	return current;
}
	

struct Number *lineToNumbers(char *line, int lineNo) {
  
  int s = -1;	

	struct Number *first = NULL;
	struct Number *prev = NULL;
	struct Number *current = first;

	/* printf("%d: %s\n", lineNo, line); */

	for (int j=0; j<LINE_LENGTH;j++) {
		if (isdigit(line[j]) && s==-1) {
    	s = j;
		} else if ((!isdigit(line[j]) || j == LINE_LENGTH -1) && s != -1) {	
			char *wrk = malloc(sizeof(char) * (j-s)+1);			
			for (int n=s;n<j;n++) {
				if (isdigit(line[n])) wrk[n-s]=line[n];
			}
			wrk[j-s] = '\0';
			
			if (current == NULL) current = malloc(sizeof(struct Number));
			if (first == NULL) first = current;
      			if (prev != NULL) prev->next = current;
   
			current->row = lineNo;
			current->start = s;
			current->end = j-1;
			current->value = atoi(wrk);
			current->next = NULL;
			/* printf("%s %d\n", wrk, current->value); */
			prev = current;
			current= NULL;
			s = -1;
			free(wrk);
		}
	}
	return first;

}
