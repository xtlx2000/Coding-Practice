#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8 // 皇后的个数，也是棋盘的长和宽
int total = 0; // 可行解的总数
int C[N]; // C[i] 表示第i 行皇后所在的列编号

/**
* @brief 输出所有可行的棋局，按列打印.
**http://poj.grids.cn/practice/2698/ ,这题需要按列打印
**
@return 无
*/
void output() {
	int i, j;
	printf("No. %d\n", total);
	for (j = 0; j < N; ++j) {
		for (i = 0; i < N; ++i) {
			if (C[i] != j) {
				printf("0 ");
			} else {
				printf("1 ");
			}
		}
		printf("\n");
	}
}

/**
* @brief 输出所有可行的棋局，按行打印.
* @return 无
*/
void output1() {
int i, j;
printf("No. %d\n", total);
for (i = 0; i < N; ++i) {
	for (j = 0; j < N; ++j) {
		if (j != C[i]) {
			printf("0 ");
		} else {
			printf("1 ");
		}
	}
	printf("\n");
	}
}

/**
* @brief 检查当前位置(row, column) 能否放置皇后.
**
@param[in] row 当前行
* @return 能则返回1，不能则返回0
*/
int check(const int row, const int column) {
	int ok = 1;
	int i;
	for(i = 0; i < row; ++i) {
		// 两个点的坐标为(row, column), (i, C[i])
		// 检查是否在同一列，或对角线上
		if(column == C[i] || row - i == column - C[i] ||
		row - i == C[i] - column) {
			ok = 0;
			break;
		}
	}
	return ok;
}
/**
* @brief 八皇后，深搜
**
@param[in] row 搜索当前行，该在哪一列上放一个皇后
* @return 可行解的个数
*/
int search(const int row) {
	int j;
	if (row == N) { // 终止条件，也是收敛条件，意味着找到了一个可行解
		++total;
		output();
		return total;
	}
	for (j = 0; j < N; ++j) { // 一列一列的试
		const int ok = check(row, j);
		if (ok) { // 如果合法，继续递归
			C[row] = j;
			search(row + 1);
		}
	}
	return total;
}
// 表示已经放置的皇后占据了哪些列
int columns[N];
// 占据了哪些主对角线
int principal_diagonals[2 * N];
// 占据了哪些副对角线
int counter_diagonals[2 * N];

/**
* @brief 检查当前位置(row, column) 能否放置皇后.
**
@param[in] row, 当前行
* @return 能则返回1，不能则返回0
*/
int check2(const int row, const int column) {
	return columns[column] == 0 && principal_diagonals[row + column] == 0
			&& counter_diagonals[row - column + N] == 0;
}

/**
* @brief 八皇后，深搜，更优化的版本，用空间换时间
**@param[in] row 搜索当前行，该在哪一列上放一个皇后
* @return 可行解的个数
*/
int search2(const int row) {
	int j;
	if (row == N) { // 终止条件，也是收敛条件，意味着找到了一个可行解
		++total;
		output();
		return total;
	}
	for (j = 0; j < N; ++j) { // 一列一列的试
		const int ok = check2(row, j);
		if (ok) { // 如果合法，继续递归
			// 执行扩展动作
			C[row] = j;
			columns[j] = principal_diagonals[row + j] =
			counter_diagonals[row - j + N] = 1;
			search2(row + 1);
			// 撤销动作
			C[row] = -1; // 这句可以省略，因为C[row] 会被覆盖掉
			columns[j] = principal_diagonals[row + j] =
			counter_diagonals[row - j + N] = 0;
		}
	}
	return total;
}
int main() {
	// search(0);
	search2(0);
	return 0;
}
