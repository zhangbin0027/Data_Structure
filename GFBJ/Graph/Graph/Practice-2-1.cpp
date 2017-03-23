//
//  Practice-2-1.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/23.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
#include "Struct.cpp"
using namespace std;

/*现有城镇道路统计表，表中列出任意两城镇之间修建道路的费用，以及该道路
 是否已经修通的状态，全省一共有n个村庄，计算全省畅通需要的最低成本*/

#define M 20        //假设已修和待修的路一共有M条

typedef struct
{
    int a,b;        //a、b为道路两端的两个村庄
    int cost;       //a、b间修路的费用
    int is;         //0代表a、b之间未修路，1代表已经修了路
}Road;

Road road[M+1];

void sortRoad(Road road[]){}
int getRoot(int a, int set[])
{
    while (a != set[a]) {
        a = set[a];
    }
    return a;
}

//使用kruscal求最小生成树，n为顶点数
int KurscalLowcost(Road road[], int n)
{
    int set[maxSize];   //定义并查集
    int min;            //最少花费cost
    
    for (int i = 0; i < n; ++i) {
        set[i] = i;
    }
    //先将已经建好的道路并入并查集
    for (int i = 0; i < M && road[i].is == 1; ++i) {
        int a = getRoot(road[i].a,set);
        int b = getRoot(road[i].b,set);
        if (a != b) {
            set[b] = a;
        }
    }
    //将边（路）从小到大排序
    sortRoad(road);
    //依次将未修通的路并入并查集并计算cost
    for (int i = 0; i < M && road[i].is == 0; ++i) {
        int a = getRoot(road[i].a,set);
        int b = getRoot(road[i].b,set);
        if (a != b ) {
            set[a] = b;
            min += road[i].cost;
        }
    }
    return min;
}
