#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
 * 题目：输入字符串s1和s2，如何判断字符串s2中是否包含字符串s1的某个变位词？
 * 如果字符串s2中包含字符串s1的某个变位词，则字符串s1至少有一个变位词是字符串s2的子字符串。
 * 假设两个字符串中只包含英文小写字母。
 *
 * 例如，字符串s1为"ac"，
 * 字符串s2为"dgcaf"，由于字符串s2中包含字符串s1的变位词"ca"，
 * 因此输出为true。如果字符串s1为"ab"，字符串s2为"dgcaf"，则输出为false。
 */

/*
 * 题目要求：仍然是模式匹配     常用做法是 滑动窗口  进行匹配
 *
 * 查找 str1  str1.size() = 3     固定窗口大小  3
 *
 * 采用hashtable  建立str1  特征
 *  1   2   [3   4   5]   6   7   8   9   ...
 *
 *  窗口固定滑动
 *
 *
 */
bool checkInclusion(string s1, string s2)
{
    int len_s1 = s1.length();
    int len_s2 = s2.length();
    if (len_s1 > len_s2)
        return false;
    //1.建立两个固定特征组   可以用数组   或者 hashtable
    vector<int> hash_s1(26), hash_s2(26);

    //2.初始化两个固定特征组
    for (int i = 0; i < len_s1; ++i)
    {
        ++hash_s1[s1[i] - 'a'];
        ++hash_s2[s2[i] - 'a'];
    }
    //3.第一次比对
    if(hash_s1 == hash_s2)
        return true;

    //4.窗口滑动
    for (int i = len_s1; i < len_s2; ++i)
    {
        --hash_s2[s2[i - len_s1] - 'a'];    //前面--
        ++hash_s2[s2[i] - 'a'];    //后面++
        if(hash_s1 == hash_s2)
            return true;
    }

    return false;
}
int main(int argc, char const *argv[])
{
    cout << checkInclusion("asdfg","ds");
    cout << checkInclusion("ds","asdfg");
    return 0;
}
