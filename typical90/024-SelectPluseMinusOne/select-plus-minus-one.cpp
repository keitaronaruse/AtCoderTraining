/*
    024 - Select +／- One（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_x
        Author: Keitaro Naruse
        Date:   2021-11-27, 2021-12-28
        MIT License
*/

//  Solution: 
//  - Calculate d, the L1 norm of two strings A and B
//  - Judge if K == d + 2k, which is K >= d and (K - d) % 2  == 0

#include <iostream>
#include <vector>

const bool Debug = false;

/*
    L1_norm()
        returns the L1 norm of two strings
*/
int L1_norm( const std::vector<int>& a, const std::vector<int>& b )
{
    int d = 0;

    for( int i = 0; i != a.size(); i ++ ) {
        int l = a.at( i ) - b.at( i );
        d += ( l > 0 )? l : - l;
    }

    return( d );
}

int main()
{
    //  Initialize
    //  Read N and K
    int N = 0, K = 0;
    std::cin >> N >> K;
    if( Debug ) {
        std::cerr << N << " " << K << std::endl;
    }

    //  Read Ai
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
        if( Debug ) {
            std::cerr << A.at( i ) << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }

    //  Read Bi
    std::vector<int> B( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> B.at( i );
        if( Debug ) {
            std::cerr << B.at( i ) << " ";
        }
    }
    if( Debug ) {
        std::cerr << std::endl;
    }
    
    //  Main
    int d = L1_norm( A, B );
    if( Debug ) {
        std::cerr << d << std::endl;
    }

    //  Check if K == d + 2k, which is K >= d and (K - d) % 2  == 0
    //  Judge and display result
    if( ( K >= d ) && ( (K - d) % 2 == 0) ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
