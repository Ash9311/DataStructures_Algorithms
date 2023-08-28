// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)^2 + (y1 - y2)^2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

class KClosest {
public:
 multimap<int,vector<int>> mp; //using multimap bcoz ,in case of same distance of 2 opints unordered map cause issues
     void distance(vector<int> input){ //duplicate keys allowed in multimap
          int d = 0;
          d = sqrt((input[0]*input[0])+(input[1]*input[1])); //euclid distance formula
          mp.insert({d,input});
     }

     vector<vector<int>> solve(vector<vector<int>> input, int k) {
          vector<vector<int>> ans;
          int n = input.size();
          for(int i = 0;i<n;i++){
               distance(input[i]);
          }
          for(auto it: mp){ //get the closest 2 points
               k--;
               ans.push_back(it.second);
               if(k==0){
                    break;
               }
          }
          return ans;
     }

};


-----------
 //https://leetcode.com/problems/k-closest-points-to-origin/
 class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
   
     priority_queue<pair<int,vector<int>>> maxheap; //de
     for(int i=0;i<points.size();i++){
          int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
          maxheap.push({dist,points[i]});
          if(maxheap.size()>k){
               maxheap.pop();
          }
     }

     vector<vector<int>> ans;
     while(maxheap.size()>0){
          ans.push_back(maxheap.top().second); //since v need second ie vector parameter of heap
          maxheap.pop();
    
     }
     return ans;
    }

};
