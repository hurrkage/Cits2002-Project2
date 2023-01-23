#include "trove.h"

void remove_trove(){
    bool check = false;
    for(int n=0;n<nfiles;++n){
        for(int i=0;i<nfiles3;++i){
            if(strcmp(files_struct[n].pathname,unique_struct[i].unique_files) == 0){
                words_struct[i].pathfile = words_struct[i+1].pathfile;
                words_struct = realloc(words_struct, (nwords-1)*sizeof(words_struct[0]));
                nwords--;
            }
            if(check == false){
                fprintf(stderr,"%s not found in trove-file\n",files_struct[i].pathname);
                exit(EXIT_FAILURE);
            }
        }
    }
}

