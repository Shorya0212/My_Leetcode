class Solution {
public:
    vector<int> topoSort(unordered_map<int, vector<int>>& graph,
                         vector<int>& indegree,
                         int nodes) {

        queue<int> q;

        for (int i = 0; i < nodes; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            result.push_back(curr);

            for (int next : graph[curr]) {
                indegree[next]--;

                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (result.size() != nodes) {
            return {};
        }

        return result;
    }

    vector<int> sortItems(int n, int m, vector<int>& group,
                           vector<vector<int>>& beforeItems) {

        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }

        unordered_map<int, vector<int>> itemgraph;
        vector<int> itemINdegree(n, 0);

        for (int i = 0; i < n; i++) {
            itemgraph[i] = vector<int>();
        }

        unordered_map<int, vector<int>> groupgraph;
        vector<int> groupINdegree(m, 0);

        for (int i = 0; i < m; i++) {
            groupgraph[i] = vector<int>();
        }

        set<pair<int, int>> groupEdges;

        for (int i = 0; i < n; i++) {
            for (int prev : beforeItems[i]) {

                itemgraph[prev].push_back(i);
                itemINdegree[i]++;

                if (group[i] != group[prev]) {
                    int prevItemGroup = group[prev];
                    int currItemGroup = group[i];

                    if (groupEdges.find({prevItemGroup, currItemGroup}) ==
                        groupEdges.end()) {

                        groupEdges.insert(
                            {prevItemGroup, currItemGroup}
                        );

                        groupgraph[prevItemGroup].push_back(
                            currItemGroup
                        );

                        groupINdegree[currItemGroup]++;
                    }
                }
            }
        }

        vector<int> itemOrder =
            topoSort(itemgraph, itemINdegree, n);

        if (itemOrder.empty()) {
            return {};
        }

        vector<int> groupOrder =
            topoSort(groupgraph, groupINdegree, m);

        if (groupOrder.empty()) {
            return {};
        }

        unordered_map<int, vector<int>> itemsInGroup;

        for (int item : itemOrder) {
            itemsInGroup[group[item]].push_back(item);
        }

        vector<int> answer;

        for (int grp : groupOrder) {
            for (int item : itemsInGroup[grp]) {
                answer.push_back(item);
            }
        }

        return answer;
    }
};