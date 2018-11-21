#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


// 2 1
// 2 3
// 2 5
// 2 6
// 2 7
// 3 4
// 4 2
// 6 1
// 6 2
// 6 3
// 6 4
// 6 5
// 6 6
// 6 7
using namespace std;
int c,r,n;

//  踩踏水稻坐标的数据结构
struct PLANT
{
	int x,y;
};

PLANT plants[5001];
PLANT plant;

bool operator < (const PLANT &p1,const PLANT &p2){
	if (p1.x == p2.x)
		return p1.y < p2.y;
	return p1.x < p2.x;
};
// 函数找寻路径
int searchPath(PLANT secPlant,int dX,int dY) {

	PLANT plant;
	int steps;
	plant.x = secPlant.x + dX;
	plant.y = secPlant.y + dY;
	steps = 2;

	printf("第三点%d  %d\n",plant.x,plant.y);

	while(plant.x <= r && plant.x >= 1 && plant.y <= c && plant.y >= 1){

		
		if (!binary_search(plants,plants+n,plant))
		{
			//  每一步都必须踩在水稻里，否则就不算路径
			steps = 0;

			break;
		}

		plant.x += dX;
		plant.y += dY;

		steps++;
	}
	return steps;
}

int main(){


	int i,j,dX,dY,pX,pY,steps,max=2;

	printf("请输入行数和列数,x方向是上下，y方向是左右\n");
	scanf("%d %d",&r,&c);

	printf("请输入踩踏水稻的总数\n");
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&plants[i].x,&plants[i].y);
	}
	// x坐标按x从小到大，y坐标按y从小到大排序  plants表示第一个数组中第一个元素，plants+n表示第n个元素
	sort(plants,plants+n);


	
	

	for (int i = 0; i < n-2; i++)  // 第一个点plants[i]
	{
		for (int j = i+1; j < n-1; j++) // 第二个点 plants[j]
		{
			// 计算步长
			dX = plants[j].x - plants[i].x;
			dY = plants[j].y - plants[i].y;

			// 计算2点之前的一个点
			pX = plants[i].x - dX;
			pY = plants[i].y - dY;

			// 如果第一点的前一点在稻田里，说明本次选择的第二点导致步长不合理，取下一个点做为第二点
			if(pX <= r && pX >= 1 && pY <= c && pY >= 1)
				continue;

			// x 方向过早越界，说明第二点不成立,说明第一个点不合理所以break出该层循环
			if (plants[i].x + (max - 1) * dX > r)
				break;

			pY = plants[i].y + (max - 1) * dY;
			if (pY > c || pY < 1)
			{
				continue; // y方向过早越界，应换一个新的第二点
			}

			printf("第一点%d %d,第二点 %d  %d\n",plants[i].x,plants[i].y,plants[j].x,plants[j].y);
			// 看看从这两点出发，最大的steps，如果
			steps = searchPath(plants[j],dX,dY);
			printf("对应步数%d\n",steps);
			// printf("steps----%d\n",steps );
			if (steps > max) max = steps;

		}
		
	}
	if (max == 2 ) max = 0;
	printf("%d\n",max);
}


