#include <stdio.h>
long long int intPower(const int base, const int index);
//////////////////////////////////////////////////////////////////////////
/* 二进制与十进制相互转换 */
void printBin(const unsigned long long num, const int size_t, const unsigned int group_size);
long long int binstrToOct(const char *str);
//////////////////////////////////////////////////////////////////////////
/* 十进制与十六进制相互转换 */
int hexchrToOct(const char hex);
long long int hexstrToOct(const char *str);
//////////////////////////////////////////////////////////////////////////
void printBin(const unsigned long long num, const int size_t, const unsigned int group_size)
{ //num为待转换为二进制数的十进制数原形，size_t为字节宽度，group_size为位分组大小,0表示不分组
    int count = 0, zero = 0, i = 0;
    if(num == 0)
    {
        for(i = 0; i < size_t*8;i++)
            putchar('0');
        goto _end;
    }
    unsigned long long flag = 1ULL << (size_t * 8 - 1); /*(size_t * 8)为二进制位数*/
    while (0 == (num & flag)) /*记1前0的个数*/
    {
        flag >>= 1;
        ++count;
    }
    if (group_size != 0)
    {
        zero = count % group_size; /*将每组中不足组数的用0补齐*/
        for (i = 0; i < zero; i++)
            printf("0");
    }
    while (flag != 0)
    {
        printf("%d", 0 != (num & flag));
        flag >>= 1;
        ++count;
        if (group_size != 0)
            if (count % group_size == 0)
                printf(" ");
    }
_end:
    printf("\n");
}
long long int binstrToOct(const char *str)
{ //将二进制字符串转换成十进制长整型并返回
    int i = 0, length = 0;
    long long int result = 0;
    while (str[length++] != '\0')
        ;
    length--;
    for (i = 0; i < length; i++)
        result += (str[i] - '0') * intPower(2, length - i - 1);
    return result;
}
//////////////////////////////////////////////////////////////////////////
long long int intPower(const int base, const int index)
{ //整数幂运算
    if (index == 0)
        return 1;
    long long int result = 1;
    int i = 0;
    for (i = 0; i < index; i++)
        result *= base;
    return result;
}
int hexchrToOct(const char hex)
{ //将单个十六进制字符转换成十进制并返回
    if ((hex >= '0') && (hex <= '9'))
        return hex - '0';
    else if ((hex >= 'A') && (hex <= 'F'))
        return hex - 'A' + 10;
    else if ((hex >= 'a') && (hex <= 'f'))
        return hex - 'a' + 10;
    else
        return 0;
}
long long int hexstrToOct(const char *str)
{ //将十六进制字符串转换成十进制长整型并返回
    int i = 0, length = 0;
    long long int result = 0;
    while (str[length++] != '\0')
        ;
    length--;
    for (i = 0; i < length; i++)
        result += hexchrToOct(str[i]) * intPower(16, length - i - 1);
    return result;
}
//////////////////////////////////////////////////////////////////////////
