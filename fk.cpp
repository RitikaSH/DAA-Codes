/*
    Created By : Vikram Markali
*/

#include <bits/stdc++.h>
using namespace std;

// structure to store profit and weight of Items
struct Objects
{
    string objeName;
    int profit, weight;
};

// compartor function
bool comparator(Objects a, Objects b)
{
    return ((double)a.profit / (double)a.weight > ((double)b.profit / (double)b.weight));
}

// fractional knapsack algorithm
double fractionalKnapsack(Objects obj[], int W, int n)
{
    double profitCount = 0.0;
    sort(obj, obj + n, comparator);

    for (int i = 0; i < n; i++)
    {
        if (obj[i].weight <= W)
        {
            W = W - obj[i].weight;
            profitCount += obj[i].profit;
        }
        else
        {
            profitCount += double((obj[i].profit) * (W / (double)obj[i].weight));
            break;
        }
    }
    return profitCount;
}
int main()
{
    int n, W;
    cout << "Enter no of items :";
    cin >> n;
    Objects obj[n];

    cout << "Enter knapsack capacity :";
    cin >> W;

    for (int i = 0; i < n; i++)
    {
        cout << "object no " << i << ">>> name"
             << " | profit |   weight\n";
        cin >> obj[i].objeName >> obj->profit >> obj->weight;
    }
    cout << "maximum profit is :" << fractionalKnapsack(obj, W, n);
}
