#include <iostream>

int Partition(int a[], int low, int high)
{
    int x = a[high];                 //将输入数组的最后一个数作为主元，用它来对数组进行划分
    int i = low - 1;                 //i是最后一个小于主元的数的下标
    for (int j = low; j < high; j++) //遍历下标由low到high-1的数
    {
        if (a[j] < x) //如果数小于主元的话就将i向前挪动一个位置，并且交换j和i所分别指向的数
        {
            int temp;
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    //经历上面的循环之后下标为从low到i（包括i）的数就均为小于x的数了，现在将主元和i+1位置上面的数进行交换
    a[high] = a[i + 1];
    a[i + 1] = x;
    return i + 1;
}
void QuickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int q = Partition(a, low, high);
        QuickSort(a, low, q - 1);
        QuickSort(a, q + 1, high);
    }
}
int main()
{
    using namespace std;

    int r[] = {0, 5, 6, 8, 10, 43, 3, 12, 23, 54, 45};
    int Num = sizeof(r) / sizeof(r[0]); //计算数组的长度
    //cout << Num << " ";
    QuickSort(r, 0, Num-1);
    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }

    return 0;
}
//性质：1、时间复杂度：O(nlogn) 2、空间复杂度：O(logn) 3、非稳定排序 4、原地排序