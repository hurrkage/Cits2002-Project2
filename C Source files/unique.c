#include "trove.h"

void unique_words(char *newword){
    for (int w=0;w<nwords3;w++){
        if(strcmp(unique_struct[w].unique_words,newword)==0){
            return;
        }
    }
    unique_struct = realloc(unique_struct,(nwords3+1)*sizeof(unique_struct[0]));
    CHECK_ALLOC(unique_struct);
    unique_struct[nwords3].unique_words = strdup(newword);
    CHECK_ALLOC(unique_struct[nwords3].unique_words);
    nwords3++;
}

void unique_files(char *newfile){
    for (int f=0;f<nfiles3;f++){
        if(strcmp(unique_struct[f].unique_files,newfile)==0){
            return;
        }
    }
    unique_struct = realloc(unique_struct,(nfiles3+1)*sizeof(unique_struct[0]));
    CHECK_ALLOC(unique_struct);
    unique_struct[nfiles3].unique_files = strdup(newfile);
    CHECK_ALLOC(unique_struct[nfiles3].unique_files);
    nfiles3++;
}


