#include <stdio.h>
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

int lineNum(char *dictionaryName, char *word, int dictWidth) {
	int rofst, offst, fd, top;
	int bot = 0;
	char *wordBuff = calloc(1, sizeof(char) * dictWidth);
	
	//The following loop builds our compare buffer
	for(int i = 0; i < dictWidth; i++) {
		if(i < strlen(word)) {
			wordBuff[i] = word[i];
		} else if(i < dictWidth -1) { 
			wordBuff[i] =  ' ';
		} else {
			wordBuff[i] = '\n';
		}
	}

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

	while(offst <= top && offst >= bot && top > bot) {
		char *readBuff = calloc(1, sizeof(char) * dictWidth);
		lseek(fd, offst, SEEK_SET);
		read(fd, readBuff, dictWidth);

		int result = strcmp(readBuff, wordBuff);
		if(result == 0) {
			free(readBuff);
			break;
		}
		else if (result > 0) {
			numElem = numElem/2;
			if(numElem < 2) numElem = 2;
			top = offst; 
			offst = bot;
			free(readBuff);
		} else if (result < 0) {
			numElem = numElem/2;
			if(numElem < 2) numElem = 2;
			bot = offst;
			offst = offst + numElem/2 * dictWidth;
			free(readBuff);
		}
	}

	if(offst <= top && offst >= bot)  {
		return(offst);
	} else {
		return(-offst);
	}


	free(wordBuff);

}
