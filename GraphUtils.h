#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include <vector>
#include <queue>

namespace GraphUtils {

using Graph = std::vector<std::vector<int>>;

// 廣度優先搜索 (BFS)
std::vector<int> bfs(const Graph& graph, int start) {
    std::vector<int> visited(graph.size(), false);
    std::vector<int> result;
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        result.push_back(node);

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return result;
}

// 深度優先搜索 (DFS)
void dfs_util(const Graph& graph, int node, std::vector<bool>& visited, std::vector<int>& result) {
    visited[node] = true;
    result.push_back(node);
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs_util(graph, neighbor, visited, result);
        }
    }
}

std::vector<int> dfs(const Graph& graph, int start) {
    std::vector<bool> visited(graph.size(), false);
    std::vector<int> result;
    dfs_util(graph, start, visited, result);
    return result;
}

} // namespace GraphUtils

#endif // GRAPH_UTILS_H