#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 10001;

unordered_map<string, int> air_to_num;
unordered_map<int, string> num_to_air;

int in_degree[MAX]{0,}, out_degree[MAX]{0};
int graph[MAX][MAX]{0,};
unordered_map<int, multiset<string>*> raw_graph;


int order = 0;

void euler_cycle(vector<string>& answer, int u)
{
    for(auto str : *raw_graph[u]){
        int v = air_to_num[str];
        while(graph[u][v]){
            graph[u][v]--;
            used_path++;
            euler_cycle(answer, v);
        }
    }
    answer.push_back(num_to_air[u]);
}

void get_euler_cycle(vector<string>& answer, int u)
{
    euler_cycle(answer, u);
    reverse(answer.begin(), answer.end());
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    total_path = tickets.size();

    for(auto v : tickets){
        if(air_to_num.find(v[0]) == air_to_num.end()) {
            air_to_num.insert(make_pair(v[0], order));
            num_to_air.insert(make_pair(order, v[0]));
            ++order;
            raw_graph.insert(make_pair(air_to_num[v[0]], new multiset<string>{}));
        }
        if(air_to_num.find(v[1]) == air_to_num.end()){
            air_to_num.insert(make_pair(v[1], order));
            num_to_air.insert(make_pair(order, v[1]));
            ++order;
            raw_graph.insert(make_pair(air_to_num[v[1]], new multiset<string>{}));
        }
        out_degree[air_to_num[v[0]]]++;
        in_degree[air_to_num[v[1]]]++;
        raw_graph[air_to_num[v[0]]]->insert(v[1]);
    }

    for(int i=0; i<order; ++i){
        if(in_degree[i] < out_degree[i]){
            fake_edge.second = i;
        }
        else if(in_degree[i] > out_degree[i]){
            fake_edge.first = i;
        }
    }

    for(auto node : raw_graph){
        int u = node.first;
        for(auto child : *node.second){
            graph[u][air_to_num[child]]++;
        }
    }

    get_euler_cycle(answer, air_to_num["ICN"]);


    return answer;
}
