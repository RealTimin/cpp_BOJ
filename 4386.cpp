#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INIT_MAX 10000
using namespace std;
double getDistance(pair<double, double> &p1, pair<double, double> &p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main()
{
    int n;
    cin >> n;
    vector<pair<double, double>> position;
    vector<bool> visited(n, false);
    vector<double> distance(n, INIT_MAX);
    int min_dist;
    int min_i;
    double x, y;
    double temp_dist;
    double cost;
    distance[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        position.push_back(make_pair(x, y));
    }

    for (int k = 0; k < n; k++)
    {
        min_dist = INIT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && distance[i] < min_dist)
            {
                min_dist = distance[i];
                min_i = i;
            }
        }
        visited[min_i] = true;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                temp_dist = getDistance(position[i], position[min_i]);
                if (temp_dist < distance[i])
                    distance[i] = temp_dist;
            }
        }
    }

    cost = 0;
    for (int i = 0; i < n; i++)
    {
        cost += distance[i];
    }

    cout << cost;
    return 0;
}