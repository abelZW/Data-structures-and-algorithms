#include <iostream>
void swap(int array[],int i,int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}
void BubbleSort1(int array[],int n)
{
    for(int i = 0;i < n-1; i++)
    {
        for(int j = i+1;j < n-1; j++)
        {
            if(array[i]>array[j])
                swap(array, j, i); 
        }
    }
}

void BubbleSort2(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            if (array[j - 1] > array[j])
                swap(array, j, i); 
        }
    }
}

int main()
{
    using namespace std;

    int r[] = {0, 5, 6, 8, 10, 43, 3, 12, 23, 54, 45};
    int Num = sizeof(r) / sizeof(r[0]); 
    int chose;
    //cout << Num << " ";
    cout << "chose 1 or 2 :" <<endl;
    cin >> chose;
    //cout << endl;
    
    switch (chose)
    {
        case 1:
            BubbleSort1(r, Num);
            break;
        case 2:
            BubbleSort2(r, Num);
        default:
            break;
    }
    
    for (int i = 0; i < Num; i++)
    {
        cout << r[i] << " ";
    }

    return 0;
}

