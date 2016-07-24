#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define DEG2RAD (M_PI/180.0)
#define RAD2DEG (180.0/M_PI)

//行列を表す構造体のテンプレート
struct matrix{
  int low;    //行列の行数
  int column; //行列の列数
  double* data;  //行列の中身を格納するポインタ
};

//ベクトルを表す構造体のテンプレート
struct vector{
  int low;    //ベクトルの次元数
  int column;
  double* data;  //行列の中身を格納するポインタ
};

//行列の生成
int matrixCreate(int low, int column, double* matdata,struct matrix *mat){
  mat->data = matdata;
  mat->low = low;
  mat->column = column;
  return 0;
}

//ベクトルの生成（実際はベクトルは１列の行列と同じ）
int vectorCreate(int low, double* vectordata,struct vector *vector){
  vector->data = vectordata;
  vector->low = low;
  vector->column = 1;
  return 0;
}

//行列表示
int matrixPrint(struct matrix mat){
  int i,j;
  for (i=0; i<mat.low; i++) {
    for (j=0; j<mat.column; j++) {
      printf("%10.3f ",*(mat.data+j+i*mat.column));
      //printf("hoge");
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}

//行列の掛け算
int matrixMulti(struct matrix A, struct matrix B, struct matrix Ans){

  int i, j, k;
  double sum;

  if(A.column!=B.low) {
    printf("Error! Can not caliculation !");
    return 1;
  }
  Ans.low = A.low;
  Ans.column = B.column;
  
  for (i=0;i<A.low;i++){
    for(j=0;j<B.column;j++) {
      sum = 0.0;
      for(k=0;k<A.column;k++) {
        sum = sum + (*(A.data+k+A.column*i)) * (*(B.data+j+B.column*k));
      }
      *(Ans.data+j+B.column*i) = sum;
    }
  }

  return 0;

}

//x軸周りの回転行列生成
int createRotX(double phi, struct matrix *mat){
  *(mat->data + 3 * 0 + 0 ) =  1.0;
  *(mat->data + 3 * 0 + 1 ) =  0.0;
  *(mat->data + 3 * 0 + 2 ) =  0.0;

  *(mat->data + 3 * 1 + 0 ) =  0.0;
  *(mat->data + 3 * 1 + 1 ) =  cos(phi);
  *(mat->data + 3 * 1 + 2 ) =  sin(phi);

  *(mat->data + 3 * 2 + 0 ) =  0.0;
  *(mat->data + 3 * 2 + 1 ) = -sin(phi);
  *(mat->data + 3 * 2 + 2 ) =  cos(phi);
  return 0;
}

//y軸周りの回転行列生成
int createRotY(double theta, struct matrix *mat){
  *(mat->data + 3 * 0 + 0 ) =  cos(theta);
  *(mat->data + 3 * 0 + 1 ) =  0.0;
  *(mat->data + 3 * 0 + 2 ) = -sin(theta);

  *(mat->data + 3 * 1 + 0 ) =  0.0;
  *(mat->data + 3 * 1 + 1 ) =  1.0;
  *(mat->data + 3 * 1 + 2 ) =  0.0;

  *(mat->data + 3 * 2 + 0 ) =  sin(theta);
  *(mat->data + 3 * 2 + 1 ) =  0.0;
  *(mat->data + 3 * 2 + 2 ) =  cos(theta);
  return 0;
}

//z軸周りの回転行列生成
int createRotZ(double psi, struct matrix *mat){
  *(mat->data + 3 * 0 + 0 ) =  cos(psi);
  *(mat->data + 3 * 0 + 1 ) =  sin(psi);
  *(mat->data + 3 * 0 + 2 ) =  0.0;

  *(mat->data + 3 * 1 + 0 ) = -sin(psi);
  *(mat->data + 3 * 1 + 1 ) =  cos(psi);
  *(mat->data + 3 * 1 + 2 ) =  0.0;

  *(mat->data + 3 * 2 + 0 ) =  0.0;
  *(mat->data + 3 * 2 + 1 ) =  0.0;
  *(mat->data + 3 * 2 + 2 ) =  1.0;
  return 0;
}

int matrixTranspose(struct matrix src, struct matrix dst){
  int i,j;
  if (src.low != dst.column || src.column != dst.low ){
    printf("Error! Cannot transpose this source matrix!\n");
    return 1;
  }

  for (i=0; i < dst.low; i++) {
    for (j=0; j < dst.column; j++ ) {
      *(dst.data+dst.column*i+j)=*(src.data+src.column*j+i);
    }
  }

  return 0;
}


#if 0
int main(){
  double a[]={1.0, 2.0, 3.0, 4.0};
  double b[]={5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
  double c[6]={0.0};
  double d[6]={0.0};
  double rotx[9]={0.0};
  double roty[9]={0.0};
  double rotz[9]={0.0};
  double rot[9]={0.0};
  double dummy[9]={0.0};
  struct matrix A;
  struct matrix B;
  struct matrix C;
  struct matrix D;
  struct matrix RotX;
  struct matrix RotY;
  struct matrix RotZ;
  struct matrix Rot;
  struct matrix Dummy;

  
  double phi = 45*DEG2RAD;
  double theta = 45*DEG2RAD;
  double psi= 45*DEG2RAD;

  matrixCreate(2, 2, a, &A);
  matrixCreate(2, 3, b, &B);
  matrixCreate(2, 3, c, &C);
  matrixCreate(3, 2, d, &D);
  matrixCreate(3, 3, rotx, &RotX);
  matrixCreate(3, 3, roty, &RotY);
  matrixCreate(3, 3, rotz, &RotZ);
  matrixCreate(3, 3, rot,  &Rot);
  matrixCreate(3, 3, dummy, &Dummy);
  createRotX(phi,   &RotX);
  createRotY(theta, &RotY);
  createRotZ(psi,   &RotZ);


  printf("Create matrix A and B.\n");
  matrixPrint(A);
  matrixPrint(B);

  printf("Multiple matrix A and B.And answer is matrix C.\n");
  matrixMulti(A, B, C);
  matrixPrint(C);

  printf("Transpose matrix C.\n");
  matrixTranspose(C,D);
  matrixPrint(D);
  
  printf("RotX.\n");
  matrixPrint(RotX);
  
  printf("RotY.\n");
  matrixPrint(RotY);
  
  printf("RotZ.\n");
  matrixPrint(RotZ);
 
  printf("Euler Matrix.\n");
  matrixMulti(RotX, RotY, Dummy);
  matrixMulti(Dummy, RotZ, Rot);
  matrixPrint(Rot);

  return 0;
}
#endif

