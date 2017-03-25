//
//  QuickSort.cpp
//  Sort
//
//  Created by 牛严 on 2017/3/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 快速排序

 @param R 要排序的数组
 @param begin 要排序的数组段开始下标
 @param end 结束下标
 */
void QuickSort(int R[], int begin, int end)
{
    int temp;
    int i = begin, j = end;
    if (i < j)
    {
        temp = R[i];
        while (i != j)
        {
            //j从后往前找到比temp小的，停下来
            while (j > i && R[j] > temp)    --j;
            //然后将数据赋值给i
            if (j > i) {
                R[i] = R[j];
                ++i;
            }
            //i从左往右找到比temp大的，停下来
            while (i < j && R[i] < temp)    ++i;
            //然后将数据赋值给j
            if (i < j) {
                R[j] = R[i];
                --j;
            }
        }
        //i,j相等时，将temp放入
        R[i] = temp;
        //递归i左边和i右边的序列
        QuickSort(R, begin, i-1);
        QuickSort(R, i + 1, end);
    }
}
