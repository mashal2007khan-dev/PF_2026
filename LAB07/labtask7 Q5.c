#include<stdio.h>
int main()
{
    int arr[3][3][3];
    int i, j, k, layer;
    int same;

    // Input
    for (i = 0; i < 3; i++)
    {
        printf("Enter elements of Layer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    // Compare all pairs of layers
    for (i = 0; i < 3; i++)
    {
        for (layer = i + 1; layer < 3; layer++)
        {
            same = 1;

            for (j = 0; j < 3; j++)
            {
                for (k = 0; k < 3; k++)
                {
                    if (arr[i][j][k] != arr[layer][j][k])
                    {
                        same = 0;
                    }
                }
            }

            if (same == 1)
            {
                printf("\nLayer %d and Layer %d are IDENTICAL.\n",
                       i + 1, layer + 1);
            }
            else
            {
                printf("\nLayer %d and Layer %d are DISTINCT.\n",
                       i + 1, layer + 1);
            }
        }
    }

    return 0;
}
