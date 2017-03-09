//
//  Practice-1-3.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/9.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"

using namespace std;

//---------------计算叶子结点个数---------------
int n = 0;
/**
 对树进行遍历来计数，此处采用先序遍历

 @param p 根结点
 */
void countLeaves(BTNode *p)
{
    if (p == NULL) {
        return ;
    }
    if (p ->lchild == NULL && p->rchild == NULL) {
        ++n;
    }
    countLeaves(p->lchild);
    countLeaves(p->rchild);
}


/**
 通过递归计算左右子树叶子结点之和

 @param p 根结点
 */
int countLeaves2(BTNode *p)
{
    if (p == NULL) {
        return 0;
    }
    //叶子结点返回1进行前一个递归栈的数字累加，不是叶子结点就继续向下
    if (p->lchild == NULL && p->rchild == NULL) {
        return 1;
    }else {
        int n1 = countLeaves2(p->lchild);
        int n2 = countLeaves2(p->rchild);
        return n1 + n2;
    }
}
