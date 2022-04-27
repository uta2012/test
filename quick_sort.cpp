#include <iostream>

int Partition(int arr[], int head, int tail)
{
    int right = tail, left = head;
    int p = arr[head];

    

    while(right != left)
    {
        while(right > left && arr[right] >= p)
        {
            right--;
        }
        arr[left] = arr[right];
        while(left < right && arr[left] <= p)
        {
            left++;
        }
        arr[right] = arr[left];
        
    }

    arr[left] = p;
    return left;
}

void Quicksort(int a[], int head, int tail)
{

    if(head < tail)
    {
        int i = Partition(a, head, tail);
         
        Quicksort(a, head, i-1);
        Quicksort(a, i+1, tail);
    }
}
int main()
{
    //std::cout << "开始" << std::endl;
    int n;
    std::cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    
    Quicksort(arr, 0, n-1);

    //std::cout << "打印" << std::endl;
    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if(i != n-1)
        {
            std::cout << " ";
        }
    }
    return 0;
}