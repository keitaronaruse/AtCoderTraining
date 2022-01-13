/*
    043 - Maze Challenge with Lack of Sleep
        https://atcoder.jp/contests/typical90/tasks/typical90_aq
        Author: Keitaro Naruse
        Date:   2022-01-13
        MIT License
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <deque>

const bool Debug = true;

int main()
{
    //  Read H and W
    int H = 0, W = 0;
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read Rs and Cs
    int Rs = 0, Cs = 0;
    std::cin >> Rs >> Cs;
    if( Debug ) {
        std::cerr << Rs << " " << Cs << std::endl;
    }
    Rs --; 
    Cs --;
    //  Read Rt and Ct
    int Rt = 0, Ct = 0;
    std::cin >> Rt >> Ct;
    if( Debug ) {
        std::cerr << Rt << " " << Ct << std::endl;
    }
    Rt --;
    Ct --;
    //  Read S
    std::vector< std::vector< char > > S( H, std::vector< char >( W, ' ') );
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
    std::deque< std::pair< int, int > > dq;
    std::vector< std::vector< int > > length( H, std::vector< int >( W, -1 ) );
    int h = Rs, w = Cs;
    dq.push_back( std::make_pair( h, w ) );
    length.at( h ).at( w ) = 0;
    while( !dq.empty() ) {
        auto p = dq.front();
        h = p.first;
        w = p.second;
        std::cerr << h << " " << w << std::endl;
        dq.pop_front();
        int i = 0, j = 0;
        for( int k = 0; k < 4; k ++ ) {
            switch( k ) {
                case 0: i =  1; j =  0; break;
                case 1: i =  0; j = -1; break;
                case 2: i = -1; j =  0; break;
                case 3: i =  0; j =  1; break;
            }
            if( 0 <= h + i && h + i < H && 0 <= w + j && w + j < W ) {
                if( S.at( h + i ).at( w + j ) == '.' ) {
                    if( length.at( h + i ).at( w + j ) == -1 ) {
                        length.at( h + i ).at( w + j ) = length.at( h ).at( w ) + 1;
                        dq.push_back( std::make_pair( h + i, w + j ) );
                    }
                }
            }
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
