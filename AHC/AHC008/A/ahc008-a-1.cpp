/**
* @file ahc008-a-1.cpp
* @brief AHC008 Problem A - Territory
* @author Keitaro Naruse
* @date 2022-02-19
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc008/tasks/ahc008_a
*/

// # Solution

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

const bool Debug = true;

//  Room size
const int H = 30, W = 30;
//  The number of turns
const int T = 300;

//  The number of pets 
int N = 0;
//  Pet x positions, py.at( t ).at( i )
std::vector< std::vector< int > > px;
//  Pet y positions, py.at( t ).at( i )
std::vector< std::vector< int > > py;
//  Pet types, pt.at( i )
std::vector< int > pt;

//  The number of humans 
int M = 0;
//  Human x positions, hy.at( t ).at( i )
std::vector< std::vector< int > > hx;
//  Human y positions, hy.at( t ).at( i )
std::vector< std::vector< int > > hy;

void read_input()
{
    std::cin >> N;
    //  Pet x positions, py.at( t ).at( i )
    px = std::vector< std::vector< int > >( T, std::vector<int>( N, 0 ) );
    //  Pet y positions, py.at( t ).at( i )
    py = std::vector< std::vector< int > >( T, std::vector<int>( N, 0 ) );
    //  Pet types, pt.at( i )
    pt = std::vector< int >( N, 0 );

    for( int i = 0; i < N; i ++ ) {
        int t = 0;
        std::cin >> px.at( t ).at( i ) >> py.at( t ).at( i ) >> pt.at( i );
    }
    if( Debug ) {
        std::cerr << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            int t = 0;
            std::cerr 
                << px.at( t ).at( i ) << " " 
                << py.at( t ).at( i ) << " " 
                << pt.at( i ) << std::endl;
        }        
    }

    std::cin >> M;
    //  Human x positions, hy.at( t ).at( i )
    hx = std::vector< std::vector< int > >( T, std::vector<int>( M, 0 ) );
    //  Human y positions, hy.at( t ).at( i )
    hy = std::vector< std::vector< int > > ( T, std::vector<int>( M, 0 ) );
    for( int j = 0; j < M; j ++ ) {
        int t = 0;
        std::cin >> hx.at( t ).at( j ) >> hy.at( t ).at( j );
    }
    if( Debug ) {
        std::cerr << M << std::endl;
        for( int j = 0; j < M; j ++ ) {
            int t = 0;
            std::cerr 
                << hx.at( t ).at( j ) << " "
                << hy.at( t ).at( j ) << std::endl;
        }
    }
}

int main()
{
    //  Read input
    read_input();

    //  Main

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
