#include <stdio.h>
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int lineNum(char *dictionaryName, char *word, int dictWidth) {
	int offst = 0;
	int fd = 0;
	int top = 0;
	int bot = 0;
	char wordBuff[dictWidth];

	
	//The following loop builds our compare buffer
	int i = 0;
	int readNull = 0;
	while(i < dictWidth) {
		if(word[i] == '\0') {
			readNull = 1;
		}
		if(word[i] != '\0'&&readNull==0) {
			wordBuff[i] = word[i];
		} else if(i < dictWidth -1) { 
			wordBuff[i] =  ' ';
		} else {
			wordBuff[i] = '\n';
		}
		i++;
	}
	if(i == dictWidth) {
		wordBuff[i-1] = '\n';
		wordBuff[i] = '\0';
	}

	//Opens files and uses lseek to prepare binary search
	fd = open(dictionaryName, O_RDONLY);
	if(fd < 0) { //checks errors
		fprintf(stderr, "Can't open %s for reading -- %s\n", dictionaryName, strerror(errno));
		exit(errno);
	}

	top = lseek(fd, offst, SEEK_END);
	if(top < 0) { //checks errors
		fprintf(stderr, "lseek() failed to navigate -- %s\n", strerror(errno));
		exit(errno);
	}
	//initializes variables for bs	
	top = top - dictWidth;
	int numElem = top/dictWidth;
	offst = numElem/2 * dictWidth;

	//the following loop incremenets through the file utilizing binary search to determine wheather the words are 
	//earlier or later in the alphabet
	char *readBuff = calloc(1, sizeof(char) * dictWidth);
	while(offst <= top && offst >= bot) {

		int erCheck = lseek(fd, offst, SEEK_SET);
		if(erCheck < 0) {
			fprintf(stderr, "lseek() failed to navigate -- %s\n", strerror(errno));
			exit(errno);
		}
		erCheck = read(fd, readBuff, dictWidth);
		if(erCheck == -1) {
			fprintf(stderr, "failed to read file %s Following error occured: %s\n", dictionaryName, strerror(errno));
			exit(errno);
		}

		readBuff[dictWidth] = '\0';
		int result = strcmp(readBuff, wordBuff);
		if(result == 0) { //Word found, free buffers and return line
			free(readBuff);
			close(fd);
			return (offst / dictWidth +1);
		}
		else if (result > 0) { //word not found

			numElem = numElem/2; //adjust the top/bot
			if(numElem < 2) numElem = 2;
			top = offst; 
			offst = bot;
			if(top - dictWidth == bot || top == bot) { 
				free(readBuff); //returns the last line searched
				close(fd);
				return (- (offst / dictWidth + 1));
			}
		} else if (result < 0) { //word not found
			numElem = numElem/2; //adjust the top/bot
			if(numElem < 2) numElem = 2;
			bot = offst;
			offst = offst + numElem/2 * dictWidth;
			if(top <= bot) { //at a certain point, return the last line searched
				free(readBuff);
				close(fd);
				return (- (offst / dictWidth ));
			}
		}
	}

}
