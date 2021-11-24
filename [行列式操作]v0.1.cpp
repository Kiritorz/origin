#include<iostream>    // [ 行列式操作 ] [ by Kiritorz ] [ qq 948655078 ]
using namespace std;

//double D[21][21];

double det(int n, double A[21][21]){
	/*
	for (int o = 1; o <= n ; o++) {
		cout << endl;
		for (int p = 1; p <= n ; p++)
			cout << A[o][p] << " ";
	}
	*/
if (n == 2) {
	return (A[1][1] * A[2][2] - A[1][2] * A[2][1]);
}
else {
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		//memset(D, 0, sizeof(D));
		double D[21][21] = { 0 };
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			if (j != i) {
				tmp++;
				//cout << "√" << j << endl;
				for (int k = 2; k <= n; k++) {
					D[k - 1][tmp] = A[k][j];
				}
			}
			else
				continue;
		}
		/*
		cout << "第" << i << "次" << endl;
		for (int o = 1; o <= n - 1; o++) {
			cout << endl;
			for (int p = 1; p <= n - 1; p++)
				cout << D[o][p] << " ";
		}
		*/
		if ((1 + i) % 2)
			ans -= A[1][i] * det(n - 1, D);
		else
			ans += A[1][i] * det(n - 1, D);
	}
	return ans;
}
}
int main() {
	printf("[ 行列式操作 ] [ by Kiritorz ] [ qq 948655078 ]\n\n");
	while (1) {
		printf("————————————————————————————\n\n");
		printf("Kiritorz : 选择「处理模式」\n\n");
		printf("Kiritorz : 输入「1」为「行列式计算」\n ");
		int cho;
		cin >> cho;
		if (cho == 1) {
			double A[21][21];
			int n;
			printf("Kiritorz : 输入行列式「行数」\n ");
			cin >> n;
			printf("Kiritorz : 输入行列式的每一个元素\n");
			for (int i = 1; i <= n; i++) {
				printf(" ");
				for (int j = 1; j <= n; j++)
					cin >> A[i][j];
			}
			if(det(n,A)-(int)det(n,A)!=0)
				printf("Kiritorz :「计算结果」\n %.4f\n", det(n, A));
			else
				printf("Kiritorz :「计算结果」\n %.0f\n", det(n, A));
		}
		else
			return 0;
	}
}