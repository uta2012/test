#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void MergeData(int* arr,int left,int mid,int right,int* s){//对两组有序序列进行归并
    int begin1=left;//第一组序列的首元素下标
    int end1=mid-1;//第一组序列最后元素下标
    int begin2=mid;//第二组序列首元素下标
    int end2=right-1;//第二组序列最后元素下标
    int count=left;//进行归并时第一个元素应放在对应的位置
    while(begin1<=end1&&begin2<=end2){//归并两组序列
        if(arr[begin1]<=arr[begin2]){
            s[count]=arr[begin1];
            begin1++;
        }else{
            s[count]=arr[begin2];
            begin2++;
        }
        count++;
    }
    while(begin1<=end1){//如果第一组序列有剩余，继续归并
        s[count]=arr[begin1];
        count++;
        begin1++;
    }
    while(begin2<=end2){//如果di二组序列有剩余，继续归并
        s[count]=arr[begin2];
        count++;
        begin2++;
    }
}
void MergeSort(int* arr,int left,int right,int* s){//归并排序递归
    if(right-left<=1){//元素个数小于1，直接返回
        return;
    }
    int mid=left+(right-left)/2;
    MergeSort(arr,left,mid,s);//归并左半部分
    MergeSort(arr,mid,right,s);//归并右半部分
    MergeData(arr,left,mid,right,s);//将当前有序的序列进行归并
    memcpy(arr+left,s+left,sizeof(arr[0])*(right-left));//将归并后的将结果拷贝回原来的数组，为下次归并做准备
 
}
void MergeSortNonR(int* arr,int size){
    int* s=(int*)malloc(sizeof(arr[0])*size);
    int gap=1;//相当于第一次每一个为一组
    while(gap<size){
        int i=0;
        for(;i<size;i+=2*gap){
            int left=i;
            int mid=left+gap;
            if(mid>size){//越界，进行复位
                mid=size;
            }
            int right=mid+gap;
            if(right>size){
                right=size;
            }
            MergeData(arr,left,mid,right,s);
        }
        gap*=2;
        memcpy(arr,s,sizeof(arr[0])*size);//拷贝
    }
}
void Print(int* arr,int size){
    int i=0;
    for(;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    //int* s=(int*)malloc(sizeof(arr));
    //MergeSort(arr,0,sizeof(arr)/sizeof(arr[0]),s);
    MergeSortNonR(arr,sizeof(arr)/sizeof(arr[0])); 
    Print(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}