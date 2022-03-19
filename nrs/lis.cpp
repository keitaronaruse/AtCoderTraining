/**
* @file lis.cpp
* @brief Longest Increasing Subsequence
* @author Keitaro Naruse
* @date 2022-03-03
* @copyright MIT License
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

namespace nrs {
    template< class T >
    int lis_length( const std::vector< T >& x ) 
    {
        std::vector< T > d;
        for( auto k : x ) {
            auto it = std::lower_bound( d.begin(), d.end(), k );
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

    template< class T >
    std::vector< T > lis( const std::vector< T >& x ) 
    {
        std::vector< T > d;
        std::vector< int > m;

        std::vector< T > seq, pre( x.size(), -1 );
        d.push_back( x.at( 0 ) );
        m.push_back( 0 );
        pre.at( 0 ) = -1;
        for( int i = 1; i < ( int ) x.size(); i ++ ) {
            auto it = std::lower_bound( d.begin(), d.end(), x.at( i ) );
            //  k is not found in l
            if( it == d.end() ) {
                d.push_back( x.at( i ) );
                m.push_back( i );
                pre.at( i ) = m.at( d.size() - 2 );
            }
            else {
                //  replace *it with k
                if( it == d.begin() ) {
                    pre.at( i ) = -1;
                }
                else {
                    pre.at( i ) = m.at( it - d.begin() - 1 );
                }
                int k = it - d.begin();
                d.at( k ) = x.at( i );
                m.at( k ) = i; 
                // *it = x.at( i );
            }
        }
        //  Back trace
        int k = m.at( d.size() - 1 );
        do {
            seq.push_back( x.at( k ) );
            k = pre.at( k );
        } while( k != -1 );
        std::reverse( seq.begin(), seq.end() );

        return( seq );
    }
}

template< class T >
std::ostream& operator<<( std::ostream& os, std::vector< T > v )
{
    for( auto k : v ) {
        os << k << " "; 
    }
    return( os );
}

int main()
{
    std::vector< int > v = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    // std::vector< int > v = { 0, 2, 4, 1, 3, 5 };
    
    std::cout << nrs::lis_length( v ) << std::endl;
    // std::cout << nrs::lis( v ) << std::endl;
    return( 0 );
}
