#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 题目：给定一个字符串，请问该字符串中有多少个回文连续子字符串？
 *
 * 例如，字符串"abc"有3个回文子字符串，
 * 分别为"a"、"b"和"c"；而字符串"aaa"有6个回文子字符串，
 * 分别为"a"、"a"、"a"、"aa"、"aa"和"aaa"。
 */
int check(string str, int left, int right)
{
    int count = 0;
    while (left >= 0 && right < str.length())
    {
        if (str[left] == str[right])
        {
            ++count;
            --left;
            ++right;
        }
        else
            break;
    }
    return count;
}

int countSubstrings(string str)
{
    int len = str.length();
    int ans = 0;
    for (int i = 0; i < len; ++i)
    {
        //奇数
        ans += check(str, i, i);
        //偶数
        ans += check(str, i, i + 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    return 0;
}
