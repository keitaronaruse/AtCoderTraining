/*
    001 - Yokan Party（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_a
        Author: Keitaro Naruse
        Date:   2021-12-29, 2022-01-01
        MIT License
*/

//  # Solution
// - Binary search of the score of the minimum cutting length between 0 and L
// - The nimimum cutting length is found by the greedy method 

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

/*
    is_possible()
        returns true if all of the pieces are longer than the given score
*/
bool is_possible( int score )
{
    int cut_num = 0;
    int prev_cut_point = 0;
    for( int i = 0 ; i < N ; i ++ ) {
        if( A.at( i ) - prev_cut_point >= score ) {
            prev_cut_point = A.at( i );
            cut_num ++;
            //  It has cut at K points
            if( cut_num >= K ) {
                return( ( L - prev_cut_point ) >= score );
            }
        }
    }
    //  It has not cut at K points -> false
    return( false );
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

    int ok = 0, ng = L;
    int score = 0;
    while( nrs::abs( ok - ng ) > 1 ) {
        score = ( ok + ng ) / 2;
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
