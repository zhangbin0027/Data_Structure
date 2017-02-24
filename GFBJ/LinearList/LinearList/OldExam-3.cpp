//
//  OldExam-3.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 找出数量为n的数组A中的主元素（元素数量大于n/2）
 */
int Majority(int A[], int n)
{
    int k = A[0];
    int j = 1;          //k是当前被计数的数字，j是当前被计数的次数
    int i;
    for (int i = 1; i < n; ++i) {      //从第二个数开始比较
        if (k != A[i]) {
            --j;
            if (j < 1) {
                k = A[i];
                j = 1;
            }
        }else {
            ++j;
        }
    }
    j = 0;
    for (i = 0; i < n; ++i) {
        if (A[i] == k) {
            ++j;
        }
    }
    if (j > n/2) {
        cout << k;
        return 0;
    }else {
        return -1;
    }
}
