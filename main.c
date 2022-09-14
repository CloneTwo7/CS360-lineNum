#include <stdio.h>

int lineNum(char*, char*, int);

int main(int argc, char** argv) {

	
	char words[16][16] = {"acid", "mellow", "acknowledgeable", "acknowledgeables", "youth", "zoo", "abc", "fi sh", "000", "a b c"};


	printf("line number: \t%d\n", lineNum("webster_16", words[0], 16));
	printf("line number: \t%d\n", lineNum("webster_16", words[1], 16));
	printf("line number: \t%d\n", lineNum("webster_16", words[2], 16));
	printf("line number: \t%d\n", lineNum("webster_16", words[3], 16));
	printf("line number: \t%d\n", lineNum("webster_16", words[5], 16));
	printf("line number: \t%d\n", lineNum("webster_16", words[6], 16));
	printf("line number: \t%d\n", lineNum("webster_16", words[7], 16));
	printf("line number: \t%d\n", lineNum("webster_16", words[8], 16));
	return(0);
}
