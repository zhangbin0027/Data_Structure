//
//  OldExam-2.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/24.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 将数组a[]从l开始之后的r个元素逆置
 */
void Reverse(int R[], int l, int r)
{
    int i = l;
    int j = l + r;
    
    for ( i = l; i < j; ++i,--j) {
        int temp;
        temp = R[i];
        R[i] = R[j];
        R[j] = temp;
    }
}

/**
 将个数为n的数组R的元素向右平移p个
*/
void RCR(int R[], int n, int p)
{
    if (p<=0 || p>=n) {
        cout << "Error";
    }else{
        Reverse(R, 1, n-p);
        Reverse(R, n-p+1, p);
        Reverse(R, 1, n);
    }
}
