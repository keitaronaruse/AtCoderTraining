/**
* @file ahc008-a-8.cpp
* @brief AHC008 Problem A - Territory
* @author Keitaro Naruse
* @date 2022-02-26
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc008/tasks/ahc008_a
*/

// # Solution
// - Humans make walls
// - Update the motions of the pets

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <fstream>
#include <cstdio>

const bool Debug = false;

//  Room size
const int H = 30, W = 30;
//  The number of turns
const int T = 300;

//  The number of pets 
int N = 0;
//  The number of humans 
int M = 0;

//  The maps
std::vector< std::vector< char > > map_obst;
std::vector< std::vector< std::list< int > > > map_pets, map_humans;

//  Zones
const int Z = 9;
class Zone {
    public:
        int zu, zd, zl, zr;
        int hh, hw;
        int num_pets;
    public:
        bool is_empty() {
            for( int h = zu; h <= zd; h ++ ) {
                for( int w = zl; w <= zr; w ++ ) {
                    if( !map_pets.at( h ).at( w ).empty() ) {
                        return( false );
                    }
                }
            }
            return( true );
        }
        void update() {
            num_pets = 0;
            for( int h = zu; h <= zd; h ++ ) {
                for( int w = zl; w <= zr; w ++ ) {
                    num_pets += map_pets.at( h ).at( w ).size();
                }
            }
        }
};
std::vector< Zone > zones;

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
        void read( const std::string& actions ) {
            m = { ' ', ' ', ' ' };
            for( size_t k = 0; k < actions.size(); k ++ ) {
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
        friend std::ostream& operator<<( std::ostream& os, const Pet& p ) {
            os << p.h << " " << p.w << " " << p.t << " " 
                << p.m.at( 0 ) << " " << p.m.at( 1 ) << " " << p.m.at( 2 ) << " "; 
            return( os );
        }
};

class Human {
    public:
        int h, w;
        char m;
    public:
        //  zone
        int z;
        std::queue< char > plan;
        int s;
    public:
        Human() : h( -1 ), w( -1 ), m( ' ' ), z( -1 ), s( -1 ) {}
        void action() {
            //  '.'
            //  'U', 'D', 'L', 'R'
            //  'u', 'd', 'l', 'r'
            switch( s ) {
                case 0: do_nothing(); break;
                case 1: go_to_zone(); break;
                case 2: do_nothing(); break;
                case 3: make_first_wall(); break;
                case 4: do_nothing(); break;
                case 5: make_second_wall(); break;
                // case 6: do_nothing(); break;
                case 6: wait_and_move_to_empty_zone(); break;
                case 7: close_wall(); break;
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
        //  s = 0, 2, 4, 6, 8
        void do_nothing() {
            m = '.';
        }
        //  s = 1
        void go_to_zone() {
            if( h == zones.at( z ).hh && w == zones.at( z ).hw ) {
                m = '.';
                s = 2;
                return;
            }
            if( zones.at( z ).hh < h ) {
                m = 'U';
            }
            else if( zones.at( z ).hh > h ) {
                m = 'D';
            }
            else if( zones.at( z ).hw < w ) {
                m = 'L';
            }
            else if( zones.at( z ).hw > w ) {
                m = 'R';
            }
            else {
                m = '.';
            }
        }
        void move_or_build() {
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
        void move_or_build_if_empty() {
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
                if( is_placable( u, v ) && zones.at( z ).num_pets == 0 ) {
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

        //  s = 3
        void make_first_wall() {
            if( plan.empty() ) {
                m = '.';
                s = 4;
            }
            else {
                move_or_build();
            }
        }
        //  s = 5
        void make_second_wall() {
            if( plan.empty() ) {
                m = '.';
                s = 6;
            }
            else {
                move_or_build();
            }
        }
        //  s = 6
        void wait_and_move_to_empty_zone() {
            switch( z ) {
                case 1:
                    if( zones.at( 1 ).num_pets == 0 ) {
                        plan.push('.');
                        plan.push('.');
                        plan.push('r');
                    }
                    else if( zones.at( 2 ).num_pets == 0 ) {
                        plan.push('R');
                        plan.push('R');
                        plan.push('l');
                    }
                break; 
                case 2:
                    if( zones.at( 2 ).num_pets == 0 ) {
                        plan.push('.');
                        plan.push('.');
                        plan.push('.');
                    }
                    else if( zones.at( 1 ).num_pets == 0 ) {
                        plan.push('L');
                        plan.push('L');
                        plan.push('.');
                    }
                break;

                case 4:
                    if( zones.at( 4 ).num_pets == 0 ) {
                        plan.push('.');
                        plan.push('.');
                        plan.push('r');
                    }
                    else if( zones.at( 5 ).num_pets == 0 && 5 < M ) {
                        plan.push('R');
                        plan.push('R');
                        plan.push('l');
                    }
                break;

                case 5:
                    if( zones.at( 5 ).num_pets == 0 ) {
                        plan.push('.');
                        plan.push('.');
                        plan.push('.');
                    }
                    else if( zones.at( 4 ).num_pets == 0 ) {
                        plan.push('L');
                        plan.push('L');
                        plan.push('.');
                    }
                break;

                case 7:
                    if( zones.at( 7 ).num_pets == 0 ) {
                        plan.push('.');
                        plan.push('.');
                        plan.push('.');
                    }
                    else if( zones.at( 8 ).num_pets == 0  && 8 < M ) {
                        plan.push('L');
                        plan.push('L');
                        plan.push('.');
                    }
                break;

                case 8:
                    if( zones.at( 8 ).num_pets == 0 ) {
                        plan.push('.');
                        plan.push('.');
                        plan.push('.');
                    }
                    else if( zones.at( 7 ).num_pets == 0 ) {
                        plan.push('L');
                        plan.push('L');
                        plan.push('.');
                    }
                break;

                case 0: case 3: case 6: 
                    m = '.';
                    plan.push('r');
                break;

                default: break;
            }
            s = 7;
        }
        //  s = 7
        void close_wall() {
            if( plan.empty() ) {
                m = '.';
                s = 0;
            }
            else {
                move_or_build();
                // move_or_build_if_empty();
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
        void plan_a( int n ) {
            for( int i = 0; i < n; i ++ ) {
                plan.push( 'd' );
                plan.push( 'R' );
            }
            plan.push('d');
        }
        void plan_b( int n ) {
            for( int i = 0; i < n; i ++ ) {
                plan.push( 'r' );
                plan.push( 'U' );
            }
        }
        void move_up( int n ) {
            for( int i = 0; i < n; i ++ ) {
                plan.push( 'U' );
            }
        }
        void move_down( int n ) {
            for( int i = 0; i < n; i ++ ) {
                plan.push( 'D' );
            }
        }
        void move_left( int n ) {
            for( int i = 0; i < n; i ++ ) {
                plan.push( 'L' );
            }
        }
        void move_right( int n ) {
            for( int i = 0; i < n; i ++ ) {
                plan.push( 'R' );
            }
        }
};

std::ostream& operator<<( std::ostream& os, const Human& h )
{
    os << h.h << " " << h.w;
    return( os );
}

//  Pets: pets.at( i )
std::vector< Pet > pets;

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

    //  Humans
    std::cin >> M;
    humans = std::vector< Human >( M );

    for( int j = 0; j < M; j ++ ) {
        std::cin >> humans.at( j ).h >> humans.at( j ).w;
        humans.at( j ).s = 0;
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

void make_zones()
{
    zones = std::vector< Zone >( Z );
    //  zu, zd, zl, zr, hh, hw
    zones.at( 0 ) = {  1, 10,  1, 10,  9,  1 };
    zones.at( 1 ) = {  1, 10, 11, 20,  9, 11 };
    zones.at( 2 ) = {  1, 10, 21, 30,  9 ,21 };
    zones.at( 3 ) = { 11, 20,  1, 10, 19,  1 };
    zones.at( 4 ) = { 11, 20, 11, 20, 19, 11 };
    zones.at( 5 ) = { 11, 20, 21, 30, 19, 21 };
    zones.at( 6 ) = { 21, 30,  1, 10, 30,  9 };
    zones.at( 7 ) = { 21, 30, 11, 20, 30, 19 };
    zones.at( 8 ) = { 21, 30, 21, 30, 30, 30 };
}

bool are_all_humans_in_state( int s )
{
    for( int j = 0; j < M; j ++ ) {
        if( humans.at( j ).s != s ) {
            return( false );
        }
    }
    return( true );
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
    //  Make zones
    make_zones();
    //  Plan: Zone assignment
    for( int j = 0; j < M; j ++) {
        //  Assign zone
        humans.at( j ).z = j;
        if( j == Z ) {
            humans.at( j ).z = 8;
        }
        //  Go home position
        humans.at( j ).s = 1;
    }

    //  Main
    for( int t = 0; t < T; t ++ ) {
        //  Update the number of pets in each of the zones
        for( int k = 0; k < Z; k ++ ) {
            zones.at( k ).update();
        }
        //  Update human states
        //  From 2: go_to_zone to 3: make_first_wall
        if( are_all_humans_in_state( 2 ) ) {
            //  Put the plan_a and make first wall
            for( int j = 0; j < M; j ++ ) {
                switch( j ) {
                    case 0: case 1: 
                    case 3: case 4: 
                        humans.at( j ).plan_a( 8 ); 
                    break;
                    case 2: case 5:
                        humans.at( j ).plan_a( 9 ); 
                    break;
                    default: break;
                }
                humans.at( j ).s = 3;
            }
        }
        //  Other states
        for( int j = 0; j < M; j ++ ) {
            switch( humans.at( j ).s ) {
                case 4:
                    switch( j ) {
                        case 0: case 1: case 3: case 4: 
                            humans.at( j ).plan_b( 8 ); 
                        break;
                        case 6: case 7:
                            humans.at( j ).plan_b( 9 ); 
                        break;
                        case 2: case 5:
                            humans.at( j ).move_up( 8 ); 
                            humans.at( j ).move_left( 9 ); 
                        break;
                        case 8:
                        case 9:
                            humans.at( j ).move_up( 9 ); 
                            humans.at( j ).move_left( 9 ); 
                        break;
                        default: break;
                    }
                    humans.at( j ).s = 5;
                break; 
                default: break;
            }
        }
        // if( 270 <= t ) {
        //     //  force to make second wall
        //     for( int j = 0; j < M; j ++ ) {
        //         if( humans.at( j ).s == 5 ) {
        //             humans.at( j ).s = 6;
        //         }
        //     }
        // }
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
