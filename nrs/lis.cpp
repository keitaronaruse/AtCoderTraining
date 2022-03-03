/**
* @file lis.cpp
* @brief Longest Increasing Subsequence
* @author Keitaro Naruse
* @date 2022-03-03
* @copyright MIT License
*/

#include <iostream>
#include <vector>
#include <algorithm>

namespace nrs {
    template< class T >
    int lis( const std::vector< T >& v, std::vector< T >& l ) 
    {
        for( auto k : v ) {
            auto it = std::lower_bound( l.begin(), l.end(), k );
            //  k is not found in l, the longest increasing subsequence
            if( it == l.end() ) {
                //  add k to l
                l.push_back( k );
            }
            else {
                //  replace *it with k
                *it = k;
            }
        }
        return( l.size() );
    }
}

const bool Debug = true;

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
    std::vector< int > l;
    
    nrs::lis( v, l );
    std::cout << l << std::endl;
    return( 0 );
}
