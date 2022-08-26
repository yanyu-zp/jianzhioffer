#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * 题目：输入一个字符串数组words，
 * 请计算不包含相同字符的两个字符串words[i]和words[j]的长度乘积的最大值。
 * 如果所有字符串都包含至少一个相同字符，那么返回0。
 *假设字符串中只包含英文小写字母。
 *
 * 例如，输入的字符串数组words为["abcw"，"foo"，"bar"，"fxyz"，"abcdef"]，
 * 数组中的字符串"bar"与"foo"没有相同的字符，它们长度的乘积为9。
 * "abcw"与"fxyz"也没有相同的字符，它们长度的乘积为16，这是该数组不包含相同字符的一对字符串的长度乘积的最大值。
 */
int maxProduct(vector<string> &words)
{
    //利用数组存字符串特征
    // int len = words.size();
    // vector<int[26]> vec(len);
    // for (int i = 0; i < len; ++i)
    // {
    //     string str = words[i];
    //     for (int j = 0; j < str.length(); ++j)
    //     {
    //         vec[i][(str[j] - 'a')]++;
    //     }
    // }
    // int ret = 0;
    // for (int i = 0; i < len; ++i)
    // {
    //     for (int j = i + 1; j < len; ++j)
    //     {
    //         int k = 0;
    //         for (; k < 26; ++k)
    //         {
    //             if (vec[i][k] && vec[j][k])
    //             {
    //                 break;
    //             }
    //         }
    //         if (k == 26)
    //         {
    //             int sz = words[i].length() * words[j].length();
    //             ret < sz ? ret = sz : ret = ret;
    //         }
    //     }
    // }
    // return ret;

    //利用int的二进制位存特征

    vector<int> feature;
    int sub_feature = 0;
    int base = 1;
    for (int i = 0; i < words.size(); ++i) {
        sub_feature = 0;
        for (int j = 0; j < words[i].size(); ++j) {
            base = 1;
            base = base << (words[i][j] - 'a');
            sub_feature = sub_feature | base;
        }
        feature.push_back(sub_feature);
    }

    int max = 0;
    for (int i = 0; i < feature.size(); ++i) {
        for (int j = i + 1; j < feature.size(); ++j) {
            if((feature[i] & feature[j]) == 0)
            {
                int tmp = words[i].size() * words[j].size();
                if(max < tmp)
                {
                    max = tmp;
                }
            }
        }
    }
    return max;
}
int main(int argc, char const *argv[])
{

    cout<< maxProduct(*new vector<std::string> {"ac","wed","a","kkkkk","uuuuu","jkt"});
    return 0;
}
