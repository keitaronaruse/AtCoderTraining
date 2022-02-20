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
#include <list>
#include <algorithm>
#include <random>

const bool Debug = false;

//  Room size
const int H = 30, W = 30;
//  The number of turns
const int T = 300;

//  The maps
std::vector< std::vector< char > > map_obst;
std::vector< std::vector< std::list< int > > > map_pets, map_humans;

//  Moves: U, D, L, R
const int K = 4;
const std::vector< int > dh = { -1,  1,  0,  0 }, dw = {  0,  0,  -1, 1 };

//  Random generator
std::default_random_engine engine;

const int A = 3;
class Pet {
    public:
        int h, w, t;
        int K;
        std::vector< char > m;
    public:
        Pet() : h( -1 ), w( -1 ), t( -1 ), m( A, ' ' ), K( 0 ) { }
        Pet( int ph, int pw, int pt ) : h( ph ), w( pw ), t( pt), m( A, ' ' ) {
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
        }
        Pet( const Pet& r ) : h( r.h ), w( r.w ), t( r.t ), K( r.K ), m( r.m ) {
            ;
        }
        Pet& operator=( const Pet& r ) {
            h = r.h;
            w = r.w;
            t = r.t;
            K = r.K;
            m = r.m;
            return( *this );
        }
        void read( std::string& actions ) {
            for( int k = 0; k < K; k ++ ) {
                m.at( k ) = actions.at( k );
            }
        }
        void update() {
            for( int k = 0; k < K; k ++ ) {
                int index = -1;
                switch( m.at( k ) ) {
                    case 'U': index = 0; break;
                    case 'D': index = 1; break;
                    case 'L': index = 2; break;
                    case 'R': index = 3; break;
                    default: index = -1; break;
                }
                h += dh.at( index );
                w += dw.at( index );
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
        char m;
    public:
        void action() {
            //  '.'
            //  'U', 'D', 'L', 'R'
            //  'u', 'd', 'l', 'r'
            m = '.';
        }
        void write() {
            std::cout << m;
        }
        void update() {
            int index = -1;
            switch( m ) {
                case 'U': index = 0; break;
                case 'D': index = 1; break;
                case 'L': index = 2; break;
                case 'R': index = 3; break;
                default: index = -1; break;
            }
            if( index != -1 ) {
                h += dh.at( index );
                w += dw.at( index );
            }
        }
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
        int rh = 0, rw = 0, rt = 0;
        std::cin >> rh >> rw >> rt;
        pets.at( i ) = Pet( rh, rw, rt);
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
    map_obst = std::vector< std::vector< char > >( H + 2, std::vector< char >( W + 2, '.' ) );
    for( int h = 0; h < H + 2; h ++ ) {
        map_obst.at( h ).at( 0 ) = '#';
        map_obst.at( h ).at( W + 1 ) = '#';
    }
    for( int w = 0; w < W + 2; w ++ ) {
        map_obst.at( 0 ).at( w ) = '#';
        map_obst.at( H + 1 ).at( w ) = '#';
    }
     
    map_pets = std::vector< std::vector< std::list< int > > >( 
        H + 2, 
        std::vector< std::list< int > >( W + 2 ) 
    );
    map_humans = std::vector< std::vector< std::list< int > > >( 
        H + 2, 
        std::vector< std::list< int > >( W + 2 ) 
    );
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

void update_map_human()
{
    for( int h = 0; h < H + 2; h ++ ) {
        for( int w = 0; w < W + 2; w ++ ) {
            map_humans.at( h ).at( w ).clear();
        }
    }
    for( int j = 0; j < M; j ++ ) {
        int h = humans.at( j ).h;
        int w = humans.at( j ).w;
        map_humans.at( h ).at( w ).push_back( j );
    }
}

void update_map_pets()
{
    for( int h = 0; h < H + 2; h ++ ) {
        for( int w = 0; w < W + 2; w ++ ) {
            map_pets.at( h ).at( w ).clear();
        }
    }
    for( int i = 0; i < N; i ++ ) {
        int h = pets.at( i ).h;
        int w = pets.at( i ).w;
        int t = pets.at( i ).t;
        map_pets.at( h ).at( w ).push_back( t );
    }
}

void print_map( std::ostream& os )
{
    for( int h = 0; h < H + 2; h ++ ) {
        for( int w = 0; w < W + 2; w ++ ) {
            if( !map_humans.at( h ).at( w ).empty() ) {
                os << "H";
            }
            else if( !map_pets.at( h ).at( w ).empty() ) {
                char ch = ' ';
                auto t = map_pets.at( h ).at( w ).front();
                switch( t ) {
                    case 1: ch = 'C'; break;
                    case 2: ch = 'P'; break;
                    case 3: ch = 'R'; break;
                    case 4: ch = 'D'; break;
                    case 5: ch = 'C'; break;
                    default: ch = ' '; break;
                }
                os << ch;
            }
            else {
                os << map_obst.at( h ).at( w );
            }
        }
        os << std::endl;
    }
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
    //  Update pets
    update_map_pets();
    //  Update humans
    update_map_human();
    //  Main
    for( int t = 0; t < T; t ++ ) {
        //  Human actions
        for( int j = 0; j < M; j ++ ) {
            humans.at( j ).action();
            humans.at( j ).write();
            humans.at( j ).update();
        }
        std::cout << std::endl;
        //  Update humans
        update_map_human();
        
        //  Pet motions
        if( t < T - 1 ) {
            for( int i = 0; i < N; i ++ ) {
                std::string pet_action;
                std::cin >> pet_action;
                if( Debug ) {
                    std::cout << pet_action << " ";
                }
                pets.at( i ).read( pet_action );
                pets.at( i ).update();
            }
            if( Debug ) {
                std::cout << std::endl;
            }
            //  Update pets
            update_map_pets();
        }
    }
    if( Debug ) {
        print_map( std::cout );
    }
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
