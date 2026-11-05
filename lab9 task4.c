#include<stdio.h>
#include<string.h>
int main (){
char sentence[50];
char word = 'a';
printf("Write a sentence: ");
fgets(sentence, 50,stdin);
char *p;
p = strchr(sentence,word);
if (strchr(sentence,word)){
	printf("character %c is found at index %td\n",word,p-sentence);
}else{
		printf("character %c is not found\n",word);
	}
char sub[] = "good";
if (strstr(sentence,sub )) {
printf("word %s is found\n",sub);
}
else{
	printf("word %s is not found \n", sub);
}	
	
return 0;	
}
