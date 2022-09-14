#include <stdio.h>

int lineNum(char*, char*, int);

int main(int argc, char** argv) {

	char word[9] = "fi sh";
	printf("%s is found on line %d\n", word, lineNum("tiny_9", word, 9));

	return(0);
}
