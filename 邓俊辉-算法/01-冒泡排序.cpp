#include <stdio.h>
#include <algorithm>
#include <iostream>

/**
	不变性：经过k次扫描交换后，最大的k个元素必然就位
	单调性：经过k次扫描交换后，问题的规模缩减至n-k
	正确性：经过至多n次扫描交换后，算法必然终止，且能给出正确排序

*/

using namespace std;
int list[10] = {2,5,8,1,3,6,10,4,3,5};




// 时间复杂度O（n^2）
void bubble_sort(int *a,int n){
	int count = 0;
	// i表示无序数组的长度
	for (int i = n-1;i > 0;i--){

// j 表示对无序数组的冒泡次数
		for(int j = 0; j < i;j++){
			count++;
			if (a[j] > a[j+1])
			{
				swap(a[j],a[j+1]);
			}

		}
	}
	cout << count << endl;
	for (int i =0;i < n;i++){
		cout << a[i] << endl;
	}

}

void bubble_sort_2(int *a ,int n){

	int flag;
	int count = 0;

	// int last = 0;
// i表示无序数组的长度
	for (int i = n-1;i > 0;i--){
		flag = 0;
// j 表示对无序数组的冒泡次数
		for(int j = 0; j < i;j++){
			count++;
			if (a[j] > a[j+1])
			{
				swap(a[j],a[j+1]);
				flag = 1; // 如果发生过交换，则表示剩余的数组无序

			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	cout << count << endl;
	for (int i =0;i < n;i++){
		cout << a[i] << endl;
	}

}

int items = 0;
// a表示待排序的数组，lo表示待排序数组的起点，hi表示待排序数组的终点
int bubble(int *a,int lo ,int hi)
{
	// 从起点到终点开始冒泡操作
	int last = lo;
	while(++lo < hi){
		items++;
		if (a[lo-1] > a[lo] )
		{
			swap(a[lo-1],a[lo]);
			last = lo; // 记录最后一次交换的位置
		}
	}

	return last;


}

/**
	优化算法3：
	优化思路  第k次扫描，n-k到n位置的数字必然有序，
	如果最后一次交换发生在j位置，则j位置到n-k到n位置必然有序，
	只需要再对0-j位置做冒泡操作
*/
void bubble_sort_3(int *a ,int n){

	int lo = 0;
	int hi = n;

	// 表示需要对数组lo到hi位置进行排序bubble，hi减小直至为1

	while(lo < (hi = bubble(a,lo,hi)));

	// cout << count << endl;
	for (int i =0;i < n;i++){
		cout << a[i] << endl;
	}
	cout << items << endl;

}


int main(){
	// bubble_sort(list,10);
	bubble_sort_2(list,10);
	return 0;
}