//
//  Practice-1-7.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/9.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"

using namespace std;

//-------------------找到值为x的结点的层号，两种方法-------------------
typedef struct
{
    BTNode *p;
    int level;
}St;
/**
 找到值为x的结点的层号
 此处使用层次遍历

 @param p 根结点
 */
int levelX(BTNode *p)
{
    St *seq[1000];
    int rear,front = 0;
    if (p != NULL) {
        //进队
        int level = 1;
        seq[++rear]->p = p;
        seq[rear]->level = level;
        BTNode *q;
        while (p->lchild != NULL && p->rchild != NULL) {
            //出队，访问q，左右子树进队
            q = seq[++front]->p;
            if (q->lchild != NULL) {
                seq[++rear]->p = q->lchild;
                seq[rear]->level = level + 1;
            }
            if (q->rchild != NULL) {
                seq[++rear]->p = q->rchild;
                seq[rear]->level = level + 1;
            }
            //判断
            if (seq[rear]->p->data == 'x' || seq[rear-1]->p->data == 'x') {
                return seq[rear]->level;
            }
        }
        return 0;
    }else {
        return -1;
    }
}


int L;
/**
 直接记录指针路径的层数，从递归开始从上到下+1，递归一次完成从下到上-1

 @param p 根结点

 @return x所在层数
 */
int travelX(BTNode *p)
{
    if (p != NULL) {
        
        if (p->data == 'x') {
            return L;
        }
        
        ++L;
        travelX(p->lchild);
        travelX(p->rchild);
        --L;
    }
    return 0;
}



