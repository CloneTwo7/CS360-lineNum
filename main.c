#include <stdio.h>

int lineNum(char*, char*, int);

int main(int argc, char** argv) {

	
	char word[9] = "bear";

	printf("bear\t%d\n", lineNum("tiny_9", word, 9));
	return(0);
}
