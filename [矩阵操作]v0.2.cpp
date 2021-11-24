#include <iostream>     // [ 矩阵操作 ] [ by Kiritorz ] [ qq 948655078 ]
#include <stdio.h>
using namespace std;

double A[105][105];
double M1[50][50], M2[50][50];

void row_op(int row1, int row2, double k, int row, int column) { //初等行变换——倍加变换、倍乘变换
	for (int i = 1; i <= column; i++)
		A[row2][i] += (k * A[row1][i]);
}

void row_tr(int row1, int row2, int column) { //初等行变换——对换变换
	for (int i = 1; i <= column; i++) {

		//swap(A[row1][i], A[row2][i]);

		double tmp = A[row1][i];
		A[row1][i] = A[row2][i];
		A[row2][i] = tmp;

	}
}

void row_fix(int row_now, int column_now, int column) { //行初始化——首元归一
	double tmp = 1 / A[row_now][column_now];
	for (int l = column_now; l <= column; l++) {
		A[row_now][l] *= tmp;
	}
}

void martix_sm(int row, int column) { //初等行变换——阶梯化简
	for (int i = 2; i <= row; i++) {
		int flag = 0;
		for (int j = 1; j <= column; j++) {
			if (A[i][j] == 1 && flag == 0) {
				flag = 1;
				for (int l = 1; l < i; l++) {
					if (A[l][j]) {
						double k = A[l][j] / A[i][j];
						row_op(i, l, (-1) * k, row, column);
					}
				}
			}
		}
	}
}

void matrix_pr(int row, int column) { //打印矩阵
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= column; j++) {
			if (A[i][j] < 0)
				printf("%.2f     ", A[i][j]);
			if (A[i][j] >= 0)
				printf(" %.2f     ", A[i][j]);
		}
		printf("\n");
	}
}

void matrix_tr(int row_now, int column_now, int row, int column) { //初等行变换——矩阵转换

	if (row_now > row || column_now > column) {
		//cout << "Kiritorz : [因越界] 结束位置于 (" << row_now << "," << column_now << ")" << endl;
		return;
	}
	if (row_now == row && column_now == column) {
		matrix_pr(row, column);
		if ((int)A[row_now][column_now] == 0)
			A[row_now][column_now] = 0;
		else
			A[row_now][column_now] = 1;
		//cout << endl << "Kiritorz : [因触界] 结束位置于 (" << row_now << "," << column_now << ")" << endl;
		return;
	}
	int flag = 0;
	for (int i = row_now; i <= row; i++) {
		if (A[i][column_now])
			flag = 1;
	}

	//cout << endl << "Kiritorz : 当前位置 (" << row_now << "," << column_now << ")  " << endl << "Kiritorz : 当前 Flag: " << flag << endl;

	if (flag == 0) {
		//cout << endl << "Kiritorz : 即将前往 (" << row_now << "," << column_now + 1 << ")" << endl;
		matrix_tr(row_now, column_now + 1, row, column);
	}
	else {
		int t;
		for (t = row_now; t <= row; t++) {
			if (A[t][column_now])
				break;
		}

		//cout << endl << "Kiritorz : 当前矩阵为 " << endl;
		//matrix_pr(row, column);

		/*
		if (row_now != t) {
			row_tr(row_now, t, column);
			cout << endl << "Kiritorz : 已换行 " << row_now << " <--> " << t << endl;
			cout << endl << "Kiritorz : [行交换] 当前矩阵为 " << endl;
			matrix_pr(row, column);
		}
		*/

		row_fix(row_now, column_now, column);

		//cout << endl << "Kiritorz : [行修复] 当前矩阵为 " << endl;
		//matrix_pr(row, column);

		for (int i = row_now + 1; i <= row; i++) {
			double k = A[i][column_now] / A[row_now][column_now];
			row_op(row_now, i, (-1) * k, row, column);
		}
		//cout << endl << "Kiritorz : [列修复] 当前矩阵为 " << endl;
		//matrix_pr(row, column);

		//cout << endl << "Kiritorz : 即将前往 (" << row_now + 1 << "," << column_now + 1 << ")" << endl;
		matrix_tr(row_now + 1, column_now + 1, row, column);
	}
}

