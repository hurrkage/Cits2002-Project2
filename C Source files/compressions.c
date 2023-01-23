#include "trove.h"


void compress_file(char *file){

    int the_pipe[2];

    if(pipe(the_pipe) != 0){
        perror("cannot create pipe");
        exit(EXIT_FAILURE);
    }

    switch (fork()){
        case 0:
            close(the_pipe[1]);
            dup2(the_pipe[0],0);
            close(the_pipe[0]);

            execl("/usr/bin/gzip","gzip",file,NULL);
            perror("/usr/bin/gzip");

            exit(EXIT_FAILURE);
            break;

        default :
            close(the_pipe[0]);
            dup2(the_pipe[1],1);
            close(the_pipe[1]);
            break;

    }
}

void decompress_file(char *file){
    int the_pipe[2];

    if(pipe(the_pipe) != 0){
        perror("cannot create pipe");
        exit(EXIT_FAILURE);
    }

    switch (fork()){
        case 0:
            close(the_pipe[1]);
            dup2(the_pipe[0],0);
            close(the_pipe[0]);

            execl("/usr/bin/gunzip","gunzip -c",file,NULL);
            perror("/usr/bin/gunzip");


            exit(EXIT_FAILURE);
            break;

        default :
            close(the_pipe[0]);
            dup2(the_pipe[1],1);
            close(the_pipe[1]);
            break;

    }
}