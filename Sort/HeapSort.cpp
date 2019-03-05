/*
大顶堆：节点大于左右孩子；小顶堆：节点小于左右孩子
用简单的公式来描述一下堆的定义就是：
大顶堆：arr[i] >= arr[2i + 1] && arr[i] >= arr[2i + 2]
小顶堆：arr[i] <= arr[2i + 1] && arr[i] <= arr[2i + 2]
升序：大顶堆
降序：小顶堆
*/

#include <iostream>
void AdjustHeap(int *arr, int i, int length);
void swap(int *arr, int a, int b); 
void HeapSort(int *arr, int Num)
{
    //建立大顶堆
    for(int i = Num/2 - 1;i >= 0; i--)
    //从第一个非叶节点从下到上，从左到右调整结构
        AdjustHeap(arr,i,Num);
    //调整堆结构+交换堆顶元素与末尾元素
    for(int j = Num - 1;j >0;j--){
        swap(arr,0,j);//将堆顶元素与末尾元素进行交换
        AdjustHeap(arr,0,j);//重新对堆进行排序
    }
}
//交换函数
void swap(int *arr, int a,int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}
//调整过程，建立在大顶堆已构建完成
void AdjustHeap(int *arr, int i, int length){
    int temp = arr[i];//先取出当前的元素i
    for (int k = i * 2 + 1; k < length; k = k * 2 + 1) //从i结点的左子节点开始，也就是2i+1处开始
    { 
        if(k+1 < length && arr[k] < arr[k+1]){
        //如果左子节点小于右子节点，k指向右子节点
        k++;
        }
        if (arr[k] > temp)
        {
            //如果子节点大于父节点，将子节点值赋值给父节点（不用进行交换）
            arr[i] = arr[k];
            i = k;
        }
        else
        {
            break;
        }
    }
    arr[i] = temp;//将temp放到最终的位置
}
int main()
{
    using namespace std;
    int r[] = {0, 5, 6, 8, 10, 43, 3, 12, 23, 54, 45};
    int Num = sizeof(r) / sizeof(r[0]); //计算数组的长度
    cout << "Before: ";
    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }
    HeapSort(r, Num);
    cout << endl
         << "After: ";
    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }

    return 0;
}

//性质：1、时间复杂度：O(nlogn)  2、空间复杂度：O(1)  3、非稳定排序  4、原地排序