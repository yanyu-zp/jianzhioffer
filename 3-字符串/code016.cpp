#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 题目：输入一个字符串，求该字符串中不含重复字符的最长子字符串的长度。
 *
 * 例如，输入字符串"babcca"，其最长的不含重复字符的子字符串是"abc"，长度为3。
 *
 */

/*
 * 滑动窗口 窗口大小变化，窗口内性质稳定
 *
 * 窗口内性质用hashtable描述
 *
 * 优化：
 * 1）可以让key对应的value存元素出现的次数，且用一个变量记录出现重复的元素
 * 2）不使用hashtable 可用位图来优化hashtable比较过程，只需要进行与运算即可得元素是否重复
 *
 */
int lengthOfLongestSubstring(string s)
{
    int len = s.length();
    int left = 0, right = 0;
    int repeat = 0;
    int ans = 0;
    vector<int> hash_s(256);    //最大窗口
    for (; right < len; ++right)
    {
        //1.right右移出现重复元素
        if (hash_s[(int)s[right]] >= 1)
        {
            ++repeat;
        }
        //1.1 repeat变量的存在，负责控制left指针的移动
        while (repeat)
        {
            //如果此时left指针移动到right所指的重复元素，
            if (s[left] == s[right])
                --repeat;
            --hash_s[(int)s[left++]];
        }
        //2.right 右移
        ++hash_s[(int)s[right]];
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string str = " ";
    cout << str[0] - '0' << (int)str[0] << endl;
    lengthOfLongestSubstring(str);
    return 0;
}
