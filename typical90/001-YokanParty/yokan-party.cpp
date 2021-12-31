/*
    001 - Yokan Party（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_a
        Author: Keitaro Naruse
        Date:   2021-12-29, 2021-12-31
        MIT License
*/

//  # Solution
// - Binary search

#include <iostream>
#include <vector>

namespace nrs {
    template < class T >
    T abs( T a )
    {
        return( ( a > 0 )? a : -a );
    }

    int binary_search( int ok, int ng, bool pred( int ) )
    {
        while( nrs::abs( ok - ng ) > 1 ) {
            int mid = ( ok + ng ) / 2;
            if( pred( mid ) ) {
                ok = mid;
            }
            else {
                ng = mid;
            }
        }

        return( ok );
    }
}

const bool Debug = true;

bool is_possible( int score, const std::vector< int >& A )
{
    bool okay = ( score > 10 );
    return( okay );
}

int main()
{
    //  Initialize
    //  Read N and L
    int N = 0, L = 0;
    std::cin >> N >> L;
    if( Debug ) {
        std::cerr << N << " " << L << std::endl;
    }
    //  Read K
    int K = 0;
    std::cin >> K;
    if( Debug ) {
        std::cerr << K << std::endl;
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

    //  Main
    int ok = L, ng = 0;
    while( nrs::abs( ok - ng ) > 1 ) {
        int mid = ( ok + ng ) / 2;
        if( is_possible( mid, A ) ) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }
    std::cout << ok << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
