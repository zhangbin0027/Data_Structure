//
//  FakeQuestions.cpp
//  LinearList
//
//  Created by 牛严 on 2017/2/20.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "LinkedList.cpp"

using namespace std;

/**
 1.设顺序表用数组A[]表示,表中元素存储在数组下表1~m+n的范围内，
 前m个元素递增有序，后n个元素也递增有序，设计算法使整个顺序表有序
 */
void insert(int A[], int m, int n)
{
    int i,j;
    int temp;
    
    for (i = m + 1; i < m + n; i++) {
        temp = A[i];
        //这段很经典，谨记
        for (j = i - 1; j >= 1 && temp < A[j]; j--){
            A[j+1] = A[j];  //元素后移
        }
        A[j+1] = temp;      //插入
    }
}

/**
 2.已知递增有序的单链表A、B（A、B中元素个数分别为m，n，且A、B都带有头结点）
 分别存储了一个集合，设计算法求出两个集合A、B的差集合A-B（仅由在A中出现而不
 在B中出现的元素的集合）。将差集保存在单链表A中，并保持元素的递增有效性。
 */
void difference(LNode *A, LNode *B)
{
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *pre = A;         //pre为p的前驱指针
    LNode *r;               //指向要删除的结点，用来释放空间的
    
    while (p->next != NULL & q->next != NULL) {
        if (q->data == p->data) {
            r = p;
            pre->next = p->next;
            p = p->next;    //解答时忘了这句，不应该
            free(r);
        }else if (q->data < p->data) {
            q = q->next;
        }else{
            pre = p;
            p = p->next;
        }
    }
}
