#include<iostream>
using namespace std;
const int N = 8;
bool map[N+1][N+1];
int ans = 0;

void dfs(int, int);
bool check(int, int);

void dfs(int i_now,int j_now) {	//深度优先搜索 & 回溯
	//cout << "Now at: " << i_now << "," << j_now << endl;

	if (i_now == N) {
		ans++;
		//cout << "Completed." << endl;
		return;
	}
	map[i_now][j_now] = true;
	
	for (int i = 1; i <= N; i++) {
		if (check(i_now + 1, i))
			dfs(i_now + 1, i);
	}
	
	map[i_now][j_now] = false;
}
bool check(int i_now,int j_now) {
	//cout << "Checking." << endl;

	for (int i = 1; i <= N; i++) {
		if (map[i_now][i] || map[i][j_now])
			return false;

		int j_right = i + (j_now - i_now);
		int j_left = (i_now + j_now) - i;
		if (1 <= j_right && j_right <= N && map[i][j_right])
			return false;
		if (1 <= j_left && j_left <= N && map[i][j_left])
			return false;
	}
	return true;
}
int main(void) {
	for (int i = 1; i <= N; i++)
		dfs(1, i);
	cout << "The answer of Eight Queen Puzzle is : " << ans << endl;
	return 0;
}