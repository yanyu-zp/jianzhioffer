#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * 题目：输入一个数组，如何找出数组中所有和为0的3个数字的三元组？
 * 需要注意的是，返回值中不得包含重复的三元组。
 *
 * 例如，在数组[-1，0，1，2，-1，-4]中有两个三元组的和为0，它们分别是[-1，0，1]和[-1，-1，2]。
 */


/*
 * 0    1   2   3   4   ...
 * i    low                 high
 * 寻找 i + low + high == 0
 * 固定 i 在 low -high 求   和为 - i 的两个元素
 *
 */


/*
 * 注意：滑动窗口需要轨道是有序的，或者符合递增趋势
 */
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    // sort
    sort(nums.begin(), nums.end());
    // two pointer solu
    int sz = nums.size();
    int i = 0;
    while (i < sz - 2)
    {
        int low = i + 1, high = sz - 1;
        while (low < high)
        {
            if (nums[low] + nums[high] + nums[i] == 0)
            {
                ans.push_back({nums[i], nums[low], nums[high]});
                int tmp = nums[low];
                while (low < high && nums[low] == tmp)
                    ++low;
            }
            else
            {
                if (nums[low] + nums[high] + nums[i] < 0)
                    ++low;
                else
                    --high;
            }
        }
        int tmp = nums[i];
        while (i < sz && nums[i] == tmp)
            ++i;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> v{-1, 0, 1, 2, -1, -4};
    threeSum(v);

    return 0;
}
