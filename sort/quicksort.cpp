#include <iostream>
#include <vector>
using namespace std;

void quicksort(int *arr, int start, int end)
{
    while (left >= right)
    {
        return;
    }
    int left = start, right = end;
    /**
     * @brief 先整体看卡里有序，再处理
     * 1. pivot, arr[start], arr[end]
     * 2. get value not index
     *
     */
    int pivot = arr[(left + right) >> 1];

    while (left <= right)
    {
        while (left <= right && arr[left] < pivot)
        {
            left++;
        }
        while (left <= right && arr[right] > pivot)
        {
            right--;
        }
        if (left <= right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
        quicksort(arr, start, right);
        quicksort(arr, left, end);
    }
}
int main()
{
    int array[] = {1, 3, 2, 4, 5};
    quicksort(array, 0, 4);
    int length = sizeof(array) / sizeof(*array);
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << "\n";
    }
    return 0;
}