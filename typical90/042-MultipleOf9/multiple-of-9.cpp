/*
    042 - Multiple of 9（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_ap
        Author: Keitaro Naruse
        Date:   2022-01-11
        MIT License
*/

// # Solution
// - K = (d1,d2,...), d1+d2+...= 9k
// - 9: 
//   - (1,8), (2,7), (3,6), (4,5) 
//   - (1,1,7), (1,2,6), (1,3,5), (1,4,4), (2,2,5), (2,3,4), (3,3,3)
//   - (1,1,1,6), (1,1,2,5), (1,1,3,4), (1,2,2,4), (1,2,3,3),
//   - (1,1,1,1,5), (1,1,1,2,4), (1,1,1,3,3)
//   - (1,1,1,1,1,4), (1,1,1,1,2,3), 
//   - (1,1,1,1,1,1,3), (1,1,1,1,1,2,2)
//   - (1,1,1,1,1,1,1,2)
//   - (1,1,1,1,1,1,1,1,1)
// - 18: (9,9)
// - 27: 

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const long long Large_Prime = 1000000007LL;
const bool Debug = true;

int main()
{
    //  Read K
    int K = 0;
    std::cin >> K;
    if( Debug ) {
        std::cerr << K << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
