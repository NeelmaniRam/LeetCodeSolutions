#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> prices(N);

        for (int i = 0; i < N; ++i) {
            cin >> prices[i];
        }

        int targetAge=20;
        //cin >> targetAge;

        unordered_set<int> seenPrices;

        bool accepted = false;

        for (int i = 0; i < N; ++i) {
            int complement = targetAge * 100 - prices[i];

            if (seenPrices.count(complement) > 0) {
                accepted = true;
                break;
            }

            seenPrices.insert(prices[i]);
        }

        cout << (accepted ? "Accepted" : "Rejected") << endl;
    }

    return 0;
}
