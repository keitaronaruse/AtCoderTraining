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

const bool Debug = false;

// class pose {
//     public:
//         int x;
//         int y;
// };

// std::ostream& operator<<( std::ostream& os, const pose& p )
// {
//     os << "( " << p.x << ", " << p.y << " ) ";
//     return( os );
// }

int H = 0, W = 0;
std::vector< std::vector< char > > c;
std::vector< std::vector< bool > > visited;
const std::vector< int > d_h = { 1,  0, -1, 0 }, d_w = { 0,  1, 0, -1 };

std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< char > >& vv )
{
    for( auto& v : vv ) {
        for( auto c : v ) {
            os << c;
        }
        os << std::endl;
    }
    return( os );
}

std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< bool > >& vv )
{
    for( auto& v : vv ) {
        for( auto c : v ) {
            if( c ) {
                os << "1";
            }
            else {
                os << "0";
            }
        }
        os << std::endl;
    }
    return( os );
}

int dfs( int s_h, int s_w, int c_h, int c_w )
{
    if( s_h == c_h && s_w == c_w && visited.at( c_h ).at( c_w ) ) {
        return( 0 );
    }

    int length = -1;
    visited.at( c_h ).at( c_w ) = true;
    for( int i = 0; i < 4; i ++ ) {
        int n_h = c_h + d_h.at( i ), n_w = c_w + d_w.at( i );
        //  If the next is unreachable,
        if( n_h < 0 || H <= n_h || n_w < 0 || W <= n_w || c.at( n_h ).at( n_w ) == '#' ) {
            continue;
        }
        //  If the next is no-goal and visited,
        if( !( s_h == n_h && s_w == n_w ) && visited.at( n_h ).at( n_w ) ) {
            continue;
        }
        int v = dfs( s_h, s_w, n_h, n_w );
        //  Update the length if it has a path
        if( v != -1 ) {
            length = std::max( length, v + 1 );
        }
    }
    visited.at( c_h ).at( c_w ) = false;
    
    return( length );
}

int main()
{
    //  Read H * W <= 16
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read Xi and Yi = [ -10^9, 10^9 ]
    c = std::vector< std::vector< char > >( H, std::vector< char >( W, ' ' ) );
    visited = std::vector< std::vector< bool > >( H, std::vector< bool >( W, false ) );
    for( int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            std::cin >> c.at( h ).at( w );
        }
    }
    if( Debug ) {
        std::cerr << c;
    }

    //  Main
    //  Find the solution
    int length = -1;
    for( int s_h = 0; s_h < H; s_h ++ ) {
        for( int s_w = 0; s_w < W; s_w ++ ) {
            length = std::max( length, dfs( s_h, s_w, s_h, s_w ) );
        }
    }
    //  Apply the constraints
    if( length < 3 ) {
        length = -1;
    }
    std::cout << length << std::endl;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
