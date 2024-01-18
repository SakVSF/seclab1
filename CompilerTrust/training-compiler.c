#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

int main(int argc, char *argv[]){


int c;
int count=0;
FILE *fptr;
fptr = fopen(argv[1], "r");

if (fptr == NULL) 
    { 
        printf("Cannot open file \n"); 
        exit(0); 
    } 
    char tmp[1024];
    // Read contents from file 
    c = fgetc(fptr);
    
    
    char strc[2];
    while (c != EOF) 
    { 
        
        tmp[count]=c;
        count++;
        c = fgetc(fptr);
    } 
    tmp[count]='\0';
    fclose(fptr);
    printf("%s",tmp);
    
    
    char newDataType[6] = {'u','i','n','t','1','\0'};
    char *whereUint;
    while((whereUint = strstr(tmp, newDataType) )!= NULL){
    	strncpy(whereUint, "char ", 5);
    }//replace all occurances of unit1 in the source file (hw.c) with char
    
   //write input array to file
    fptr = fopen(argv[1],"w");
    int results = fputs(tmp, fptr);
    if (results == EOF) {
	    // Failed to write do error code here.
    }
    fclose(fptr);
    
    
    
    int len= strlen(argv[1]);
    char buf[30];
    strcpy(buf,argv[1]);
    buf[len-2]='\0';//define outputfile by removing ".c", name of the executable file

    
    pid_t child = fork();
    if(child==0){
    	
    	char * args [ ] = { "/usr/bin/gcc" , argv[1], "-o",buf, NULL } ;
    	int retval = execv("/usr/bin/gcc",args);
    	
    }
    return 0; 
}
