#include<stdio.h>
int add(int a, int b, int *result){
*result =  a + b;
return 1;
}
int subtract(int a, int b, int*result){
	*result = a - b;
	return 1;
}
int multiply ( int a, int b, int *result){
 *result = a * b;
 return 1;
}
int divide (int a, int b, int *result ){
	if(b==0){
		return 0;
	}
	*result = a/b;
	return 1;
}
int main ()
{
	int a, b;
	int result, success;
	int choice;
	printf(" enter 1st number:\n  ");
	scanf("%d", &a);
	printf(" enter 2nd number:\n");
	scanf("%d", &b);
	do{
		printf("\n1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
	printf("enter your choice (1-5):  ");
	scanf("%d",&choice);
	switch ( choice){
		case 1:
			 success = add(a,b, &result);
			printf(" addition result : %d", result);
			break;
		case 2 :
		 success = subtract(a,b, &result);
		printf("substraction result: %d", result);
		   break;
		case 3: 
		 success = multiply (a,b, &result );
		printf ("multiply result: %d", result)	;
		break;
		case 4:
			success = divide( a,b, &result);
			if(  success == 0){
				printf("error: division by zero");
			}
			printf("division result: %d",result );
			break;
			case 5:
				printf("good bye!!!");
			default:
				printf("invalid choice! Try again.");
	}
} while ( choice !=5);
return 0;	
}





























