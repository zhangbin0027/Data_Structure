//
//  main.cpp
//  GFBJ-Example2-3
//
//  Created by 牛严 on 2017/2/15.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode;

/**
 【例2-3】A和B是两个单链表（带表头节点），其中元素递增有序，
 将A和B归并成一个按元素非递减有序的链表C，C由A和B中的结点组成
 
 @param A 链表A
 @param B 链表B
 @param C 链表C
 */
void merge(LNode *A, LNode *B, LNode *&C)
{
    LNode *p = A->next;     //跟踪A链表的最小结点
    LNode *q = B->next;     //跟踪B链表的最小结点
    LNode *r;               //指向C链表的终点
    
    C = A;                  //用A的头结点来做C的头结点
    C->next = NULL;
    free(B);                //B的头结点已无用
    r = C;                  //此时头结点也是终端结点
    
    while (p!=NULL && q!=NULL)
    {
        if (p->data <= q->data)
        {
            r->next = p;
            p = p->next;
            r = r->next;
        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
        }
    }
    r->next = NULL;
    
    //将某条剩下的结点直接链接在C的尾部，对应while循环条件中的&&，一条完成即可
    if (p!=NULL )   r->next = p;
    if (q!=NULL)    r->next = q;
}

/**
 尾插法建立单链表，假设有n个数组已存储在a中
 
 @param C 链表C
 @param a 数组a
 @param n 数组a的元素个数
 */
void createListR(LNode *&C, int a[], int n)
{
    //s用来指向新申请的结点，r始终指向C的尾端结点
    LNode *s,*r;
    int i;
    
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    r = C;
    
    for (i = 0; i < n ; ++i)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r= r->next;
    }
    r->next = NULL;     //链表C建立完成
}

/**
 尾插法
 */
void creatListF(LNode *&C, int a[], int n)
{
    LNode *s;
    int i;
    
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    
    for (i = 0; i < n ; ++i)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = C->next;
        C->next = s;
    }
}

/**
 【例2-4】查找链表C（带头结点）是否存在一个值为x的结点，
 若存在则删除该结点并返回1，否则返回0

 @param C 链表C
 @param x 要查找的值x

 @return 若存在返回1，否则返回0
 */
int searchAndDelete(LNode *C, int x)
{
    //q用来保存要删除的结点指针，用来释放其所指空间
    LNode *p,*q;
    p = C->next;
    
    while (p!=NULL) {
        if (p->data != x) {
            break;
        }
        p = p->next;
    }
    if (p->next == NULL) {
        return 0;
    }else{
        q = p->next;
        p->next = p->next->next;
        free(q);
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}
