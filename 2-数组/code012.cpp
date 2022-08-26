#include <iostream>
#include <vector>
using namespace std;
/*
 * 题目：输入一个整数数组，如果一个数字左边的子数组的数字之和等于右边的子数组的数字之和，
 * 那么返回该数字的下标。如果存在多个这样的数字，则返回最左边一个数字的下标。
 * 如果不存在这样的数字，则返回-1。
 *
 * 例如，在数组[1，7，3，6，2，9]中，下
 * 标为3的数字（值为6）的左边3个数字1、7、3的和与右边两个数字2和9的和相等，都是11，
 * 因此正确的输出值是3。
 */

/*
 * 很显然，依旧需要前缀和，前缀和作为已计算信息，存入数据结构，减少重复计算
 *
 * 假设中间数字为， mid
 *
 * 满足：Sum[mid] - [mid] = total - [mid]
 *
 * 小技巧：由于i->j刚好符合前缀和自左向右的要求，因此可以不提前求出前缀和数组，实现S(n) = O(1)
 *
 */

int pivotIndex(vector<int> &nums)
{
   int total = 0;
   for(int num : nums)
   {
       total += num;
   }
   int sum =0;

   for(int i = 0;i < nums.size();i++)
   {
       sum += nums[i];
       if(sum - nums[i] == total - nums[i])
       {
           return i;
       }
   }
    return -1;
}

int main()
{
    return 0;
}