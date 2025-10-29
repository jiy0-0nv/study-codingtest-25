#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    int S = 0;

    for (int i = 0; i < M; i++) {
        string op;
        cin >> op;

        int x;

        if (op == "add") {
            cin >> x;
            S = S | (1 << (x - 1));
        }
        else if (op == "remove") {
            cin >> x;
            S = S & ~(1 << (x - 1));
        }
        else if (op == "check") {
            cin >> x;
            if (S & (1 << (x - 1))) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        else if (op == "toggle") {
            cin >> x;
            S = S ^ (1 << (x - 1));
        }
        else if (op == "all") {
            S = (1 << 20) - 1;
        }
        else if (op == "empty") {
            S = 0;
        }
    }
    return 0;
}
