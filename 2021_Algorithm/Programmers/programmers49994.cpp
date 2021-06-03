#include <string>
#include <queue>
#include <map>
#include <vector>
using namespace std;

struct Node {
public:
    int x1, y1;
    int x2, y2;

    Node(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}
    bool operator==(const Node& other) {
        if (x1 == other.x1 && y1 == other.y1 && x2 == other.x2 && y2 == other.y2) return true;
        if (x1 == other.x2 && y1 == other.y2 && x2 == other.x1 && y2 == other.y1) return true;
        return false;
    }
};

int solution(string dirs) {
    map<char, pair<int, int>> m;
    m['U'] = { -1,0 };
    m['D'] = { 1,0 };
    m['R'] = { 0,1 };
    m['L'] = { 0,-1 };
    int x = 0;
    int y = 0;
    int ans = 0;
    queue<char> q;
    vector<Node> vis;
    for (char c : dirs) q.push(c);
    while (!q.empty()) {
        int nx = x + m[q.front()].first;
        int ny = y + m[q.front()].second;
        q.pop();

        if (nx < -5 || ny < -5 || nx > 5 || ny > 5) continue;
        Node node(x, y, nx, ny);
        bool ok = true;
        for (Node n : vis) {
            if (n == node) {
                ok = false;
                break;
            }
        }
        if (ok) {
            vis.push_back(node);
            ans++;
        }
        x = nx;
        y = ny;
    }
    return ans;
}