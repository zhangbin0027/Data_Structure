     //
//  Prim.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/16.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;


/**
 Prim算法找最小生成树MST
 天勤上的算法不好，在这里做下改进
 @param G 图
 @param v0 开始顶点编号
 */
int Prim(MGraph G, int v0)
{
    //存放当前生成树到剩余顶点最短边的权值，0表示已加入树
    //lowcost[i]表示已i为终点的边的最小权值
    int lowcost[maxSize];
    //mst存放lowcost值中对应边权值的结点，0表示已加入树
    // <mst[i],i>就是一条边，lowcost[i]表示该边的权值
    int mst[maxSize];
    int sum = 0;
    
    //初始化lowset和mst数组
    for (int i = 1; i < G.n; ++i)
    {
        lowcost[i] = G.edges[v0][i];    //初始化邻接矩阵中v0那行
        mst[i] = 1;
    }
    mst[v0] = 0;           //将v0并入树中
    
    int min;
    //循环完成一次，代表最小生成树并入了一个顶点，n个结点，即n-1条边，遍历次数为n-1
    for (int i = 1; i < G.n; ++i)
    {
        min = INF;          //INF相当于邻接矩阵中的∞
        int k = 0;          //标记要并入树的顶点,<mst[k],k>表示到k权值最小的边的权值
        //找到当前生成树的候选边的最小一条
        for (int j = 1; j <= G.n; ++j)
        {
            if (lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];   //找到矩阵i行中最小的权值
                k = j;
            }
        }
        lowcost[k] = 0;
        mst[k] = 0;
        sum += min;
        //输出刚加入最小生成树的边
        cout << "V" << mst[k] << "-V" << k << "=" << min << endl;
        //以刚并入生成树中的顶点为媒介，更新lowcost
        for (int j = 1; j<= G.n; ++j)
        {
            if (lowcost[j] != 0 && G.edges[k][j] < lowcost[j])
            {
                lowcost[j] = G.edges[k][j];
                mst[j] = k;
            }
        }
    }
    return sum;
}

int main()
{
    int i, j, k, m, n;
    int cost;
    cin >> m >> n;//m=顶点的个数，n=边的个数
    //初始化图G
    MGraph *G = new MGraph;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= m; j++)
        {
            G->edges[i][j] = INF;
        }
    }
    //构建图G
    for (k = 1; k <= n; k++)
    {
        cin >> i >> j >> cost;
        G->edges[i][j] = cost;
        G->edges[j][i] = cost;
    }
    //求解最小生成树
    cost = Prim(*G, m);
    //输出最小权值和
    cout << "最小权值和=" << cost << endl;
    return 0;
}
