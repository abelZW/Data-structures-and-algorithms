#include <iostream>
void InsertSort(int a[],int n)
{
    for(int j = 1;j < n; j++)//对第j个元素排序
    {
        int key = a[j];//待排序的第一个元素
        int i = j -1;   //代表已经排过序的元素的最后的一个索引数
        while(i >= 0 && key < a[i])
        {
            a[i+1] = a[i];//从后向前比较已经排序的数组，如果比它下，则把后者和前者代替
            i--;
        }
        a[i+1] = key;//找到合适的位置了，赋值，在i索引的后面设置key值
    }
}

int main()
{
    using namespace std;

    int r[] = {0, 5, 6, 8, 10, 43, 3, 12, 23, 54, 45};
    int Num = sizeof(r) / sizeof(r[0]); //计算数组的长度
    //cout << Num << " ";
    InsertSort(r, Num);
    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }

    return 0;
}
//性质：1、时间复杂度：O(n2)  2、空间复杂度：O(1)  3、稳定排序  4、原地排序
