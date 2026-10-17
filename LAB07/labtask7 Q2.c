#include<stdio.h>
// yaha n sy murad size of matrix hai.
long long determinant(int mat[5][5], int n)
{
	//agr size of matrix 1 hai mtlb 1x1 ka matrix hai tu hum wo single element return kardy gaye
    if(n == 1)
    {
        return mat[0][0];
    }
// Ye int minor ek temporary matrix hai jisme hum original matrix ki selected row aur column remove karne ke baad bache hue elements copy karte hain.
    long long det = 0;
    int minor[5][5];
   // Yahan j first row ke har column ko select karta hai.
    for(int j = 0; j < n; j++)
    {
    //r temporary minor matrix ki row position batata hai. Har nayi minor matrix banate waqt ise 0 se start karte hain.
        int r = 0;
// i=1 sy start horha hai tu ye zero index wali row ko delete karky baqi bachy hoye matrix element ko likh dy ga
//c temporary minor matrix ke column ki position hai. Har original row ke liye ise dobara 0 karte hain, taake minor matrix ke elements sahi columns mein copy hon.
// i = original matrix ki row select karta hai. j = first row mein woh column select karta hai jise remove karna hai. k = abhi kaunsa column check ho raha hai.r = minor matrix mein row position batata hai.
// c = minor matrix mein column position batata hai.
        for(int i = 1; i < n; i++)
        {
            int c = 0;
            for(int k = 0; k < n; k++)
            {
                if(k == j)
                {
                    continue;
                }
                //original matrix ka element minor(temporary matrix) mai store hojaye ga.
                minor[r][c] = mat[i][k];
                //ek columns badha do mtlb dosry columns pr ajao
                c++;
            }
//phir next rows mai ajao.
            r++;
        }
        //  subdet mai ab minor ka det ly kar store kay gaye.
        long long subDet = determinant(minor, n - 1);
        // agr j even hai tu plus hoga warna minus hoga.
        if(j % 2 == 0)
        {
            det += (long long)mat[0][j] * subDet;
        }
        else
        {
            det -= (long long)mat[0][j] * subDet;
        }
    }
    return det;
}

int main(){
int mat[5][5];
    int rows, cols;
    int zero = 1, identity = 1;
    int diagonal = 1, scalar = 1;
    int upper = 1, lower = 1;
    int symmetric = 1, skew = 1;
    int idem = 1, nil = 0;
    int product[5][5];
    int power[5][5];
    printf("enter the rows and columns of matrix:\n");
scanf("%d %d",&rows, &cols);
if(rows<1 || rows>5 || cols<1 || cols>5){
	printf("invalid matrix size!\n");
	return 0;
}
 else{
	printf("enter the matrix elements:\n");
	for( int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
				scanf("%d",&mat[i][j]);
		}
		continue;
	}
}
printf("THE MATRIX HAS FOLLOWING TYPES:\n");	
if(rows == cols){
	printf("square matrix\n");
} else{
	printf("rectangular matrix;\n");
}
if(rows ==1){
	printf("row matrix\n");
}
if(cols==1){
	printf("column matrix\n");
}
int a = mat[0][0];
//zero = 1 ka matlab abhi hum assume kar rahe hain ke matrix 'zero matrix' hai.
//Agar koi bhi element 0 ke equal nahi hai, toh zero = 0 ho jayega or kuch bhi print nhi hoga matlb condition false hai.
//Agar saare elements 0 hon, toh zero ki value 1 hi rahegi aur message print hoga
for( int i=0; i<rows; i++){
	for ( int j=0; j<cols; j++){
		if(mat[i][j] != 0){
			zero=0;
		}
	}
}
if(zero==1){
	printf("zero matrix\n");
	printf("null matrix\n");
}
for( int i=0; i<rows; i++){
	for ( int j=0; j<cols; j++)	{
		// agr i and j barabar nhi hai or unky elements non zero bhi nhi hai tu diagnol ki condition fail hojayegi
if(i!=j && mat[i][j] !=0){
	diagonal = 0;
}
 //agr diagnol element 1 ky equal na ho tu identity matrix ki comdition false hojaye gi.
 if(i==j  && mat[i][j] !=1) {
 	identity =0;
	 }
 // agr diagonal element ky ilawa sary element non zero jo tabhi condition false hojaye gi.
	  if (i!=j && mat[i][j]!=0){
	 identity = 0;
}
 // agr off diaganol element non zero ho tu scalar ki condition fail hojaye gi.
 if(i!=j && mat[i][j] !=0)  {
  scalar =0;
}
//agr diaganol element kisi constant ky equal nhi hogaye tu scalar condtion fail hojaye gi.
if(i == j && mat[i][j] !=a){
	scalar = 0;
	
}
}
}
//agr diagnol ki condition true hogi tu message print hoga
if(rows == cols && diagonal == 1){
	printf("diaganols matrix\n");
}// agr identity ki condotion true hojaye gi tu statement print hojaye gi	
if(rows == cols && identity == 1){
	 	printf("identity matrix\n");
	 }
	 // isi tarah scalar ky sath bhi hoga.	 		
