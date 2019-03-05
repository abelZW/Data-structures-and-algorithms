#include <iostream>
void Merge(int *arr, int start, int end, int *result);
void MergeSort(int *arr, int start, int end, int *result)
{
    if (1 == end - start) //如果区间中只有两个元素，则对这两个元素进行排序
    {
        if (arr[start] > arr[end])
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
        return;
    }
    else if (0 == end - start) //如果只有一个元素，则不进行排序
        return;
    else
    {
        //int mid = (end - start + 1) / 2 ;//+ start;
        //继续划分子区间，分别对左右子区间进行排序
        MergeSort(arr, start, (end - start + 1) / 2 + start, result);
        MergeSort(arr, (end - start + 1) / 2 + start, end, result);
        //开始归并已经排序的start到end之间的数据
        Merge(arr, start, end, result);

        //排好序的区间数据复制到原数据中去
        for (int i = start; i <= end; ++i)
            arr[i] = result[i];
    }
}

void Merge(int *arr, int start, int end, int *result) //数据归并
{
    int left_length = (end - start + 1) / 2 + 1; //左部分区间的数据元素的个数
    int left_index = start;
    int right_index = start + left_length;
    int result_index = start;
    while (left_index < start + left_length && right_index < end + 1)
    {
        //对分别已经排好序的左区间和右区间进行合并
        if (arr[left_index] <= arr[right_index])
            result[result_index++] = arr[left_index++];
        else
            result[result_index++] = arr[right_index++];
    }
    while (left_index < start + left_length)
        result[result_index++] = arr[left_index++];
    while (right_index < end + 1)
        result[result_index++] = arr[right_index++];
}

int main()
{
    using namespace std;

    int r[] = {0, 5, 6, 8, 10, 43, 3, 12, 23, 54, 45};
    const int Num = sizeof(r) / sizeof(r[0]); //计算数组的长度
    int result[Num];
    //cout << Num << " ";
    MergeSort(r, 0, Num - 1, result);

    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }

    return 0;
}
//性质：1、时间复杂度：O(nlogn) 2、空间复杂度：O(n) 3、稳定排序 4、非原地排序
