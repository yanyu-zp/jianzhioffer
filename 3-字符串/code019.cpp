#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 * 题目：给定一个字符串，请判断如果最多从字符串中删除一个字符能不能得到一个回文字符串。
 *
 * 例如，如果输入字符串"abca"，
 * 由于删除字符'b'或'c'就能得到一个回文字符串，因此输出为true。
 */
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int left, right;
        left = 0;
        right = s.length()-1;
        int flag = 1;
        while(left < right)
        {
            if(s[left] == s[right])
            {
                ++left;
                --right;
                continue;
            }
            else
            {
                if(check(s,left+1,right) || check(s,left,right-1))
                {
                    return true;
                }
                else
                    return false;
            }
        }
        return true;
    }
private:
    bool check(string &str, int left, int right)
    {
        while(left < right)
        {
            if(str[left] != str[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    //cout << validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga");
    return 0;
}
