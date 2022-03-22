/**
* @file past09-l.cpp
* @brief PAST 9 Problem L - 嘘つきな生徒たち
  @author Keitaro Naruse
* @date 2022-03-18, 2022-03-19
* @copyright MIT License
* @details https://atcoder.jp/contests/past202112-open/tasks/past202112_l
*/

#include <iostream>
#include <vector>
#include <algorithm>

namespace nrs {
    template< class T >
    int lis_length( const std::vector< T >& x ) 
    {
        std::vector< T > d;
        for( auto k : x ) {
            auto it = std::upper_bound( d.begin(), d.end(), k );
            int i = it - d.begin();
            //  k is not found in l
            if( it == d.end() ) {
                //  add k to l
                d.push_back( k );
            }
            else {
                //  replace *it with k
                *it = k;
            }
        }
        return( d.size() );
    }
}

template < class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v ) 
{
    for( auto k : v ) {
        os << k << " ";
    }
    os << std::endl;
    return( os );
}

int main()
{
    //  N = [ 2, 2 * 10^5 ]
    int N;
    //  P = [ 1, 10^9 ]
    int P;
    std::cin >> N >> P;

    //  Ai = [ 0, P ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    std::vector< int > B = A;
    std::reverse( B.begin(), B.end() );
    for( int i = 0; i < N; i ++ ) {
        B.at( i ) -= i;
        if( B.at( i ) < 0 || P - ( N - 1 ) < B .at( i ) ) {
            B.at( i ) = -1;
        }
    }
    B.erase( std::remove( B.begin(), B.end(), -1 ), B.end() ); 
    std::cout << N - nrs::lis_length( B ) << std::endl; 

    return( 0 );
}
