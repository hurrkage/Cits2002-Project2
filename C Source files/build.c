#include "trove.h"

void build_trove() {
    FILE *fp;
    fp = fopen(trove_file,"w");
    if (fp ==NULL){
        printf("file cant be opened\n");
        exit(EXIT_FAILURE);
    }
    for (int i=0;i<nwords;i++){
        char line[1000];
        sprintf(line, "%s-%s\n", words_struct[i].words,words_struct[i].pathfile);
        fwrite(line,1,strlen(line),fp);
    }
    fclose(fp);
}



