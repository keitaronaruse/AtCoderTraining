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
        Pet() : h( -1 ), w( -1 ), t( -1 ), m( A, -1 ) { }
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
//  Pets: pets.at( i ).at( t )
std::vector< std::vector< Pet > > pets;

//  The number of humans 
int M = 0;
//  Humans: humans.at( j ).at( t )
std::vector< std::vector< Human > > humans;

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
    int t = 0;
    std::cin >> N;
    pets = std::vector< std::vector< Pet > >( N, std::vector< Pet >( T ) );
    for( int i = 0; i < N; i ++ ) {
        std::cin >> pets.at( i ).at( t ).h >> pets.at( i ).at( t ).w >> pets.at( i ).at( t ).t;
    }
    if( Debug ) {
        std::cerr << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            std::cerr << pets.at( i ).at( t ) << std::endl;
        }        
    }

    //  Humans
    std::cin >> M;
    humans = std::vector< std::vector< Human > >( M, std::vector< Human >( T ) );
    for( int j = 0; j < M; j ++ ) {
        std::cin >> humans.at( j ).at( t ).h >> humans.at( j ).at( t ).w;
    }
    if( Debug ) {
        std::cerr << M << std::endl;
        for( int j = 0; j < M; j ++ ) {
            std::cerr << humans.at( j ).at( t ) << std::endl;
        }
    }
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
    //  Initailze random
    unsigned long long seed_num = 0uLL;
    engine = std::default_random_engine( seed_num );

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
        
        //  Pet motion
        for( int i = 0; i < N; i ++ ) {
            std::string pet_action;
            std::cin >> pet_action;
            switch( pets.at( i ).at( t ).t ) {
                case 1: //  Cow
                    pets.at( i ).at( t ).m.at( 0 ) = pet_action.at( 0 );
                break;
                case 2: //  Pig
                case 4: //  Dog
                case 5: //  Cat
                    pets.at( i ).at( t ).m.at( 0 ) = pet_action.at( 0 );
                    pets.at( i ).at( t ).m.at( 1 ) = pet_action.at( 1 );
                break;
                case 3: //  Rabbit
                    pets.at( i ).at( t ).m.at( 0 ) = pet_action.at( 0 );
                    pets.at( i ).at( t ).m.at( 1 ) = pet_action.at( 1 );
                    pets.at( i ).at( t ).m.at( 2 ) = pet_action.at( 2 );
                break;
                default:
                break;
            }
            std::cerr << pet_action << " " << std::endl;
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
