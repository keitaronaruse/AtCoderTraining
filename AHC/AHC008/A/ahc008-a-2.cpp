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

//  Room size
const int H = 30, W = 30;
//  The number of turns
const int T = 300;

//  The map
std::vector< std::vector< char > > ws;

//  Moves: U, D, L, R
const int K = 4;
const std::vector< int > dh = { -1,  1,  0,  0 }, dw = {  0,  0,  1, -1 };

//  Random generator
std::default_random_engine engine;

const int A = 3;
class Pet {
    public:
        int h, w;
        int t;
        std::vector< int > m;
    public:
        Pet() : h( -1 ), w( -1 ), t( -1 ), m( A, -1 ) { }
        void read( std::string& actions ) {
            int K = 0;
            switch( t ) {
                case 1: //  Cow
                    K = 1; 
                break;
                case 2: //  Pig
                case 4: //  Dog
                case 5: //  Cat
                    K = 2; 
                break;
                case 3: //  Rabbit
                    K = 3;
                break;
                default:
                break;
            }
            for( int k = 0; k < K; k ++ ) {
                int index = -1;
                switch( actions.at( k ) ) {
                    case 'U': index = 0; break;
                    case 'D': index = 1; break;
                    case 'L': index = 2; break;
                    case 'R': index = 3; break;
                    default: index = -1; break;
                }
                m.at( k ) = index;
            }
        }
        void update() {
            int K = 0;
            switch( t ) {
                case 1: //  Cow
                    K = 1;
                break;
                case 2: //  Pig
                case 4: //  Dog
                case 5: //  Cat
                    K = 2;
                break;
                case 3: //  Rabbit
                    K = 3;
                break;
                default:
                break;
            }
            for( int k = 0; k < K; k ++ ) {
                h += dh.at( m.at( k ) );
                w += dw.at( m.at( k ) );
            }
        }
};

std::ostream& operator<<( std::ostream& os, const Pet& p )
{
    os << p.h << " " << p.w << " " << p.t;
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

//  The number of pets 
int N = 0;
//  Pets: pets.at( i )
std::vector< Pet > pets;

//  The number of humans 
int M = 0;
//  Humans: humans.at( j )
std::vector< Human > humans;

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
        //  Human actions
        std::string human_actions( M, '.' );
        std::cout << human_actions << std::endl;
        
        //  Pet motions
        for( int i = 0; i < N; i ++ ) {
            std::string pet_action;
            std::cin >> pet_action;
            pets.at( i ).read( pet_action );
            if( Debug ) {
                std::cerr << pet_action << " " << std::endl;
            }
        }
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
