//
//  Proactice-2-1.cpp
//  Sort
//
//  Created by 牛严 on 2017/3/28.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

#define maxSize 100

//1.1
/**
 计数排序，统计表中有多少元素比某元素数量少，时间空间复杂度都高，没啥意义
 */
void CountSort(int A[],int B[],int n)
{
    for (int i = 1; i <= n; ++i)
    {
        int co = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (A[j] < A[i]) {
                ++co;
            }
        }
        B[co] = A[i];
    }
}

//1.3
/**
 双向冒泡，在排序过程中交替改变扫描方向
 改进，使用isChanged代替min<max做为while循环的条件，可判断有序提前退出
 */
void BothwayBubbleSort(int R[], int n)
{
    int min = 0;        //向左边冒泡得出的最小序列的位数
    int max = n-1;      //向右边冒泡得出的最大序列的位数
    int isChanged = 1;
    while (isChanged)
    {
        isChanged = 0;
        //从min到max，将最大的冒泡到max位置，--max
        for (int i = min; i < max; ++i) {
            if (R[i-1] > R[i]) {
                int temp = R[i];
                R[i] = R[i-1];
                R[i-1] = temp;
                isChanged = 1;
            }
        }
        --max;
        //从max到min，将最小的冒泡的min位置，min++
        for (int i = max; i > min; --i) {
            if (R[i] < R[i-1] ) {
                int temp = R[i-1];
                R[i-1] = R[i];
                R[i] = temp;
                isChanged = 1;
            }
        }
        ++min;
    }
}

//1.8 给定一组关键字，创建一个带头结点的链表，设计一个直接插入排序算法，对这个单链表进行递增排序
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

void CreateLink(LNode *&h, char R[], int n)
{
    h = (LNode *)malloc(sizeof(LNode));
    LNode *s;
    LNode *tail = NULL;
    for (int i = 0; i < n; ++i) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = R[i];
        tail->next = s;
        tail = s;
    }
    tail->next = NULL;
}

void Sort(LNode *h)
{
    LNode *p,*pre,*q;
    if (h->next != NULL) {
        p = h->next->next;      //p指向链表第二个数据结点
        h->next->next = NULL;   //产生只带一个结点的有序表
    }
    while (p != NULL) {
        pre = h;
        q = pre->next;
        //找到一个结点q，其data值大于p的data值
        while (q != NULL && q->data < p->data) {
            pre = q;
            q = q->next;
        }
        LNode *p1 = p->next;
        p->next = pre->next;
        pre->next = p;          //将p插到pre之后
        p = p1;
    }
}