if (rows == cols && scalar ==1)	{
	printf("scalar matrix\n");
}
for( int i=0; i<rows; i++){
	for ( int j=0; j<cols; j++)	{
if(i>j && mat[i][j]!=0){
	upper=0;
}	
if(i<j && mat[i][j]!=0 ){
 	lower =0;
}	
}
}
if( rows == cols && upper == 1){
	printf("upper triangular matrix\n");
}
if(rows == cols && lower == 1){
	printf("lower triangular matrix\n");
}	
for( int i=0; i<rows; i++){
	for ( int j=0; j<cols; j++)	{	
	if(mat[i][j]!= mat [j][i]){
		symmetric = 0;
	}
	if ( mat[i][j]!=  - mat[j][i])
{
	skew = 0;
	}	
}
}
if( rows == cols && symmetric ==1 ){
	printf("symmetric matrix\n");
}
if(rows == cols && skew == 1){
	printf("skew symmetric \n");
}
for( int i=0; i<rows; i++){
	for ( int j=0; j<cols; j++)	{
		product[i][j]=0;
		for(int k=0; k<cols ; k++){
			// product[i][j] mai hum har multiplied value ko add karwa kar store karye gaye.
	product[i][j] += mat[i][k] * mat[k][j];
       }// agr multiplied matrix ka answer original matrix ky equal nhi ha tu wo idempotent nhi hai.
       	if(product[i][j] != mat[i][j]){
		idem =0;
	}
		if( product[i][j] != 0	){
	nil = 0;
    }
}
}
if (rows == cols && idem == 1){
	printf("idempotent matrix\n");
}//  original matrix ko power waly matrix ky andar store karwaye gaye.
if( rows == cols){	
for( int i=0; i<rows; i++){
	for ( int j=0; j<cols; j++)	{
 power[i][j] = mat[i][j];
     }
   }
 for(int p = 1; p < rows; p++){
        int zeroPower = 1;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                product[i][j] = 0;

                for(int k = 0; k < cols; k++){
                	// power waly matrix ky har element ko original matrix ky element sy multiply karo or then add karo or phir usy product waly matrix mai store karo.
                    product[i][j] += power[i][k] * mat[k][j];
                }
            }
        }
// ab power waly matrix ko update karo product waly matrix sy.
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                power[i][j] = product[i][j];

                if(power[i][j] != 0){
                    zeroPower = 0;
                }
            }
        }

        if(zeroPower == 1){
            nil = 1;
            break;
        }
    }
}

if(rows == cols && nil == 1){
    printf("nilpotent matrix\n");
}
int equal = 1;
int rows1, cols1, rows2, cols2;
int mat1[5][5], mat2[5][5];
if(rows1 != rows2 || cols1 != cols2){
    equal = 0;
}
else{
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols1; j++){
            if(mat1[i][j] != mat2[i][j]){
                equal = 0;
            }
        }
    }
}

if(equal == 1){
    printf("Equal matrices\n");
}
else{
    printf("Not equal matrices\n");
}

if(rows == cols)
{
    long long det = determinant(mat, rows);

    printf("Determinant = %lld\n", det);

    if(det == 0)
    {
        printf("Singular matrix\n");
    }
    else
    {
        printf("Non-singular matrix\n");
    }
}
else
{
    printf("Determinant is defined here only for square matrices\n");
}


	return 0;
}