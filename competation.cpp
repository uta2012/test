#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX 101
int a[MAX][MAX];

void plan(int k)
{
    //std::cout << "start!" << std::endl;
    a[1][1] = 1;
    a[1][2] = 2;
    a[2][1] = 2;
    a[2][2] = 1;



    for(int i=2; i<=k; i++)
    {
        // 左下角
        for(int j=1+std::pow(2,i-1); j<=std::pow(2,i); j++)
        {
            for(int q=1; q<=std::pow(2,i-1); q++)
            {
                a[j][q] = a[j-(int)(std::pow(2,i-1))][q] + std::pow(2,i-1);
            }
        }

        // 右上角
        for(int j=1; j<=std::pow(2,i-1); j++)
        {
            for(int q=1+std::pow(2,i-1); q<=std::pow(2,i); q++)
            {
                a[j][q] = a[j+(int)pow(2,i-1)][q-(int)pow(2,i-1)];
            }
        }

        // 右下角
        for(int j=1+std::pow(2,i-1); j<=std::pow(2,i); j++)
        {
            for(int q=1+std::pow(2,i-1); q<=std::pow(2,i); q++)
            {
                a[j][q] = a[q-(int)(std::pow(2,i-1))][j-(int)(std::pow(2,i-1))];
            }
        }


    }




    
    // 打印
    for(int i=1; i<=std::pow(2, k); i++)
    {
        for(int j=1; j<=std::pow(2, k); j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

}




int main()
{
    int k;
    std::cin >> k;
    plan(k);


    return 0;
}