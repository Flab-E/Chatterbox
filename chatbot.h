#include "logo.h"
#include <time.h>

void greeting();
void desc();
void chat();
void ext();
void respond(char*);
void ask(char[]);
void delay();


char user_inp[1024];


void run()      			/* the main function where it'll run */
{	desc();
	greeting();
	while(1)
	{
		chat();
	}
}	

void ext()				/* Exit if the user says bye */
{
	printf("Good Bye!\n");
	exit(1);
}

void greeting()				/* Initial greeting when the program runs */
{
	time_t t;
	char * Greet_arr[5] = {"Hi", "Hello", "Namaste", "Good Day", "Greetings"};
	int rand_num;
	srand((unsigned) time(&t));
	rand_num=rand()%4;
	printf("%s", Greet_arr[rand_num]);
	printf("\n");
}

void chat()				/* The body of the chat. has two more functions in it */
{
	printf("\n>");
	fflush(stdin);
	fgets(user_inp, 1024, stdin);
	if(strcmp(user_inp, "bye\n")==0)
		ext();
	else
		respond(user_inp);
}

void desc()				/* Print the logo and the description */
{
	char * initiate[4] = {"Initializing","Done", "Booting"};

	logo();
	printf("\n");
	for(int i =0; i<3; i++) 
	{
		printf("%s\n", initiate[i]);
		delay();
	}
	printf("\n\n\n");
}

void respond(char inp[])		/* Extract the inputs from csv file and respond if matches user input */
{
	char *temp;
	int row_count =0,  field_count=0;
	char ch[3096];
	FILE *fp = fopen("data.csv", "r");


	if(!fp)
	{
		printf("Unable to read data.csv\n");
		return;
	}	


	while(fgets(ch, 3096, fp))
	{
		field_count = 0;
		char *buf = strtok(ch, ",");
		while(buf)
		{
			if(field_count == 1) 
			{
				if(( strcmp(inp, buf)==0))
				{
					printf("%s\n", temp);
					fclose(fp);
					return;
				}
			}			
			else if(field_count == 0)
			{
				temp = buf;
			}
			else
				printf("Seems like the previous input for this question was not right.... %d\n", field_count);	
			field_count++;
			buf = strtok(NULL, ",");
		}
	}
	fclose(fp);
	ask(inp);
}

void ask(char * inp)
{
	printf("%s", inp);
	FILE * fp = fopen("data.csv", "a");
	char exp_temp[1024];
	
	printf("Hmm. I'm not quite sure how to respond to %sWhat response were you expecting?\n>",inp);
	fgets(exp_temp, 1024, stdin);
	
	char * exp_output = strtok(exp_temp, "\n");

	fputs(exp_output, fp);
	fputs(",",fp);
	fputs(inp,fp);
	fclose(fp);
	printf("Memory has been updated.\n");
}

void delay()				/* A cool delay interface made for initial boot. Extra stuff. */
{
	clock_t begin;
	double time_spent;
	unsigned int i;
	
	begin = clock();
	for(i=0;1;i++)
	{
		/*To read read Cpu time */
		time_spent = (double)(clock()-begin)/CLOCKS_PER_SEC; 
		if(time_spent >= 2.0)
			break;
	}
}








	



















