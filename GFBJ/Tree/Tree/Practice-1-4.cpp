//
//  Practice-1-4.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/9.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"

using namespace std;

/**
 因先序、中序、后序遍历，叶子结点的先后顺序不变
 此处用先序遍历

 @param p 根结点
 */
void linkLeaves(BTNode *p)
{
    BTNode *head = NULL;
    BTNode *tail = NULL;
    
    if (p != NULL) {
        
        if (p->lchild == NULL && p->rchild == NULL) {
            if (head == NULL) {
                head = p;
                tail = p;
            }else {
                head->rchild = p;
                tail = p;
            }
        }
        
        linkLeaves(p->lchild);
        linkLeaves(p->rchild);
        
        //由于无法知道和控制递归的深度，所以无法知道最后一个结点在哪里
        //因此只能链接一次设置一次当前为链表尾部结点tail
        
    }
}
