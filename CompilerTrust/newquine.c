#include<stdio.h>
char*f="#include<stdio.h>%cchar*f=%c%s%c;%c%cmain()%c{%c%cprintf(f,10,34,f,34,10,10,10,10,9,10,10);%c}%c";

main()
{
	printf(f,10,34,f,34,10,10,10,10,9,10,10);
}
