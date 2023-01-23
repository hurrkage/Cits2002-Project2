//  CITS2002 Project 2 2022
//  Student1:   23102622   Cura   Jericho

#include "trove.h"

void usage()
{
	fprintf(stderr,"Usage: %s  [-f trovefile] [-b | -r | -u] [-l length] filelist or %s [-f trovefile] word \n where options are: \n -b 	build a new trove-file \n -f filename	provide the name of the trove-file to be built or searched \n -l length	specify the minimum-length of words added to the trove-file \n -r		remove information from the trove-file \n -u		update information in the trove-file\n",progname,progname);
	exit(EXIT_FAILURE);
}


int main(int argc,char *argv[])
{
	int		opt;
	opterr	= 0;
	progname = argv[0];

	while((opt = getopt(argc, argv, OPTLIST)) != -1)   {  
		//  ACCEPT A BOOLEAN ARGUMENT
		if(opt == 'b') {
        	build_flag = !build_flag;
        }
		else if(opt == 'u') {
        	update_flag = !update_flag;
        }
		else if(opt == 'r') {
        	remove_flag = !remove_flag;
        }
		// ACCEPT A INTEGER ARGUMENT
		else if(opt == 'l') {
			word_length = atoi(optarg);
			length_flag = !length_flag;
        }
		// ACCEPT A STRING ARGUMENT
		else if(opt == 'f') {
			trove_file = strdup(optarg);
			file_flag = !file_flag;
        }
//  OOPS - AN UNKNOWN ARGUMENT
		else {
				argc = -1;
		}
	}

//  PROVIDE A 'USAGE' MESSAGE IF AN INVALID SWITCH PROVIDED
	if(argc <= 0) {    
        usage();
    }
	argc  -= optind;
    argv  += optind;


	if((build_flag&&remove_flag&&update_flag) | (build_flag&&remove_flag) | (remove_flag&&update_flag) | (build_flag&&update_flag)){
		usage();
	}

	if (file_flag && !build_flag && !remove_flag && !update_flag && argc == 1){
		printf("reading trove-file\n");
		printf("decompressing trove-file\n");
		//decompress_file(trove_file);
		printf("searching for %s\n",argv[0]);
		read_trove_file(trove_file);
		search_trove_file(argv[argc-1]);
		list_searched_words();
	}
	else{
		if(build_flag){
		printf("Building trove-file\n");
		for(int i=0;i<argc;++i){
			scan_directory(argv[i]);
		}
		printf("writing trove-file\n");
		build_trove();
		printf("compressing trove file\n");
		printf("%i unique files\n",nfiles);
		printf("%i unique words\n",nwords3);
		// compress_file(trove_file);
		}
		else if(remove_flag){
			printf("reading trove-file\n");
			printf("decompressing trove-file\n");
			for(int i=0;i<argc;++i){
				scan_directory(argv[i]);
			}
			read_trove_file(trove_file);
			remove_trove();
		}
		else if(update_flag){
			printf("reading trove-file\n");
			printf("decompressing trove-file\n");
		}
	}

    exit(EXIT_SUCCESS);
	return 0;
}