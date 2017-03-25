//
//  SelectSort.cpp
//  Sort
//
//  Created by 牛严 on 2017/3/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 选择排序
 每次选择一个最小的放在无序最前面
 */
void SelectSort(int R[], int n)
{
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i+1; j < n; ++j) {
            if (R[k] > R[j]) {
                k = j;
            }
        }
        int temp = R[i];
        R[i] = R[k];
        R[k] = temp;
    }
}
