/*
    ABC230 Problem C
    C - X drawing
        https://atcoder.jp/contests/abc230/tasks/abc230_c
        Author: Keitaro Naruse
        Date:   2021-12-03, 2021-12-04
        MIT License
*/

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
    int H = ( int )( Q - P + 1 );
    int W = ( int )( S - R + 1 );
    std::vector< std::vector< char > > cells( H, std::vector< char >( W, '.' ) );

    //  First line
    //  Determine the minimun end
    //  max(1−A, 1−B ) <= k
    long long K_min_prob = std::max( 1LL - A, 1LL - B );
    //  P <= A+k, R <= B+k
    long long K_min_cell = std::max( P - A, R - B );
    //  Integrate
    long long K_min = K_min_cell;
    
    //  Determine the maximum end
    //  min(N−A,N−B)
    long long K_max_prob = std::min( N - A + 1LL, N - B + 1LL );
    //  A+k < Q + 1, B+k < S + 1
    long long K_max_cell = std::min( Q - A + 1LL, S - B + 1LL );
    //  Integrate
    long long K_max = K_max_prob;

    //  Plot
    int apk = ( int )( A - P + K_min );
    int brk = ( int )( B - R + K_min );
    int k_max = ( int )( K_max - K_min );
    for(int k = 0; k != k_max; k ++ ) {
        if( ( 0 <= apk + k ) && ( apk + k < H ) && ( 0 <= brk + k ) && ( brk + k < W ) )    {
            cells.at( apk + k ).at( brk + k ) = '#';
        }
    }

    //  Second line
    //  Determine the minimun end
    //  max(1−A, B-N ) <= k
    K_min_prob = std::max( 1 - A, B - N );
    //  P <= A+k, R <= B-k
    //  P - A <= k < B - R + 1
    K_min_cell = P - A;
    K_max_cell = B - R + 1LL;

    //  Determine the maximum end
    //  min(N−A,B−1)
    K_max_prob = std::min( N - A + 1LL, B - 1LL + 1LL );
    //  A+k <= Q + 1, B-k <= S + 1
    //  B - S - 1 <= k <= Q - A + 1
    K_min_cell = std::max( K_min_cell, B - S - 1LL );
    K_max_cell = std::min( K_max_cell, Q - A + 1LL );
    //  Integrate
    K_min = std::max( K_min_cell, K_min_prob );
    K_max = std::min( K_max_cell, K_max_prob );

    //  Plot
    apk = ( int )( A - P + K_min );
    brk = ( int )( B - R - K_min );
    k_max = ( int )( K_max - K_min );
    for(int k = 0; k != k_max; k ++ ) {
        if( ( 0 <= apk + k ) && ( apk + k < H ) && ( 0 <= brk - k ) && ( brk - k < W ) )    {
            cells.at( apk + k ).at( brk - k ) = '#';
        }
    }

    //  Display result
    for( int i = 0 ; i != H ; i ++ ) {
        for( int j = 0 ; j != W ; j ++ ) {
            std::cout << cells.at( i ).at( j );
        }
        std::cout << std::endl;
    }

    //  Finalize
    return( 0 );
}
