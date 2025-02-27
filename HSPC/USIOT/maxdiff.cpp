#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long maxSumOfSubarrayValues(int N, vector<int>& A) {
    vector<int> left(N, -1), right(N, N);
    stack<int> s;

    // Compute left boundaries for max contributions
    for (int i = 0; i < N; i++) {
        while (!s.empty() && A[s.top()] < A[i]) s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty()) s.pop(); // Clear stack

    // Compute right boundaries for max contributions
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && A[s.top()] <= A[i]) s.pop();
        right[i] = s.empty() ? N : s.top();
        s.push(i);
    }

    // Calculate max contributions
    vector<long long> maxContribution(N, 0);
    for (int i = 0; i < N; i++) {
        maxContribution[i] = (long long)A[i] * (i - left[i]) * (right[i] - i);
    }

    // Compute min contributions by negating A
    for (int& x : A) x = -x;
    fill(left.begin(), left.end(), -1);
    fill(right.begin(), right.end(), N);
    while (!s.empty()) s.pop(); // Clear stack

    // Compute left boundaries for min contributions
    for (int i = 0; i < N; i++) {
        while (!s.empty() && A[s.top()] < A[i]) s.pop();
        left[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    while (!s.empty()) s.pop(); // Clear stack

    // Compute right boundaries for min contributions
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && A[s.top()] <= A[i]) s.pop();
        right[i] = s.empty() ? N : s.top();
        s.push(i);
    }

    // Calculate min contributions
    vector<long long> minContribution(N, 0);
    for (int i = 0; i < N; i++) {
        minContribution[i] = (long long)(-A[i]) * (i - left[i]) * (right[i] - i);
    }

    // Compute the final result
    long long result = 0;
    for (int i = 0; i < N; i++) {
        result += maxContribution[i] - minContribution[i];
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<long long> results;

    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        results.push_back(maxSumOfSubarrayValues(N, A));
    }

    for (long long res : results) {
        cout << res << "\n";
    }

    return 0;
}
