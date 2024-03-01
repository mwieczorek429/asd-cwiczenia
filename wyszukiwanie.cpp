#include <iostream>
#include <math.h>

using namespace std;


int linearSearch(int arr[], int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
            return i;
    }

    return -1;
}

int binarySearch(int arr[], int n, int x)
{
    int l = 0;
    int r = n; 
    int m;

    while (l<=r)
    {
        m = (l+r) / 2;
        if(arr[m] < x)
            l = ++m;
        else if(arr[m] > x)
            r = --m;
        else
            return  m;
    }

    return -1;
    
}

int jumpSearch(int arr[], int n, int x)
{
    int block = sqrt(n);
    int index = 0;

    while (arr[min(block, n) - 1] < x)
    {
        index = block;
        block += sqrt(n);

        if(index >= n)
            return -1;
    }

    while (arr[index] < x)
    {
        index++;
        if(index == min(block, n))
            return -1;
    }

    if(arr[index] == x)
        return index;
    
    return -1;
}


int main(int argc, char const *argv[])
{
    int data[9] = {1,4,7,10,14,23,45,47,53};
    int n = 9;
    int x = 47;

    int linearResult = linearSearch(data, n, x);
    cout<<"Linear: "<<linearResult<<endl;
    int binaryResult = binarySearch(data, n, x);
    cout<<"Binary: "<<binaryResult<<endl;
    int jumpResult = jumpSearch(data, n, x);
    cout<<"Jump: "<<jumpResult<<endl;
    system("pause");
    return 0;
}
