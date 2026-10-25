#include<stdio.h>
int Validmark ( int m){

if ( m > 100 || m < 0){
	return 0;
} else {
	return 1;
 }
}
void findMinMax (int arr[], int size , int *max, int *min ){
 *max = arr [0];
 *min = arr[0];
for ( int i=1; i < size; i++){
     if ( *max  < arr[i]  ){
	*max = arr [i];
    } 
     if ( *min > arr[i]){
	*min = arr [i];
       }	
	
   }
   
 
}
int main (){
    int arr[5];
    int min, max;

    for (int i = 0; i < 5; i++) { 
        do {
            printf("Enter mark %d: ", i + 1);
            scanf("%d", &arr[i]);

            if (Validmark(arr[i]) == 0) {
                printf("Invalid mark, enter again\n");
            }

        } while (Validmark(arr[i]) == 0);
    }

    findMinMax(arr, 5, &max, &min);

    printf("Lowest mark: %d\n", min);
    printf("Highest mark: %d\n", max);

    return 0;
}
















