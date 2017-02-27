//
//  FakeQuestion-1.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/27.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

#define maxSize 200

typedef struct
{
    int elem[maxSize];
    int top[2];
}SqStack;

/**
 入栈

 @param st   共享栈
 @param stNo 栈的编号，s0,s1
 @param x    压栈元素

 @return 入栈成功返回1，输入有误返回-1，栈满返回0
 */
int push(SqStack &st, int stNo, int x)
{
    if (st.top[0] + 1 < st.top[1]) {    //栈未满
        if (stNo == 0) {
            st.elem[++st.top[0]] = x;
            return 1;
        }else if (stNo == 1) {
            st.elem[--st.top[1]] = x;
            return 1;
        } else {
            return -1;
        }
    }else {
        return 0;
    }
}

/**
 出栈

 @param x    x接收出栈值
 @return 出栈成功返回1，输入有误返回-1，栈空返回0
 */
int pop(SqStack &st, int stNo, int &x)
{
    if (stNo == 0) {
        if (st.top[0] != -1) {
            x = st.elem[st.top[0]--];
            return 1;
        }else {
            return 0;
        }
    }else if (stNo == 1) {
        if (st.top[1] != maxSize) {
            x = st.elem[st.top[1]++];
            return 1;
        }else {
            return 0;
        }
    }else {
        return -1;
    }
}
