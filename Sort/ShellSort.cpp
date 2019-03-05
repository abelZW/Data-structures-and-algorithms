#include <iostream>
void Swap(int i, int j)
{
    int temp = i;
    j = i;
    i = temp;
}
//分组插入排序 or 分组插入排序
void ShellSort1(int a[], int n)
{
    int i,j,gap;

    for(gap = n/2; gap > 0; gap /= 2)   //步长
        for(i = 0; i < gap; i++)
        {
            for(j = i + gap; j < n; j = j + gap)
                if(a[j] < a[j-gap])
                {
                    int temp = a[j];
                    int k = j - gap;
                    while (k >= 0 && a[k] > temp)
                    {
                        a[k+gap] = a[k];
                        k = k - gap;
                    }
                    a[k + gap] = temp;  //可能需要调换，也可能不需要调换
                }
        }
}

void ShellSort2(int a[],int n)
{
    int j,gap;
    for (gap = n/2; gap > 0; gap /= 2)
    {
        for(j = gap; j < n; j++)//从数组的第gap个元素开始
            if(a[j] < a[j-gap]) //每个元素与自己组内的数据进行直接插序
            {
                int temp = a[j];
                int k = j - gap;
                while (k >= 0 && a[k] > temp)
                {
                    a[k+gap] = a[k];
                    k = k - gap;
                }
                a[k+gap] = temp;
            }
    }
}

void ShellSort3(int a[],int n)
{
    int i,j,gap;
    for(gap = n/2;gap > 0; gap = gap/2)
        for(i = gap; i < n;i++)
            for(j = i - gap;j >= 0&&a[j] > a[j+gap]; j = j - gap)
                Swap(a[j],a[j+gap]);
}
int main()
{
    using namespace std;

    int r[] = {0, 5, 6, 8, 10, 43, 3, 12, 23, 54, 45};
    int chose;//选择算法；
    int Num = sizeof(r) / sizeof(r[0]); //计算数组的长度
    //cout << Num << " ";
    cout << "算法1（直观插入）:1\n算法2（优化）:2\n算法3（冒泡插入）:3\n";
    cin >> chose;
    switch (chose)
    {
    case 1:
        ShellSort1(r, Num);
        break;
    case 2:
        ShellSort2(r, Num);
    case 3:
        ShellSort3(r,Num);
    default:
        break;
    }
    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }

    return 0;
}
//性质：1、时间复杂度：O(nlogn)  2、空间复杂度：O(1)  3、非稳定排序  4、原地排序