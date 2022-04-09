/**
* @file arc138-a.cpp
* @brief ARC138 Problem A - Larger Score
* @author Keitaro Naruse
* @date 2022-04-09, 2022-04-10
* @copyright MIT License
* @details https://atcoder.jp/contests/arc138/tasks/arc138_a
*/

// # Solution

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

template< class K, class V >
std::ostream& operator<<( std::ostream& os, const std::pair< K, V >& p )
{
    os << "( " << p.first << ", " << p.second << " ) ";
    return( os );
}

int wrong_solution( int N, int K, const std::vector< int >& A )
{
    //  Preprocess
    std::map< int, int > head_value_index, tail_value_index;
    //  Head, from head
    for( int i = 0; i < K; i ++ ) {
        head_value_index[ A.at( i ) ] = i;
    }
    //  Tail, form tail
    for( int i = N - 1; i >= K; i -- ) {
        tail_value_index[ A.at( i ) ] = i;
    }

    //  Find the solution
    int min_step = N;
    for( const auto& p : head_value_index ) {
        auto it = tail_value_index.upper_bound( p.first );
        while( it != tail_value_index.end() ) {
            if( min_step >= it -> second - p.second ) {
                min_step = it -> second - p.second;
                it ++;
            }
            else {
                break;
            }
        }
    }
    if( min_step == N ) {
        min_step = -1;
    }

    return( min_step );
}

int sample_solution( int N, int K, const std::vector< int >& A )
{
    //  Pair of value and index
    std::vector< std::pair< int, int > > value_index( N );
    for( int i = 0; i < N; i ++ ) {
        value_index.at( i ) = std::make_pair( A.at( i ), -i );
    }
    std::sort( value_index.begin(), value_index.end() );

    int min_step = N;
    int target_index = -N;
    for( const auto& p : value_index ) {
        int k = -p.second;
        //  The first half
        if( k < K ) {
            target_index = std::max( k, target_index );
        }
        else {
            min_step = std::min( k - target_index, min_step );
        }
    }

    if( min_step == N ) {
        min_step = -1;
    }

    return( min_step );
}

int main()
{
    //  Read N = [ 2, 4 * 10^5 ], K = [ 1, N - 1 ]
    int N, K;
    std::cin >> N >> K;

    //  Read Ai = [ 1, 10^9 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    int min_step = sample_solution( N, K, A );
    std::cout << min_step << std::endl;

    //  Finalize
    return( 0 );
}
