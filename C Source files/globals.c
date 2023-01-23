#include "trove.h"
// Initializiang global defines

bool build_flag = false;    //global is initialiazed
bool update_flag = false;   //global is initialiazed
bool remove_flag = false;   //global is initialiazed
bool length_flag = false;
bool file_flag = false;
// Initializiang global variables
int nfiles = 0;
int nfiles2 = 0;
int nfiles3 = 0;
int nwords2 = 0;
int nwords3 = 0;
int nwords = 0;
int nsearches = 0;

// Initializiang global defines
char *trove_file = DEFAULT_TROVE_FILE_NAME;
int word_length = DEFAULT_WORD_LENGTH;
char *progname = NULL;

// Initializing global Structures
FILES   *files_struct  = NULL;
WORDS   *words_struct  = NULL;
UNIQUE  *unique_struct = NULL;
READ    *read_struct = NULL;
SEARCH  *search_struct = NULL;

