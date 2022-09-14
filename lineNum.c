#include <stdio.h>
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int lineNum(char *dictionaryName, char *word, int dictWidth) {
	int rofst, offst, fd, top;
	int bot = 0;
	char wordBuff[dictWidth];

	
	//The following loop builds our compare buffer
	int i = 0;
	while(i < dictWidth) {
		if(word[i] != '\0') {
			wordBuff[i] = word[i];
		} else if(i < dictWidth -1) { 
			wordBuff[i] =  ' ';
		} else {
			wordBuff[i] = '\n';
		}
		i++;
	}
	wordBuff[dictWidth] = '\0';

	fd = open(dictionaryName, O_RDONLY);
	if(fd < 0) { //checks errors
		//handle error
		return(0);
	}

	top = lseek(fd, offst, SEEK_END);
	if(top < 0) {
		//handle error
	}
	
	int numElem = top/dictWidth;
	offst = numElem/2 * dictWidth;

	char *readBuff = calloc(1, sizeof(char) * dictWidth);
	while(offst <= top && offst >= bot) {
		lseek(fd, offst, SEEK_SET);
		read(fd, readBuff, dictWidth);

		int result = strcmp(readBuff, wordBuff);
		if(result == 0) { //Word found, free buffers and return line
			free(readBuff);
			return (offst / dictWidth +1);
		}
		else if (result > 0) { //word not found
			numElem = numElem/2; //adjust the top/bot
			if(numElem < 2) numElem = 2;
			top = offst; 
			offst = bot;
			if(top - dictWidth == bot) { 
				free(readBuff);
				return (- (offst / dictWidth + 1));
			}
		} else if (result < 0) {
			numElem = numElem/2;
			if(numElem < 2) numElem = 2;
			bot = offst;
			offst = offst + numElem/2 * dictWidth;
			if(top - dictWidth == bot) {
				free(readBuff);
				return (- (offst / dictWidth + 1));
			}
		}
	}

}
