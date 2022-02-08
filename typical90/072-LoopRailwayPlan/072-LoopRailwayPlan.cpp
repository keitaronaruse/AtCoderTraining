/*
* @file 072-LoopRailwayPlan.cpp
* @brief 072 - Loop Railway Plan（★4）
* @author Keitaro Naruse
* @date 2022-02-08
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_bt
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

const bool Debug = true;

class pose {
    public:
        int x;
        int y;
};

std::ostream& operator<<( std::ostream& os, const pose& p )
{
    os << "( " << p.x << ", " << p.y << " ) ";
    return( os );
}

int main()
{
    //  Read H * W <= 16
    int H = 0, W = 0;
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read Xi and Yi = [ -10^9, 10^9 ]
    std::vector< std::vector< char > > c( H, std::vector< char >( W, ' ' ) );
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            std::cin >> c.at( h ).at( w );
        }
    }
    if( Debug ) {
        for( int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                std::cerr << c.at( h ).at( w );
            }
            std::cerr << std::endl;
        }
    }

    //  Main
    const std::vector< int > dx = { 1,  0, -1, 0 }, dy = { 0,  1, 0, -1 };
    std::vector< std::vector< bool > > used( H, std::vector< bool >( W, false ) );
    std::stack< pose > q;
    pose start = { 0, 0 };
    q.push( start );
    while( !q.empty() ) {
        pose curr = q.top();
        used.at( curr.x ).at( curr.y ) = true;
        for( int i = 0; i < 4; i ++ ) {
            pose next = { curr.x + dx.( i ), curr.y + dy.at( i ) };
            if( 0 <= next.x && next.x < H  )
            dx.at();
        }
        used.at( curr.x ).at( curr.y ) = false;
        q.pop();
        std::cout << p << std::endl;
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
