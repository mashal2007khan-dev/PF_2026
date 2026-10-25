#include <stdio.h>
 void reverseArray (int *arr, int n){
 	//int *start = arr; — start array ke pehle element ko point karega.int *end = arr + n - 1; — end array ke aakhri element ko point karega.
//while (start < end) — jab tak dono pointers mil nahi jaate, swapping hoti rahegi.temp = *start; — start wali value temporary save karo.
//*start = *end; — end wali value start par rakho.
//*end = temp; — purani start wali value end par rakho.
//start++ — start pointer ek element aage.
//end-- — end pointer ek element peeche.
 	int temp,start,end;
 	for ( int i=0; i< n/2; i++){
 int *start = arr;
    int *end = arr + n - 1;
    int temp;
	while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
}
 void printArray ( const int *arr, int n){
 	for ( int i =0; i<n; i++){
 		printf ("  %d", *(arr+i) );	
	 }
	 printf ("\n");
	 }	 
int main() {
    int n, arr[20];

    do {
        printf("Enter number of songs: ");
        scanf(" %d", &n);
        if (n < 1 || n > 20) {
		
            printf("Invalid size\n");
        }
    } while (n < 1 || n > 20);

    printf("Enter song IDs: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Original: ");
    printArray(arr, n);

    reverseArray(arr, n);

    printf("Reversed: ");
    printArray(arr, n);

    return 0;
}
 	
 	
 	
 	
 	
 	
 	
 