//用二维数组存放数字三角形
//D(i,j):第r行第j个数字（r,j从1开始算）
//MaxSum:从D（r,j)到底边个路径中，最佳路径之和。
//问题：求MaxSum(1,1)
//典型递归问题
//从d(r,j)出发，下一步只能走D（r+1,j)或者D（r+1,j+1)
//故 对N行的三角形性：
/*if(r==N)
MaxSum(r,j)=D(r,j)
else
MaxSum(r,j)=Max{ MaxSum(r+1,j) ,MaxSum(r+1,j+1) }+D(r,j)
*/

/*#include<iostream>
#include<algorithm>
using namespace std;
int D[011][101];
int n;
int MaxSum(int i, int j);
int main() {
	int i, j;
	cin >> n;
	for (int i = 1; i <=n; i++)//用二维数组存放数字三角形
	{
		for (j = 1; j <= i; j++)
			cin >> D[i][j];
	}
	cout << MaxSum(1, 1) << endl;
}

int MaxSum(int i, int j) {
	if (i == n)
		return  D[i][j];
	int x = MaxSum(i + 1, j);
	int y = MaxSum(i + 1, j + 1);
	return max(x, y) + D[i][j];
}

递归超时，存在的大量的重复的计算

*/



//数字三角形的记忆递归型动归程序：
/*#include<iostream>
#include<algorithm>
using namespace std;
int D[101][101];   
int n;
int maxSum[101][101];//用二维数组存放算取的结果，以避免重复计算
int main() {
	int i, j;
	cin >> n;
	for(i=1;i<=n;i++)
		for (j = 1; j <= i; j++) {
			cin >> D[i][j];
			maxSum[i][j] = -1;
		}
	cout << MaxSum(1, 1) << endl;
}
int MaxSum(int i, int j) {
	if (maxSum[i][j] != -1)
		return maxSum[i][j];
	if (i == n)
		maxSum[i][j] = D[i][j];//用二维数组存放算取的结果，以避免重复计算
	else
	{
		int x = MaxSum(i + 1, j);
		int y = MaxSum(i + 1, j + 1);
		maxSum[i][j] = max(x, y) + D[i][j];
	}
	return maxSum[i][j];
}
*/

/*

//递归转化为递推
#include<iostream>
#include<algorithm>
using namespace std;
int D[101][101];
int n;
int maxSum[101][101];
int main() {
	int i, j;
	cin >> n;
	for (i = 1; i < n; i++)
		for (j = 1; j < i; j++)
			cin >> D[i][j];
	for (int i = 1; i <= n; i++)
		maxSum[n][i] = D[n][i];//对最后一行进行赋值
	for (int i = n - 1; i >= 1; --i)//二重循环从下倒上进行递推
		for (int j = 1; j <= i; j++)
			maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1] + D[i][j]);
			cout << maxSum[1][1] << endl;
}*/

//空间上进行优化
//一行一行向上进行递推，仅需要一个一维数组，即只要储存一行MaxSum值就可以
#include<iostream>
#include<algorithm>
using namespace std;
int D[101][101];
int n, int* maxSum;
int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= i; j++)
			cin >> D[i][j];
			maxSum = D[n];//maxSum指向第N行
	for (int i = n - 1; i >= 1; --i)
		for (int j = 1; j <= i; j++)
			maxSum[j] = max(maxSum[j], maxSum[j + 1]) + D[i][j];
	cout << maxSum[1] << endl;
}
