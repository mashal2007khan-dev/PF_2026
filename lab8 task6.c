#include<stdio.h>
int deposit ( float *balance, float amount){
	if (  amount <= 0 ){
		return 0;
	}
	*balance = *balance + amount;
	return 1;
}
int withdraw(float *balance, float amount){
	if(amount > *balance || amount <= 0)
{
	return 0;
} 
*balance = *balance - amount;
return 1;
}
int main (){
int choice, result;
float amount, balance=1000;
do{
printf(" choose an option ( 1-4):  ")	;
scanf (" %d", &choice);
switch ( choice){
	case 1: 
	printf("enter the amount: ");
	scanf ("%f", &amount);
	if ( amount <= 0 ){
		printf(" invalid amount !\n");
	}else{
	result = deposit(&balance, amount);
	
	printf("amount deposited successfully\n");
}
	break; 
    case 2:
	printf (" enter the withdrwal amount:  ");	
	scanf ("%f", &amount);
		if ( amount <=0  ){
		printf(" insufficient funds or invalid amount!\n");
	}else{
	result = withdraw ( &balance, amount);
	if ( result ==1){
	
	printf("amount withdrwal successfully\n");
} else {
	printf ("invalid amount!");
}
	}
	break;
	case 3:
		printf(" current balance is: %.2f\n", balance);
		break;
		case 4: 
		printf("GOOD BYE!\n");
		break;
		default:
		 printf("invalid options\n");	
}
} while ( choice !=4);
return 0;	
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
