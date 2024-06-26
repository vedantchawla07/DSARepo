class Solution {
public:
    vector<int> nextSmallerElementOnRight(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nsr;
    }
    vector<int> nextSmallerElementOnLeft(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nsl;
    }
    int largestRectangleArea(vector<int>& heights) {
        //nextSmallerElementOnRight
        //nextSmallerElementOnLeft
        //finalArray --> (NSR - NSL - 1) * height.

        int n = heights.size();
        int ans = 0;
        vector<int> nsr(n);
        vector<int> nsl(n);
        nsr = nextSmallerElementOnRight(heights);
        nsl = nextSmallerElementOnLeft(heights);
        for (int i = 0; i < n; i++) {
            int currValue = (nsr[i] - nsl[i] - 1) * heights[i];
            ans = max(currValue, ans);
        }
        return ans;
    }
};