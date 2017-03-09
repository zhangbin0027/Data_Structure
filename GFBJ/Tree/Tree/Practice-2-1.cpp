//
//  Practice-2-1.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/9.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"

using namespace std;


int top = 0;
char pathStack[100];
/**
 输出根结点到每个叶子结点的路径

 @param p 根结点
 */
void leavesPath(BTNode *p)
{
    if (p != NULL) {
        
        //-------------------操作当前结点-----------------
        //入栈
        pathStack[top++] = p->data;
        if (p->rchild == NULL && p->lchild == NULL) {
            //打印栈
            for (int i = 0; i < top; ++i) {
                cout<<pathStack[i];
            }
            cout<<endl;
        }
        //-------------------操作当前结点-----------------
        
        leavesPath(p->lchild);
        leavesPath(p->rchild);
        --top;
    }
}
