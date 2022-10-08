//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int j = partition(arr, low, high);
            quickSort(arr, low, j);
            quickSort(arr, j + 1, high);
        }
    }

public:
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i = low, j = high + 1;
        while (i < j)
        {
            do
            {
                i++;
            } while (arr[i] <= pivot);
            do
            {
                j--;
            } while (arr[j] > pivot);
            if (i < j)
                swap(arr[i], arr[j]);
        }
        swap(arr[j], arr[low]);
        return j;
    }
};

//{ Driver Code Starts.
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int arr[1000], n, T, i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        Solution ob;
        ob.quickSort(arr, 0, n - 1);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends