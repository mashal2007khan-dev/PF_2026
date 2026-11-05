#include<stdio.h>
#include<string.h>
int main(){
char firstname[20];
char lastname[20];
char fullname[50] =" ";
	printf("Enter your first name: ");
	scanf(" %s",firstname);
	printf("Enter your last name: ");
	scanf(" %s",lastname);	
	strcat(fullname,firstname);
	strcat(fullname, " ");
	strcat(fullname, lastname);
	printf("Full name: %s\n", fullname);	
	
	return 0;
}