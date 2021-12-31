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

//  Problem
int N, L, K;
std::vector< int > A;

bool is_possible( int score )
{
    std::vector< int > cut( K + 1, 0 );

    int k = 0;
    cut.at( k ) = 0;
    for( int i = 0 ; i < N ; i ++ ) {
        if( A.at( i ) - cut.at( k ) >= score ) {
            cut.at( k + 1 ) = A.at( i );
            k ++;
            if( k >= K ) {
                cut.at( k ) = L - A.at( i );
                break;
            }
        }
    }

    return( cut.at( k ) >= score );
}

int main()
{
    //  Initialize
    //  Read N and L
    std::cin >> N >> L;
    if( Debug ) {
        std::cerr << N << " " << L << std::endl;
    }
    //  Read K
    std::cin >> K;
    if( Debug ) {
        std::cerr << K << std::endl;
    }
    //  Read Ai
    A = std::vector< int > ( N );
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
        int score = ( ok + ng ) / 2;
        if( is_possible( score ) ) {
            ok = score;
        }
        else {
            ng = score;
        }
    }
    std::cout << ok << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
