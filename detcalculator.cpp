#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int detcalculator(int matrix[50][50],int n){ //n = equ number 50: matrix limit
	int det=0;
	int matrix2[50][50];
	
	if (n==2) {
	 return ((matrix[0][0]*matrix[1][1])-(matrix[1][0]*matrix[0][1]));
}
else {
	for(int m=0;m<n;m++) {
		int ii=0;
		for(int i=1;i<n;i++){
			int jj=0;
			for(int j=0;j<n;j++) {
				if (j==m) continue;
				matrix2[ii][jj]=matrix[i][j];
				jj++;
			}
			ii++;
		}
		det+=pow(-1,m)*(matrix[0][m])*(detcalculator(matrix2,n-1));
	}
}

return det;
	
}

int main (void) {
	int equnum,unknum;

	puts("Enter the number of equations you have :");
		scanf("%d",&equnum);
	puts("\nEnter the number of unknowns you want to solve :");
		scanf("%d",&unknum);
		
		if (equnum!=unknum) {
			puts("\n\nUnable to solve.If you have x number of unknowns , you need to have x number of equations ."); exit(1);
	}
	
	puts("\n\nEnter the coefficients of your equations at a certain order.(if your equations are x+2y=a  and 4x+y=a then enter 1,2,4,1 in order.)");
		
	int i,j,matrix[50][50];
	for(i=0;i<equnum;i++) {
		
		for(j=0;j<equnum;j++) {
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("\nThe entered matrix is: \n");
	for(i=0;i<equnum;i++){
		for(j=0;j<equnum;j++){
			printf("(%d) ",matrix[i][j]);
		}
		puts("\n");
	}

//
	printf("\n\nThe determinant of your main coefficient matrix is : %d",detcalculator(matrix,equnum));
	//buraya kadar katsayilar matrisinin determinantýný bulmus olduk.
	
	return 0;

} 
//denklem sayisi,bilinmeyen sayisi,katsayilar matrisi,sonuclar matrisi elimizde var.simdi determinant hesaplayan bir fonksiyon kodlayacaz.
