// Problem Statement: Given an integer array, print all/onlyone the subsequences having sum equals to k(a given integer).

#include <bits/stdc++.h>
using namespace std;

void printAllSubSumK(int arr[], vector<int> &v, int sum, int i, int n)
{
    if (i == n)
    {
        if (sum == 0)
        {
            for (auto el : v)
                cout << el << " ";
            cout << endl;
        }
        return;
    }

    v.push_back(arr[i]);
    sum -= arr[i];
    printAllSubSumK(arr, v, sum, i + 1, n);
    v.pop_back();
    sum += arr[i];

    printAllSubSumK(arr, v, sum, i + 1, n);
}

bool printOneSubSumK(int arr[], vector<int> &v, int sum, int i, int n)
{
    if (i == n)
    {
        if (sum == 0)
        {
            for (auto el : v)
                cout << el << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    v.push_back(arr[i]);
    sum -= arr[i];
    if (printOneSubSumK(arr, v, sum, i + 1, n) == true)
        return true;
    v.pop_back();
    sum += arr[i];

    if (printOneSubSumK(arr, v, sum, i + 1, n) == true)
        return true;

    return false;
}

void subSeqSumK(int arr[], int k, int n)
{
    vector<int> v;
    printAllSubSumK(arr, v, k, 0, n);

    // printOneSubSumK(arr, v, k, 0, n);
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    subSeqSumK(arr, k, n);
    return 0;
}
