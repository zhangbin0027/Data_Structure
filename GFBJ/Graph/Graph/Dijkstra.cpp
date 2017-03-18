//
//  Dijkstra.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/18.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;

/**
 Dijkstra求图中某一顶点到其余各顶点的最短路径

 注意：此算法可参考草图
 @param G 图
 @param v 顶点编号
 @param distance distance[]存放v点到其余顶点的最短路径长度，如20-30-40-50-60
 @param parent parent[]保存下标对应顶点的前一个顶点，parent是一棵双亲树，
             根据下标存的父亲能找到根结点
 */
void Dijkstra(MGraph G, int v, int distance[], int parent[])
{
    //标记数组，set[vi]为1则已并入
    int set[maxSize];
    
    //对数组进行初始化
    for (int i = 1; i < G.n; ++i) {
        //邻接表v行的数据,即v连接的边的长度，自身（见下）和无连接设置-1
        distance[i] = G.edges[v][i];
        set[i] = 0;
        if (G.edges[v][i] < INF) {
            parent[i] = v;
        }else {
            parent[i] = -1;
        }
    }
    
    set[v] = 1;
    parent[v] = -1;
    
    int min;
    int u = 0;
    
    //关键操作，上面都是初始化
    for (int i = 1; i <= G.n; ++i) {
        min = INF;
        //从剩余顶点中选出一个顶点，v通往此顶点的总路径比v通往其他顶点的总路径短
        //即最近点
        for (int j = 1; j <= G.n; ++j) {
            if (set[j] == 0 && distance[j] < min) {
                u = j;
                min = distance[j];
            }
        }
        //标记查找到的最近点
        set[u] = 1;

        //以刚刚并入的顶点作为中间点，对所有通往剩余顶点的路径进行检测
        for (int j = 1; j <= G.n; ++j) {
            /*判断u的加入是否会出现通往j(要遍历一遍j，即通往所有点)更短的路径，
            若有就改变原来的路径和长度*/
            if (set[j] == 0 && distance[u] + G.edges[u][j] < distance[j]) {
                distance[j] = distance[u] + G.edges[u][j];  //改变长度
                parent[j] = u;                              //改变路径
            }
        }
        /*注意distance总是比parent快一步，distance比较之后才能定parent*/
    }
}
