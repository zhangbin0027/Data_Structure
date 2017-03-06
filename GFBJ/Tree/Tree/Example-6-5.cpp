//
//  Example-6-5.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/6.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"

using namespace std;

#define maxSize 100     //大于树的总结点数

typedef struct
{
    BTNode *p;
    int level;
}St;

/**
 求二叉树的宽度（结点最多的那层的结点数）
 采用层次遍历，队列保存结点
 
 @param b 根节点

 @return 宽度
 */
int maxNode(BTNode *b)
{
    St que[maxSize];
    int front, rear;
    front = rear = 0;

    int level = 0;  //记录树的深度
    BTNode *q;  //指向最后出队的结点
    
    if (b != NULL) {
        //根结点进队
        //若是循环队列则需要取模运算，此处不需要
        que[++rear].p = b;
        que[rear].level = 1;
        
        while (front != rear) {
            //头结点出队（第一次执行时是根结点出队）
            //注意此处出队不是真正意义上的出队，只是将队列头指针后移,队列头在左侧，尾在右侧
            //之前分配的内存没有销毁，数据更不会覆盖，所以最终会得到一个包含所有结点的队列
            //且按树从上到下，从左到右排列在数组中
            //根结点-第二层从左到右-第三层从左到右....最后一层从左到右
            q = que[--front].p;
            level = que[front].level;
            
            if (q->lchild != NULL) {
                que[++rear].p = q->lchild;
                que[rear].level = level + 1;
            }
            if (q->rchild != NULL) {
                que[++rear].p = q->rchild;
                que[rear].level = level + 1;
            }   
        }
        //循环完成后level的大小是树的深度即层数，此时遍历树的队列，查找哪层的结点最多即可
        //遍历队列level次，记录每层对应的结点数量，返回最大值即可
        int max = 0;
        for (int i = 1; i <= level; ++i) {
            int n = 0;
            for (int j = 1; j<= rear; ++j) {
                if (que[j].level == i) {
                    ++n;
                }
            }
            if (max < n) {
                max = n;
            }
        }
        return max;
        
    }else {
        return 0;   //空树返回0
    }
}
