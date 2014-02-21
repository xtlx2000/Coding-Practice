#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define N 8 // �ʺ�ĸ�����Ҳ�����̵ĳ��Ϳ�
int total = 0; // ���н������
int C[N]; // C[i] ��ʾ��i �лʺ����ڵ��б��

/**
* @brief ������п��е���֣����д�ӡ.
**http://poj.grids.cn/practice/2698/ ,������Ҫ���д�ӡ
**
@return ��
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
* @brief ������п��е���֣����д�ӡ.
* @return ��
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
* @brief ��鵱ǰλ��(row, column) �ܷ���ûʺ�.
**
@param[in] row ��ǰ��
* @return ���򷵻�1�������򷵻�0
*/
int check(const int row, const int column) {
	int ok = 1;
	int i;
	for(i = 0; i < row; ++i) {
		// �����������Ϊ(row, column), (i, C[i])
		// ����Ƿ���ͬһ�У���Խ�����
		if(column == C[i] || row - i == column - C[i] ||
		row - i == C[i] - column) {
			ok = 0;
			break;
		}
	}
	return ok;
}
/**
* @brief �˻ʺ�����
**
@param[in] row ������ǰ�У�������һ���Ϸ�һ���ʺ�
* @return ���н�ĸ���
*/
int search(const int row) {
	int j;
	if (row == N) { // ��ֹ������Ҳ��������������ζ���ҵ���һ�����н�
		++total;
		output();
		return total;
	}
	for (j = 0; j < N; ++j) { // һ��һ�е���
		const int ok = check(row, j);
		if (ok) { // ����Ϸ��������ݹ�
			C[row] = j;
			search(row + 1);
		}
	}
	return total;
}
// ��ʾ�Ѿ����õĻʺ�ռ������Щ��
int columns[N];
// ռ������Щ���Խ���
int principal_diagonals[2 * N];
// ռ������Щ���Խ���
int counter_diagonals[2 * N];

/**
* @brief ��鵱ǰλ��(row, column) �ܷ���ûʺ�.
**
@param[in] row, ��ǰ��
* @return ���򷵻�1�������򷵻�0
*/
int check2(const int row, const int column) {
	return columns[column] == 0 && principal_diagonals[row + column] == 0
			&& counter_diagonals[row - column + N] == 0;
}

/**
* @brief �˻ʺ����ѣ����Ż��İ汾���ÿռ任ʱ��
**@param[in] row ������ǰ�У�������һ���Ϸ�һ���ʺ�
* @return ���н�ĸ���
*/
int search2(const int row) {
	int j;
	if (row == N) { // ��ֹ������Ҳ��������������ζ���ҵ���һ�����н�
		++total;
		output();
		return total;
	}
	for (j = 0; j < N; ++j) { // һ��һ�е���
		const int ok = check2(row, j);
		if (ok) { // ����Ϸ��������ݹ�
			// ִ����չ����
			C[row] = j;
			columns[j] = principal_diagonals[row + j] =
			counter_diagonals[row - j + N] = 1;
			search2(row + 1);
			// ��������
			C[row] = -1; // ������ʡ�ԣ���ΪC[row] �ᱻ���ǵ�
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
