//
//  Kruskal.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/16.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;

typedef struct
{
    int a,b;      //a,b为一条边的两个顶点
    int weight;   //边的权值
}Road;


Road road[maxSize]; //假设road数组存放了图中各边和所连接的两个顶点信息
int v[maxSize];     //并查集数组

//查找根结点
int getRoot(int a)
{
    while (a != v[a]) {
        a = v[a];
    }
    return a;
}

/**
 排序，将road数组中的e条边按权值从小到大排序
 */
void sortRoad(Road road[], int e)
{
    //根据题目选择相应排序算法
}

void Kruskal(MGraph G, int &sum, Road road[])
{
    //初始化并查集，下标对应其顶点标号，表示每个顶点都独立，无父子关系
    for (int i = 1; i <= G.n; ++i)
    {
        v[i] = i;
    }
    
    //将road数组中的e条边按权值从小到大排列
    sortRoad(road, G.e);
    
    //从小到大遍历边，在并查集中将顶点对应下标的值指向父结点，即
    for (int i = 1; i <= G.e; ++i)
    {
        int a = getRoot(road[i].a);     //边顶点a的根
        int b = getRoot(road[i].b);     //边顶点b的根
        
        //判断a、b是否已经在一颗生成树中，若不在，v[a] = b, b当a的父亲
        if (a != b)
        {
            v[a] = b;
            
            //此处求生成树的权值，可改成各边输出，或存放在数组里
            sum += road[i].weight;
        }
    }
}











