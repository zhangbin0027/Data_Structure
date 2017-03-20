//
//  TopoLogicalSort.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/20.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;

/**
 拓扑排序
 
 此方法从上往下遍历，从上往下输出，也可以使用DFS，从下往上遍历
 */
void TopSort(AGraph *G)
{
    ArcNode *p;
    int stack[maxSize], top = -1;
    int i,j;
    
    //将入度为0的顶点入栈，等一个顶点和后面的链完成后，换另一个顶点
    for (i = 1; i <= G->n; ++i)
    {
        if (G->adjList[i].inCount == 0) {
            stack[++top] = i;
        }
    }
    
    //开始排序输出
    while (top != -1)
    {
        i = stack[top--];
        cout<<i<<" ";
        p = G->adjList[i].firstArc;
        //对刚出栈的顶点i的孩子进行入栈操作（若入度为0）
        //与树的层次遍历和BFS算法有异曲同工之妙
        while (p != NULL)
        {
            j = p->adjVex;
            --(G->adjList[i].inCount);
            //入度为0，入栈
            if (G->adjList[i].inCount == 0)
            {
                stack[++top] = j;
            }
            p = p->nextArc;
        }
    }
}
