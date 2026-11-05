#include<stdio.h>
#include<string.h>
int main(){
char name[20];
printf("Enter your name: "); 
fgets(name, sizeof(name),stdin);//fgets use karny sy hum wo string bhi READ karlyty hai jis ky beech mai spaces ajaty hai. but spaces bhi as single character count hoty hai.
name[strcspn (name,   "\n")] = '\0';//jab hum fgets use karty hai tu string ky end mai ek new invisible line ajati hai. isky liye humny ye strcspn use kia hai or end mai humny usky terminator laga dia hia.
printf("Length: %d\n",(int)strlen(name));//ye string ky character ko count karky print karta hai
char destination[20];
strcpy(destination, name );//name array ky sary character ko copy karky destintion array mai daal dyta hai
printf("Copied string: %s\n", destination);
printf("Length(name): %zu character \n", strlen(name));//ye length of name print karta hai
return 0;
}