#include <iostream>
#include <limits.h>
using namespace std;
/*
 *题目：输入2个int型整数，它们进行除法计算并返回商，
 * 要求不得使用乘号'*'、除号'/'及求余符号'%'。
 * 当发生溢出时，返回最大的整数值。假设除数不为0。
 * 例如，输入15和2，输出15/2的结果，即7。
 *
 */

//divident 被除数  divisor 除数
int divideCore(int dividend, int divisor)
{
    int result = 0;
    while(dividend <= divisor)
    {
        int value = divisor;
        int quotient = 1;                   //商
        //被除数和除数的两倍比较，最后得道除数是被除数的多少个两倍
        while(value >=0xc0000000 && dividend <= value << 2)
        {

            quotient <<= 2;     //商翻倍
            value <<= 2;        //值翻倍
        }
        result += quotient;
        dividend -= value;
    }
    return result;
}

int divide(int divident, int divisor)
{
    //0x80000000为最小得int型整数，-2^31
    if (divident == 0x80000000 && divisor == -1)
    {
        return INT32_MAX;
    }
    int negative = 2;
    if (divident > 0)
    {
        negative--;
        divident = -divident;
    }
    if (divisor > 0)
    {
        negative--;
        divisor = -divisor;
    }

    int result = divideCore(divident, divisor);
    return negative == 1 ? -result : result;
}

int main()
{
    cout << divide(25, 3) << endl;
    return 0;
}