#include<stdio.h>
#include<string.h>
#include <stdlib.h>;
int main (){
char name[50];
int count=0;
	FILE *fptr;
	fptr = fopen("students.txt","w"); //file mai writing ky liye 
	if(fptr == NULL)//file mai agr koi null ha tu usy identify karky error print karna
 {
 printf("Error!");
 exit(1);
 }
for ( int i=0; i<3; i++){
	printf("Enter the student %d name:  \n",i+1);
 fgets( name, 50 , stdin);	
  name[strcspn (name,   "\n")] = '\0';	
  fprintf(fptr, "%s\n", name); //file mai name store karyga
 	}	
	fclose(fptr);   //to close the file
	fptr = fopen("students.txt","r");//file ko read karyga
		if(fptr == NULL)
 {
 printf("Error!");
 exit(1);
	 }
while	(fgets(name, 50 , fptr)){

	count++;
	 name[strcspn (name,   "\n")] = '\0';	
	printf("%d. %s\n",count,name);
	
}
printf("Total student in file: %d",count);
	fclose(fptr);
	return 0;
}