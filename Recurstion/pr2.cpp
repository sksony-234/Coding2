// Problem statement: Print the number of subsequences having sum equal to k.

#include <bits/stdc++.h>
using namespace std;

int numberOfSubSeqSumK(int arr[], vector<int> &v, int sum, int i, int n)
{
    if (i == n)
        return sum == 0 ? 1 : 0;

    v.push_back(arr[i]);
    sum -= arr[i];
    int l = numberOfSubSeqSumK(arr, v, sum, i + 1, n);
    v.pop_back();
    sum += arr[i];

    int r = numberOfSubSeqSumK(arr, v, sum, i + 1, n);

    return l + r;
}

void subSeqSumK(int arr[], int k, int n)
{
    vector<int> v;
    int res = numberOfSubSeqSumK(arr, v, k, 0, n);
    cout << res << endl;
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