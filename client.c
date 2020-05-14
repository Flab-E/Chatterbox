#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "manpage.h"
#include "chatbot.h"

int main( int argc, char * argv[])
{
	if(argc == 1){
		printf("Syntax: ./chatbot <Option>\nOptions: \n1.  help\n2.  run\n");
	}
	else
	{
		if(strcmp(argv[1], "help")==0){
			manpg();
		}
		if(strcmp(argv[1], "run")==0){
			run();
		}
	}
	return 0;
}

