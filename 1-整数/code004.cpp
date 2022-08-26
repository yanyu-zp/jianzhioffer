#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
 * 题目：输入一个整数数组，
 * 数组中只有一个数字出现了一次，
 * 而其他数字都出现了3次。请找出那个只出现一次的数字。
 *
 * 例如，如果输入的数组为[0，1，0，1，0，1，100]，则只出现一次的数字是100。
 */

/*
 * 0 1 0 1 1 1
 * 0 1 0 1 1 1
 * 0 1 0 1 1 1
 *
 * -1 1 1 0 1 0
 *
 * 所有整数的第i位 位之和%2 = 单独出现的整数位
 */

/*题目：输入一个整数数组，
 * 数组中只有一个数字出现m次，
 * 其他数字都出现n次。
 *
 * 请找出那个唯一出现m次的数字。假设m不能被n整除。
 *
 */

int m = 3, n =4;
int singleNumber(vector<int> &nums)
{
//解法1：哈希表，时间复杂度O(n)，空间复杂度O(n)
    // unordered_map<int,int> Map;
    // for(auto it = nums.begin();it!=nums.end();++it)
    // {
    //     Map[*it]++;
    // }
    // int rel = -1;
    // for(auto it = Map.begin();it!=Map.end();++it)
    // {
    //     if(it->second == 1)
    //     {
    //         rel = it->first;
    //         return rel;
    //     }
    // }
    // return rel;
//解法2：位运算



    int ret = 0;
    for(int i=0;i<32;++i)
    {
        int tmp = 0;
        for(int num : nums)
        {
            tmp += num >> (31-i) & 1;
        }
        //前提 m n 互质
        if(tmp % n != 0)
        {
            ret = (ret << 1) + 1;
        }
        else
        {
            ret = (ret << 1);
        }
    }
    return ret;
}

int main()
{
    vector<int> v{2,2,3,2,2,3,3};
    cout<<singleNumber(v);
    return 0;
}


/*
 * 求解
 */