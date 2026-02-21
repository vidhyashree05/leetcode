class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Step 1: Create graph and indegree array
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            
            graph[prereq].push_back(course);
            indegree[course]++;
        }
        
        // Step 2: Push all nodes with indegree 0 into queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        int count = 0;
        
        // Step 3: BFS
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;
            
            for (int neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        // Step 4: Check if all courses processed
        return count == numCourses;
    }
};