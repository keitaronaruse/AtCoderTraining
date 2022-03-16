#include <bits/stdc++.h>

using ll = long long;

template <class T> using Vec = std::vector<T>;
template <class T> using Heap = std::priority_queue<T, Vec<T>, std::greater<T>>;

constexpr ll INF = std::numeric_limits<ll>::max() / 2;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll N;
    int M;
    std::cin >> N >> M;
    Vec<ll> A(M), B(M), C(M);
    Vec<ll> cmp;
    cmp.reserve(2 * M + 2);
    cmp.push_back(1);
    cmp.push_back(N);
    for (int i = 0; i < M; ++i) {
        std::cin >> A[i] >> B[i] >> C[i];
        cmp.push_back(A[i]);
        cmp.push_back(B[i]);
    }
    std::sort(cmp.begin(), cmp.end());
    cmp.erase(std::unique(cmp.begin(), cmp.end()), cmp.end());
    const int V = (int) cmp.size();
    Vec<Vec<std::pair<int, ll>>> graph(V);
    for (int i = 0; i < V - 1; ++i) {
        graph[i].emplace_back(i + 1, cmp[i + 1] - cmp[i]);
        graph[i + 1].emplace_back(i, cmp[i + 1] - cmp[i]);
    }
    for (int i = 0; i < M; ++i) {
        const int u = std::lower_bound(cmp.begin(), cmp.end(), A[i]) - cmp.begin();
        const int v = std::lower_bound(cmp.begin(), cmp.end(), B[i]) - cmp.begin();
        graph[u].emplace_back(v, C[i]);
        graph[v].emplace_back(u, C[i]);
    }
    Vec<ll> dist(V, INF);
    Heap<std::pair<ll, int>> heap;
    const auto push = [&](const int u, const ll d) {
        if (dist[u] > d) {
            dist[u] = d;
            heap.emplace(d, u);
        }  
    };
    push(0, 0);
    while (!heap.empty()) {
        const auto [d, u] = heap.top();
        heap.pop();
        if (dist[u] < d) {
            continue;
        }
        for (const auto& [v, c] : graph[u]) {
            push(v, d + c);
        }
    }
    std::cout << dist[V - 1] << '\n';
}
