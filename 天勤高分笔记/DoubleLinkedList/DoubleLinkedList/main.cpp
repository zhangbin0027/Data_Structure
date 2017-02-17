//
//  main.cpp
//  DoubleLinkedList
//
//  Created by 牛严 on 2017/2/17.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

typedef struct DLNode
{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
}DLNode;

/**
 采用尾插法建立双链表
 */
void createDListR(DLNode *&L, int a[], int n)
{
    DLNode *s, *r;          //s为构造的结点，r始终指向链表尾部
    int i;
    L = (DLNode *)malloc(sizeof(DLNode));
    L->next = NULL;
    r = L;
    s = L->next;
    
    for (i = 0 ; i < n ; ++i)
    {
        s = (DLNode *)malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}

/**
 双链表查找结点

 @param C 被查找的双链表
 @param x 与结点比较的数据

 @return 若找到则返回该结点指针，否则返回NULL
 */
DLNode* searchNode(DLNode *C, int x)
{
    DLNode *p;
    p = C->next;
    while (p != NULL) {
        if (p->data == x) {
            break;
        }
        p = p->next;
    }
    //此句包含p为NULL的情况
    return p;
}

/**
 双链表插入结点

 @param C 被插入的双链表
 @param n 被插入结点的数据
 @param x 插入结点的数据
 */
void insertDLNode(DLNode *C, int n, int x)
{
    DLNode *p, *s;
    p = C->next;
    while (p != NULL) {
        if (p->data == n) {
            break;
        }
        p = p->next;
    }
    if (p != NULL) {
        s = (DLNode *)malloc(sizeof(DLNode));
        s->data = x;
        s->next = p->next;
        s->prior = p;
        p->next = s;
        s->next->prior = s;
    }
}

/**
 删除结点数据为x的结点
 */
void deleteDLNode(DLNode *C, int x)
{
    DLNode *p, *q;
    p = C->next;
    while (p != NULL) {
        if (p->data == x) {
            break;
        }
        p = p->next;
    }
    if (p != NULL) {
        q = p->next;
        p->next = q->next;
        q->next->prior = p;
        free(q);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
