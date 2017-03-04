//
//  Practice-2.cpp
//  LinearList
//
//  Created by 牛严 on 2017/3/4.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 递归找浮点型数组A的最大值，从（i，j）
 
 @param A 数组
 @param i 函数作用起始位置
 @param j 函数作用结束为止
 */
float findMax(float A[], int i, int j)
{
    if (i == j) {
        return A[i];
    }else {
        if (A[i] > findMax(A, i+1, j)) {
            return A[i];
        }else {
            return findMax(A, i+1, j);
        }
    }
}

/**
 递归求数组n个数之后

 @param A 浮点型数组
 @param i 函数作用起始位置
 @param j 函数作用结束为止
 */
float sum(float A[], int i, int j)
{
    if (i == j) {
        return A[i];
    }else {
        return A[i] + sum(A, i+1, j);
    }
}

/**
 递归求数组平均值
*/
float average(float A[], int i, int j)
{
    if (i == j) {
        return A[i];
    }else {
        return (A[i] + (j-1) * average(A, i+1, j))/(j-i+1);
    }
}
