//
//  Practice-1-5.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/9.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>

using namespace std;

typedef struct BTNode
{
    char data;
    
    struct BTNode *lchild;
    struct BTNode *rchild;
    struct BTNode *parent;
}BTNode;

/**
 遍历二叉树，设置双亲

 @param p      当前结点
 @param parent 双亲结点
 */
void setParent(BTNode *p, BTNode *parent)
{
    if (p != NULL) {
        //赋值
        p->parent = parent;
        
        setParent(p->lchild, p);
        setParent(p->rchild, p);
    }
}

/**
 输出某结点到根结点的路径

 @param p 输入结点
 */
void parents(BTNode *p)
{
    while (p != NULL) {
        cin >> p->parent->data;
        p = p-> parent;
    }
}
