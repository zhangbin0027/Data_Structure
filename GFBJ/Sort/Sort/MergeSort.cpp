//
//  MergeSort.cpp
//  Sort
//
//  Created by 牛严 on 2017/3/25.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

#define maxSize 100

//将A的两段A[low...mid],A[mid+1...high]合并成一个有序表
void Merge(int A[], int low, int mid, int high)
{
    int i,j,k;
    int B[maxSize];     //将A的元素复制到B中
    for (k = low; k <= high; ++k) {
        B[k] = A[k];
    }
    for (i=low, j=mid+1, k=i; i<=mid && j<=high; ++k) {
        if (B[i] <= B[j]) {
            A[k] = B[i++];
        }else {
            A[k] = B[j++];
        }
    }
    //若两段中有一段全部完成，则将另一段直接赋值到A中
    while (i<=mid) {
        A[k++] = B[i++];
    }
    while (j<=mid) {
        A[k++] = B[j++];
    }
}

/**
 2路归并排序
 */
void MergeSort(int A[], int low, int high)
{
    if (low < high) {
        int mid = (low + high)/2;
        //递归归并，返回是 1个一组比较，2个一组比较，4个一组比较....
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}
