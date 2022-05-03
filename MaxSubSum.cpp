#include <iostream>
#include <algorithm>



int max(int a, int b, int c)
{
    int arr[3] = {a, b, c};
    std::sort(arr, arr+3);
    return arr[2];
}



int MaxSubSum(int arr[], int left, int right)
{
    int MaxLeft, MaxRight;
    int mid;
    int MaxBorderLeft = 0, MaxBorderRight = 0;
    int BorderLeft, BorderRight;
    int MaxMidSum;


    if(arr[left] == arr[right])
    {
        if(arr[left] > 0)
            return arr[left];
        else
            return 0;
    }


    mid = (left + right)/2;
    MaxLeft = MaxSubSum(arr, left, mid);
    MaxRight = MaxSubSum(arr, mid+1, right);


    BorderLeft = 0, BorderRight = 0;
    for(int i=mid; i>0; i--)
    {
        BorderLeft += arr[i];
        if(BorderLeft > MaxBorderLeft)
            MaxBorderLeft = BorderLeft;
    }
    for(int i=mid+1; i<right; i++)
    {
        BorderRight += arr[i];
        if(BorderRight > MaxBorderRight)
            MaxBorderRight = BorderRight;
    }
    MaxMidSum = MaxBorderLeft + MaxBorderRight;

    return max(MaxLeft, MaxRight, MaxMidSum);
}




int main()
{

    return 0;
}