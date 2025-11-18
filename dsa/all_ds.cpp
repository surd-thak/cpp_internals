#include <bits/stdc++.h>
using namespace std;

// ---------------- Sliding Window ----------------
class slidingWindow {
private:
    vector<int> arr;
    int n;
    int left = 0, right = 0;

public:
    slidingWindow(vector<int>& arr_) : arr(arr_), n(arr_.size()), left(0), right(0) {}

    int fixed_size(int k) {
        int ans = 0;
        while (right < n) {
            if (right - left + 1 < k) {
                right++;
                continue;
            }
            // calculate ans for this window
            left++;
            right++;
        }
        return ans;
    }

    int var_size() {
        int ans = 0;
        while (right < n) {
            while (true) { // replace true with your condition
                // calculate ans for this window
                right++;
            }
            left++;
        }
        return ans;
    }
};

// ---------------- Two Pointers ----------------
class twoPointers {
private:
    vector<int> arr;
    int n, left, right;

public:
    twoPointers(vector<int>& arr_) : arr(arr_), n(arr_.size()), left(0), right(n) {}

    int algo() {
        int ans = -1;
        while (left <= right) {
            // calculate ans
            if (true) { // replace true with condition
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};

// ---------------- String Algorithms ----------------
class stringAlgo {
private:
    string hay, needle;

public:
    // Rabin-Karp
    // KMP
    // Z Algorithm
    // Manacher's Algorithm
    // Usage examples
};

// ---------------- Stack & Queue ----------------
class stackAlgo {};
class queueAlgo {};

// ---------------- Linked List ----------------
class linkedList {
    // Reversal / iteration / recursion
    // Cycle detection / pointers
    // Merging / sorting logic
    // Two-pointer / single-pass techniques
    // Hashing / complex pointer structures
};

// ---------------- Trees ----------------
class tree {
    // Iterative DFS, BFS
    // Postorder, Preorder, Inorder
    // LCA
    // Binary lifting
    // Euler tour
};

class binaryTree {
    // Mirror / Invert binary tree
    // Convert binary tree to doubly linked list (inorder)
    // Flatten binary tree to linked list (preorder)
    // Construct tree from traversals (Inorder + Preorder / Postorder)
    // Zigzag (spiral order) traversal
    // Boundary traversal
    // Vertical order traversal
    // Top/Bottom/Left/Right view of tree
};

// ---------------- Segment Tree ----------------
class segmentTree {
    // Normal segment tree
    // Lazy segment tree
};

// ---------------- Trie ----------------
class Trie {
private:
    // Define Trie nodes and methods
};

// ---------------- Coordinate Compression ----------------
class coordinateCompression {};

// ---------------- Maths ----------------
class maths {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }

    long long modExp(long long a, long long x, long long mod) {
        long long res = 1;
        a %= mod;
        while (x > 0) {
            if (x & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            x >>= 1;
        }
        return res;
    }

    long long modInv(long long a, long long p, long long mod, vector<int>& prime) {
        if (!prime[p]) return -1;
        return modExp(a, p - 2, mod);
    }

    void isPrimePrecompute(int maxn, vector<int>& isPrime) {
        isPrime.assign(maxn + 1, 1);
        isPrime[0] = 0; isPrime[1] = 0;
        for (int i = 2; i * i <= maxn; i++) {
            if (isPrime[i] != 1) continue;
            for (int j = i * i; j <= maxn; j += i)
                isPrime[j] = 0;
        }
    }

    void isPrimePrecomputeSPF(int maxn, vector<int>& spf) {
        spf.assign(maxn + 1, 0);
        iota(spf.begin(), spf.end(), 0);
        spf[0] = 0; spf[1] = 1;
        for (int i = 2; i * i <= maxn; i++) {
            if (spf[i] != i) continue;
            for (int j = i * i; j <= maxn; j += i) {
                if (spf[j] != j) spf[j] = i;
            }
        }
    }
    // prime factors
    // combinatorics
};

// ---------------- Heap ----------------
class heap {
    // Kth Largest/Smallest Element
    // Merge K Sorted Lists/Arrays
    // Top K Frequent Elements/Words
    // Find Median from Data Stream
    // Reorganize String / Task Scheduler
};

// ---------------- Miscellaneous ----------------
class miscellaneous {
    // Backtracking template (permutations, subsets, N-Queens)
    // Bitmask tricks (subset enumeration)
    // Meet-in-the-middle
    // Custom comparator for sorting pairs
    // Custom Hashing for unordered containers
};

// ---------------- Dynamic Programming ----------------
class dp {
    // LIS, LCS, Edit Distance
    // 0/1 Knapsack, Coin Change
    // Unique Paths, Minimum Path Sum
    // House Robber variants
    // Decode Ways, Word Break
    // Palindromic substrings / subsequences
    // Burst Balloons, Matrix Chain Multiplication
    // Digit DP, Bitmask DP
};

// ---------------- Graphs ----------------
class graph {
    // BFS / DFS, Cycle detection
    // Topological sort
    // Dijkstra, Bellman-Ford, Floyd-Warshall
    // Union-Find / DSU
    // Kruskal’s MST
    // Tarjan’s bridges/articulation points
    // Bipartite check
    // Connected components
    // Kosaraju / Tarjan SCC
};

// ---------------- Binary Search ----------------
class BinarySearch {
    // Rotated sorted arrays
    // 2D rotated binary search
};

// ---------------- BST ----------------
class BST {
    // BST iterator
    // BST from Preorder
    // BST to linked list
};
