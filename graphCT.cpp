#include <bits/stdc++.h>

using namespace std;

static const int INF = 1e9;

vector<int> dijkstra(int src, const vector<vector<pair<int, int>>> &adjList)
{
	int n = static_cast<int>(adjList.size()) - 1;
	vector<int> dist(n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[src] = 0;
	pq.push({0, src});

	while (!pq.empty())
	{
		auto [currentDist, u] = pq.top();
		pq.pop();

		if (currentDist != dist[u])
			continue;

		for (const auto &edge : adjList[u])
		{
			int v = edge.first;
			int w = edge.second;
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

	return dist;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adjList(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adjList[u].push_back({v, w});
		adjList[v].push_back({u, w});
	}

	int bestCity = -1;
	int bestSum = INF;
	vector<int> bestDist;

	for (int city = 1; city <= n; city++)
	{
		vector<int> dist = dijkstra(city, adjList);
		int sum = 0;
		bool ok = true;

		for (int other = 1; other <= n; other++)
		{
			if (dist[other] >= INF / 2)
			{
				ok = false;
				break;
			}
			sum += dist[other];
		}

		if (!ok)
			continue;

		if (sum < bestSum || (sum == bestSum && city < bestCity))
		{
			bestSum = sum;
			bestCity = city;
			bestDist = dist;
		}
	}

	if (bestCity == -1)
	{
		cout << "IMPOSSIBLE" << '\n';
		return 0;
	}

	cout << bestCity << '\n';
	for (int city = 1; city <= n; city++)
	{
		if (city > 1)
			cout << ' ';
		cout << bestDist[city];
	}
	cout << '\n';

	return 0;
}
