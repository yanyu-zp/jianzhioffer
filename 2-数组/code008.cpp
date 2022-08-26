#include <iostream>
#include<vector>
using namespace std;

/*
 * 题目：输入一个正整数组成的数组和一个正整数k，请
 * 问数组中和大于或等于k的连续子数组的最短长度是多少？
 * 如果不存在所有数字之和大于或等于k的子数组，则返回0。
 *
 * 例如，输入数组[5，1，4，3]，k的值为7，和大于或等于7的最短连续子数组是[4，3]，因此输出它的长度2。
 */

/*
 * 滑动窗口：其实也是双指针的用法
 * 0    【1   2   3】      5    6
 */
int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0,right = 0;
    int sum = 0;
    int minLength = INT32_MAX;

    for(;right < nums.size();right++)
    {
        sum += nums[right];
        while(sum >= target && left < right)
        {
            minLength = min(minLength,right - left +1);
            sum -= nums[left++];
        }
    }

    return minLength == INT32_MAX? 0 : minLength;
}

int main(int argc, char const *argv[])
{
    vector<int> v{2,3,1,2,4,3};
    cout<<minSubArrayLen(7,v);
    return 0;
}


