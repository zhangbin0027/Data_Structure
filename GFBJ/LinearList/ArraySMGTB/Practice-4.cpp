//
//  Practice-4.cpp
//  LinearList
//
//  Created by 牛严 on 2017/3/5.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

//此算法本质还是快速排序的一部分，使用条件变了而已，当做练习

void quickSort(int A[], int n)
{
    int i = 0;
    int j = n-1;
    int temp = A[n-1];
    
    while (i < j) {
        while (A[i] <= temp) {
            ++i;
        }
        if (i < j) {
            A[j] = A[i];
            --j;
        }
        
        while (A[j] >= temp) {
            --j;
        }
        if (i < j) {
            A[i] = A[j];
            ++i;
        }
    }
    A[i] = temp;
}

void transToBinary(int m)
{
    //创建栈
    int stack[100];
    int top = -1;
    
    //进栈
    while (m != 1) {
        stack[++top] = m % 2;
        m = m/2;
    }
    
    //出栈
    for (int i = top; i > -1; --i) {
        cout<<stack[i];
    }
}

















