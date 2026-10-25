#include<stdio.h>
int sumShelf (const int *shelves, int count){ // shelf-konsa shelf, count- us shelf mai kitni books hai
int sum =0;
	for ( int j=0; j< count; j++){  //i-kis shelf par hai. or j-us shelf ki konsi book pr hai.
		sum = sum + *(shelves+ j);	// current shelf mai mojjod  current books  ki value(yani ids) access karna 
	}
   return sum ;	
}
int findLargestShelf (const int *counts, int shelves ){
int largest =0;
for (int i=0; i<shelves; i++){
	if (*(counts + i) > *(counts + largest)){
		largest = i;
	}
}
	return largest;
}

int main (){
int shelfA [3]= { 101,102,103};
int shelfB [2]= {201, 202};
int shelfC [4] = {301,302, 303, 304};
int *shelves[]= { shelfA, shelfB, shelfC};
int count[] = {3,2,4}; //Ye har shelf par books ki quantity batata hai.
	for (int i=0; i<3; i++){
		printf("shelf %d ID total : %d\n", i+1 , sumShelf(shelves [i], count[i]));	
	}
	int largest = findLargestShelf (count,3);
	printf (" Shelf with the most book: shelf %d ( %d books)\n", largest +1, count[largest]);
	return 0;	
}

