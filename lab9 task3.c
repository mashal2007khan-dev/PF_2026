#include<stdio.h>
#include<string.h>
int main(){
 char str1[20] = "lab10pass";
 char str2[20];
printf("Enter the passwords:");
scanf("%c", str2 );
strncmp (str1,str2,20);
if( str1 == str2){
	printf("Access granted\n ");
	if(strncmp(str1, str2, 3)){
		printf("First 3 character match!");
	}
}
else{
	printf("Access denied\n");
		if(strncmp(str1, str2, 3)){
		printf("First 3 character match!");
	}else{
		printf("First 3 charcter not match!");
	}
}
	return 0;	
}