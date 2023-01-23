# A Makefile to build 'trove' project

PROJECT =  trove
HEADERS =  $(PROJECT).h
OBJ     =  trove.o words.o findfiles.o globals.o build.o read.o compressions.o unique.o remove.o


C11     =  cc -std=c11
CFLAGS  =  -Wall -Werror


$(PROJECT) : $(OBJ)
	$(C11) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm

%.o : %.c $(HEADERS)
	$(C11) $(CFLAGS) -c $<

clean:
	rm -f $(PROJECT) $(OBJ)