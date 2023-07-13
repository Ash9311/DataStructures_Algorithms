//https://leetcode.com/problems/maximum-of-absolute-value-expression/description/
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
            int n = arr1.size();
    int maxX1 = INT_MIN;
    int minY1 = INT_MAX;
    int maxX2 = INT_MIN;
    int minY2 = INT_MAX;
    int maxX3 = INT_MIN;
    int minY3 = INT_MAX;
    int maxX4 = INT_MIN;
    int minY4 = INT_MAX;
    //divide into cases so that we can ignore modulo sign. group i,j together
    //arr1[i] - arr1[j] + arr2[i] - arr2[j] + i - j
    //(arr1[i]+i+arr2[i])-(arr1[j]+j+arr2[j])
    //increase 1st eqn and decrease 2nd eqn and track max for all cases 
    for (int i = 0; i < n; i++) {
        maxX1 = max(maxX1, arr1[i] + arr2[i] + i);
        minY1 = min(minY1, arr1[i] + arr2[i] + i);

        maxX2 = max(maxX2, arr1[i] - arr2[i] + i);
        minY2 = min(minY2, arr1[i] - arr2[i] + i);

        maxX3 = max(maxX3, arr1[i] - arr2[i] - i);
        minY3 = min(minY3, arr1[i] - arr2[i] - i);

        maxX4 = max(maxX4, arr1[i] + arr2[i] - i);
        minY4 = min(minY4, arr1[i] + arr2[i] - i);
    }

    return max(max(maxX1 - minY1, maxX2 - minY2), max(maxX3 - minY3, maxX4 - minY4));
    }
};
