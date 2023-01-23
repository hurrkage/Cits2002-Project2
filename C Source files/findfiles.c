#include "trove.h"

void list_all_files(void)
{
    for(int n=0 ; n<nfiles ; ++n) {
        printf( "%s\n", files_struct[n].pathname);
    }
}

void scan_directory(char *dirname)        
{
    struct stat info_file;
    struct stat *stat_info_file = &info_file;

    stat(dirname,stat_info_file);

    if(S_ISREG(stat_info_file->st_mode)){
        char *absolutepath = realpath(dirname,NULL);
        files_struct = realloc(files_struct, (nfiles+1)*sizeof(files_struct[0]));
        CHECK_ALLOC(files_struct);	
        files_struct[nfiles].pathname = strdup(absolutepath);
        CHECK_ALLOC(files_struct[nfiles].pathname);
        find_words(absolutepath,word_length);
        ++nfiles;
    }
    else {
        DIR             *dirp;
        struct dirent   *dp;
        dirp       = opendir(dirname);
        if(dirp == NULL) {
            perror( dirname );
            exit(EXIT_FAILURE);
        }
        while((dp = readdir(dirp)) != NULL) { 
            if (strcmp (dp->d_name, ".") == 0){
            continue;
            }
            if (strcmp (dp->d_name, "..") == 0){
            continue;
            }

            struct stat     stat_info;
            struct stat  *stat_pointer = &stat_info;
            char            pathname[MAXPATHLEN];

            sprintf(pathname, "%s/%s", dirname, dp->d_name);
            char *absolutepath = realpath(pathname, NULL);
    //  DETERMINE ATTRIBUTES OF THIS DIRECTORY ENTRY
            if(stat(absolutepath , &stat_info) != 0) {
                perror( absolutepath );
                exit(EXIT_FAILURE);
            }
            else if(S_ISDIR(stat_pointer->st_mode )) {
                scan_directory(absolutepath);
                continue;
            }
            else if(S_ISREG(stat_pointer->st_mode )) {
                files_struct = realloc(files_struct, (nfiles+1)*sizeof(files_struct[0]));
                CHECK_ALLOC(files_struct);	
                files_struct[nfiles].pathname = strdup(absolutepath);
                CHECK_ALLOC(files_struct[nfiles].pathname);
                find_words(absolutepath,word_length);
                ++nfiles;
            }
            else {
                printf( "%s is unknown!\n",absolutepath );
            }   
        }
        //  CLOSE THE DIRECTORY
        closedir(dirp);
    }
}


