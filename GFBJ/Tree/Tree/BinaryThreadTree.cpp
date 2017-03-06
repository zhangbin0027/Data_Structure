//
//  BinaryThreadTree.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/6.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct TBTNode
{
    char data;
    int ltag,rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
}TBTNode;

//先序创建二叉树
void createBT(TBTNode *&p)
{
    char c;
    scanf("%c",&c);
    
    if (' ' != c) {
        p = NULL;
    }else {
        p = (TBTNode *)malloc(sizeof(TBTNode));
        p->data = c;
        p->ltag = 0;
        p->rtag = 0;
        
        createBT(p->lchild);
        createBT(p->rchild);
    }
    
}

/**
 线索化二叉树，注意只能中序遍历

 @param p   根结点
 @param pre 刚刚访问过的结点，即前驱结点
 */
void InThread(TBTNode *p, TBTNode *&pre)
{
    if (p != NULL) {
        
        //线索化左孩子
        InThread(p->lchild, pre);
        
        //处理双亲结点
        if (!p->lchild) {
            p->ltag = 1;
            p->lchild = pre;
        }
        if (!pre->rchild) {
            pre->rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        
        //线索化右孩子
        InThread(p->rchild, pre);
    }
}

//中序遍历建立二叉搜索树
void creatInThread(TBTNode *root)
{
    TBTNode *pre = NULL;
    if (root != NULL) {
        InThread(root, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

//------------访问线索二叉树------------------
//中序遍历时第一个结点
TBTNode *First(TBTNode *p)
{
    while (p->ltag == 0) {
        p = p->lchild;      //最左下角结点（不一定是叶子结点）
    }
    return p;
}

//根据线索查找后继结点
TBTNode *Next(TBTNode *p)
{
    if (p->rtag == 0) {
        return First(p->rchild);
    }else {
        return p->rchild;
    }
}

//在线索二叉树上执行线索遍历
void InOrder(TBTNode *root)
{
    for (TBTNode *p = First(root); p != NULL; p = Next(p)) {
        //visit(p)
        cout << p->data << endl;
    }
}



