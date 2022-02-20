/**
* @file abc239-c.cpp
* @brief ABC239 Problem C - Knight Fork
* @author Keitaro Naruse
* @date 2022-02-19, 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/abc239/tasks/abc239_c
*/

// # Solution

#include <iostream>
#include <vector>
#include <utility>

const bool Debug = false;

int main()
{
    //  Read x1, y1, x2, y2 = [ -10^9, 10^9 ]
    long long x1 = 0LL, y1 = 0LL, x2 = 0LL, y2 = 0LL;
    std::cin >> x1 >> y1 >> x2 >> y2;
    if( Debug ) {
        std::cerr << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
    }

    //  Main
    //  Knight positions
    std::vector< int > dx = {  2,  1, -1, -2, -2, -1,  1,  2 };
    std::vector< int > dy = {  1,  2,  2,  1, -1, -2, -2, -1 };

    //  Solution A
    bool isYes = false;
    for( int i = 0; i < 8; i ++ ) {
        int x = x1 + dx.at( i );
        int y = y1 + dy.at( i );
        for( int j = 0; j < 8; j ++ ) {
            if( x + dx.at( j ) == x2 && y + dy.at( j ) == y2 ) {
                isYes = true;
                break;
            }
        }
    }

    //  Solution B
    // std::vector< std::pair< int, int > > knight_positions;
    // for( int i = 0; i < 8; i ++ ) {
    //     int x = x1 + dx.at( i );
    //     int y = y1 + dy.at( i );
    //     knight_positions.push_back( std::make_pair( x, y ) );
    // }
    // bool isYes = false;
    // for( int j = 0; j < 8; j ++ ) {
    //     for( auto p : knight_positions ) {
    //         int x = p.first, y = p.second;
    //         if( x2 + dx.at( j ) == x && y2 + dy.at( j ) == y ) {
    //             isYes = true;
    //             break;
    //         }
    //     }
    // }

    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
