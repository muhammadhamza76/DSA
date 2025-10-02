// User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int> leaves_ar;
        for(int i=1;i<=leaves;i++){
            leaves_ar.push_back(i);
        }
        for(int i=0;i<N;i++)
        {
          
          for(int j=0;j<leaves_ar.size();j++)
        {
          if(leaves_ar[j]==-1){
              continue;
          }
          else if(leaves_ar[j]%frogs[i]==0){
              leaves_ar[j]=-1;
          }
          
          
                  }
                  }
                  int count=0;
                  for(int i=0;i<leaves_ar.size();i++)
        {
          if(leaves_ar[i]!=-1)
          count++;
                  }
                  
            if(count)
            return count;
            else  
            return 0;
       
    }
   
};
// Frogs and Jumps
// Difficulty: EasyAccuracy: 49.69%Submissions: 63K+Points: 2
// N frogs are positioned at one end of the pond. All frogs want to reach the other end of the pond as soon as possible. The pond has some leaves arranged in a straight line. Each frog has the strength to jump exactly K leaves. For example, a  frog having strength 2 will visit the leaves 2, 4, 6, ...  etc. while crossing the pond.

// Given the strength of each frog and the number of leaves, your task is to find the number of leaves that not be visited by any of the frogs when all frogs have reached the other end of the pond. 

// Example 1:

// Input:
// N = 3
// leaves = 4
// frogs[] = {3, 2, 4} 
// Output: 1
// Explanation:
// Leaf 1 will not be visited by any frog.
// Example 2:

// Input: 
// N = 3
// leaves = 6
// frogs[] = {1, 3, 5} 
// Output: 0
// Explanation: 
// First frog will visit all the leaves so no 
// leaf is left unvisited.
// Your Task:
// Complete the function unvisitedLeaves() which takes the integers N, leaves and the array frogs as the input parameters, and returns the number of unvisited leaves.

// Expected Time Complexity: O(N*log(leaves))
// Expected Auxiliary Space: O(leaves)
