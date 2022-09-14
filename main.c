#include <stdio.h>

int lineNum(char*, char*, int);

int main(int argc, char** argv) {

	char *word = "mellow";
	printf("%s is found on line %d\n", word, lineNum("tiny_9", word, 9));

	return(0);
}
