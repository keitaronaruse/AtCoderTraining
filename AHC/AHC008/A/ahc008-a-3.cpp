/**
* @file ahc008-a-3.cpp
* @brief AHC008 Problem A - Territory
* @author Keitaro Naruse
* @date 2022-02-20
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc008/tasks/ahc008_a
*/

// # Solution
// - Humans make walls
// - Update the motions of the pets

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>

const bool Debug = true;

//  Room size
const int H = 30, W = 30;
//  The number of turns
const int T = 300;

//  The maps
std::vector< std::vector< char > > map_obst;
std::vector< std::vector< std::list< int > > > map_pets, map_humans;

//  Zones
//  9: d
const int Z = 10;
std::vector< int > hh = {  9,  9,  9, 19, 19, 19, 30, 30, 30, 15 };
std::vector< int > hw = {  1, 11, 21,  1, 11, 21,  9, 19, 30, 15 };

const int A = 3;
class Pet {
    public:
        int h, w, t;
        std::vector< char > m;
    public:
        Pet() : h( -1 ), w( -1 ), t( -1 ), m( A, ' ' ) { }
        Pet( int ph, int pw, int pt ) : h( ph ), w( pw ), t( pt ), m( A, ' ' ) {
            ;
        }
        Pet( const Pet& r ) : h( r.h ), w( r.w ), t( r.t ), m( r.m ) {
            ;
        }
        Pet& operator=( const Pet& r ) {
            h = r.h;
            w = r.w;
            t = r.t;
            m = r.m;
            return( *this );
        }
        void read( std::string& actions ) {
            m = { ' ', ' ', ' ' };
            for( int k = 0; k < actions.size(); k ++ ) {
                m.at( k ) = actions.at( k );
            }
        }
        void update() {
            for( int k = 0; k < A; k ++ ) {
                switch( m.at( k ) ) {
                    case 'U': h -= 1; break;
                    case 'D': h += 1; break;
                    case 'L': w -= 1; break;
                    case 'R': w += 1; break;
                    default: break;
                }
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
        //  zone
        int z;
        std::queue< char > plan;
        //  s = 1: Do nothing
        //  s = 2: Go zone position
        //  s = 3: Make walls
        int s;
    public:
        Human() : h( -1 ), w( -1 ), m( ' ' ), z( -1 ), s( -1 ) {}
        void action() {
            //  '.'
            //  'U', 'D', 'L', 'R'
            //  'u', 'd', 'l', 'r'
            switch( s ) {
                case 0: do_nothing(); break;
                case 1: do_nothing(); break;
                case 2: go_to_zone(); break;
                case 3: make_wall(); break;
            }
        }
        void write() {
            std::cout << m;
        }
        void update() {
            switch( m ) {
                case 'U': 
                    if( map_obst.at( h - 1 ).at( w ) == '.' ) {
                        h -= 1;
                    }
                break;
                case 'D':
                    if( map_obst.at( h + 1 ).at( w ) == '.' ) {
                        h += 1;
                    }
                break;
                case 'L':
                    if( map_obst.at( h ).at( w - 1 ) == '.' ) {
                        w -= 1;
                    }
                break;
                case 'R':
                    if( map_obst.at( h ).at( w + 1 ) == '.' ) {
                        w += 1;
                    }
                break;
                case 'u': map_obst.at( h - 1 ).at( w ) = '#'; break;
                case 'd': map_obst.at( h + 1 ).at( w ) = '#'; break;
                case 'l': map_obst.at( h ).at( w - 1 ) = '#'; break;
                case 'r': map_obst.at( h ).at( w + 1 ) = '#'; break;
                default: break;
            }
        }
        void make_plan() {
            switch( z ) {
                case 0:
                case 1:
                case 3:
                case 4:
                    for( int i = 0; i < 8; i ++ ) {
                        plan.push('d');
                        plan.push('R');
                    }
                    plan.push('d');
                    for( int i = 0; i < 8; i ++ ) {
                        plan.push('r');
                        plan.push('U');
                    }
                    plan.push('r');
                break;

                case 2:
                case 5:
                    for( int i = 0; i < 9; i ++ ) {
                        plan.push('d');
                        plan.push('R');
                    }
                    plan.push('d');
                break;

                case 6:
                case 7:
                    for( int i = 0; i < 8; i ++ ) {
                        plan.push('r');
                        plan.push('U');
                    }
                    plan.push('r');
                break;
                case 8:
                case 9:
                break;
                default:
                break;
            }
        }
        //  s = 1
        void do_nothing() {
            m = '.';
        }
        //  s = 2
        void go_to_zone() {
            if( h == hh.at( z ) && w == hw.at( z ) ) {
                m = '.';
                s = 1;
                return;
            }
            if( hh.at( z ) < h ) {
                m = 'U';
            }
            else if( hh.at( z ) > h ) {
                m = 'D';
            }
            else if( hw.at( z ) < w ) {
                m = 'L';
            }
            else if( hw.at( z ) > w ) {
                m = 'R';
            }
            else {
                m = '.';
            }
        }
        //  s = 3
        void make_wall() {
            if( plan.empty() ) {
                s = 1;
            }
            else {
                int u = h, v = w;
                bool wall_build = false;
                m = plan.front();
                switch( m ) {
                    case 'u': wall_build = true; u = h - 1; v = w; break;
                    case 'd': wall_build = true; u = h + 1; v = w; break;
                    case 'l': wall_build = true; u = h; v = w - 1; break;
                    case 'r': wall_build = true; u = h; v = w + 1; break;
                }
                if( wall_build ) {
                    if( is_placable( u, v ) ) {
                        plan.pop();
                    }
                    else {
                        m = '.';
                    }
                }
                else {
                    plan.pop();
                }
            }
        }
        bool is_placable( int u, int v ) {
            if( map_humans.at( u ).at( v ).empty() 
                && map_pets.at( u ).at( v ).empty() 
                && map_pets.at( u - 1 ).at( v ).empty() 
                && map_pets.at( u + 1 ).at( v ).empty()
                && map_pets.at( u ).at( v - 1 ).empty() 
                && map_pets.at( u ).at( v + 1 ).empty()
            ) {
               return( true );
            }
            return( false );
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

class Planner {
};

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
        humans.at( j ).s = 0;
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
    //  Read input
    read_input();
    //  Make a map
    make_map();
    //  Update pets
    update_map_pets();
    //  Update humans
    update_map_human();

    //  Plan: Zone assignment
    for( int j = 0; j < M; j ++) {
        //  Assigne zone
        humans.at( j ).z = j;
        //  Male a plan
        humans.at( j ).make_plan();
        //  Go home position
        humans.at( j ).s = 2;
    }

    //  Main
    for( int t = 0; t < T; t ++ ) {
        if( Debug ) {
            print_map( std::cout );
        }
        if( t == 60 ) {
            //  make walls
            for( int j = 0; j < M; j ++ ) {
                humans.at( j ).s = 3;
            }
        }
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
                std::cerr << pet_action << " ";
                pets.at( i ).read( pet_action );
                pets.at( i ).update();
            }
            std::cerr << std::endl;
            //  Update pets
            update_map_pets();
        }
    }
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }    
    return( 0 );
}
