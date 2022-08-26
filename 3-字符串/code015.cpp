#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*
 * 题目：输入字符串s1和s2，如何找出字符串s2的所有变位词在字符串s1中的起始下标？
 *
 * 假设两个字符串中只包含英文小写字母。例如，字符串s1为"cbadabacg"，字符串s2为"abc"，
 * 字符串s2的两个变位词"cba"和"bac"是字符串s1中的子字符串，
 * 输出它们在字符串s1中的起始下标0和5。
 *
 */

/*
 * 和上题一样   只不过滑动窗口在遇到符合条件的不停下来
 *
 * 滑动窗口     窗口大小固定  窗口内部性质稳定
 *
 */
vector<int> findAnagrams(string s, string p)
{
    int len_s = s.length();
    int len_p = p.length();
    if(len_p > len_s)
        return {};
    //1.建立两个特征组
    vector<int> hash_s(26), hash_p(26);

    //2.初始化特征组
    for(int i=0;i<len_s;++i)
    {
        ++hash_s[s[i] - 'a'];
        ++hash_p[p[i] - 'a'];
    }

    //3.第一次判断，这样到循环中不需要再判断
    set<string> check;
    vector<int> ans;
    if(hash_s == hash_p)
    {
        check.insert(string(s,0));
        ans.push_back(0);
    }

    //4.移动窗口，循环匹配
    for(int i=len_s;i<len_p;++i)
    {
        --hash_s[s[i-len_p] - 'a'];
        ++hash_s[s[i] - 'a'];

        if(hash_s == hash_p)
        {
            string str(s,i-len_p+1,i);
            if(check.find(str)==check.end())
            {
                check.insert(str);
                ans.push_back(i-len_p+1);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string str = "123456789";
    string str1(str, 1,5);
    cout<<str1<<endl;
    return 0;
}
