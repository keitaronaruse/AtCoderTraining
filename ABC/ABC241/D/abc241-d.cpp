/**
* @file abc241-d.cpp
* @brief ABC241 Problem D - Sequence Query
* @author Keitaro Naruse
* @date 2022-02-26, 2022-02027
* @copyright MIT License
* @details https://atcoder.jp/contests/abc241/tasks/abc241_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

const bool Debug = false;

std::ostream& operator<<( std::ostream& os, const std::multiset< long long >& s )
{
    for( auto k : s ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read Q = [ 1, 2 * 10^5 ]
    int Q = 0;
    std::cin >> Q;
    if( Debug ) {
        std::cerr << Q <<  std::endl;
    }
    //  Read ci, xi, ki
    std::vector< int > c( Q, 0 );
    std::vector< long long > x( Q, 0LL );
    std::vector< int > k( Q, 0 );
    for( int i = 0; i < Q; i ++ ) {
        std::cin >> c.at( i ) >> x.at( i );
        if( c.at( i ) >= 2 ) {
            std::cin >> k.at( i );
        }
    }
    if( Debug ) {
        for( int i = 0; i < Q; i ++ ) {
            std::cerr << c.at( i ) << " " << x.at( i );
            if( c.at( i ) >= 2 ) {
                std::cerr << " " << k.at( i );
            }
            std::cerr << std::endl;
        }
    }

    //  Main
    std::multiset< long long > A;
    for( int i = 0; i < Q; i ++ ) {
        //  Insert
        if( c.at( i ) == 1 ) {
            A.insert( x.at( i ) ); 
        }
        //  K-th large Ai <= x 
        else if( c.at( i ) == 2 ) {
            auto it = A.upper_bound( x.at( i ) );
            bool is_found = true;
            for( int j = 0; j < k.at( i ); j ++ ) {
                if( it == A.begin() ) {
                    is_found = false;
                    break;
                }
                else {
                    it --;
                }
            }
            if( is_found ) {
                std::cout << *it << std::endl;
            }
            else {
                std::cout << "-1" << std::endl;
            }
        }
        //  K-th small Ai >= x 
        else if( c.at( i ) == 3 ) {
            auto it = A.lower_bound( x.at( i ) );
            bool is_found = true;
            for( int j = 0; j < k.at( i ) - 1; j ++ ) {
                if( it == A.end() ) {
                    is_found = false;
                    break;
                }
                else {
                    it ++;
                }
            }
            if( it == A.end() ) {
                is_found = false;
            }
            if( is_found ) {
                std::cout << *it << std::endl;
            }
            else {
                std::cout << "-1" << std::endl;
            }
            ;
        }
        else {
            ;
        }
        if( Debug ) {
            std::cerr << A << std::endl;
        }
    }
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
