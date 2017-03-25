//
//  InsertSort.cpp
//  Sort
//
//  Created by 牛严 on 2017/3/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 插入排序

 @param R 存放数据的数组
 @param n 数据个数
 */
void InsertSort(int R[], int n)
{
    int j,temp;
    for (int i = 1; i < n; ++i) {
        temp = R[i];
        j = i - 1;
        
        while (j >= 0 && temp < R[j]) {
            R[j+1] = R[j];
            temp = R[j];
            --j;
        }
        R[j+1] = temp;
    }
}
