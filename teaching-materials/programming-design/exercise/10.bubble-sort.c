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
    for (int i = 1; i <= size - 1; i++)
    {
        for (int j = size - 1; j >= i; j--)
        {
            if (arr[j] < arr[j - 1])
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
    //int arr[] = {8, 7, 5, 3, 6, 9, 1, 2};

    //int size = sizeof(arr) / sizeof(int);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    ;

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
