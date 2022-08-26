#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
 * 题目：输入一个非负数n，
 * 请计算0到n之间每个数字的二进制形式中1的个数，
 * 并输出一个数组。
 *
 * 例如，输入的n为4，由于0、1、2、3、4的二进制形式中1的个数分别为0、1、1、2、1，
 * 因此输出数组[0，1，1，2，1]。
 */
void countBits(int num)
{
    vector<int> ans;
    //solution 1    每次去掉一个1
    //从前往后，不利用已经计算出来的结果
    // for (unsigned int i = 0; i <= num; ++i)
    // {
    //     int j = i;
    //     int cnt = 0;
    //     while (j != 0)
    //     {
    //         cnt++;
    //         j = j & (j - 1);
    //     }
    //     ans.push_back(cnt);
    // }


    //solution 2    每次去掉一个1
    //从前往后，利用之前计算出来的结果
    // ans.push_back(0);
    // for (int i = 1; i <= num; ++i)
    // {
    //     int pos = i & (i - 1);
    //     ans.push_back(ans[pos] + 1);
    // }


    //solution 3    每次去掉一个
    //从前往后，利用之前计算出来的结果
    ans.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        i % 2 ? ans.push_back(ans[i << 1] + 1) : ans.push_back(ans[i << 1]);
    }
    
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        cout << *it << endl;
    }
}

int main()
{
    countBits(4);
    return 0;
}