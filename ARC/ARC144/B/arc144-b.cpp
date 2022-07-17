/**
 * @file arc144-b.cpp
 * @brief ARC144 Problem B
 * @author Keitaro Naruse
 * @date 2022-07-16
 * @copyright MIT License
 * @details https://atcoder.jp/contests/arc144/tasks/arc144_b
 */

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main( ) {
    //  Read N = [ 2, 3*10^5 ]
    int N;
    std::cin >> N;
    //  Read a, b = [1, 10^9 ]
    int a, b;
    std::cin >> a >> b;
    //  Read Ai = [ 1, 10^9 ]
    std::vector< int > A( N );
    for( int i = 0; i < N; i++ ) {
        std::cin >> A.at( i );
    }

    //  Main
    //  Preprocess
    std::multiset< int > B;
    for( int i = 0; i < N; i++ ) {
        B.insert( A.at( i ) );
    }
    //  Find the solution
    int min = *B.begin( );
    while( true ) {
        auto it_head = B.begin( );
        auto it_tail = B.end( );
        it_tail--;
        if( *it_head != *it_tail ) {
            int new_head = *it_head + a;
            int new_tail = *it_tail - b;
            B.erase( it_head );
            B.erase( it_tail );
            B.insert( new_head );
            B.insert( new_tail );
            if( *B.begin() > min ) {
                min = *B.begin();
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }

    //  Print the splution
    std::cout << min << std::endl;

    //  Finalize
    return ( 0 );
}
