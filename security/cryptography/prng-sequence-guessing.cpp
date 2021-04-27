#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long seed = 0;

uint64_t setSeed(uint64_t seed)
{
    return (seed ^ 0x5DEECE66D)       & ((1ULL << 48) - 1);
}
uint64_t nextInt(uint64_t n, uint64_t& seed)
{
    seed = (seed * 0x5DEECE66D + 0xB) & ((1ULL << 48) - 1);
    return (seed >> 17) % n;
}

int main() {
    int n;
    cin >> n;
    
    while (n-- > 0) {
        int seq[10];
        for (int i = 0; i < 10; i++) {
            cin >> seq[i];
        }

        uint64_t guess[] = {1374037200,1374037459,1057556953,1226891312,1287968623,1282073374,1287158953,1159300833,1139155438,1074640221,1040332083,1347392806,990639200,969276712,1182050116,1265867460,1257725758,1185815629};
        for (int i = 0; i < 18; i++)
        {
            uint64_t seed = setSeed(guess[i]);
            bool ok = true;
            for (int i = 0; i < 10; i++) {
                if (nextInt(1000, seed) != seq[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                for (int i = 0; i < 10; i++) {
                    cout << nextInt(1000, seed) << " ";
                }
                cout << endl;
                break;
            }
        }        
    }
    
    return 0;
}

