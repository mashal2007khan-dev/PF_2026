#include<stdio.h>
#include<string.h>
int main (){
char name[5][50];
char temp[50];
for(int i=0; i<5; i++){
	printf("Enter the name of student %d: \n",i+1);
	scanf("%s", name[i]);
}
for (int i=0; i<5; i++){
 for( int j=0; j< 5-i; j++){      // j ko i sy ek number kam hona chahiye tabhi wo do neighbour strings ko compare kary ga
 	if ( strcmp(name[j], name[j+1])  > 0){
 		strcpy(temp,name[j]);
 		strcpy(name[j], name[j+1]);	
 		strcpy (name[j+1],temp);		 
		  }
 	
 }
}
printf("===SORTED NAMES===\n");
for( int i=0; i<6; i++){
printf("%s\n", name[i]);
}
 return 0;
}