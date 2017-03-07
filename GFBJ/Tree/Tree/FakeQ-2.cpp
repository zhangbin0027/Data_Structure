//
//  FakeQ-2.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/7.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"

using namespace std;

/**
 根据二叉树的先序遍历和中序遍历构造二叉树

 @param pre 先序遍历数组
 @param in  中序遍历数组
 @param b1  截取pre数组的起始点，起始为1
 @param e1  截取pre数组的终止点
 @param b2  截取in数组的起始点
 @param e2  截取in数组的终止点

 @return 根节点
 */
BTNode *CreateBT(int pre[], int in[], int b1, int e1, int b2, int e2)
{
    if (b1 > e1) {
        return NULL;    //在递归过程中，b1>e1说明截取数列没元素了
    }
    
    BTNode *s = (BTNode *)malloc(sizeof(BTNode));
    s->lchild = NULL;
    s->rchild = NULL;
    
    //遍历中序数组，根据先序遍历截取的数组确定子树的根结点
    int i;
    for (i = b2; i < e2; ++i) {
        if (pre[b1] == in[i]) {
            break;
        }
    }
    s->data = in[i];
    
    //递归求左子树和右边子树
    s->lchild = CreateBT(pre, in, b1+1, b1+i-1-b2, b2, b2+i-1);
    s->rchild = CreateBT(pre, in, b1+i-b2, e1, i+1, e2);
    
    return s;
}
