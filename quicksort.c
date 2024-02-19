#include <stdio.h>

int partition(int a[], int l, int r)
{
    int key, i, j, temp;
    key = a[l];
    i = l + 1;
    j = r;
    do
    {
        while (a[i] < key && i < r)
        {
            i++;
        }
        while (a[j] > key && j > l)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);
    temp = a[j];
    a[j] = a[l];
    a[l] = temp;
    return j;
}

void quicksort(int a[], int l, int r)
{
    int pos;
    if (l < r)
    {
        pos = partition(a, l, r);
        quicksort(a, l, pos - 1);
        quicksort(a, pos + 1, r);
    }
}

void main()
{
    int a[50], n, i;
    printf("Enter array size:");
    scanf("%d", &n);
    printf("Enter array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}