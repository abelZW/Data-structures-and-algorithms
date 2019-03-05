//将数组分开为很多份,然后对每份排序
#include <iostream>
#include <cstring>
using namespace std;
int getMax(int a[], int n)
{
    int i, max;

    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}
void BucketSort(int *a, int n, int max)
{
    int i, j;
    int *buckets;

    if (a == NULL || n < 1 || max < 1)
        return;
    // 创建一个容量为max的数组buckets，并且将buckets中的所有数据都初始化为0。
    if ((buckets = new int[max]) == NULL)
        return;
    memset(buckets, 0, max * sizeof(int));
    // 计数
    for (i = 0; i < n; i++)
        buckets[a[i]]++;
    //排序
    for (i = 0, j = 0; i < max; i++)
        while ((buckets[i]--) > 0)
            a[j++] = i;
    delete[] buckets;
}

int main()
{
    int r[] = {0, 5, 6, 8, 10, 43, 3, 12, 23, 54, 45};
    int Num = sizeof(r) / sizeof(r[0]); //计算数组的长度
    cout << "Before: ";
    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }
    BucketSort(r, Num,100);//数组，数组长度，数组最大表示范围
    cout << endl <<"After: ";
    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }

    return 0;
}
//性质：1、时间复杂度：O(n+k)  2、空间复杂度：O(n+k)  3、稳定排序  4、非原地排序