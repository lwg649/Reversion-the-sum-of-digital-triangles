//�ö�ά����������������
//D(i,j):��r�е�j�����֣�r,j��1��ʼ�㣩
//MaxSum:��D��r,j)���ױ߸�·���У����·��֮�͡�
//���⣺��MaxSum(1,1)
//���͵ݹ�����
//��d(r,j)��������һ��ֻ����D��r+1,j)����D��r+1,j+1)
//�� ��N�е��������ԣ�
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
	for (int i = 1; i <=n; i++)//�ö�ά����������������
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

�ݹ鳬ʱ�����ڵĴ������ظ��ļ���

*/



//���������εļ���ݹ��Ͷ������
/*#include<iostream>
#include<algorithm>
using namespace std;
int D[101][101];   
int n;
int maxSum[101][101];//�ö�ά��������ȡ�Ľ�����Ա����ظ�����
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
		maxSum[i][j] = D[i][j];//�ö�ά��������ȡ�Ľ�����Ա����ظ�����
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

//�ݹ�ת��Ϊ����
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
		maxSum[n][i] = D[n][i];//�����һ�н��и�ֵ
	for (int i = n - 1; i >= 1; --i)//����ѭ�����µ��Ͻ��е���
		for (int j = 1; j <= i; j++)
			maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1] + D[i][j]);
			cout << maxSum[1][1] << endl;
}*/

//�ռ��Ͻ����Ż�
//һ��һ�����Ͻ��е��ƣ�����Ҫһ��һά���飬��ֻҪ����һ��MaxSumֵ�Ϳ���
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
			maxSum = D[n];//maxSumָ���N��
	for (int i = n - 1; i >= 1; --i)
		for (int j = 1; j <= i; j++)
			maxSum[j] = max(maxSum[j], maxSum[j + 1]) + D[i][j];
	cout << maxSum[1] << endl;
}
