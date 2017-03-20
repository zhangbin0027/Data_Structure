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
 sorted是排序后的数组
 */
int TopSort(AGraph *G, int sorted[])
{
    ArcNode *p;
    int stack[maxSize], top = -1;
    int i,j;
    int n;      //计数，判断是否拓扑排序成功
    //将入度为0的顶点入栈，等一个起始点和后面的孩子们完成后，换其他起始点，保证图中所有顶点全部遍历
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
        sorted[n] = i;
        ++n;
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
    //判断n是否与图中顶点个数相等，相等则排序成功，返回1
    if (n == G->n) {
        return 1;
    }else {
        return 0;
    }
}
