#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum{
	UNDEFINIED = 0,
	OBJECT = 1,  //a container of key-valuse pairs{}
	ARRAY = 2,  //a sequence of values []
	STRING = 3,  //a quoted sequence of chars""
	PRIMITIVE = 4  //a number, a boolean or null
}type_t;

typedef struct{
	type_t type; //Token type
	int start; //Token start position
	int end; //Token end position
	int size; //Number of child(nested) tokens
}tok_t;

/*
typedef struct{
	tok_t tokens
}json;
*/

int main(int argc, char *argv[])
{
	char *filename = argv[1];
	FILE *fp = fopen(filename, "r");

	if(fp == NULL)
		return -1;
	
	int size;
	char *buffer;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	buffer = (char*)malloc(size+1);
		//buffer[size+1] = {0,};
		//memset(buffer, 0, sizeof(buffer)); 
	
	fseek(fp, 0, SEEK_SET); //rewind(fp);

	fread(buffer, size, 1, fp);

	printf("%s", buffer);



	fclose(fp);
	free(buffer);
	return 0;
}

