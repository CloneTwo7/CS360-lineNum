#include <stdio.h>

int lineNum(char*, char*, int);

int main(int argc, char** argv) {

	
	char words[16][16] = {"acid", "mellow","youth", "acknowledgeable", "acknowledgeables", "zoo", "abc", "fi sh", "000", "a b c"};

	
	printf("line number: \t%d\n", lineNum("webster_16", words[0], 16));
        printf("line number: \t%d\n", lineNum("tiny_9", words[0], 9));
	printf("line number: \t%d\n", lineNum("webster_16", words[1], 16));
	printf("line number: \t%d\n", lineNum("tiny_9", words[1], 9));
	printf("line number: \t%d\n", lineNum("webster_16", words[2], 16));
	printf("line number: \t%d\n", lineNum("tiny_9", words[2], 9));
	printf("line number: \t%d\n", lineNum("webster_16", words[3], 16));
	printf("line number: \t%d\n", lineNum("tiny_9", words[3], 9));
	printf("line number: \t%d\n", lineNum("webster_16", words[4], 16));
	printf("line number: \t%d\n", lineNum("tiny_9", words[4], 9));
	printf("line number: \t%d\n", lineNum("webster_16", words[5], 16));
	printf("line number: \t%d\n", lineNum("tiny_9", words[5], 9));
	printf("line number: \t%d\n", lineNum("webster_16", words[6], 16));
	printf("line number: \t%d\n", lineNum("tiny_9", words[6], 9));
	printf("line number: \t%d\n", lineNum("webster_16", words[7], 16));
	printf("line number: \t%d\n", lineNum("tiny_9", words[7], 9));
	printf("line number: \t%d\n", lineNum("webster_16", words[8], 16));
	printf("line number: \t%d\n", lineNum("tiny_9", words[8], 9));
	printf("line number: \t%d\n", lineNum("webster_16", words[9], 16));
	printf("line number: \t%d\n", lineNum("tiny_9", words[9], 9));
	
	
	return(0);
}
