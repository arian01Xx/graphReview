#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> courses;
        if(n<=0) return {};

        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<n; i++){
            inDegree[i]=0;
            graph[i]={};
        }

        for(int i=0; i<prerequisites.size(); i++){
            int parent=prerequisites[i][1], child=prerequisites[i][0];
            graph[parent].push_back(child);
            inDegree[child]=inDegree[child]+1;
        }

        queue<int> sources;
        for(auto itr=inDegree.begin(); itr!=inDegree.end(); itr++){
            if(itr->second==0) sources.push(itr->first);
        }

        while(!sources.empty()){
            int vertex=sources.front();
            sources.pop();
            courses.push_back(vertex);
            vector<int> children=graph[vertex];
            for(int child: children){
                inDegree[child]=inDegree[child]-1;
                if(inDegree[child]=0) sources.push(child);
            }
        }
        if(courses.size()!=n) courses.clear();
        return courses;
    }
};

int main(){
    return 0;
}