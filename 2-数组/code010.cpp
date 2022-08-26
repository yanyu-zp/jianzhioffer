#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 *题目：输入一个整数数组和一个整数k，
 * 请问数组中有多少个数字之和等于k的连续子数组？
 *
 * 例如，输入数组[1，1，1]，k的值为2，有2个连续子数组之和等于2。
 *
 */

/*
 * 用双指针无法解决，因为可能加入一个负数，这样不满足指针移动的规则
 * 只能保存前i个数字的和，求i-j之和，只需要[j]-[i]
 *
 * 这个题目需要计算和为k的子数组的个数。
 * 当扫描到数组的第i个数字并求得前i个数字之和是x时，
 * 需要知道在i之前存在多少个j并且前j个数字之和等于x-k。
 * 所以，对每个i，不但要保存前i个数字之和，还要保存每个和出现的次数。
 * 分析到这里就会知道我们需要一个哈希表，哈希表的键是前i个数字之和，值为每个和出现的次数
 */

/*
 * 一般关于 和  我们会用前缀和  记录计算过的信息    减少时间复杂度
 *
 * k = [j] - [i]  ->  k + [i] = [j]
 * key [j]
 * value 次数
 *
 * 在满足 i < j 时，hash[k + [i]]
 *这个条件，只需要从i->j 增大查询
 *
 *
 */

/*
 * hashtable key 为 pre - k
 *           value 前i次出现的次数
 */
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    mp[0] = 1;
    int count = 0, preSum = 0;
    for (auto &x : nums)
    {
        preSum += x;
        if (mp.find(preSum - k) != mp.end())
        {
            count += mp[preSum - k];
        }
        mp[preSum]++;
    }
    return count;

}

int main()
{
    return 0;
}