//
//  BSearchSort.cpp
//  Sort
//
//  Created by 牛严 on 2017/3/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 折半查找

 @param R R[1]-R[n]为数据
 */
void BinaryInsertSort(int R[], int n)
{
    int i,j,low,high,mid;
    for (i = 2; i <= n; ++i) {
        R[0] = R[i];
        low = 1; high = i-1;
        
        while (low < high) {
            mid = (low + high)/2;
            if (R[mid] > R[0]) {
                high = mid - 1;
            }else {
                low = mid + 1;
            }
        }
        //统一后移，空出插入位置
        for (j = i-1; j >= high + 1; --j) {
            R[j+1] = R[j];
        }
        R[high+1] = R[0];
    }
}
