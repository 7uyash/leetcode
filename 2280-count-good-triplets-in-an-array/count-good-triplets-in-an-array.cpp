#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define endl '\n'
void update(vector<int>& BIT, int idx, int val, int n) {
    for (++idx; idx <= n; idx += idx & -idx) {
        BIT[idx] += val;
    }
}

int query(vector<int>& BIT, int idx) {
    int sum = 0;
    for (++idx; idx > 0; idx -= idx & -idx) {
        sum += BIT[idx];
    }
    return sum;
}class Solution {
public:
    ll goodTriplets(vi& nums1, vi& nums2) {
        int n = nums1.size();
        vi pos2(n), nums1Mapped(n);
        for (int i = 0; i < n; ++i) pos2[nums2[i]] = i;
        for (int i = 0; i < n; ++i) nums1Mapped[i] = pos2[nums1[i]];

        vi BIT(n + 1, 0);
        vll left(n, 0), right(n, 0);

        for (int i = 0; i < n; ++i) {
            left[i] = query(BIT, nums1Mapped[i] - 1);
            update(BIT, nums1Mapped[i], 1, n);
        }

        fill(BIT.begin(), BIT.end(), 0);

        for (int i = n - 1; i >= 0; --i) {
            right[i] = query(BIT, n - 1) - query(BIT, nums1Mapped[i]);
            update(BIT, nums1Mapped[i], 1, n);
        }

        ll result = 0;
        for (int i = 0; i < n; ++i) result += left[i] * right[i];
        return result;
    }
};
void solve() {
    vi arr1, arr2;
    int x;
    while (cin >> x) {
        arr1.push_back(x);
        if (cin.peek() == '\n') break;
    }
    while (cin >> x) {
        arr2.push_back(x);
        if (cin.peek() == '\n') break;
    }
    Solution solution;
    cout << solution.goodTriplets(arr1, arr2) << endl;
}