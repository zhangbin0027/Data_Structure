//
//  Exam3-2.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/27.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 运算函数，计算a op b的值
 */
int operation(int a, char op, int b)
{
    if (op == '+') return a+b;
    if (op == '-') return a-b;
    if (op == '*') return a*b;
    if (op == '/') {
        if (b == 0) {
            cout << "Error" << endl;
            return 0;
        }else {
            return a/b;
        }
    }
    return 0;
}


/**
 后缀式计算函数，如 abcd*++e
 */
int com(char exp[])
{
    int stack[100];
    int top = -1;
    
    for (int i = 0; exp[i] != '\0'; ++i) {
        if (exp[i] >= '0' && exp[i] <= '9') {
            stack[++top] = exp[i] - '0';    //将char数字转化为int
        }else {
            char op = exp[i];
            int a = stack[top--];
            int b = stack[top--];
            stack[++top] = operation(a, op, b);
            
        }
    }
    return stack[top];
}
