#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 题目：输入两个字符串s和t，请找出字符串s中包含字符串t的所有字符的最短子字符串。
 *
 * 例如，输入的字符串s为"ADDBANCAD"，字符串t为"ABC"，
 * 则字符串s中包含字符'A'、'B'和'C'的最短子字符串是"BANC"。
 * 如果不存在符合条件的子字符串，则返回空字符串""。如果存在多个符合条件的子字符串，则返回任意一个。
 *
 *
 * 分析：这又是一道关于统计子字符串中出现的字符及每个字符出现的次数的面试题。
 *如果一个字符串s中包含另一个字符串t的所有字符，那么字符串t的所有字符在字符串s中都出现，
 * 并且同一个字符在字符串s中出现的次数不少于在字符串t中出现的次数。
 */

/*
 * 滑动窗口     窗口大小变化  窗口内部性质稳定
 *
 */
string minWindow(string src, string target)
{
    //hash_src   hash_target
    //1.初始化窗口 hs  和  目标 ht
    vector<int> hash_src(256), hash_target(256);
    string ans("");
    for (auto &c : target)
        hash_target[c]++;

    int left = 0, right = 0, cnt = 0; //l为窗口的左边界，r为窗口的右边界

    //2.开始循环窗口移动，left = right =0
    while (right < src.size())
    {
        //2.1右边界右移
        hash_src[src[right]]++;
        if (hash_src[src[right]] <= hash_target[src[right]])
            //有效字符加一
            cnt++; //在找到第一个符合条件的窗口后，这个语句不会再运行了。
                   //ps.该语句的作用是统计窗口内的有效字符
        //2.2左边界右移
        while (hash_src[src[left]] > hash_target[src[left]])
        {
            //这个语句会右移左边界，比如这个边界字符不在t里，
            hash_src[src[left]]--; //或者符合条件的边界值在后面又增加了一个且和左边界值相同，那么就可以右移左边界
            left++;
        }
        //2.3长度相等
        if (cnt == target.size())
        { //有效字符等于字符串t的长度，我们可以放入答案；或者对比前窗口的大小和当前的大小，然后决定是否更新ans。
            if (ans.empty() || right - left + 1 < ans.size())
                ans = src.substr(left, right - left + 1);
        }
        right++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string str1 = "a", str2 = "b";
    cout << (int)str2[1] << endl;
    cout << minWindow(str1, str2);

    return 0;
}
