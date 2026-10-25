#include<stdio.h>
void computeTotals ( int (*marks)[3], int rows, int totals[]){
for (int i=0; i<rows; i++){
	int sum =0;
	for (int j=0; j<3; j++){
		sum  = sum + *(*(marks + i) + j);	//Ye student i ke subject j ke marks access karny hai
	}
	totals [i] = sum;
	printf("total for student %d: %d\n", i+1, sum);
}	
}
int findTopper ( const int *totals , int rows){
	int highest = 0;                               // highest ko phely student ky total marks sy initilaize kardia
	for ( int i=0; i<rows; i++){
		if( *(totals + i)  >   *(totals + highest)){ // phir highest ko compare kry gaye dussre student ky total sy agr wo bara howa tu highest mai uus bachy ky marks update hojaye gaye. 
			highest = i;
		}
}
return highest;
}
int main (){
	int marks[3][3];
	int rows;
	int totals[3];
	printf("enter the number for student ( 1-3):  ");
	scanf ("%d", &rows);
	if( rows >3 || rows <1)
{
	printf(" invalid input!\n");
	return 0;
	}	for ( int  i =0; i<rows; i++){   //i-number of students hai.
	printf(" enter the marks of student %d:   ",i+1);
	for (int j=0; j<3; j++){ //j-number of subjects hai e.g subj1, subj2....... 
	scanf("%d", &marks[i][j]);		
	}
}
	computeTotals ( marks ,rows, totals);
	findTopper ( totals, rows);
	int topper = 	findTopper ( totals, rows);
	printf("Student %d is the topper of total %d", topper+1 , totals[topper]);
return 0;	
}







