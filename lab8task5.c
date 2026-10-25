#include<stdio.h>

void initializeGrid (int (*grid)[5]){
 
 for ( int i =0; i<5; i++){
 	for (int j =0; j<5 ;j++){
 		grid[i][j] = 0;
	 }
 }
 grid[1][2] = 1;
 grid [2][2] = 1;
 grid [3][2]= 1;
}
void printgrid ( int (*grid)[5]){
	for ( int i =0; i<5;i++){
		for ( int j=0; j<5; j++){
		printf (" %d",grid[i][j]);	
		}
		printf ("\n");
	}
}
 int countNeighbours(int (*grid)[5], int row, int col){
 	int count=0;
 	int i,j;
 	// Current cell ke upar wali row se neeche wali row tak loop chalao.
 	
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
        	// Current cell ke left column se right column tak loop chalao.
        	// Agar row ya column matrix ki boundary se bahar ho, to us position ko skip kar do.
            if (i < 0 || i >= 5 ||j < 0 || j >= 5) {
                continue;
        }
             // Agar current position wahi cell hai jise check kar rahe hain, to usko skip kar do kyun ke cell apna neighbour nahi hota.
			           if (i == row && j == col) {
                continue;
            }
 // Sirf bit 0 check karo taake current generation ki state mile.
        // Agar neighbour alive hai to count mein 1 add kar do.
            if (grid[i][j] & 1) {
                count++;
            }
        }
    }

    return count;
}
 void nextGeneration(int (*grid)[5]) {
    // First pass: calculate and store next states
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            int alive = grid[i][j] & 1;
            int neighbours = countNeighbours(grid, i, j);

            if (alive) {
                if (neighbours == 2 || neighbours == 3) {
                    grid[i][j] |= 2;
                }
            } else {
                if (neighbours == 3) {
                    grid[i][j] |= 2;
                }
            }
        }
    }

    // Second pass: make next state the current state
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j] >>= 1;
        }
    }
}

int main(void) {
    int grid[5][5] = {0};
    int generations;

    // Initial vertical pattern
    grid[1][2] = 1;
    grid[2][2] = 1;
    grid[3][2] = 1;

    do {
        printf("Enter number of generations (0-50): ");
        scanf("%d", &generations);

        if (generations < 0 || generations > 50) {
            printf("Invalid number. Try again.\n");
        }
    } while (generations < 0 || generations > 50);

    printf("\nGeneration 0:\n");
    printgrid(grid);

    for (int i = 1; i <= generations; i++) {
        nextGeneration(grid);

        printf("\nGeneration %d:\n", i);
        printgrid(grid);
    }

    return 0;
}	



















