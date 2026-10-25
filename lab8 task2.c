#include<stdio.h>
void swapvalues ( int *a, int *b){
int temp;
temp = *a ;
*a = *b;
*b = temp;
	
}
int main (){
int a,b;
printf("enter price 1 : ")	;
scanf ("%d", &a);
printf ("Enter price 2: ")	;
scanf ("%d", &b);
printf("=====BEFORE SWAP=====\n");	
printf ("Price 1:  %d\n", a);
printf ("Price 2:  %d\n", b);	
printf("=====AFTER SWAP=====\n");
swapvalues (&a,&b);
printf("price 1:  %d\n",a);
printf ( "price 2:  %d\n",b);
	return 0;
}