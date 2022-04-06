/**
* @file abc225-d.cpp
* @brief ABC225 Problem D - Play Train
* @author Keitaro Naruse
* @date 2022-04-06
* @copyright MIT License
* @details https://atcoder.jp/contests/abc225/tasks/abc225_d
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //  Read N = [ 1, 10^5 ], Q = [ 1 , 10^5 ]
    int N, Q;
    std::cin >> N >> Q;
    //  Read ci = [ 1, 3 ], xi, yi = [ 1, N ]
    std::vector< int > c( Q ), x( Q ), y( Q );
    for( int i = 0; i < Q; i ++ ) {
        std::cin >> c.at( i );
        if( c.at( i ) == 1 || c.at( i ) == 2 ) {
            std::cin >> x.at( i ) >> y.at( i );
        }
        else if( c.at( i ) == 3 ) {
            std::cin >> x.at( i );
        }
    }
    
    //  Main
    std::vector< int > prev( N + 1, -1 ), next( N + 1, -1 );
    for( int i = 0; i < Q; i ++ ) {
        if( c.at( i ) == 1 ) {
            next.at( x.at( i ) ) = y.at( i );
            prev.at( y.at( i ) ) = x.at( i );
        }
        else if( c.at( i ) == 2 ) {
            next.at( x.at( i ) ) = -1;
            prev.at( y.at( i ) ) = -1;
        }
        else if( c.at( i ) == 3 ) {
            int num_prev = 0, num_next = 0;
            int head, j;
            //  Find the number of previous cars
            j = x.at( i );
            while( prev.at( j ) != -1 ) {
                num_prev ++;
                j = prev.at( j );
            }
            head = j;

            //  Find the number of next cars
            j = x.at( i );
            while( next.at( j ) != -1 ) {
                num_next ++;
                j = next.at( j );
            }
            //  Write the number of cars
            std::cout << num_prev + 1 + num_next << " ";
            j = head;
            while( next.at( j ) != -1 ) {
                std::cout << j << " ";
                j = next.at( j );
            }
            std::cout << j << std::endl;
        }
    }

    //  Finalize
    return( 0 );
}
