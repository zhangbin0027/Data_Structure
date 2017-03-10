//
//  Practice-2-3.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/10.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"

using namespace std;

/**
 非递归，利用数组栈进行先序遍历

 @param p 根结点
 */
void preOrder(BTNode *p)
{
    BTNode *stack[100];
    int top = -1;
    
    if(p != NULL) {
        //根结点入栈
        stack[++top] = p;
        
        BTNode *q;
        while (top != -1) {
            //出栈，操作该结点
            q = stack[top--];
            cout<<q->data<<endl;
            //先进右结点，先进后出
            if (q->rchild) {
                stack[++top] = q->rchild;
            }
            if (q->lchild) {
                stack[++top] = q->lchild;
            }
        }
    }
}

/**
 非递归中序遍历

 @param root 根结点
 */
void inOrder(BTNode *root)
{
    BTNode *stack[100];
    int top = -1;
    
    BTNode *p = root;
    if (root != NULL) {
        //1.结点入栈时将左孩子（及其左孩子）入栈
        //2.当到叶子的时候开始出栈，出了后将右孩子入栈
        //3.重复以上步骤
        while (top != -1 || p != NULL) {
            //入左子树的左子树的左子树直到叶子结点
            while (p != NULL) {
                stack[++top] = p;
                p = p->lchild;
            }
            //出栈，p指向其右孩子，进行循环左子树入栈操作
            if (top != -1) {
                p = stack[top--];
                cout<<p->data<<endl;
                p = p->rchild;
            }
        }
    }
}
