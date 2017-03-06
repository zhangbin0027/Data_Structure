//
//  LevelTraversal.cpp
//  Tree
//
//  Created by 牛严 on 2017/3/6.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"

#define maxsize 100

using namespace std;

//访问结点操作，此处仅以打印结点内容为例
void visit(BTNode *q)
{
    cout << q->data << endl;
}

//层次遍历
//入队出队操作可单独写成函数，此处练习
void level(BTNode *p)
{
    int front, rear;
    BTNode *que[maxsize];   //循环队列
    front = rear = 0;
    BTNode *q;
    
    if (p != NULL) {
        //跟结点入队
        rear = (rear + 1) % maxsize;
        que[rear] = p;
        
        //队列不为空时循环
        while (front != rear) {
            front = (front + 1) % maxsize;
            q = que[front]; //队头结点出队
            
            if (q->lchild != NULL) {
                rear = (rear + 1) % maxsize;
                que[rear] = q->lchild;
            }
            if (q->rchild != NULL) {
                rear = (rear + 1) % maxsize;
                que[rear] = q->lchild;
            }
        }
    }
}
