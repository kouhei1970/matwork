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
}

int vectorCreate(int low, double* vectordata,struct matrix vector){
  vector.data = vectordata;
  vector.low = low;
}

main(){

}

