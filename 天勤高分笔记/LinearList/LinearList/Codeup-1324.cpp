//
//  Codeup-1324.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/21.
//  Copyright © 2017年 牛严. All rights reserved.
//

//题目ID：1324 有序线性表的有序合并

#include <iostream>
#include "Codeup-1323.cpp"

using namespace std;

/**
 已知线性表 LA 和 LB 中的数据元素按值非递减有序排列，现要求将 LA 和 LB 归并为一个新的线性表 LC， 且 LC 中的数据元素仍然按值非递减有序排列
 
 此为顺序表算法，链表在LinkedList【例2-3】中
 */
void MergeList(List A, List B, List &C)
{
    int i,j;
    int C_len = 0;

    //C初始化
    C = List();
     
    while (i < A.length && j < B.length) {
        if (B.data[j] > A.data[i]) {
            C.data[C_len++] = A.data[i++];
        }else{
            C.data[C_len++] = B.data[j++];
        }
    }
    while (i < A.length) {
        C.data[C_len++] = A.data[i++];
    }
    while (j < B.length) {
        C.data[C_len++] = B.data[j++];
    }
    C.length = C_len;
}
