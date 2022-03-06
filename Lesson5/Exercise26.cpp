#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

// 연습문제 26: 크루스칼 MST 알고리즘: Minimum Spanning Tree 

class SimpleDisjointSet {
private:
    struct Node {
        unsigned id;
        unsigned rank;
        unsigned parent;

        Node(unsigned _id): id(_id), rank(0), parent(_id) {}

        bool operator != (const Node& n) const {
            return this->id != n.id;
        }
    };

    vector<Node> nodes;

public:
    SimpleDisjointSet(unsigned N) {
        nodes.reserve(N);
    }    

    void make_set(const unsigned& x) {
        nodes.emplace_back(x);
    }

    unsigned find(unsigned x) {
        auto node_it = find_if(nodes.begin(), nodes.end(), 
            [x](auto n) { return n.id == x; });
        unsigned node_id = (*node_it).id;

        while(node_id != nodes[node_id].parent) {
            node_id = nodes[node_id].parent;
        }

        return node_id;
    }

    void union_sets(unsigned x, unsigned y) {
        auto root_x = find(x);
        auto root_y = find(y);

        if (root_x == root_y)
            return;
        
        if (nodes[root_x].rank > nodes[root_y].rank)
            swap(root_x, root_y);

        nodes[root_x].parent = nodes[root_y].parent;
        nodes[root_y].rank++;
    }
};

template<typename T>
struct Edge {
    unsigned src;
    unsigned dst;
    T weight;

    inline bool operator> (const Edge<T>& e) const {
        return this->weight > e.weight;
    }
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
Graph<T> minimum_spanning_tree(const Graph<T>& G) {
    priority_queue<Edge<T>, vector<Edge<T>>, greater<Edge<T>>> edge_min_heap;

    for (auto& e: G.edges())
        edge_min_heap.push(e);

    auto N = G.vertices();
    SimpleDisjointSet dset(N);
    for (unsigned i=0; i < N; ++i)
        dset.make_set(i);

    Graph<T> MST(N);
    while (!edge_min_heap.empty()) {
        auto e = edge_min_heap.top();
        edge_min_heap.pop();
        if (dset.find(e.src) != dset.find(e.dst)) {
            MST.add_edge(Edge<T>{ e.src, e.dst, e.weight});
            dset.union_sets(e.src, e.dst);
        }
    }

    return MST;
}

int main() {
    using T = unsigned;

    Graph<T> G(9);

    map<unsigned, vector<pair<unsigned, T>>> edge_map;
	edge_map[1] = {{2, 2}, {5, 3}};
	edge_map[2] = {{1, 2}, {5, 5}, {4, 1}};
	edge_map[3] = {{4, 2}, {7, 3}};
	edge_map[4] = {{2, 1}, {3, 2}, {5, 2}, {6, 4}, {8, 5}};
	edge_map[5] = {{1, 3}, {2, 5}, {4, 2}, {8, 3}};
	edge_map[6] = {{4, 4}, {7, 4}, {8, 1}};
	edge_map[7] = {{3, 3}, {6, 4}};
	edge_map[8] = {{4, 5}, {5, 3}, {6, 1}};

    for (auto& i: edge_map)
        for (auto& j : i.second)
            G.add_edge(Edge<T> { i.first, j.first, j.second });

    cout << "[입력 그래프]" << endl;
    cout << G << endl;

    Graph<T> MST = minimum_spanning_tree(G);
    cout << "[최소 신장 트리]" << endl;
    cout << MST;   
}