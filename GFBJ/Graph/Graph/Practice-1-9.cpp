//
//  Practice-1-9.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/23.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;

int visit[maxSize] = {0};
void handle(int v){}

//DFS非递归遍历，手动使用栈，类似树的先序非递归遍历
void DFS(AGraph G, int v)
{
    ArcNode *p;
    int stack[maxSize], top = -1;
    //v入栈
    stack[++top] = v;
    visit[v] = 1;
    
    while (top != -1) {
        //取栈顶元素，但不出栈，除非它所有孩子都访问过了
        int i = stack[top];
        p = G.adjList[i].firstArc;
        while (p != NULL && visit[p->adjVex] == 1) {
            p = p->nextArc;
        }
        //退出循环说明此时p是没被访问过的孩子
        //或者i的孩子都访问过了，走到最后p为NULL
        if (p != NULL) {
            handle(p->adjVex);
            visit[p->adjVex] = 1;
            stack[++top] = p->adjVex;
        }else {
            --top;
        }
    }
}
