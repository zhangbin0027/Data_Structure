//
//  KMP.cpp
//  LinearList
//
//  Created by 牛严 on 2017/3/2.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 获取next数组，已优化

 @param T    模式串，即子串
 @param T_length    模式串长度
 @param next next数组
 */
void getNext(char T[], int T_length, int next[])
{
    int i = 1;      //i代表后缀
    int j = 0;      //j代表前缀
                    //前缀是固定的，后缀是相对的
    next[1] = 0;
    while (i < T_length) {
        if (j == 0 || T[i] == T[j]) {   //匹配成功
            ++i;
            ++j;
            //重定位后跟i相对的子串元素仍然一样，匹配必然失败
            //直接进行再次匹配失败处理（假设移动了子串，匹配失败，那么该位置再次进行匹配失败处理）
            //直接移动到最开始的位置，也即递归的最终结果
            if (T[i] != T[j]) {
                next[i] = j;
            }else {
                next[i] = next[j];  //
            }
        }else {
            j = next[j];    //失配，指导下一轮的匹配位置，即j进行回溯
        }
    }
}

/**
 KMP算法，返回子串T在主串S中的位置

 @param S        主串
 @param S_lenth  主串长度
 @param T        模式串，子串
 @param T_length 子串长度
 @param next     next数组

 @return 若存在返回子串在主串中的起始位置，否则返回-1
 */
int KMP(char S[], int S_lenth, char T[], int T_length, int next[])
{
    int i = 0, j = 0;
    
    while (i < S_lenth && j < T_length) {
        if (S[i] == T[j] || 0 == j) {
            ++i;
            ++j;
        }else {
            j = next[j];
            if (0 == j) {
                ++i;
            }
        }
    }
    if (j > T_length) {     //模式串匹配成功
        return i - T_length;
    }else {
        return -1;
    }
}
