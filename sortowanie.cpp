#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; ++i)
       for(int j = 0; j < n - i - 1; ++j)
            if(arr[j] > arr[j+1])
            {
                int a = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = a;
            }
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        int min_idx = i;

        for(int j = i + 1; j < n; ++j)
            if(arr[j] < arr[min_idx])
                min_idx = j;

        int a = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = a;
    }
}

int main(int argc, char const *argv[])
{
    int tab[] = {10,5,1,15,4};
    int n = 5;
    //bubbleSort(tab, n);
    insertionSort(tab, n);
    //selectionSort(tab, n);
    for(int i = 0; i < n; ++i)
        cout<< tab[i] << " ";

    system("pause");
    return 0;
}
