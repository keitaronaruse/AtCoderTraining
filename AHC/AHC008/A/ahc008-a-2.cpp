/**
* @file ahc008-a-2.cpp
* @brief AHC008 Problem A - Territory
* @author Keitaro Naruse
* @date 2022-02-16
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc008/tasks/ahc008_a
*/

// # Solution
// - Humans do nothing
// - Update the motions of the pets

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

const bool Debug = false;

const int A = 3;
class Pet {
    public:
        int h, w;
        int t;
        std::vector< int > m;
    public:
        Pet() : m( A, -1 ) { }
        //  Return a move: U, D, L, R
};

std::ostream& operator<<( std::ostream& os, const Pet& p )
{
    os << p.h << " " << p.w << " " << p.t;
    // char c = ' ';
    // for( int i = 0; i < A; i ++ ) {
    //     //  Moves: U, D, L, R
    //     switch( p.m.at( i ) ) {
    //         case 0: c = 'U'; break;
    //         case 1: c = 'D'; break;
    //         case 2: c = 'L'; break;
    //         case 3: c = 'R'; break;
    //         default: c = '.'; break;
    //     }
    //     os << c << " "; 
    // }
    return( os );
}

class Human {
    public:
        int h, w; 
};

std::ostream& operator<<( std::ostream& os, const Human& h )
{
    os << h.h << " " << h.w;
    return( os );
}

//  Room size
const int H = 30, W = 30;
//  The number of turns
const int T = 300;

//  The number of pets 
int N = 0;
//  Pets
std::vector< Pet > pets;

//  The number of humans 
int M = 0;
//  Humans
std::vector< Human > humans;

//  The map
std::vector< std::vector< char > > ws;

//  Moves: U, D, L, R
const int K = 4;
const std::vector< int > dh = { -1,  1,  0,  0 }, dw = {  0,  0,  1, -1 };

//  Random generator
std::default_random_engine engine;

void read_input()
{
    //  Pets
    std::cin >> N;
    pets = std::vector< Pet >( N );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> pets.at( i ).h >> pets.at( i ).w >> pets.at( i ).t;
    }
    if( Debug ) {
        std::cerr << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            std::cerr << pets.at( i ) << std::endl;
        }        
    }

    //  Humans
    std::cin >> M;
    humans = std::vector< Human >( M );
    for( int j = 0; j < M; j ++ ) {
        std::cin >> humans.at( j ).h >> humans.at( j ).w;
    }
    if( Debug ) {
        std::cerr << M << std::endl;
        for( int j = 0; j < M; j ++ ) {
            std::cerr << humans.at( j ) << std::endl;
        }
    }
    unsigned long long seed_num = 0uLL;
    // std::cin >> seed_num;
    engine = std::default_random_engine( seed_num );
}

void make_map()
{
    //  free = ., obstacle = #
    //  Pets: cow = C, pig = P, rabbit = R, dog = D, cat = C 
    //  Human : human = H 
    ws = std::vector< std::vector< char > >( H + 2, std::vector< char >( W + 2, '.' ) );
    for( int h = 0; h < H + 2; h ++ ) {
        ws.at( h ).at( 0 ) = '#';
        ws.at( h ).at( W + 1 ) = '#';
    }
    for( int w = 0; w < W + 2; w ++ ) {
        ws.at( 0 ).at( w ) = '#';
        ws.at( H + 1 ).at( w ) = '#';
    }
}

std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< char > >& m )
{
    for( int h = 0; h < H + 2; h ++ ) {
        for( int w = 0; w < W + 2; w ++ ) {
            os << m.at( h ).at( w );
        }
        os << std::endl;
    }
    return( os );
}

int main()
{
    //  Read input
    read_input();
    //  Make a map
    make_map();
    if( Debug ) {
        std::cerr << ws;
    }

    //  Main
    for( int t = 0; t < T; t ++ ) {
        std::string human_actions( M, '.' );
        // for( int j = 0; j < M; j ++ ) {
        //     std::cout << ".";
        // }
        std::cout << human_actions << std::endl;
        // std::cout << std::flush;
        
        std::string pet_actions;
        std::getline( std::cin, pet_actions );
        std::cerr << pet_actions << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
