// User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here

//brute force

      
//         vector<int> leaves_ar;
//         for(int i=1;i<=leaves;i++){
//             leaves_ar.push_back(i);
//         }
//         for(int i=0;i<N;i++)
//         {
          
//           for(int j=0;j<leaves_ar.size();j++)
//         {
//           if(leaves_ar[j]==-1){
//               continue;
//           }
//           else if(leaves_ar[j]%frogs[i]==0){
//               leaves_ar[j]=-1;
//           }
          
          
//                   }
//                   }
//                   int count=0;
//                   for(int i=0;i<leaves_ar.size();i++)
//         {
//           if(leaves_ar[i]!=-1)
//           count++;
//                   }
                  
//             if(count)
//             return count;
//             else  
//             return 0;
       
//     }
   
// };



      // n* log n



     // Boolean array to mark visited leaves
        vector<bool> leaves_vis(leaves + 1, false);

        // Sort frogs to process smaller jumps first (like sieve of Eratosthenes)
        sort(frogs, frogs + N);

        // Process each frog
        for(int i = 0; i < N; i++) {
            int jump = frogs[i];

            // Special case: if frog has jump = 1,
            // it can visit ALL leaves -> answer is 0
            if (jump == 1)
                return 0;

            // If this jump has already been covered by a smaller frog,
            // skip redundant work
            if (leaves_vis[jump])
                continue;

            // Mark this frog's jump as "covered"
            leaves_vis[jump] = true;

            // Ignore invalid cases where frog can't jump on any leaf
            if (jump <= 0 || jump > leaves)
                continue;

            // Mark all multiples of this jump as visited
            for (int j = jump; j <= leaves; j += jump) {
                leaves_vis[j] = true;
            }
        }

        // Count how many leaves are still unvisited
        int count = 0;
        for (int i = 1; i < leaves_vis.size(); i++) {
            if (!leaves_vis[i])
                count++;
        }

        return count; // final answer
    }



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
