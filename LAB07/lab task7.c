#include<stdio.h>
int main (){
int mat[3][3] = {{1 ,2 ,1 } ,{0 ,1 ,2 } ,{2 ,1 ,1 } };
int det;
printf("original  matrix:\n");
for (int i=0; i<3; i++){
	for(int j=0; j<3; j++){
		printf("  %d ",mat[i][j]);
	}
	printf ("\n");
	
}
printf("transpose of matrix:\n");
for(int i=0; i<3; i++){
	for (int j=0; j<3; j++){
		printf(" %d ",mat[j][i]);		
		
	}
	printf("\n");
	}	
printf("determinant of matrix:\n");
   det = 	mat[0][0]*(mat[1][1] * mat[2][2] - mat[2][1]* mat [1][2]) - mat[0][1]*(mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2]) + mat[0][2]* (mat[1][0]*mat[2][1] - mat [2][0]*mat[1][1] );	
	printf( " %d\n ", det);
printf("cofactor of matrix:\n");

    int cof[3][3];
// Ye outer loops sy hum matrix ky har element ko access kary gaye.
//ye i and j wo rows and column  hai jis ka humy cofactor calculate karna hai.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
// is temp mai hum wo four values store karwaye gaye jis ka hum ny determinanant lyna hai
            int temp[4];
            // k bataya ky kis index mai konsi value store hogi.
            int k = 0;
// r and c ko rows and columns hai jo original matrix ki hai 
            for (int r = 0; r < 3; r++) {
                for (int c = 0; c < 3; c++) {
// selected elemet ki row and column dono ko skip kardo.
                    if (r != i && c != j) {
                    	//  ab jo four vlues bachi hai unko ek alag matrx mai store karlo.
                        temp[k] = mat[r][c];
                        //k yani index barhta rehy ga or us index pr mojood value matrix mai store hoti rhy gi
                        k++;
                    }
                }
            }
// int minor 2x2 matrix ka determinant hai
            int minor = temp[0] * temp[3]
                      - temp[1] * temp[2];
// is sy hum cofactor ky sign ka pata lgye gaye. agr row and colum ka addition divided by 2 hogya or remainder 0 agya tu cofactor value ky sath minus sign lgy ga warna positive sign lgye ga.
            if ((i + j) % 2 != 0) {
                minor = -minor;
            }
//phir hum cofactor values ko cofactor waly matrix mai successfully store karwaye gaye.
            cof[i][j] = minor;
        }
    }
//ab hum print karwady gaye gye %4d sy hum har number ky beech mai 4times more space dydy gaye.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%4d", cof[i][j]);
        }
        printf("\n");
    }
printf("adjoint of matrix:\n");
for (int i =0; i<3; i++){
	for ( int j=0; j<3; j++){
		printf("%4d",cof[j][i] );
}
printf("\n");		
}	
float inv;	
printf("inverse of matrix:\n");
for (int i=0;i<3; i++){
	for (int j=0; j<3; j++)
	{
		inv = cof[j][i];
		inv = inv / det;
printf("%8.2f", inv);	
	}
	printf("\n");
}	
	return 0;
}