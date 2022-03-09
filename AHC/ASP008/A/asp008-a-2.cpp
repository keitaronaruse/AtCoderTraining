/**
* @file asp008-a-2.cpp
* @brief Asprova 8 Problem A - Automated Painting Line
  @author Keitaro Naruse
* @date 2022-03-09, 2022-03-09
* @copyright MIT License
* @details https://atcoder.jp/contests/asprocon8/tasks/asprocon8_a
*/

// # Solution
// - Determine the order of (s,c) as the minimum setup time 
// - Solve the above problem by greedy + 2-opt

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

const bool Debug = true;

//  S = [ 4, 10 ]: The number of Shapes 
//  C = [ 4, 10 ]: The number of Colors
//  H = [ 250 ]: The number of Hooks
int S, C, H;

//  a, b = [ 1, 99 ]: Weights of the cost
int a, b;

//  Ns,c = [ 0, 5000 ]: The number of products
std::vector< std::vector< int > > N;

//  Ks = [ 1, H ]: The number of Hangers
std::vector< int > K;

//  As,s = [ 1, 20 ]: The setting time of shapes
std::vector< std::vector< int > > A;

//  Bc,c = [ 5, 40 ]: The setting time of colors
std::vector< std::vector< int > > B;

void read_input()
{
    std::cin >> S >> C >> H >> a >> b;
    N = std::vector< std::vector< int > > ( S, std::vector< int >( C, 0 ) );
    for( int s = 0; s < S; s ++ ) {
        for( int c = 0; c < C; c ++ ) {
            std::cin >> N.at( s ).at( c );
        }
    }
    K = std::vector< int > ( S, 0 );
    for( int s = 0; s < S; s ++ ) {
        std::cin >> K.at( s );
    }
    
    A = std::vector< std::vector< int > > ( S, std::vector< int >( S, 0 ) );
    for( int i = 0; i < S; i ++ ) {
        for( int j = 0; j < S; j ++ ) {
            std::cin >> A.at( i ).at( j );
        }
    }

    B = std::vector< std::vector< int > > ( C, std::vector< int >( C, 0 ) );
    for( int i = 0; i < C; i ++ ) {
        for( int j = 0; j < C; j ++ ) {
            std::cin >> B.at( i ).at( j );
        }
    }

}

void write_output( const std::vector< std::pair< int, int > > &ans ) {
    std::cout << ans.size() << std::endl;
    for( int i = 0; i < int(ans.size()); i++ ) {
        if( ans[i].first >= 0 ) {
            std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << std::endl;
        }
        else {
            std::cout << ans[i].first << std::endl;
        }
    }
}

void main_rtn( std::vector< std::pair< int, int > >& ans )
{
    std::vector< int > hanger_on_hook( H, -1 );
    std::vector< int > hangers_available = K;
    int pos = 0, prev_s = -1, prev_c = -1;

    for( int s = 0; s < S; s ++ ) {
        for( int c = 0; c < C; c ++ ) { // assign item (s, c)
            if( N.at( s ).at( c ) == 0 ) {
                continue;
            }

            // need this amount of empty hooks
            const int setup = (prev_s == -1 ? 0 : std::max( A.at( prev_s ).at( s ), B.at( prev_c ).at( c )) );
            for( int i = 0; i < setup; i ++ ) {
                ans.push_back( std::make_pair( -2, 0 ) );
                (++ pos) %= H;
            }

            // put (s, c)
            for( int n = 0; n < N.at( s ).at( c ); ) {
                if( hanger_on_hook.at( pos ) != s && hangers_available.at( s ) == 0 ) {
                    // run out of hangers
                    ans.push_back( std::make_pair( -2, 0 ) );
                    (++ pos) %= H;
                }
                else {
                    ans.push_back( std::make_pair( s, c ) );
                    n ++;
                    if( hanger_on_hook.at( pos ) != s ) {
                        if( hanger_on_hook.at( pos ) >= 0 ) {
                            hangers_available.at( hanger_on_hook.at( pos ) ) ++;
                        }
                        hangers_available.at( s ) --;
                        hanger_on_hook.at( pos ) = s;
                    }
                    (++ pos) %= H;
                }
                prev_s = s;
                prev_c = c;
            }
        }
    }
}

int main()
{
    //  Read input
    read_input();
    if( Debug ) {
        std::cerr << S << " " << C << " " << H << " " << a << " " << b << std::endl;
        for( int s = 0; s < S; s ++ ) {
            for( int c = 0; c < C; c ++ ) {
                std::cerr << N.at( s ).at( c ) << " ";
            }
            std::cerr << std::endl;
        }

        for( int s = 0; s < S; s ++ ) {
            std::cerr << K.at( s ) << " ";
        }
        std::cerr << std::endl;

        for( int i = 0; i < S; i ++ ) {
            for( int j = 0; j < S; j ++ ) {
                std::cerr << A.at( i ).at( j ) << " ";
            }
            std::cerr << std::endl;
        }

        for( int i = 0; i < C; i ++ ) {
            for( int j = 0; j < C; j ++ ) {
                std::cerr << B.at( i ).at( j ) << " ";
            }
            std::cerr << std::endl;
        }
    }

    //  Main
    //  Same as sample.cpp
    std::vector< std::pair< int, int > > ans;
    main_rtn( ans );

    // write answer
    write_output( ans );


    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
