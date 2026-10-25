#include<stdio.h>
 float averageSteps(int *steps, int n){
 	float sum = 0;
 	float avg;
 	for ( int i = 0; i<n; i++){     // i day1 sy start hoga or day n tak chaly ga.
		 sum = sum + *(steps + i );//*(steps + i) = us address par stored steps ki value
		}  
		avg = sum / n;
	return avg;
 }
 int countGoalDays (int *steps, int n, int goal){
 int achivedgoal = 0;
 for ( int i =0; i<n; i++){
 
 if ( *(steps + i) >= goal){
 	achivedgoal ++;
 }
}
 return achivedgoal;
 			
 }	
int main (){
int n= 7;
int steps[7];	
int goal = 8000;
int achivedgoal;
float avg;
for ( int i = 0; i<n; i++){     // i day1 sy start hoga or day n tak chaly ga.
 	printf ("enter the steps for day %d:    ", i+1);
    scanf ("%d", (steps + i)) ;
	} // *(steps + i) = us address par stored steps ki value
 avg = averageSteps( steps, n);
achivedgoal = countGoalDays ( steps, n, goal);
printf("average steps: %.2f\n", avg);
printf ("days reached goals: %d \n", achivedgoal)	;
	
return 0;	
}	
 	
 	
 	
 	
 	
 	 


