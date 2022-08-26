#include <iostream>
#include <vector>
using namespace std;
/*
 * 题目：输入一个二维矩阵，
 * 如何计算给定左上角坐标和右下角坐标的子矩阵的数字之和？
 * 对于同一个二维矩阵，计算子矩阵的数字之和的函数可能由于输入不同的坐标而被反复调用多次。
 *
 * 例如，输入图2.1中的二维矩阵，以及左上角坐标为（2，1）和右下角坐标为（4，3）的子矩阵，该函数输出8。
 */
class NumMatrix
{
public:
    vector<vector<int>> sums;

    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (m > 0)
        {
            int n = matrix[0].size();
            sums.resize(m + 1, vector<int>(n + 1));
            for (int i = 0; i < m; i++)
            {
                int sum = 0;
                for (int j = 0; j < n; j++)
                {
                    sum += matrix[i][j];
                    sums[i + 1][j + 1] = sums[i][j + 1] + sum;
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = sums[row2 + 1][col2 + 1] 
        - sums[row1][col2 + 1] 
        - sums[row2 + 1][col1] 
        + sums[row1][col1];

        return ans;
    }
};
