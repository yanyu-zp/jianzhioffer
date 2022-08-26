#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 题目：输入一个只包含0和1的数组，请问如何求0和1的个数相同的最长连续子数组的长度？
 *
 * 例如，在数组[0，1，0]中有两个子数组包含相同个数的0和1，
 * 分别是[0，1]和[1，0]，它们的长度都是2，因此输出2。
 */

/*
 * 在求解      连续符合条件的序列中，最常使用的技巧就是    前缀和 + hashtable
 * 满足的条件： target = [j] - [i]
 * 即：target + [i] = [j]，前提是 i < j，自左向有构建hashtable即可
 * key = target + [i]
 * value = [j]
 *
 * 自左向右查询 hash[key] 是否存在
 *
 */
int findMaxLength(vector<int> &nums)
{
    //暴力穷举 O(n^2)
    // int ans = 0;
    // int len = nums.size();
    // int sum = 0;
    // for(int i=0;i<len;++i)
    // {
    //     for(int j=i;j>=0;--j)
    //     {
    //         sum+=nums[j];
    //         if((i-j+1)%2==0 && sum%2==0 && sum)
    //             ans = max(i-j+1,ans);
    //     }
    // }
    // return ans;

    int ans = 0;
    int len = nums.size();
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < len; ++i)
    {
        sum += nums[i] == 0 ? -1 : 1;
        if (mp.find(sum - 0) != mp.end())
        {
            ans = max(ans, i - mp[sum]);
        }
        else
            mp[sum] = i;
    }
    return ans;
}

int main()
{
    vector<int> v{0, 0, 1, 1, 1, 0, 0, 0, 1};
    cout << findMaxLength(v);
    return 0;
}