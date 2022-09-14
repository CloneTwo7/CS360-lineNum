#include <stdio.h>

int lineNum(char*, char*, int);

int main(int argc, char** argv) {

	char word[16] = "fi sh";
	printf("%s is found on line %d\n", word, lineNum("webster_16", word, 16));

	return(0);
}
