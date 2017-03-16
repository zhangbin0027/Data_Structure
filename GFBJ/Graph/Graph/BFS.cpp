//
//  BFS.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/12.
//  Copyright © 2017年 牛严. All rights reserved.
//


#include <iostream>
#include "Struct.cpp"
using namespace std;


void handle(int i)
{
    //do something
}

/**
 图的广度优先搜索遍历

 @param G     图
 @param v     开始结点编号
 @param visit 存放结点是否被访问过的数组
 */
void BFS(AGraph *G, int v, int visit[maxSize])
{
    //定义队列
    int que[maxSize] = {0};
    int front, rear = 0;
    
    ArcNode *p;
    handle(v);      //访问顶点编号v的顶点
    visit[v] = 1;   
    //进队
    rear = (rear+1) % maxSize;
    que[rear] = v;
    //队列空时遍历完成
    while (front != rear) {
        //出队
        front = (front+1) % maxSize;
        p = G->adjList[que[front]].firstArc;
        
        //此while循环将某个结点连接的所有边结点全部入栈
        while (p != NULL) {
            //若当前顶点未访问，则进队
            if (visit[p->adjVex] == 0) {
                handle(p->adjVex);
                visit[p->adjVex] = 1;
                rear = (rear + 1) % maxSize;
                que[rear] = p->adjVex;
            }
            //结点若访问过直接找下一个arcNode，没访问过则进队，再找下一个arcNode
            p = p->nextArc;
        }
    }
}
