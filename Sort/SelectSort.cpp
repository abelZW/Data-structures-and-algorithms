#include <iostream>
void SelectSort(int r[], int n)
{
    int i, index, j, temp;
    for (i = 1; i < n; i++) //执行第i遍的扫描
    {
        index = i;
        for (j = i + 1; j < n; j++) //比较无序序列中的记录
        {
            if (r[index] > r[j]) //找出序列中的最小的位置
            {
                index = j;
            }
        }
        if (index != i) //如果无序序列中第一个记录不是最小值，则进行交换
        {
            temp = r[index];
            r[index] = r[i];
            r[i] = temp;
        }
    }
}

int main()
{
    using namespace std;
    
    int r[] = {0,5,6,8,10,43,3,12,23,54,45};
    int Num = sizeof(r)/sizeof(r[0]);//计算数组的长度
    //cout << Num << " ";
    SelectSort(r,Num);
    for(int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }
    
    return 0;   
}
//性质：1、时间复杂度：O(n2)  2、空间复杂度：O(1)  3、非稳定排序  4、原地排序
