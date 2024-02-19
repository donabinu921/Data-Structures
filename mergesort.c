#include <stdio.h>

void merge(int a[], int l, int s, int r)
{
    int b[50], k = 0, i = l, j = s;
    while (i < s && j <= r)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i < s)
    {
        b[k++] = a[i++];
    }
    while (j <= r)
    {
        b[k++] = a[j++];
    }
    for (i = l, k = 0; i <= r;)
    {
        a[i++] = b[k++];
    }
}

void mergesort(int a[], int l, int r)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid + 1, r);
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
    mergesort(a, 0, n - 1);
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}