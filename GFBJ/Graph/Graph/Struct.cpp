//
//  Struct.cpp
//  Graph
//
//  Created by 牛严 on 2017/3/12.
//  Copyright © 2017年 牛严. All rights reserved.
//

#include <iostream>
using namespace std;

#define maxSize 100

//-------------------------邻接矩阵------------------------
//顶点结构
typedef struct Vertex
{
    int no;         //顶点编号
    char info;      //顶点数据
}Vertex;

//邻接矩阵
typedef struct Mgraph
{
    int edges[maxSize][maxSize];    //邻接矩阵定义，若是有权图，数据类型为float
    int n,e;                        //顶点数、边数
    Vertex vex[maxSize];           //结点信息
}Mgraph;


//-------------------------邻接表-----------------------
//边结构
typedef struct ArcNode
{
    int adjVex;                     //该边所指向的结点编号
    struct ArcNode *nextArc;        //指向下一条边的指针
    int info;                       //该边信息，如权值
}ArcNode;

//顶点结构
typedef struct VNode
{
    char data;                      //顶点信息。顶点编号可通过数组下标获取
    ArcNode *firstArc;              //顶点指向的第一条边的指针
}VNode;

//邻接表结构
typedef struct
{
    VNode adjList[maxSize];         //邻接表
    int n,e;                        //顶点数和边数
}AGraph;







