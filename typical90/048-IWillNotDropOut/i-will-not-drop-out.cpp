/*
    048 - I will not drop out（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_av
        Author: Keitaro Naruse
        Date:   2021-12-15
        MIT License
*/

// # Solution
// - Read Ai and Bi, calculate Ci = Ai - Bi
// - Constraints: Ci can be taken after Bi is done
// - Put Bi and Ci to S and sort S in the descending order
// - Pick the first K numbers from S, which satisfies the problem constraints 
//   because Bi > Ci always
// - Proof: Bi > Ai/2 => 2Bi > Ai => Bi > Ai - Bi => Bi > Ci

#include <iostream>
#include <vector>
#include <algorithm>

bool is_larger( int a, int b )
{
    return( a > b );
}

int main()
{
    //  Read N and K
    int N = 0, K = 0; 
    std::cin >> N >> K;
    // std::cerr << N << " " << K << std::endl;

    //  Read Ai and Bi, and make Ci
    std::vector< int > s( 2 * N, 0 );
    for( int i = 0; i < N; i ++ ) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        s.at( 2 * i ) = b; 
        s.at( 2 * i + 1) = a - b;
    }
    std::sort( s.begin(), s.end(),  is_larger ); 

    //  Main
    long long sum = 0LL;
    for( int i = 0; i < K; i ++ ) {
        sum += ( long long ) s.at( i );
    }

    //  Output results
    std::cout << sum << std::endl;
    
    //  Finalize
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
