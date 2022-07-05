#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int stages = 4, min;
    int n = 7;
    int cost[n + 1], d[n + 1], path[stages];
    // int c[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
    //                {0, 0, 2, 1, 3, 0, 0, 0, 0},
    //                {0, 0, 0, 0, 0, 2, 3, 0, 0},
    //                {0, 0, 0, 0, 0, 6, 7, 0, 0},
    //                {0, 0, 0, 0, 0, 6, 8, 9, 0},
    //                {0, 0, 0, 0, 0, 0, 0, 0, 6},
    //                {0, 0, 0, 0, 0, 0, 0, 0, 4},
    //                {0, 0, 0, 0, 0, 0, 0, 0, 5},
    //                {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int c[n + 1][n + 1] = {{0, 1, 2, 5, 0, 0, 0, 0},
                           {0, 0, 0, 0, 4, 11, 0, 0},
                           {0, 0, 0, 0, 9, 5, 16, 0},
                           {0, 0, 0, 0, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0, 0, 0, 18},
                           {0, 0, 0, 0, 0, 0, 0, 13},
                           {0, 0, 0, 0, 0, 0, 0, 2},
                           {0, 0, 0, 0, 0, 0, 0, 0}};

    cost[n] = 0;
    d[n] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        min = 32767;
        for (int k = i + 1; k <= n; k++)
        {
            if (c[i][k] != 0 && c[i][k] + cost[k] < min)
            {
                min = c[i][k] + cost[k];
                d[i] = k;
            }
        }
        cost[i] = min;
    }

    path[0] = 0;
    for (int i = 1; i < stages; i++)
    {
        path[i] = d[path[i - 1]];
    }

    cout << "cost array :" << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << cost[i] << " ";
    }
    cout << "\nd array : " << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << d[i] << " ";
    }
    cout << "\nPath : " << endl;
    for (int i = 0; i < stages; i++)
    {
        cout << path[i] << " ";
    }

    return 0;
}
