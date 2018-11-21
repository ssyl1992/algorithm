
/*
	要制作一个体积为Nπ的M层生日蛋糕，每层都是一个圆柱体
	设从下往上数第i（1<=i<=M）层的蛋糕半径为Ri  高度为Hi的圆柱，当i<M时，要求Ri > Ri+1  且Hi > Hi+1

	由于要在蛋糕上抹奶油，为尽可能节约经费，需要蛋糕外表面的面积Q最小
	Q = Sπ

	请对给出N和M，给出制作蛋糕的方案，使S最小
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;


int N,M;  // 体积为N，层数为M
int minArea = 1 << 30; // 最优表面积

int area = 0; // 当前正在搭建中的表面积

int minV[30]; // minV[n]表示n层蛋糕最少的体积

int minA[30]; // minA[n]表示n层面积的最小侧表面积


int MaxVForNRH(int n,int r,int h){
// 求在n层蛋糕，底层最大半径r,最高高度h的情况下，能凑出来的最大体积
	int v = 0;
	for (int i=0;i<n;++i){
		v += (r-i)*(r-i)*(h-i);

	}
	return v;
}



void Dfs(int v,int n,int r, int h){

	if (n == 0){
		if (v) return ;

		else {
			minArea = min(minArea,area);
			return ;
		}
	}

	if (v <= 0)
		return ;

	if (minV[n] > v) //剪枝3
		return ;

	if (area + minA[n] >= minArea) // 剪枝1
		return ;

	if (h < n || r < n) // 剪枝2
		return ;

	if (MaxVForNRH(n,r,h) < v) // 剪枝4
		//这个剪枝效果最好
		return;

	for (int rr = r; rr >=n ; -- rr){
		// 从大到小块，这边大了，内部循环的可选择范围就少了，符合先做选择步骤少的思路

		if (n == M){ // 低面积
			area = rr * rr;
			for (int hh = h; hh >= n; --h){
				area += 2 * rr * hh;
				Dfs(v-rr*rr*hh,n-1,rr-1,hh-1);
				area -= 2 * rr * hh;
			}
		}


	}
}



int main(){


	cin >> N >> M;
	minV[0] = 0;
	minA[0] = 0;

	for (int i = 1;i <= M; i++){
		minV[i] = minV[i-1] + i * i * i; // 第i层的半径至少为i，高度至少为i
		minA[i] = minA[i-1] + 2 * i * i;
	}

	if (minV[M] > N)
		cout << 0 << endl;
	else {

		int maxH = (N-minV[M-1])/(M * M) + 1; //底层的最大高度
		//  最底层的体积不超过 （N - minV(M-1)),且半径至少为M
		int maxR = sqrt(double(N-minV[M-1]/M)) + 1; // 底层的最小高度至少为M  

		area = 0;
		minArea = 1 << 30;

		Dfs(N,M,maxR,maxH);

		if (minArea == 1 << 30)
			cout << 0 << endl;

		else 
			cout << minArea << endl;

	}

	return 0;
}
