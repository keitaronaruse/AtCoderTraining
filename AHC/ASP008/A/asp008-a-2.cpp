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

const bool Debug = false;

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

void print_input( std::ostream& os )
{
    os << S << " " << C << " " << H << " " << a << " " << b << std::endl;
    for( int s = 0; s < S; s ++ ) {
        for( int c = 0; c < C; c ++ ) {
            os << N.at( s ).at( c ) << " ";
        }
        os << std::endl;
    }

    for( int s = 0; s < S; s ++ ) {
        os << K.at( s ) << " ";
    }
    os << std::endl;

    for( int i = 0; i < S; i ++ ) {
        for( int j = 0; j < S; j ++ ) {
            os << A.at( i ).at( j ) << " ";
        }
        os << std::endl;
    }

    for( int i = 0; i < C; i ++ ) {
        for( int j = 0; j < C; j ++ ) {
            os << B.at( i ).at( j ) << " ";
        }
        os << std::endl;
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

int calc_X( std::vector< std::pair< int, int > >& ans )
{
    std::vector< int > t( H, -1 );
    std::vector< int > r = K;
    int X = 0;
    int h = 0;
    for( size_t i = 0; i < ans.size(); i ++ ) {
        int s = ans.at( i ).first;
        int c = ans.at( i ).second;
        if( s == -1 && t.at( h ) != -1 ) {
            r.at( t.at( h ) ) ++;
            X ++;
            t.at( h ) = 0;
        }
        else if( 0 <= s && s < S && t.at( h ) == -1 ) {
            r.at( s ) --;
            X ++;
            t.at( h ) = s;
        }
        else if( 0 <= s && s < S && t.at( h ) != -1 && t.at( h ) != s ) {
            r.at( t.at( h ) ) ++;
            r.at( s ) --;
            X += 2;
            t.at( h ) = s;
        }
        h ++;
        h %= H;
    }

    return( X );
}

int calc_Y( std::vector< std::pair< int, int > >& ans )
{
    int L = ( int ) ans.size();
    int Y = L;
    for( int s = 0; s < S; s ++ ) {
        for( int c = 0; c < C; c ++ ) {
            Y -= N.at( s ).at( c );
        }
    }

    return( Y );
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

std::vector< std::pair< int, int > > make_plan( const std::vector< std::pair< int, int > >& s_c_order )
{
    std::vector< std::pair< int, int > > plan;

    std::vector< int > hanger_on_hook( H, -1 );
    std::vector< int > hangers_available = K;
    int pos = 0, prev_s = -1, prev_c = -1;

    for( auto p : s_c_order ) {
        int s = p.first;
        int c = p.second;

        if( N.at( s ).at( c ) == 0 ) {
            continue;
        }

        // need this amount of empty hooks
        const int setup = (prev_s == -1 ? 0 : std::max( A.at( prev_s ).at( s ), B.at( prev_c ).at( c )) );
        for( int i = 0; i < setup; i ++ ) {
            plan.push_back( std::make_pair( -2, 0 ) );
            (++ pos) %= H;
        }

        // put (s, c)
        for( int n = 0; n < N.at( s ).at( c ); ) {
            if( hanger_on_hook.at( pos ) != s && hangers_available.at( s ) == 0 ) {
                // run out of hangers
                plan.push_back( std::make_pair( -2, 0 ) );
                (++ pos) %= H;
            }
            else {
                plan.push_back( std::make_pair( s, c ) );
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

    return( plan );
}

std::vector< std::pair< int, int > > make_default_order()
{
    std::vector< std::pair< int, int > > order;
    for( int s = 0; s < S; s ++ ) {
        for( int c = 0; c < C; c ++ ) {
            order.push_back( std::make_pair( s, c ) );
        }
    }
    return( order );
}

std::vector< std::pair< int, int > > make_minimum_setup_order()
{
    std::vector< std::pair< int, int > > order;

    int n = S * C;
    for( int s = 0; s < S; s ++ ) {
        for( int c = 0; c < C; c ++ ) {
            int index = s * C + c; 
            order.push_back( std::make_pair( s, c ) );
        }
    }
    return( order );
}

int main()
{
    //  Read input
    read_input();
    if( Debug ) {
        print_input( std::cerr );
    }

    //  Main
    std::vector< std::pair< int, int > > order = make_default_order();
    std::vector< std::pair< int, int > > plan = make_plan( order );

    //  Calculate the score
    int X = calc_X( plan );
    int Y = calc_Y( plan );
    int score = std::max( 1, 10000000 - a * X - b * Y );
    if( Debug ) {
        std::cerr << X << " " << Y << " " << score << std::endl;
    }

    // write answer
    write_output( plan );

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
