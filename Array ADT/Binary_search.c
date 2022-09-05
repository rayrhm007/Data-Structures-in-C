#include <stdio.h>
#include <stdlib.h>

int Binsearch(int a[], int key, int low, int top)
{
    int mid;
    mid = (low + top)/2;

    if(low > top)
    {
        return -1;
    }

    if(key > a[mid])
    {
        mid = Binsearch(a, key, mid+1, top);
        return mid;
    }
    else if(key < a[mid])
    {
        mid = Binsearch(a, key, low, mid-1);
        return mid;
    }

    return mid;
}

int main()
{
    int a[] = {2, 3, 7, 9, 10, 16, 18, 21, 28, 32, 35, 43, 44, 47, 50, 58};
    int key, low = 0, x;

    printf("Enter the number you want to search for: ");
    scanf(" %d", &key);

    int top = sizeof(a)/sizeof(a[0]);

    x = Binsearch(a, key, low, top);

    if(x != -1)
    {
        printf("Key found at index: %d", x);
    }
    else
    {
        printf("Key not found");
    }
    
    return 0;

}

