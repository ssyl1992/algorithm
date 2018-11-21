#include <stdio.h>
#include "algorithm"

using namespace std;
int s[9][9]; // 每个格子的分数
int sum[9][9]; //(1,1)到(i,j)的矩形分数之和
int res[15][9][9][9][9]; // fun的记录表


int calSum(int x1,int y1, int x2,int y2){ // 计算（x1,y1)到(x2,y2)矩形的分数之和

	return sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
}


int fun(int n,int x1,int y1,int x2,int y2){

	int t,a,b,c,e,MIN=100000;
	if (res[n][x1][y1][x2][y2] != -1)
	{
		return res[n][x1][y1][x2][y2];
	}
	if (n==1){
		t = calSum(x1,y1,x2,y2);
		res[n][x1][y1][x2][y2] = t * t;

		return t * t;
	}

	for(a=x1;a<x2;a++){
		c = calSum(a+1,y1,x2,y2);
		e = calSum(x1,y1,a,y2);
		t = min(fun(n-1,x1,y1,a,y2) + c * c,fun(n-1,a+1,y1,x2,y2) + e * e);
		if(MIN>t) MIN=t;
	}

	for (b=y1;b<y2;b++)
	{
		c = calSum(x1,b+1,x2,y2);
		e = calSum(x1,y1,x2,b);
		t = min(fun(n-1,x1,y1,x2,b)+c*c,fun(n-1,x1,b+1,x2,y2)+e*e);
		if(MIN>t) MIN=t;


	}

	res[n][x1][y1][x2][y2] = MIN;
	return MIN;
}

int main(){


	return 0;
}