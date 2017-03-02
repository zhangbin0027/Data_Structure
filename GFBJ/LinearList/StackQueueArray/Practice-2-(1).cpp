//
//  Practice-2-(1).cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/27.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 求n个不同字符的全排列，递归

 */
void perm(char str[], int k, int n)
{
    int i,j;
    char temp;
 
    if (k == 0) {
        for (j = 0; j <= n-1; ++j) {
            cout << str[j];
        }
    }else {
        for (i = 0; i <= k; ++i) {
            temp = str[k];
            str[k] = str[i];
            str[i] = temp;
            
            perm(str, k-1, n);
            
            //使数组倒回原来的样子，不会产生重复的排列结果
            temp = str[i];
            str[i] = str[k];
            str[k] = temp;
        }
    }
}
