#include <iostream>
#include <vector>
using namespace std;
/*
 * 题目：输入一个由正整数组成的数组和一个正整数k，请问数组中有多少个数字乘积小于k的连续子数组？
 *
 * 例如，输入数组[10，5，2，6]，k的值为100，
 * 有8个子数组的所有数字的乘积小于100，
 * 它们分别是[10]、[5]、[2]、[6]、[10，5]、[5，2]、[2，6]和[5，2，6]。
 */


int numSubarrayProductLessThanK(vector<int> &nums, int target)
{
    long product = 1;   //乘积
    int left = 0, right = 0;
    int count = 0;

    while (right < nums.size())
    {
        product *= nums[right];
        while(product >= target && right <= left)
        {
            product /= nums[left++];
        }
        count += right >= left ? right-left+1 : 0;
        right++;
    }


}

int main(int argc, char const *argv[])
{

    return 0;
}
//双指针总结：使用双指针的前提是数组都是正数，若数组中含有负数，则不可