int main() {
	printf("[ 矩阵操作 ] [ by Kiritorz ] [ qq 948655078 ]\n\n");
	int cho;
	while (1) {
		printf("————————————————————————————\n\n");
		printf("Kiritorz : 选择「处理模式」\n\n");
		printf("Kiritorz : 输入「1」为「矩阵乘法」\n");
		printf("Kiritorz : 输入「2」为「矩阵转置」\n");
		printf("Kiritorz : 输入「3」为「矩阵变换」\n");
		printf("Kiritorz : 输入「4」为「矩阵求逆」\n");
		printf("Kiritorz : 输入「5」为「矩阵方程求解」\n");
		printf(" ");
		cin >> cho;
		printf("\n");
		if (cho == 1) {	 //矩阵乘法
			printf("Kiritorz : 输入两矩阵的「行数」与「列数」\n");
			printf(" ");
			int row1, column1, row2, column2;	//创建变量代表A、B矩阵的长和宽
			cin >> row1 >> column1 >> row2 >> column2;	//输入
			if (column1 != row2) {	//若A矩阵的列数不等于B矩阵的行数，两矩阵不可乘
				printf("Kiritorz : 两矩阵不可乘 \n");
				return 0;
			}
			printf("\nKiritorz : 输入矩阵的每一个元素 \n");
			for (int i = 1; i <= row1; i++) {  //输入A矩阵
				printf(" ");
				for (int j = 1; j <= column1; j++)
					cin >> M1[i][j];
			}
			for (int i = 1; i <= row2; i++) {  //输入B矩阵
				printf(" ");
				for (int j = 1; j <= column2; j++)
					cin >> M2[i][j];
			}
			for (int i = 1; i <= row1; i++)	//计算矩阵相乘
				for (int j = 1; j <= column2; j++)
					for (int k = 1; k <= column1; k++)
						A[i][j] += (M1[i][k] * M2[k][j]);

			printf("\nKiritorz :「矩阵相乘结果」\n");
			matrix_pr(row1, column2);

		}

		if (cho == 2) {	//矩阵转置
			int row, column;
			printf("Kiritorz : 输入矩阵的「行数」与「列数」\n");
			printf(" ");
			cin >> row >> column;
			printf("\nKiritorz : 输入矩阵的每一个元素 \n");
			for (int i = 1; i <= row; i++) {
				printf(" ");
				for (int j = 1; j <= column; j++)
					cin >> A[i][j];
			}
			printf("\nKiritorz :「矩阵转置结果」\n");
			for (int i = 1; i <= column; i++) {
				for (int j = 1; j <= row; j++) {
					if (A[j][i] < 0)
						printf("%.2f     ", A[j][i]);
					if (A[j][i] >= 0)
						printf(" %.2f     ", A[j][i]);
				}
				printf("\n");
			}
		}

		if (cho == 3) {	 //矩阵变换
			int n;
			printf("Kiritorz : 输入需要处理的「矩阵数量」\n");
			printf(" ");
			cin >> n;
			for (int h = 1; h <= n; h++) {
				printf("\nKiritorz : 当前为你需要输入的第「%d」个矩阵 \n", h);
				int row, column;
				printf("Kiritorz : 输入矩阵的「行数」与「列数」\n");
				printf(" ");
				cin >> row >> column;
				printf("\nKiritorz : 输入矩阵的每一个元素 \n");
				for (int i = 1; i <= row; i++) {
					printf(" ");
					for (int j = 1; j <= column; j++)
						cin >> A[i][j];
				}

				matrix_tr(1, 1, row, column);

				printf("\nKiritorz :「行阶梯形」\n");
				matrix_pr(row, column);

				martix_sm(row, column);

				printf("\nKiritorz :「行最简形」\n");
				matrix_pr(row, column);

				int sum = 0;
				for (int i = 1; i <= row; i++) {
					for (int j = 1; j <= column; j++) {
						if (A[i][j] == 1) {
							sum++;
							i++;
							j = 1;
						}
					}
				}

				printf("\nKiritorz :「等价标准形」\n");
				for (int i = 1; i <= row; i++) {
					printf(" ");
					for (int j = 1; j <= column; j++) {
						if (i == j && sum) {
							sum--;
							printf("1   ");
						}
						else
							printf("0   ");
					}
					printf("\n");
				}
			}
		}

		if (cho == 4) {  //方阵求逆
			int row;
			printf("Kiritorz : 输入方阵的「行数」\n");
			printf(" ");
			cin >> row;
			printf("\nKiritorz : 输入方阵的每一个元素 \n");
			for (int i = 1; i <= row; i++) {
				printf(" ");
				for (int j = 1; j <= row; j++)
					cin >> A[i][j];
			}

			for (int i = 1; i <= row; i++)
				for (int j = row + 1; j <= row * 2; j++)
				{
					if (i == j - row)
						A[i][j] = 1;
					else
						A[i][j] = 0;
				}

			matrix_tr(1, 1, row, row * 2);

			martix_sm(row, row * 2);

			int flag = 0;
			for (int i = 1; i <= row; i++)
				if (!A[i][i]) flag = 1;

			if (!flag) {
				printf("\nKiritorz :「逆矩阵」\n");
				for (int i = 1; i <= row; i++) {
					for (int j = row + 1; j <= row * 2; j++) {
						if (A[i][j] < 0)
							printf("%.2f     ", A[i][j]);
						if (A[i][j] >= 0)
							printf(" %.2f     ", A[i][j]);
					}
					printf("\n");
				}
			}
			else
				printf("\nKiritorz :该矩阵不可逆\n");

		}

		if (cho == 5) {  //矩阵方程求解
			int row1, row2, column1, column2;
			printf("Kiritorz : 矩阵方程求解的标准形式为「AX = B」\n");
			printf("Kiritorz : 输入矩阵「A」的「行数」与「列数」\n");
			printf(" ");
			cin >> row1 >> column1;
			printf("\nKiritorz : 输入矩阵的每一个元素 \n");
			for (int i = 1; i <= row1; i++) {
				printf(" ");
				for (int j = 1; j <= column1; j++)
					cin >> A[i][j];
			}
			printf("Kiritorz : 输入矩阵「B」的「行数」与「列数」\n");
			printf(" ");
			cin >> row2 >> column2;
			if (row1 != row2) {
				printf("\nKiritorz : 检测到矩阵「A」「B」行数不相等 \n");
				printf("Kiritorz : 题目有误，请重新输入 \n\n\n");
				continue;
			}
			printf("\nKiritorz : 输入矩阵的每一个元素 \n");
			for (int i = 1; i <= row2; i++) {
				printf(" ");
				for (int j = column1 + 1; j <= column1 + column2; j++)
					cin >> A[i][j];
			}
			matrix_tr(1, 1, row1, column1 + column2);

			martix_sm(row1, column1 + column2);


			printf("\nKiritorz :「矩阵方程求解结果」\n");
			for (int i = 1; i <= row1; i++) {
				for (int j = column1 + 1; j <= column1 + column2; j++) {
					if (A[i][j] < 0)
						printf("%.2f     ", A[i][j]);
					if (A[i][j] >= 0)
						printf(" %.2f     ", A[i][j]);
				}
				printf("\n");
			}

		}
		printf("\n\n");
	}
	return 0;
}