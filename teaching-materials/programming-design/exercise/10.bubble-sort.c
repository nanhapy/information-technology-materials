#include <stdio.h>

void printArray(int arr[], int size);

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                printf("%2d. ", ++count);
                printArray(arr, size);
            }
        }
    }
}

void bs(int arr[], int size)
{
    // printArray(arr, size);
}

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // int min = arr[i];
        int min_pos = i;
        for (int j = i + 1; j <= size - 1; j++)
        {
            if (arr[j] < arr[min_pos])
            {
                // min = arr[j];
                min_pos = j;
            }
        }

        if (i != min_pos)
        {
            int temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }

    printArray(arr, size);
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    arr[high] = arr[i + 1];
    arr[i + 1] = pivot;
    return i + 1;
}

// 交换
int partition2(int arr[], int low, int high)
{
    // 取第一个位置的元素作为基准元素
    int pivot = arr[low];
    int left = low;
    int right = high;
    while (left != right)
    {
        //控制right指针比较并左移
        while (left < right && arr[right] > pivot)
        {
            right--;
        }
        //控制right指针比较并右移
        while (left < right && arr[left] <= pivot)
        {
            left++;
        }
        //交换left和right指向的元素
        if (left < right)
        {
            int p = arr[left];
            arr[left] = arr[right];
            arr[right] = p;
        }
    }

    //pivot和指针重合点交换
    int p = arr[left];
    arr[left] = arr[low];
    arr[low] = p;
    return left;
}

// 挖坑
int partition3(int arr[], int low, int high)
{
    // 取第一个位置的元素作为基准元素
    int pivot = arr[low];
    int left = low;
    int right = high;
    // 坑的位置，初始等于pivot的位置
    int index = low;
    //大循环在左右指针重合或者交错时结束
    while (right >= left)
    {
        //right指针从右向左进行比较
        while (right >= left)
        {
            if (arr[right] < pivot)
            {
                arr[left] = arr[right];
                index = right;
                left++;
                break;
            }
            right--;
        }
        //left指针从左向右进行比较
        while (right >= left)
        {
            if (arr[left] > pivot)
            {
                arr[right] = arr[left];
                index = left;
                right--;
                break;
            }
            left++;
        }
    }
    arr[index] = pivot;
    return index;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {8, 7, 5, 3, 6, 9, 1, 2};

    int size = sizeof(arr) / sizeof(int);

    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }

    getch();
    // int size = 0;

    // scanf("%d", &size);

    // int arr[size];

    // for (int i = 0; i < size; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    // ;

    // int size = arr.length;

    // int size = 6;

    printArray(arr, size);

    printf("bubbleSort:\n");

    bubbleSort(arr, size);

    int arr2[] = {8, 7, 5, 3, 6, 9, 1, 2};

    printf("selectionSort:\n");

    selectionSort(arr2, size);

    int arr3[] = {8, 7, 5, 3, 6, 9, 1, 2};

    printf("quickSort:\n");

    quickSort(arr3, 0, size - 1);

    printArray(arr3, size);

    getch();
}

void printArray(int arr[], int size)
{
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}
