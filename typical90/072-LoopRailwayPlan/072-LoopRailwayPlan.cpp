/*
* @file 072-LoopRailwayPlan.cpp
* @brief 072 - Loop Railway Plan（★4）
* @author Keitaro Naruse
* @date 2022-02-08, 2022-02-10
* @copyright MIT License
* @details https://atcoder.jp/contests/typical90/tasks/typical90_bt
*/

// # Solution

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

const bool Debug = false;

class pose {
public:
    int h;
    int w;
    std::vector< std::vector< int > > length;
};

std::ostream& operator<<( std::ostream& os, const pose& p )
{
    os << "( " << p.h << ", " << p.w << " )" << std::endl;
    for( auto& v : p.length ) {
        for( auto c : v ) {
            os << std::setw( 2 ) << c << " ";
        }
        os << std::endl;
    }
    return( os );
}

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

std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< int > >& vv )
{
    for( auto& v : vv ) {
        for( auto c : v ) {
            os << std::setw( 2 ) << c; 
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

int dfs_stack( int s_h, int s_w, int c_h, int c_w )
{
    int length = -1;

    std::stack< pose > q;
    pose r = { 
        s_h, 
        s_w, 
        std::vector< std::vector< int > >( H, std::vector< int >( W, -1 ) ) 
    };

    r.length.at( r.h ).at( r.w ) = 0;
    q.push( r );
    while( !q.empty() ) {
        r = q.top(); q.pop();
        if( Debug ) {
            std::cout << r << std::endl;
        }
        if( s_h == r.h && s_w == r.w && r.length.at( r.h ).at( r.w ) > -1 ) {
            //  Goal, update the length
            length = std::max( length, r.length.at( r.h ).at( r.w ) );
        } 
        for( int i = 0; i < 4; i ++ ) {
            pose p = r;
            p.h = r.h + d_h.at( i );
            p.w = r.w + d_w.at( i );

            //  If the next is reachable
            if( 0 <= p.h && p.h < H && 0 <= p.w && p.w < W && c.at( p.h ).at( p.w ) == '.' ) {
                //  If the next is unvisited
                if( p.length.at( p.h ).at( p.w ) < 1 ) {
                    //  Push to the stack
                    p.length.at( p.h ).at( p.w ) = p.length.at( r.h ).at( r.w ) + 1;
                    q.push( p );
                }
            }
        }
    }

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
            // length = std::max( length, dfs_stack( s_h, s_w, s_h, s_w ) );
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
