#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//////////////////////////////////////////////////////////////////////////宏定义
#define DEBUG 0
#define SIZE 18
#define GET_INT_ARRAYLEN(array, len)            \
    {                                           \
        len = sizeof(array) / sizeof(array[0]); \
    }
#define SWAP_INT(a, b) \
    {                  \
        int tmp = (a); \
        (a) = (b);     \
        (b) = tmp;     \
    }                  \
//////////////////////////////////////////////////////////////////////////比较方式
bool up_comp(int a, int b) //升序排列
{
    if (a > b)
        return true;
    else
        return false;
}
bool down_comp(int a, int b) //降序排列
{
    if (a < b)
        return true;
    else
        return false;
}
//////////////////////////////////////////////////////////////////////////函数声明
int bubble_sorter(int *array, int length, bool (*comp)(int, int));     //冒泡排序
int selection_sorter(int *array, int length, bool (*comp)(int, int)); //选择排序
int insertion_sorter(int *array, int length, bool (*comp)(int, int));  //插入排序
//////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    int length = 0, count = 0;
    int num[SIZE] = {5, 3, 9, 4, 1, 5, 6, 9, 7, 25, 6, 5, 1, 69, 8, 52, 25, 5};
    GET_INT_ARRAYLEN(num, length); //使用宏函数获取数组长度

    //count = bubble_sorter(num, length, up_comp);
    //selection_sorter(num, length, up_comp);
    count = insertion_sorter(num, length, up_comp);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", num[i]);
    }

    printf("\n%d\n", count);

    //count = bubble_sorter(num, length, down_comp);
    //selection_sorter(num, length, down_comp);
    count = bubble_sorter(num, length, down_comp);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", num[i]);
    }

    printf("\n%d\n", count);

    return 0;
}
//////////////////////////////////////////////////////////////////////////冒泡排序
int bubble_sorter(int *array, int length, bool (*comp)(int, int))
{
    if(length==1)
        return 0;
    int i = 0, count = 0, flag = 0;

    do
        for (flag = 0, i = 0; i < length; i++)
            if (comp(array[i], array[i + 1]))
            {
                if (i == length - 1) //当指向数组最后一个数字时结束本轮冒泡
                    continue;
                SWAP_INT(array[i], array[i + 1])
                flag++;  //计算本轮冒泡次数
                count++; //计算总冒泡次数
            }
    while (flag > 0); //检查本轮冒泡次数是否为0(冒泡次数为0证明排序完成)
    return count;     //返回总冒泡次数(可选)
}
//////////////////////////////////////////////////////////////////////////选择排序
int selection_sorter(int *array, int length, bool (*comp)(int, int))
{
    if(length==1)
        return 0;
    int i = 0, j = 0, tmp = 0, swap = 0,count = 0;

    for (i = 0, tmp = 0; i < length; i++)
    {
        for (j = i, swap = i; j < length; j++)
            if (comp(array[swap], array[j])) //遍历寻找余项最值
                swap = j;
        SWAP_INT(array[swap], array[i]) //将余项最值与未排序数列第一项交换
        count++;
    }
    return count;
}
//////////////////////////////////////////////////////////////////////////插入排序
int insertion_sorter(int *array, int length, bool (*comp)(int, int))
{
    if(length==1)
        return 0;
    int i = 0, j = 0, insert = 0, p = 0, count = 0;

    do
    {
        p = i + 1;

        if (comp(array[i], array[p]) && p > 0)
        {
            insert = array[p]; //将待排项取出
            do
            {
                array[p] = array[p - 1]; //大项右移
                p--;                     //从后往前遍历已排序数列
                count++;                 //计算总排序次数
            } while ((p > 0) && comp(array[p - 1] , insert));
            array[p] = insert; //将待排项插入
        }

        i++;
    } while (i < (length - 1));
    return count; //返回总排序次数(可选)
}
//////////////////////////////////////////////////////////////////////////