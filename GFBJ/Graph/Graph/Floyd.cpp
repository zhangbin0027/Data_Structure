//
//  Floyd.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/20.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;

/**
 输出u到v最短路径顶点序列
 */
void printPath(int u, int v, int path[][maxSize])
{
    if (path[u][v] == -1) {
        //直接输出
        cout<<u<<"->"<<v;
    }else {
        int mid = path[u][v];
        printPath(u, mid, path);
        printPath(mid, v, path);
    }
}

/**
 Floyd算法求解最短路径

 @param G 图的邻接矩阵
 @param dis 存放各顶点之间距离的矩阵
 @param path 存放各顶点之间
 */
void Floyd(MGraph G, int dis[][maxSize], int path[][maxSize])
{
    //初始化dis矩阵和path矩阵
    for (int i = 0; i < G.n; ++i)
    {
        for (int j = 0; j < G.n; ++j)
        {
            dis[i][j] = G.edges[i][j];
            path[i][j] = -1;
        }
    }
    
    //里面两层循环是遍历一次矩阵，最外面一层代表以每个顶点为中间点，遍历一次矩阵
    for (int k = 0; k < G.n; ++k)
    {
        for (int i = 0; i < G.n; ++i)
        {
            for (int j = 0; j < G.n; ++j)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}
















