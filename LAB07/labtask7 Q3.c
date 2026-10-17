#include <stdio.h>
int main (){
int mat1[3][3], mat2[3][3];
int r1,r2,c1,c2;
int result[3][3];

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (r1 < 1 || r1 > 3 || c1 < 1 || c1 > 3 ||
        r2 < 1 || r2 > 3 || c2 < 1 || c2 > 3)
    {
        printf("Invalid dimensions! Maximum size is 3x3.\n");
        return 0;
    }
    //first matrix ka column or second matrix ki rows same hai tu multiplication possible hogi.	
else if (c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }
    else {
	
 printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
    {
    	
	scanf("%d", &mat1[i][j]);
        }
    }	
	
  printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }	
	
	//Ye statement k loop se pehle hai, taake har naye result element ke liye zero dobara set ho. Agar ise k loop ke andar rakh dein, to har dafa purana sum reset ho jayega aur multiplication ghalat hogi.
	//k dono matrices ke matching elements ko multiply karne ke liye use hota hai.
	 for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < c1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    printf("First matrix:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            printf("%d ", mat1[i][j]);
        }
        printf("\n");
    }

    printf("Second matrix:\n");
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    printf("Result of multiplication:\n");
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

    return 0;
}
	