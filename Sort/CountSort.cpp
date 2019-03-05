//临时数组大小 (max - min + 1)就可以了，然后在把 min作为偏移量
#include <iostream>
using namespace std;
void CountSort(int *arr,int Num)
{
    if(arr == NULL || Num < 2)
        return;
    int n = Num;
    int min = arr[0];
    int max = arr[0];
    //搜寻数组最大值和最小值
    for(int i = 1; i < n; i++)
    {
        if(max <= arr[i])
            max = arr[i];
        if(min > arr[i])
            min = arr[i];
    }
    const int d = max - min + 1;//创建大小为d的临时数组
    int temp[d] = {0};
    //统计元素i出现的次数
    
    for(int i = 0; i < n; i++)
    {
        temp[arr[i] - min]++;
    }
    int k = 0;
    
    //把临时数组统计好的数汇总到原数组
    for(int i = 0;i < d;i++)
    {
        for(int j = temp[i]; j > 0; j--)
        {
            arr[k++] = i + min;
        }
       
    }
    return ;
}
int main()
{
    int r[] = {0, 5, 6, 8, 10, 43, 3, 12, 23, 54, 45};
    int Num = sizeof(r) / sizeof(r[0]); //计算数组的长度
    //cout << Num << " ";
    CountSort(r, Num);
    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }

    return 0;
}
//性质：1、时间复杂度：O(n+k)  2、空间复杂度：O(k)  3、稳定排序  4、非原地排序