//
//  Codeup-1330.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/27.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 将十进制数转化为八进制数

 */
void conversion(int x)
{
    int stack[100];
    int top = -1;
    while (x) {
        stack[++top] = x % 8;
        x = x / 8;
    }
    //输出
    while (top > -1) {
        cout << stack[top--];
    }
}
