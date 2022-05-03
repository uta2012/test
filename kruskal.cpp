#include <iostream>
#include <algorithm>
#include <cstdio>

#define max 1000010

struct Edge
{
    int vertexA;
    int vertexB;
    int dis;
}edges[max];

int vertexs[max];

// 排序函数
bool cmp(struct Edge a, struct Edge b)  
{
    return a.dis < b.dis;
}

int kruscal(int N, int M, struct Edge edges[], int vertexs[])
{
    int i = 0;
    int temp;
    int result = 0;
    while(i != M)
    {
        if(vertexs[edges[i].vertexA] != vertexs[edges[i].vertexB])
        {
    
            // 同化
            temp = vertexs[edges[i].vertexB];
            for(int j=1; j<N+1; j++)
            {
                if(vertexs[j] == temp)
                {
                    vertexs[j] = vertexs[edges[i].vertexA];
                }
            }
            result += edges[i].dis;
            i += 1;
        }
        else
        {
            i += 1;
        }
    }


    for(int i=1; i<N; i++)
    {
        if(vertexs[i] != vertexs[i+1])
        {
            return -1;
        }
    }
    return result;
}




int main()
{
    // 接收输入
    int N,M;
    std::cin >> N >> M;
    
    for(int i=0; i<M; i++)
    {
        std::cin >> edges[i].vertexA >> edges[i].vertexB >> edges[i].dis;
    } 

    // 节点标识符
    
    for(int i=1; i<=N; i++)
    {
        vertexs[i] = i;
    }


    // 排序
    std::sort(edges,edges+M, cmp);    

    /* // 打印
    std::cout << "print" << std::endl;
    std::cout << "节点标识" << std::endl;
    for(int i=0; i<N+1; i++)
    {
        std::cout << vertexs[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "排序后的边" << std::endl;
    for(int i=0; i<M; i++)
    {
        std::cout << edges[i].vertexA << " " << edges[i].vertexB << " " << edges[i].dis << std::endl;
    } */ 


    std::cout << kruscal(N, M, edges, vertexs);
    return 0;
}