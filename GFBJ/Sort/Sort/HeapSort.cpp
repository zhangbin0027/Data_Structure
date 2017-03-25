//
//  HeapSort.cpp
//  Sort
//
//  Created by 牛严 on 2017/3/25.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 R[]是完全二叉树的表示，调整堆，R[low]到R[high]
 */
void HeapAdjust(int R[], int low, int high)
{
    int i = low, j = 2*i;       //R[j]是R[i]的左孩子结点
    int temp = R[i];
    while (j <= high) {
        //若i的右孩子比较大，将j指向右孩子
        if (j < high && R[j] < R[i+1]) {
            ++j;
        }
        if (temp < R[j]) {
            R[i] = R[j];
            i = j;
            j = 2*i;
        }else {
            break;
        }
    }
    R[i] = temp;
}

/**
 堆排序
 */
void HeapSort(int R[], int n)
{
    int i;
    int temp;
    
    //建立初始堆
    for (i = n/2; i >= 1; --i) {
        HeapAdjust(R, i, n);
    }
    //n-1次循环完成堆排序
    for (i = n; i >= 2; --i) {
        temp = R[1];
        R[1] = R[i];
        R[i] = temp;
        //在减少了1个元素的序列中进行堆排序找到一个最大（小）值
        HeapAdjust(R, 1, i-1);
    }
}
