#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

//연습문제 28: BFS 구현하기 

template<typename T>
struct Edge {
    unsigned src;
    unsigned dst;
    T weight;
};

template<typename T>
class Graph {
public:
    Graph(unsigned N) : V(N) {}

    auto vertices() const { return V; }
    auto edges() const { return edge_list; }
    auto edges(unsigned v) const {
        vector<Edge<T>> edges_from_v;
        for (auto& e : edge_list) {
            if (e.src == v)
                edges_from_v.emplace_back(e);
        }
        return edges_from_v;
    }

    void add_edge(Edge<T>&& e) {
        if (e.src >= 1 && e.src <= V && e.dst >= 1 && e.dst <= V)
            edge_list.emplace_back(e);
        else
            cerr << "에러: 유효 범위를 벗어난 정점!" << endl;
    }

    template<typename U>
    friend ostream& operator<< (ostream& os, const Graph<U>& G);

private:
    unsigned V;
    vector<Edge<T>> edge_list;    
};

template<typename U>
ostream& operator<< (ostream& os, const Graph<U>& G) {
    for (unsigned i = 1; i < G.vertices(); ++i) {
        os << i << ":\t";
        auto edges = G.edges(i);
        for (auto& e: edges)
            os << "{" << e.dst << ": " << e.weight << "}, ";
        os << endl;
    }
    return os;
}

template<typename T>
auto create_reference_graph() {
    Graph<T> G(9);

    map<unsigned, vector<pair<unsigned, T>>> edge_map;
    edge_map[1] = {{2, 0}, {5, 0}};
	edge_map[2] = {{1, 0}, {5, 0}, {4, 0}};
	edge_map[3] = {{4, 0}, {7, 0}};
	edge_map[4] = {{2, 0}, {3, 0}, {5, 0}, {6, 0}, {8, 0}};
	edge_map[5] = {{1, 0}, {2, 0}, {4, 0}, {8, 0}};
	edge_map[6] = {{4, 0}, {7, 0}, {8, 0}};
	edge_map[7] = {{3, 0}, {6, 0}};
	edge_map[8] = {{4, 0}, {5, 0}, {6, 0}};

    for (auto& i : edge_map)
        for (auto& j : i.second)
            G.add_edge(Edge<T>{ i.first, j.first, j.second });

    return G;
}

template<typename T>
auto bredth_first_search(const Graph<T>& G, unsigned start) {
    queue<unsigned> queue;
    set<unsigned> visited;
    vector<unsigned> visit_order;
    queue.push(start);

    while (!queue.empty()) {
        auto current_vertex = queue.front();
        queue.pop();

        if (visited.find(current_vertex) == visited.end()) {
            visited.insert(current_vertex);
            visit_order.push_back(current_vertex);

            for (auto& e : G.edges(current_vertex)) {
                if (visited.find(e.dst) == visited.end()) {
                    queue.push(e.dst);
                }
            }
        }
    }

    return visit_order;
}

int main() {
    using T = unsigned;

    auto G = create_reference_graph<T>();
    cout << "[입력 그래프]" << endl;
    cout << G << endl;

    cout << "[BFS 방문 순서]" << endl;
    auto bfs_visit_order = bredth_first_search(G, 1);
    for (auto v : bfs_visit_order)
        cout << v << endl;
}