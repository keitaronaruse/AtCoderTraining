/*
    007 - CP Classes（★3）
        https://atcoder.jp/contests/typical90/tasks/typical90_g
        Author: Keitaro Naruse
        Date:   2021-12-05, 2021-12-06
        MIT License
*/

// # Solution
// - A_ascend: Sort class score A in the ascending order
// - lower_bound( A.begin(), A.end(), Qj )

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    //  Debug
    // std::cerr << N << std::endl;
    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        //  Debug
        // std::cerr << A.at( i ) << std::endl;
    }
    //  Sort A in the ascending order
    std::sort( A.begin(), A.end() );
    // Debug
    // for( const auto& a : A ) {
    //     std::cerr << a << " ";
    // }
    // std::cerr << std::endl;
    
    //  Read Q
    int Q = 0;
    std::cin >> Q;
    //  Debug
    // std::cerr << Q << std::endl;

    //  Read Bj
    for( int j = 0; j < Q; j ++ ) {
        int B = 0;
        std::cin >> B;
        //  Debug
        // std::cerr << B << std::endl;

        //  Find lower bound of Bj in A in the ascending order
        std::vector< int >::iterator it = std::lower_bound( A.begin(), A.end(), B );

        if( it == A.begin() ) {
            //  B is smaller than the first clas
            std::cout << std::abs( B - *it ) << std::endl;
        }
        else if( it == A.end() ) {
            //  B is larger than the last clas
            std::cout << std::abs( B - *( it - 1 ) ) << std::endl;
        }
        else {
            //  B is in between it-1 and it
            std::cout 
            << std::min( std::abs( B - *( it - 1 )), std::abs( B - *it ) )
            << std::endl;
        }
    }

    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
