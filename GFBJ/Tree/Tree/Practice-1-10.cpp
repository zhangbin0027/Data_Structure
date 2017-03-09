//
//  Practice-1-10.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/9.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"

using namespace std;

void visit(BTNode *p)
{
    cout << p->data;
}

/**
 双序遍历：每一个结点，先访问这个结点，再按双序遍历它的左子树
 再一次访问这个结点，接下来按双序遍历它的右子树

 @param p 根结点
 */
void DoubleOrderTraversal(BTNode *p)
{
    if (p != NULL) {
        visit(p);
        DoubleOrderTraversal(p->lchild);
        visit(p);
        DoubleOrderTraversal(p->rchild);
    }
}
