#include <stdio.h>
#include <math.h>

//行列を表す構造体のテンプレート
struct matrix{
  int low;    //行列の行数
  int column; //行列の列数
  double* data;  //行列の中身を格納するポインタ
}

//ベクトルを表す構造体のテンプレート
struct vector{
  int low;    //ベクトルの次元数
  double* data;  //行列の中身を格納するポインタ
}

int matrixCreate(int low, int column, double* matdata,struct matrix mat){
  mat.data = matdata;
  mat.low = low;
  mat.column = column;
  return 0;
}

int vectorCreate(int low, double* vectordata,struct matrix vector){
  vector.data = vectordata;
  vector.low = low;
  return 0;
}

int matrixPrint(struct matrix mat){
  int i,j;
  
  for (i=0; i<mat.low; i++) {
    for (j=0; j<mat.column; j++) {
      printf("%10.3f ",*(mat.data));
    }
    printf("\n");
  }
  return 0;
}

int main(){
  double a={1.0, 2.0, 3.0, 4.0};
  double b={5.0, 6.0, 7.0, 8.0};
  struct matrix A;
  struct matrix B;
  
  matrixCreate(2,2,a,A);
  matrixCreate(2,2,b,B);
  
  matrixPrint(A);
  
  return 0;
}

