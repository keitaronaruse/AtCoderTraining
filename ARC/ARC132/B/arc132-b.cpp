/**
* @file arc132-b.cpp
* @brief ARC132 Problem B - Shift and Reverse
* @author Keitaro Naruse
* @date 2022-03-28
* @copyright MIT License
* @details https://atcoder.jp/contests/arc132/tasks/arc132_b
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( auto k : v ) {
        os << k << " ";
    }
    return( os );
}

int main()
{
    //  Read n = [ 2, 10^5 ]
    int n;
    std::cin >> n;
    //  Read pi = [ 1, n ]
    std::vector< int > p( n, 0 );
    for( int i = 0; i < n; i ++ ) {
        std::cin >> p.at( i );
    }

    //  Main
    //  Judge if we should reverse it
    int pos_one = 0;
    bool is_ascending = true;
    if( p.at( n - 1 ) == 1 ) {
        pos_one = n - 1;
        is_ascending = ( p.at( 0 ) == 2 ) ? true : false;
    }
    else {
        for( int i = 0; i < n - 1; i ++ ) {
            if( p.at( i ) == 1 ) {
                pos_one = i;
                is_ascending = ( p.at( i + 1 ) == 2 ) ? true : false;
                break;
            }
        }
    }

    //  search
    int num_operation = 0;
    std::queue< std::pair< int , bool > > q;
    q.push( std::make_pair( pos_one, is_ascending ) );
    while( !q.empty() ) {
        auto p = q.front();
        int pos_one = p.first;
        bool is_ascending = p.second; 
        q.pop();
        if( pos_one == 0 && is_ascending ) {
            break;
        }
        else {
            //  Operation 1
            q.push( std::make_pair( n - 1 - pos_one, !is_ascending ) );
            num_operation ++;

            //  Operation 2
            if( pos_one != 0 ) {
                q.push( std::make_pair( pos_one - 1, is_ascending ) );
                num_operation ++;
            }
        }
    }
    std::cout << num_operation << std::endl;

    //  Finalize
    return( 0 );
}
