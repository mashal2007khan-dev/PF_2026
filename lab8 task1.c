#include<stdio.h>

void bubblesort (int *arr, int n) 
//int *arr — arr ek pointer hai jo integer array ke pehle element ka address receive karega.int n — array mein kitne scores hain, woh batata hai.
{  int i, j, temp;   
 //i-Outer loop ke passes count karta hai.j-Adjacent elements ko compare karne ke liye use hota hai.temp-Do numbers ko swap karte waqt ek number temporarily store karta hai.

	for (i =0; i< n-1; i++){
		for( j=0; j< n-1; j++){
//n-1 isliye q ky index 0 hai phely value ki
		 if(*(arr + j) > *(arr + j + 1) ){        
 //phely zero index ki value ko one index ki value sy compare karo . 
 //agr j=0 hai tu arr + 0 → pehle element ka address.
//*(arr + 0) → pehle element ki value.
// agr temp = 40 hai → 40 ko temporary variable mein save kar diya.		 		 	
		  temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
//Pehle index(mtlb index 0) mein doosre index( mtlb index 1) ki value daal do.
                *(arr + j + 1) = temp; 
// doosre index mai pehly index ki value daal do{swap karlia values ko}
            }
        }
    }
}
	
void printArray(const int *arr, int n) {
	// Function array ko print karta hai.
// const ka matlab hai ke ye function array ko modify nahi karega.
    int i;
// Pointer arithmetic se current element print karo.
    for (i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
int main (){
int n,i;
int arr[20];
do {
printf(" enter the scores (1-20):  ");
scanf ("%d", &n);
if ( n > 20 || n < 1){
	printf("invalid input! Try again");
}	
} while ( n >20 || n<1);
 // Array mein scores input karo.
    printf("Enter scores: ");

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
printArray (arr,n);
	  // Sorting se pehle original array print karo.
    printf("Before sorting: ");
    printArray(arr, n);

    // Array ko ascending order mein sort karo.
    bubblesort(arr, n);

    // Sorting ke baad array print karo.
    printf("After sorting: ");
    printArray(arr, n);
    
	return 0;
}	
	
	
	
	
	
	
	
	
	
	
	
	