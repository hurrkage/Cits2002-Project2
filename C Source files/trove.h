// DECLARE GLOBAL INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

// DECLARE GLOBAL PREPROCESSOR CONSTANTS
#define DEFAULT_TROVE_FILE_NAME "/tmp/trove"
#define DEFAULT_WORD_LENGTH 4
#define	OPTLIST "bruf:l:"
#define _POSIX_C_SOURCE     200809L
#define	CHECK_ALLOC(p) if(p == NULL) { perror(__func__); exit(EXIT_FAILURE); }

// DECLARE STRUCTURES
typedef struct {
    char        *pathname;
} FILES;

typedef struct {
    char        *words;
    char        *pathfile;
} WORDS;

typedef struct {
    char        *unique_words;
    char        *unique_files;
} UNIQUE;

typedef struct {
    char        *read_words;
    char        *read_files;
} READ;

typedef struct {
    char        *searched_paths;
} SEARCH;

// DECLARE GLOBAL FUNCTIONS
extern void list_all_files();
extern void list_searched_words();
extern void unique_words(char *);
extern void unique_files(char *);
extern void scan_directory(char *);
extern void find_words(char *,int );
extern void add_word(char []);
extern FILE *open_file(char *);
extern void build_trove();
extern void trim_line(char []);
extern void read_trove_file(char *file);
extern void compress_file(char *);
extern void decompress_file(char *);
extern void search_trove_file(char *);
extern void remove_trove();

// DECLARE GLOBAL VARIABLES
extern int      nfiles;
extern int      nfiles2;
extern int      nfiles3;
extern int      nwords;
extern int      nwords2;
extern int      nwords3;
extern int      nsearches;
extern bool     build_flag;
extern bool     update_flag;
extern bool     remove_flag;
extern bool     length_flag;
extern bool     file_flag;
extern char     *trove_file;
extern int      word_length;
extern char     *progname;
extern FILES    *files_struct;
extern WORDS    *words_struct;
extern UNIQUE   *unique_struct;
extern READ     *read_struct;
extern SEARCH   *search_struct;
