//4を4つ使って41をつくる
//gcc -lm main.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//単項演算子
double op1(int ope, double a){
  switch (ope){
  case 0:
    return a; break;
  case 1:
    return sqrt(a); break;
  case 2:
    return tgamma(a+1); break;
  }
}

//二項演算子
double op2(int ope, double a, double b){
  switch (ope){
  case 0:
    return a+b; break;
  case 1:
    return a-b; break;
  case 2:
    return a*b; break;
  case 3:
    return a/b; break;
  }
}

//短くするやつ
double ops(int ope1, int ope2, double a, double b){
  return op1(ope1, op2(ope2, a, b));
}

int main (void){
  int n;
  double ans[5];
  int a,b,c;
  int p,q,r,s,t,u,v;

  //二項演算子
  for(a=0;a<4;a++){
	 for(b=0;b<4;b++){
		for(c=0;c<4;c++){
		  
		  //単項演算子(4に直接)
		  for(p=0;p<3;p++){
			 for(q=0;q<3;q++){
				for(r=0;r<3;r++){
				  for(s=0;s<3;s++){
					 
					 //単項演算子
					 for(t=0;t<3;t++){
						for(u=0;u<3;u++){
						  for(v=0;v<3;v++){
							 //123
							 ans[0] = ops(v, c, ops(u, b, ops(t, a, op1(p,4), op1(q,4)), op1(r,4)), op1(s,4));
							 //312
							 ans[1] = ops(t, a, op1(p,4), ops(v, c, ops(u, b, op1(q,4), op1(r,4)), op1(s,4)));
							 //231,132
							 ans[2] = ops(u, b, ops(t, a, op1(p,4), op1(q,4)), ops(v, c, op1(r,4), op1(s,4)));
							 //213
							 ans[3] = ops(v, c, ops(t, a, op1(p,4), ops(u, b, op1(q,4), op1(r,4))), op1(s,4));
							 //321
							 ans[4] = ops(t, a, op1(p,4), ops(u, b, op1(q,4), ops(v, c, op1(r,4), op1(s,4))));
							 
							 for (n=0;n<5;n++){
								if(ans[n] < 41.01 && ans[n] > 40.99)
								  printf("[%d,%d,%d],[%d,%d,%d,%d],[%d,%d,%d],%d, %f \n"
											,a,b,c,p,q,r,s,t,u,v,n,ans[n]);
							 }
						  }
						}
					 }
				  }
				}
			 }
		  }
		}
	 }
  }
  return 0;
}
