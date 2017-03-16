//
//  Example-7-2.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/16.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;

int visit[maxSize] = {0};

/**
 带记录边数和顶点数的深度优先遍历
 
 @param G 图
 @param v 当前顶点编号
 @param vn 顶点数vexNo.
 @param an 边数arcNo.
 */
void DFS(AGraph G, int v, int &vn, int &an)
{
    visit[v] = 1;
    ++vn;
    
    ArcNode *p = G.adjList[v].firstArc;
    
    while (p != NULL) {
        if (visit[p->adjVex] == 0) {
            DFS(G, p->adjVex, vn, an);
        }
        p = p->nextArc;
        ++an;   //p指向过多少个边，无向图，也就是所有边数*2
    }
}

/**
 判断一个无向图是否是一颗树
 判断条件：1.图的边数（即树的分支数）为顶点数（即树的总结点数） -1
         2.连通，即遍历后顶点数满足1

 @param G 图的某结点
 @return 树返回1，否则返回0
 */
int GisTree(AGraph G)
{
    int vn = 0, en = 0;
    DFS(G, 1, vn, en);
    if (vn == G.n && G.n-1 == en/2) {
        return 1;
    }else {
        return 0;
    }
}

