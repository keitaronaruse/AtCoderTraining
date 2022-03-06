/**
* @file asp008-a-1.cpp
* @brief Asprova 8 Problem A - Automated Painting Line / 
  @author Keitaro Naruse
* @date 2022-03-06
* @copyright MIT License
* @details https://atcoder.jp/contests/asprocon8/tasks/asprocon8_a
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>

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
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
