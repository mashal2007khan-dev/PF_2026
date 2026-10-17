#include <stdio.h>
int main(){
int arr[3][3][3];
int i, j, k;
int layerSum, layerMin, layerMax;
int total = 0;
int even = 0, odd = 0;
int positive = 0, negative = 0, zero = 0;
int overallMin, overallMax;
float average;

    // Input all 27 elements. i is the number of layers
    for (i = 0; i < 3; i++)
    {
        printf("\nEnter elements of Layer %d:\n", i + 1);
// j is the rows and k is the columns
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    // Initialize overall minimum and maximum
    overallMin = arr[0][0][0];
    overallMax = arr[0][0][0];

    // Analyze each layer
    for (i = 0; i < 3; i++)
    {
    	//sum = 0 nayi layer ka total zero se shuru hoga. current layer ke pehle element ko minimum maan lete hain. current layer ke pehle element ko maximum maan lete hain.
        layerSum = 0;
        layerMin = arr[i][0][0];
        layerMax = arr[i][0][0];

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                int value = arr[i][j][k];
// layer sum sy hum sirf per layer  every elements ka sum store kary gaye. or total sy sary layers ky sary elemets ko sum kary gaye.
                layerSum += value;
                total += value;
//layermin or layermax ko update karhy by comparing with other elements of same layer.
                if (value < layerMin)
                    layerMin = value;

                if (value > layerMax)
                    layerMax = value;
// overallmin and overallmax ko upadate karhy hai by comapring all elements with every layers elements.
                if (value < overallMin)
                    overallMin = value;

                if (value > overallMax)
                    overallMax = value;
//yaha even,odd,positive,negative counter hai. agr value even hai tu even counter mai 1 add kardo
                if (value % 2 == 0)
                    even++;
                else
                    odd++;

                if (value > 0)
                    positive++;
                else if (value < 0)
                    negative++;
                else
                    zero++;
            }
        }

        printf("\nLayer %d Results:\n", i + 1);
        printf("Total = %d\n", layerSum);
        printf("Average = %.2f\n", layerSum / 9.0);
        printf("Minimum = %d\n", layerMin);
        printf("Maximum = %d\n", layerMax);
    }

    // Overall analysis
    average = total / 27.0;

    printf("\n--- Overall Data Analysis ---\n");
    printf("Grand Total = %d\n", total);
    printf("Overall Average = %.2f\n", average);
    printf("Overall Minimum = %d\n", overallMin);
    printf("Overall Maximum = %d\n", overallMax);
    printf("Even Numbers = %d\n", even);
    printf("Odd Numbers = %d\n", odd);
    printf("Positive Numbers = %d\n", positive);
    printf("Negative Numbers = %d\n", negative);
    printf("Zeros = %d\n", zero);

    return 0;
}
