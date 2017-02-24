//
//  Practice-1-(5).cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 将顺序表L中所有小于表头元素的整数放在前半部分，
 大于表头元素的整数放在后半部分（快速排序）
 */
void QuickSort(int L[], int n)
{
    int temp = L[0];
    int i = 0;
    int j = n;          //i从前往后，j从后往前
    
    while (i < j) {
        
        while (i < j && L[i] > temp) {
            --j;
        }
        if (i < j) {
            L[i] = L[j];
            ++i;
        }
        
        while (i < j && L[i] < temp) {
            ++i;
        }
        if (i < j) {
            L[j] = L[i];
            --j;
        }
    }
    L[i] = temp;
}
