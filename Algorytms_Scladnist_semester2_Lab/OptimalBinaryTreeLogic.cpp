#include "OptimalBinaryTreeLogic.h"



// A utility function to get sum of vector elements
// freq[i] to freq[j]


/* A Dynamic Programming based function that calculates
minimum cost of a Binary Search Tree and returns the sorted
vector of keys. */




int OptimalBinaryTreeLogic::sum(vector<int> freq, int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

vector<int> OptimalBinaryTreeLogic::optimalSearchTree(vector<int> keys, vector<int> freq)
{
    int n = keys.size();

    /* Create auxiliary 2D vectors to store results
    of subproblems */
    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> root(n, vector<int>(n));

    /* cost[i][j] = Optimal cost of binary search tree
    that can be formed from keys[i] to keys[j].
    root[i][j] = Root of the optimal binary search tree
    that can be formed from keys[i] to keys[j]. */

    // For a single key, cost is equal to frequency of the key
    for (int i = 0; i < n; i++)
    {
        cost[i][i] = freq[i];
        root[i][i] = i;
    }

    // Now we need to consider chains of length 2, 3, ... .
    // L is chain length.
    for (int L = 2; L <= n; L++)
    {
        // i is row number in cost[][]
        for (int i = 0; i <= n - L; i++)
        {
            // Get column number j from row number i and
            // chain length L
            int j = i + L - 1;
            cost[i][j] = INT_MAX;
            int off_set_sum = sum(freq, i, j);

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++)
            {
                // c = cost when keys[r] becomes root of this subtree
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                    ((r < j) ? cost[r + 1][j] : 0) +
                    off_set_sum;
                if (c < cost[i][j])
                {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    // Reconstruct the optimal binary search tree using root[][]
    vector<int> sortedKeys;
    stack<pair<int, int>> st;
    st.push({ 0, n - 1 });
    while (!st.empty())
    {
        int i = st.top().first;
        int j = st.top().second;
        st.pop();
        if (i <= j)
        {
            sortedKeys.push_back(keys[root[i][j]]);
            if (root[i][j] - 1 >= i)
                st.push({ i, root[i][j] - 1 });
            if (root[i][j] + 1 <= j)
                st.push({ root[i][j] + 1, j });
        }
    }
    return sortedKeys;
}
