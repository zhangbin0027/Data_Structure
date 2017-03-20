//
//  CPM.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/20.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;

int ve[maxSize];        //事件发生最早时间（事件即顶点）
int vl[maxSize];        //事件发生最迟时间
int ee;                 //活动最早开始时间（活动即边）
int el;                 //活动最晚开始时间

//拓扑排序，将序列存在sorted中，同时初始化ve
int TopSort(AGraph *G, int sorted[])
{
    ArcNode *p;
    int stack[maxSize], top = -1;
    int i,j;
    int n;      //计数，判断是否拓扑排序成功
    int ve[maxSize];
    //将入度为0的顶点入栈，等一个起始点和后面的孩子们完成后，换其他起始点，保证图中所有顶点全部遍历
    for (i = 1; i <= G->n; ++i)
    {
        if (G->adjList[i].inCount == 0) {
            stack[++top] = i;
        }
    }
    //初始化ve
    for (int i = 0; i < G->n; ++i) {
        ve[i] = 0;
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
        while (p != NULL)
        {
            j = p->adjVex;
            --(G->adjList[i].inCount);
            //入度为0，入栈
            if (G->adjList[i].inCount == 0){
                stack[++top] = j;
            }
            if(ve[i] + p->info > ve[j]){
                ve[j] = ve[i] + p->info;
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

//关键路径算法
int CriticalPath(AGraph *G)
{
    ArcNode *p;
    int stack[maxSize], top = -1;
    int i,j,k,weight;
    //拓扑排序将序列存到stack中，并初始化了事件最早开始时间数组ve[]
    if (!TopSort(G, stack)) {
        return 0;
    }
    //初始化事件最迟发生时间，都初始化为最后一个事件（顶点）的最早开始时间
    for (i = 0; i < G->n; ++i) {
        vl[i] = ve[G->n - 1];
    }
    //按拓扑排序依次求各顶点的事件最迟开始时间数组vl[]
    while (top != -1) {
        i = stack[top--];
        p = G->adjList[i].firstArc;
        while (p != NULL) {
            k = p->adjVex;
            weight = p->info;
            if (vl[k] - weight < vl[i]) {
                vl[i] = vl[k] - weight;
            }
            p = p->nextArc;
        }
    }
    //求活动最早开始时间ee，活动最迟开始时间el，关键活动
    for (j = 0; j < G->n; ++j) {
        p = G->adjList[j].firstArc;
        while (p != NULL) {
            k = p->adjVex;
            weight = p->info;
            ee = ve[j];
            el = vl[k] - weight;
            if (ee == el) {
                cout<<j<<" "<<k<<" "<<ee<<endl;
            }
            p = p->nextArc;
        }
    }
    return 1;
}
