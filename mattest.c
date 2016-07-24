#include "matrix.h"

#define N 2000

int main()
{
  //const int N=1000;
  int i;
  double phi=45.0*DEG2RAD;
  double theta=45.0*DEG2RAD;
  double psi=45.0*DEG2RAD;

  struct matrix P[N];
  struct matrix Pdst[N];

  struct matrix Rot;
  struct matrix RotX;
  struct matrix RotY;
  struct matrix RotZ;
  struct matrix Dummy;
  double p[N][3]={0.0};
  double pdst[N][3]={0.0};
  double rot[9]={0.0};
  double rotx[9]={0.0};
  double roty[9]={0.0};
  double rotz[9]={0.0};
  double dummy[9]={0.0};

  //Make Rot matrix
  matrixCreate(3, 3, rot,  &Rot);
  matrixCreate(3, 3, rotx, &RotX);
  matrixCreate(3, 3, roty, &RotY);
  matrixCreate(3, 3, rotz, &RotZ);
  matrixCreate(3, 3, dummy, &Dummy);
  createRotX(phi,   &RotX);
  createRotY(theta, &RotY);
  createRotZ(psi,   &RotZ);
  matrixMulti(RotX,  RotY, Dummy);
  matrixMulti(Dummy, RotZ, Rot);

#if 0
  matrixPrint(RotX);
  matrixPrint(RotY);
  matrixPrint(RotZ);
  matrixPrint(Rot);
#endif

  //Make 3D point vector
  for (i=0; i<N; i++){
    matrixCreate(3, 1, p[i], P+i);
    matrixCreate(3, 1, pdst[i], Pdst+i);
  }
#if 1
  for ( i=0; i<N; i++) {
    *(P[i].data)   = 2.0*rand()/RAND_MAX - 1.0;
    *(P[i].data+1) = 2.0*rand()/RAND_MAX - 1.0;
    *(P[i].data+2) = 2.0*rand()/RAND_MAX - 1.0;
    matrixMulti(Rot, P[i], Pdst[i]);
    printf("%f %f %f %f %f %f\n", *(P[i].data), *(P[i].data+1), *(P[i].data+2), *(Pdst[i].data), *(Pdst[i].data+1), *(Pdst[i].data+2));

  }
#endif

  



}
