/*
    043 - Maze Challenge with Lack of Sleep
        https://atcoder.jp/contests/typical90/tasks/typical90_aq
        Author: Keitaro Naruse
        Date:   2022-01-13, 2022-01-18
        MIT License
*/

// # Solution
// - Introduce 01-bfs by deque for graph searching
// - state ( h, w, q ) and four actions
// - 0 cost for same direction, 1 cost for changing direction

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>

struct state {
    int h; // [ 0, H )
    int w; // [ 0, W )
    int q; // 0(Right: w ++), 1(Up: h --), 2(Left: w --), 3 (Down: h++) 
};

//  According to the orientaion of q, the increse of the next position is as follows 
std::vector< int > dh = {  0, -1,  0,  1 };
std::vector< int > dw = {  1,  0, -1,  0 };

const bool Debug = false;
const int Inf = 1000000007;

int main()
{
    //  Constants
    const int Q = 4;
    //  Read H and W
    int H = 0, W = 0; std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read Rs and Cs
    int Rs = 0, Cs = 0; std::cin >> Rs >> Cs;
    if( Debug ) {
        std::cerr << Rs << " " << Cs << std::endl;
    }
    Rs --; Cs --;
    //  Read Rt and Ct
    int Rt = 0, Ct = 0; std::cin >> Rt >> Ct;
    if( Debug ) {
        std::cerr << Rt << " " << Ct << std::endl;
    }
    Rt --; Ct --;
    //  Read S
    std::vector< std::vector< char > > S( H, std::vector< char >( W, ' ' ) );
    for(int h = 0; h < H; h ++ ) {
        for( int w = 0; w < W; w ++ ) {
            std::cin >> S.at( h ).at( w );
        }
    }
    if( Debug ) {
        for(int h = 0; h < H; h ++ ) {
            for( int w = 0; w < W; w ++ ) {
                std::cerr << S.at( h ).at( w );
            }
            std::cerr << std::endl;
        }
    }

    //  Main
    std::deque< state > deq;
    std::vector< std::vector< std::vector< int > > > length( 
        H, std::vector< std::vector< int > > ( 
            W, std::vector< int > ( Q, Inf ) 
        ) 
    );
    //  Initial value
    int h = Rs, w = Cs;
    for( int q = 0; q < Q; q ++ ) {
        length.at( h ).at( w ).at( q ) = 0;
        deq.push_back( { h, w, q } );
    }
    //  Main
    while( !deq.empty() ) {
        //  Take a current state 
        struct state s = deq.front();
        if( Debug ) {
            std::cerr << s.h << " " << s.w << " " << s.q << " " 
                << length.at( s.h ).at( s.w ).at( s.q ) << std::endl;
        }
        deq.pop_front();

        //  Goal check
        if( s.h == Rt && s.w == Ct ) {
            if( Debug ) {
                std::cerr << "Goal" << std::endl;
            }
            break;
        }

        //  Move to the four directions
        //  If it moves to a facing direction, cost is the same
        //  Otherwise, cost = cost + 1
        for( int q = 0; q < Q; q ++ ) {
            int h = s.h + dh.at( q ); 
            int w = s.w + dw.at( q ); 
            if( 0 <= h && h < H && 0 <= w && w < W ) {
                if( S.at( h ).at( w ) == '.' ) {
                    int cost = length.at( s.h ).at( s.w ).at( s.q ) 
                        + ( q == s.q ? 0 : 1);
                    if( length.at( h ).at( w ).at( q ) > cost ) {
                        length.at( h ).at( w ).at( q ) = cost;
                        if( q == s.q ) {
                            deq.push_front( { h, w, q } );
                        }
                        else {
                            deq.push_back( { h, w, q } );
                        }
                    }
                }
            }
        }
    }

    // Display result
    int result = length.at( Rt ).at( Ct ).at( 0 );
    for( int q = 1; q < Q; q ++ ) {
        result = std::min( result, length.at( Rt ).at( Ct ).at( q ) );
    }
    std::cout << result << std::endl;
        
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
