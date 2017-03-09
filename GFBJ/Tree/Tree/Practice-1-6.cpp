//
//  Practice-1-6.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/9.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 将完全二叉树的先序遍历转化为后序遍历，此处在同一个数组操作

 @param A 先序遍历数组，下标从1开始
 @param begin 相对于整个数组的数组下标，是数组段的第一个位置
 @param n begin到end数组段的数组元素个数
 */
void preOderToPostOrder(char A[],int begin, int n)
{
    if (n > 2) {
        //先将数组段第一个元素放到最后
        char temp = A[begin];
        for (int i = begin ; i < begin+n-1; ++i) {
            A[i] = A[i+1];
        }
        A[begin+n-1] = temp;
        //然后分别将数组段中前(n-1)/2个元素和后面的(n-1)/2个元素进行同样操作
        n = (n-1)/2;
        preOderToPostOrder(A, begin, n);
        preOderToPostOrder(A, begin+n, n);
    }
}
