class Solution {
public:
    vector<int> findOrder(
        int numCourses,
        vector<vector<int>>& prerequisites
    ) {
        // graph[u] = các course có thể học sau u
        vector<vector<int>> graph(numCourses);

        // indegree[i] = số prerequisite của course i
        vector<int> indegree(numCourses, 0);

        // Xây dựng graph
        for (auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        // Các course không có prerequisite
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        // Topological Sort
        while (!q.empty()) {
            int course = q.front();
            q.pop();

            result.push_back(course);

            // Xóa course khỏi các prerequisite
            for (int next : graph[course]) {
                indegree[next]--;

                // Đã đủ prerequisite
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // Không học được đủ tất cả course
        if (result.size() != numCourses) {
            return {};
        }

        return result;
    }
};