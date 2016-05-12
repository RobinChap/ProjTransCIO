# Makefile du serveur et du client TCP
default : servcom execute command

servcom : servcom.c
	cc -o servcom servcom.c

execute : execute.c chif.h chif.o
	cc -o execute chif.o execute.c

chif.o : chif.c chif.h
	cc -c chif.c

command : command.c
	cc -o command command.c

clean :
	rm -f servcom execute *.o

