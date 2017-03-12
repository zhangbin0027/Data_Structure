//
//  DFS.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/12.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;


int visit[maxSize];
void handle(int i)
{
    //do something
}
/**
 图的深度优先搜索遍历

 @param G 图
 @param v v是起点编号
 */
void DFS(AGraph *G, int v)
{
    ArcNode *p;
    visit[v] = 1;   //标志编号为v的顶点已被访问过
    handle(v);      //操作编号v结点，如输出结点信息等
    
    //指向邻接表下标为v的结点所指的第一条边
    p = G->adjList[v].firstArc;
    while (p != NULL) {
        //如果未被访问过
        if (visit[p->adjVex] == 0) {
            DFS(G, p->adjVex);
        }
        p = p->nextArc;
    }
    
}
