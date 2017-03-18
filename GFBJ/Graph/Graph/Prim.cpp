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

 @param G 图
 @param v0 开始顶点编号
 @param sum 记录树的权值
 */
void Prim(MGraph G, int v0, int &sum)
{
    int lowcost[maxSize];   //存放当前生成树到剩余顶点最短边的权值
    int vset[maxSize];      //vset[i]=1表示 顶点i已被并入生成树中
    
    /*注：此处vset数组其实就是lowcost数组的参考，vset为1的顶点，
    lowcost对应的位置就不会再比较大小去选边了，相当于放弃了。*/
    
    
    //初始化lowset和vset数组
    for (int i = 1; i < G.n; ++i)
    {
        lowcost[i] = G.edges[v0][i];    //初始化邻接矩阵中v0那行
        vset[i] = 0;                    //置0，当前没有结点并入MST
    }
    
    vset[v0] = 1;           //将v0并入树中
    
    int min;
    //循环完成一次，代表最小生成树并入了一个顶点，n个结点，即n-1条边，遍历次数为n-1
    for (int i = 1; i < G.n; ++i)
    {
        min = INF;          //INF相当于邻接矩阵中的∞
        int k = 0;          //标记最短边对应的顶点
        //找到当前生成树的候选边的最小一条
        for (int j = 1; j <= G.n; ++j)
        {
            //以vset数组为参考，从lowcost数组中选一条权值最小的边
            //（此时）lowcost中的边都是和生成树相连的
            if (vset[j] == 0 && lowcost[j] < min)
            {
                min = lowcost[j];   //找到矩阵i行中最小的权值
                k = j;
            }
        }
        
        vset[k] = 1;
        
        //此处以求MST权值为例，可换成其他操作，如输出各边，或将各边存入数组
        sum += min;
        
        //以刚并入生成树中的顶点为媒介，更新候选边
        for (int j = 1; j<= G.n; ++j)
        {
            /*此算法比较难懂的部分是lowcost怎样维护，即加入一个顶点就扫描一遍
             该顶点的边，与之前扫描过的进行比较来维护 */
            if (vset[j] == 0 && G.edges[k][j] < lowcost[j])
            {
                lowcost[j] = G.edges[k][j];
            }
        }
    }
}
