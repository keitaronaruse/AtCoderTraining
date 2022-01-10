/*
    ABC230 Problem C - X drawing
        https://atcoder.jp/contests/abc230/tasks/abc230_c
        Author: Keitaro Naruse
        Date:   2021-12-03, 2022-01-09
        MIT License
*/

// # Solution
// - First line
//   - Plot( A + k, B + k )
//   - max( P - A, R - B ) <= k <= min( Q - A, S - B )
// - Second line
//   - Plot( A + k, B - k )
//   - max( P - A, R - S ) <= <= min( Q - A, B - R )

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N, A, B
    long long N, A, B;
    std::cin >> N >> A >> B;
    //  Read P Q R S
    long long P, Q, R, S;
    std::cin >> P >> Q >> R >> S;

    //  Main
    std::vector< std::vector< char > > cells( Q - P + 1LL, std::vector< char >( S - R + 1LL, '.' ) );

    //  First line
    long long k_min = std::max( P - A, R - B );
    long long k_max = std::min( Q - A, S - B );
    
    //  Plot
    for(long long k = k_min; k <= k_max; k ++ ) {
        cells.at( A - P + k ).at( B - R + k ) = '#';
    }

    //  Second line
    k_min = std::max( P - A, B - S );
    k_max = std::min( Q - A, B - R );
    //  Plot
    for(long long k = k_min; k <= k_max; k ++ ) {
        cells.at( A - P + k ).at( B - R - k ) = '#';
    }

    //  Display result
    for( long long i = 0L ; i <= Q - P ; i ++ ) {
        for( long long j = 0L ; j <= S - R ; j ++ ) {
            std::cout << cells.at( i ).at( j );
        }
        std::cout << std::endl;
    }

    //  Finalize
    return( 0 );
}
