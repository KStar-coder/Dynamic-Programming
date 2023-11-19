#include <bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> largestLeft(n), largestRight(n);
    stack<int> stk;

    // calculating for largestLeft
    for (int i = 0; i < n; i++)
    {
        while (!stk.empty() && heights[stk.top()] >= heights[i])
        {
            stk.pop();
        }

        if (stk.empty())
            largestLeft[i] = 0;
        else
            largestLeft[i] = (stk.top() + 1);
        stk.push(i);
    }

    // emptying the stack
    while (!stk.empty())
        stk.pop();

    // calculating for largestRight
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && heights[stk.top()] >= heights[i])
        {
            stk.pop();
        }
        if (stk.empty())
            largestRight[i] = n - 1;
        else
            largestRight[i] = stk.top() - 1;

        stk.push(i);
    }

    int maxAns = 0;
    for (int i = 0; i < n; i++)
    {
        int ans = heights[i] * (largestRight[i] - largestLeft[i] + 1);
        maxAns = max(maxAns, ans);
    }

    return maxAns;
}
