#include "trove.h"


void trim_line(char line[]){
    int i=0;
    while(line[i] != '\0'){
        if(line[i] == '\r' || line[i]=='\n'){
            line[i] = '\0';
            break;
        }
        i = i+1;
    }
}


void read_trove_file(char *file){
    FILE *fp = fopen(file,"r");
    if(fp == NULL) {
		fprintf(stderr,"File: %s cannot be opened\n",file);
		exit(EXIT_FAILURE);
	} 
    char file_temp[1000];
    char word_temp[1000];
    char    line[BUFSIZ];
    char dash = '-';
    word_temp[0] = '\0';
    file_temp[0] = '\0';

    while(fgets(line, sizeof line, fp) != NULL) {
        trim_line(line);
        int dash_count = 0;
        for(int i=0;i<strlen(line);++i){
            if(dash_count==0){
                if(strncmp(&line[i],&dash,1) != 0){
                    strncat(word_temp,&line[i],1);
                }
                else{
                    dash_count++;
                }
            }
            else{
                strncat(file_temp,&line[i],1);
            }
        }   
    read_struct = realloc(read_struct, (nwords2+1) * sizeof(read_struct[0]));
    CHECK_ALLOC(read_struct);

    read_struct[nwords2].read_words = strdup(word_temp);
    CHECK_ALLOC(read_struct[nwords2].read_words);
    read_struct[nwords2].read_files = strdup(file_temp);
    CHECK_ALLOC(read_struct[nwords2].read_files);
    nwords2++;

    word_temp[0] = '\0';
    file_temp[0] = '\0';

    }
}


void search_trove_file(char *word){
    for(int i=0;i<nwords2;++i){
        if(strcmp(word,read_struct[i].read_words) == 0){
            search_struct = realloc(search_struct, (nsearches+1) * sizeof(search_struct[0]));
            CHECK_ALLOC(search_struct);
            search_struct[nsearches].searched_paths = strdup(read_struct[i].read_files);
            CHECK_ALLOC(search_struct[nsearches].searched_paths);
            nsearches++;
        }
    }
}

void list_searched_words(void)
{
    for(int n=0;n<nsearches;++n) {
        printf( "%s\n", search_struct[n].searched_paths);
    }
}



