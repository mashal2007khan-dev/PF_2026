#include<stdio.h>
#include<string.h>
int main (){
char cities[5][20];
int longest = 0;
int name =0 ;
for (int i=0; i<5; i++){
printf("Enter the %d city name: ",i+1);
fgets (cities[i] , 20 , stdin);
 cities[i][strcspn (cities[i],   "\n")] = '\0';	
}
for (int i=0; i<5; i++){
	int len = strlen(cities[i]);
	if(len > longest){
		longest = len;
		name = i;
	}	
}
printf("name of lengthy city: %s\n ",cities [name]);
	printf("Length: %d\n",longest);
	return 0;
}