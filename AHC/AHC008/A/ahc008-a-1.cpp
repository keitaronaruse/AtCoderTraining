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
#include <string>
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
//  Pet x positions, py.at( i )
std::vector< int > px;
//  Pet y positions, py.at( i )
std::vector< int > py;
//  Pet types, pt.at( i )
std::vector< int > pt;

//  The number of humans 
int M = 0;
//  Human x positions, hy.at( i )
std::vector< int > hx;
//  Human y positions, hy.at( i )
std::vector< int > hy;

//  The map
std::vector< std::vector< char > > ws;

//  Moves: U, D, L, R
const int K = 4;
const std::vector< int > dh = { -1,  0,  1,  0 }, dw = {  0,  1,  0, -1 };

//  Random generator
std::default_random_engine engine;

void read_input()
{
    std::cin >> N;
    //  Pet x positions
    px = std::vector< int >( N, 0 );
    //  Pet y positions
    py = std::vector< int >( N, 0 );
    //  Pet types, pt.at( i )
    pt = std::vector< int >( N, 0 );

    for( int i = 0; i < N; i ++ ) {
        std::cin >> px.at( i ) >> py.at( i ) >> pt.at( i );
    }
    if( Debug ) {
        std::cerr << N << std::endl;
        for( int i = 0; i < N; i ++ ) {
            std::cerr << px.at( i ) << " " << py.at( i ) << " " << pt.at( i ) << std::endl;
        }        
    }

    std::cin >> M;
    //  Human x positions, hy.at( t ).at( i )
    hx = std::vector< int >( M, 0 );
    //  Human y positions, hy.at( t ).at( i )
    hy = std::vector< int > ( M, 0 );
    for( int j = 0; j < M; j ++ ) {
        std::cin >> hx.at( j ) >> hy.at( j );
    }
    if( Debug ) {
        std::cerr << M << std::endl;
        for( int j = 0; j < M; j ++ ) {
            std::cerr << hx.at( j ) << " " << hy.at( j ) << std::endl;
        }
    }

    unsigned long long seed_num = 0uLL;
    std::cin >> seed_num;
    engine = std::default_random_engine( seed_num );
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

const int A = 3;
class Pet {
    public:
        int h, w;
        int t;
        std::vector< int > m;
    public:
        Pet() : m( A, -1 ) { }
        Pet( int rh, int rw, int rt ) : m( A, -1 ) {
            h = rh; w = rw; t = rt; 
        }
        //  Return a move: U, D, L, R
        int standard_move( int h, int w ) {
            std::vector< int > moves;
            for( int k = 0; k < K; k ++ ) {
                int v = h + dh.at( k ), u = w + dw.at( k );
                if( ws.at( v ).at( u ) != '#' ) {
                    moves.push_back( k );
                }
            }
            std::uniform_int_distribution<> dist( 0, moves.size() );
            return( moves.at( dist( engine ) )  );
        }
        void update() {
            for( int i = 0; i < A; i ++ ) {
                if( m.at( i ) != -1 ) {
                    h += dh.at( m.at( i ) );
                    w += dw.at( m.at( i ) );
                }
                m.at( i ) = -1;
            }
        }
};

class Human {
    public:
        int h, w; 
};

std::ostream& operator<<( std::ostream& os, const Pet& p )
{
    std::string a( A, ' ' );
    for( int i = 0; i < A; i ++ ) {
        //  Moves: U, D, L, R
        switch( p.m.at( i ) ) {
            case 0: a.at( i ) = 'U'; break;
            case 1: a.at( i ) = 'D'; break;
            case 2: a.at( i ) = 'L'; break;
            case 3: a.at( i ) = 'R'; break;
            default: a.at( i ) = '.'; break;
        }
    }
    os << p.h << " " << p.w << " " << p.t << " " << a.at( 0 ) << a.at( 1 ) << a.at( 2 );
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
    Pet p( 1, 1, 1 );
    std::cout << p << std::endl << std::flush;
    p.m[ 0 ] = p.standard_move( p.h, p.w );
    p.m[ 1 ] = p.standard_move( p.h + dh[ p.m[ 0 ] ], p.w  + dw[ p.m[ 0 ] ]);
    p.m[ 2 ] = p.standard_move( p.h + dh[ p.m[ 0 ] ] + dh[ p.m[ 1 ] ], p.w + dw[ p.m[ 0 ] ] + dw[ p.m[ 1 ] ]);
    std::cout << p << std::endl << std::flush;
    p.update();
    std::cout << p << std::endl << std::flush;

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
