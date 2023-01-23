#include "trove.h"


void list_all_words(void)
{
    for(int n=0 ; n<nwords ; ++n) {
        printf( "%s\n",words_struct[n].words);
    }
}



void find_words(char *filename,int length)
{
    FILE *file_pointer = fopen(filename,"r");

	if(file_pointer == NULL) {
		fprintf(stderr,"File: %s cannot be opened",filename);
			exit(EXIT_FAILURE);
	} 

    char line[BUFSIZ];

    while(fgets(line,sizeof line, file_pointer) != NULL) {
        int s = 0;

        while(line[s] != '\0') {
            char word[BUFSIZ];
            int w = 0;

            while(isalnum(line[s]) ) {
                word[w++] = line[s++];
            }

            if(w >= length) {
                word[w] = '\0';
                unique_words(word);       
                words_struct = realloc(words_struct, (nwords+1) * sizeof(words_struct[0]));
                words_struct[nwords].words = strdup(word);
                words_struct[nwords].pathfile = strdup(filename);
                ++nwords; 
            }

            while(line[s] != '\0' && !isalnum(line[s])) {
                ++s;
            }
        }
    }
    fclose(file_pointer);
}