#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
 *题目：给定一个字符串，请判断它是不是回文。
 * 假设只需要考虑字母和数字字符，并忽略大小写。
 *
 * 例如，"Was it a cat I saw？"是一个回文字符串，而"race a car"不是回文字符串。
 *
 */
bool isPalindrome(string str)
{
    int left = 0, right =str.size()-1;
    while(left < right)
    {
        while(str[left] == ' ')left++;
        while (str[right] == ' ')right--;
        if(str[left] == str[right])
        {
            left++;
            right--;
        }
        else
            return false;

    }
    return true;
}

int main(int argc, char const *argv[])
{
    string sss = "a bjjkb a ";
    cout<<isPalindrome(sss);
    return 0;
}
