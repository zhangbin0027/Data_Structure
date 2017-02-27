//
//  Exam3-1.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/27.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 判断一个表达式中的小括号是否正确配对
 */
int match(char exp[],int n)
{
    char stack[100];
    int top = -1;
    
    for (int i = 1 ; i <= n; ++i) {
        if (exp[i] == '(') {
            stack[++top] = '(';
        }else if (exp[i] == ')') {
            if (top == -1) {
                return 0;
            }else {
                --top;
                return 1;
            }
        }
    }
    if (top == -1) {
        return 1;
    }else {
        return 0;
    }
}
