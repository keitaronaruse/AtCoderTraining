/*
    ABC230 Problem C
    C - X drawing
        https://atcoder.jp/contests/abc230/tasks/abc230_c
        Author: Keitaro Naruse
        Date:   2021-12-03
        MIT License
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N, A, B
    int N, A, B;
    std::cin >> N >> A >> B;
    //  Debug
    // std::cerr << N << " " << A << " " << B << std::endl;
    //  Read P Q R S
    int P, Q, R, S;
    std::cin >> P >> Q >> R >> S;
    //  Debug
    // std::cerr << P << " " << Q << " " << R << " " << S << std::endl;

    //  Main
    int H = ( int )( Q - P + 1 );
    int W = ( int )( S - R + 1 );
    //  Debug
    // std::cerr << "P: " << P << " Q: " << Q << std::endl;
    // std::cerr << "R: " << R << " S: " << S << std::endl;
    std::cerr << "H: " << H << " W: " << W << std::endl;
    std::vector< std::vector< char > > cells( H, std::vector< char >( W, '.' ) );
    std::vector< std::vector< char > > large_cells( N + 1, std::vector< char >( N + 1, '.' ) );

    //  First line
    //  Determine the minimun end
    //  max(1−A, 1−B ) <= k
    int k_min_prob = std::max( 1 - A, 1 - B );
    //  P <= A+k, R <= B+k
    int k_min_cell = std::max( P - A, R - B );  // always larger
    //  Integrate
    int k_min = std::max( k_min_cell, k_min_prob );
    //  Debug
    std::cerr << "k_min: " << k_min_cell << " " << k_min_prob << " " << k_min<< std::endl;;
    
    //  Determine the maximum end
    //  min(N−A,N−B)
    int k_max_prob = std::min( N - A + 1, N - B + 1 );
    //  A+k < Q + 1, B+k < S + 1
    int k_max_cell = std::min( Q - A + 1, S - B + 1 ); // always smaller 
    //  Integrate
    int k_max = std::min( k_max_cell, k_max_prob );
    //  Debug
    std::cerr << "k_max: " << k_max_cell << " " << k_max_prob << " " << k_max << std::endl;;
    //  Plot
    for(int k = k_min; k != k_max; k ++ ) {
        large_cells.at( A + k ).at( B + k ) = '#';
        cells.at( A - P + k ).at( B - R + k  ) = '#';
    }

    //  Second line
    //  Determine the minimun end
    //  max(1−A, B-N ) <= k
    k_min_prob = std::max( 1 - A, B - N );  // smaller
    //  P <= A+k, R <= B-k
    //  P - A <= k <= B - R
    // k_min_cell = std::max( P - A, B - R );  // larger
    k_min_cell = P - A;
    k_max_cell = B - R;

    //  Determine the maximum end
    //  min(N−A,B−1)
    k_max_prob = std::min( N - A + 1, B - 1 + 1 );
    //  A+k <= Q + 1, B-k <= S + 1
    //  B - S - 1 <= k <= Q - A + 1
    // k_max_cell = std::min( Q - A + 1, B - S - 1 );  // smaller
    // k_max_cell = std::min( k_max_cell, std::min( Q - A + 1, B - S - 1 ) );
    k_min_cell = std::max( k_min_cell,  P - A );
    k_max_cell = std::min( k_max_cell, Q - A + 1 );

    // k_max_cell = std::max( Q - A, B - S );  // smaller
    //  Integrate
    k_min = std::max( k_min_cell, k_min_prob );
    //  Debug
    std::cerr << "k_min: " << k_min_cell << " " << k_min_prob << " " << k_min<< std::endl;;
    //  Integrate
    k_max = std::min( k_max_cell, k_max_prob );
    //  Debug
    std::cerr << "k_max: " << k_max_cell << " " << k_max_prob << " " << k_max << std::endl;;

    //  Plot
    for(int k = k_min; k != k_max; k ++ ) {
        large_cells.at( A + k ).at( B - k ) = '#';
        if( ( A - P + k >= 0 ) && ( B - R - k >= 0) ) {
            cells.at( A - P + k ).at( B - R - k  ) = '#';
        }
    }

    //  Display result
    for( int i = 1 ; i != N + 1 ; i ++ ) {
        for( int j = R ; j != N + 1 ; j ++ ) {
            std::cout << large_cells.at( i ).at( j );
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for( int i = 0 ; i != H ; i ++ ) {
        for( int j = 0 ; j != W ; j ++ ) {
            std::cout << cells.at( i ).at( j );
        }
        std::cout << std::endl;
    }

    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
