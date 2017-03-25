//
//  ShellSort.cpp
//  Sort
//
//  Created by 牛严 on 2017/3/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 希尔排序
 也称缩小增量排序
 */
void ShellSort(int R[], int n)
{
    int dk;      //增量,步长
    int j;
    
    //每一个步长排序一次，如5，2，1
    for (dk = n/2; dk>=1 ; dk = dk/2)
    {
        //在每一个增量中，将被分割的所有子序列进行排序
        for (int i = dk + 1; i <= n; ++i)
        {
            //对一个子序列进行插入排序
            if (R[i] < R[i-dk])
            {
                R[0] = R[i];
                //遍历该子序列，比较一次后移一次
                for (j = i-dk; j>0 && R[0] < R[j]; j -= dk)
                {
                    R[i+dk] = R[j];
                }
                //此时空出位置，进行插入
                R[j+dk] = R[0];
            }
            
        }
    }
}
