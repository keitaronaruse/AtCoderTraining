/**
* @file asp008-a-4.cpp
* @brief Asprova 8 Problem A - Automated Painting Line
  @author Keitaro Naruse
* @date 2022-03-10
* @copyright MIT License
* @details https://atcoder.jp/contests/asprocon8/tasks/asprocon8_a
*/

// # Solution
// - Determine the order of (s,c) as the minimum setup time 
// - Solve the above problem by greedy + 2opt

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <random>

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

//  As,s = [ 0/1, 20 ]: The setting time of shapes
std::vector< std::vector< int > > A;

//  Bc,c = [ 0/5, 40 ]: The setting time of colors
std::vector< std::vector< int > > B;

//  Wn,n = [ 0/5, 40]
typedef std::pair< int, int > s_c;
typedef std::pair< s_c, s_c > s_c_s_c;
std::map< s_c_s_c, int > W; 

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

int calc_X( const std::vector< std::pair< int, int > >& ans )
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

int calc_Y( const std::vector< std::pair< int, int > >& ans )
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

std::vector< std::pair< int, int > > make_S_C_order()
{
    std::vector< std::pair< int, int > > order;
    for( int s = 0; s < S; s ++ ) {
        for( int c = 0; c < C; c ++ ) {
            order.push_back( std::make_pair( s, c ) );
        }
    }
    return( order );
}

std::vector< std::pair< int, int > > make_C_S_order()
{
    std::vector< std::pair< int, int > > order;
    for( int c = 0; c < C; c ++ ) {
        for( int s = 0; s < S; s ++ ) {
            order.push_back( std::make_pair( s, c ) );
        }
    }
    return( order );
}

void make_setup_time_matrix()
{
    for( int s1 = 0; s1 < S; s1 ++ ) {
        for( int c1 = 0; c1 < C; c1 ++ ) {
            s_c p = std::make_pair( s1, c1 );
            for( int s2 = 0; s2 < S; s2 ++ ) {
                for( int c2 = 0; c2 < C; c2 ++ ) {
                    s_c q = std::make_pair( s2, c2 );
                    s_c_s_c pq = std::make_pair( p, q );
                    int cost = std::max( A.at( s1 ).at( s2 ), B.at( c1 ).at( c2 ) );
                    W.insert( std::make_pair( pq, cost ) ); 
                }
            }
        }
    }

    if( Debug ) {
        for( int s1 = 0; s1 < S; s1 ++ ) {
            for( int c1 = 0; c1 < C; c1 ++ ) {
                s_c p = std::make_pair( s1, c1 );
                for( int s2 = 0; s2 < S; s2 ++ ) {
                    for( int c2 = 0; c2 < C; c2 ++ ) {
                        s_c q = std::make_pair( s2, c2 );
                        s_c_s_c pq = std::make_pair( p, q );
                        std::cerr << "( " << s1 << ", " << c1 << " ) ( " << s2 << ", " << c2 << " ) = " << W.at( pq ) << std::endl; 
                    }
                }
            }
        }
    }
}

template< class T, class S >
std::ostream& operator<<( std::ostream& os, const std::map< T, S >& m )
{
    for( auto p : m ) {
        os << p.second << " ";
    }
    return( os );
}

std::ostream& operator<<( std::ostream& os, const std::vector< s_c >& v )
{
    for( auto p : v ) {
        os << "( " << p.first << ", " << p.second << " ) ";
    }
    return( os );
}

std::vector< std::pair< int, int > > make_minimum_setup_order( int s1, int c1 )
{
    std::vector< s_c > order;
    std::map< s_c, bool > used;
    for( int s = 0; s < S; s ++ ) {
        for( int c = 0; c < C; c ++ ) {
            s_c p = std::make_pair( s, c );
            used.insert( std::make_pair( p, false ) );
        }
    }
    int n = S * C;

    //  Start values
    s_c p = std::make_pair( s1, c1 );
    used.at( p ) = true;
    order.push_back( p );

    //  Loop
    for( int k = 1; k < n; k ++ ) {
        int min_setup = 100;
        s_c min_q;
        for( auto r : used ) {
            s_c q = r.first;
            if( !r.second ) {
                s_c_s_c pq = std::make_pair( p, q );
                if( W.at( pq ) < min_setup ) {
                    min_setup = W.at( pq );
                    min_q = q;
                }
            }
        }
        used.at( min_q ) = true;
        order.push_back( min_q );
        p = min_q;
    }

    return( order );
}

int calculate_score( const std::vector< std::pair< int, int > >& plan )
{
    int X = calc_X( plan );
    int Y = calc_Y( plan );
    int score = std::max( 1, 10000000 - a * X - b * Y );
    return( score );
}

std::vector< s_c > two_opt( const std::vector< s_c >& original_order, int l, int r )
{
    std::vector< s_c > modified_order = original_order;

    for( int k = 0; k <= r - l; k ++ ) {
        modified_order.at( l + k ) = original_order.at( r - k );
    }
    return( modified_order );
}

int main()
{
    //  Read input
    read_input();
    if( Debug ) {
        print_input( std::cerr );
    }

    //  Preprocess
    make_setup_time_matrix();

    //  Main
    std::vector< s_c > order = make_C_S_order();
    std::vector< std::pair< int, int > > plan = make_plan( order ), best_plan = plan;
    int max_score = calculate_score( best_plan );
    for( int s = 0; s < S; s ++ ) {
        for( int c = 0; c < C; c ++ ) {
            order = make_minimum_setup_order( s, c );
            plan = make_plan( order );
            int score = calculate_score( plan );
            if( max_score < score ) {
                max_score = score;
                best_plan = plan;
            }
            for( int k = 0; k < S * C - 8; k += 6 ) {
                std::vector< s_c > new_order = two_opt( order, k, k + 7 );
                plan = make_plan( new_order );
                score = calculate_score( plan );
                if( max_score < score ) {
                    max_score = score;
                    best_plan = plan;
                    order = new_order;
                }
            }
            for( int k = 0; k < S * C - 4; k += 3 ) {
                std::vector< s_c > new_order = two_opt( order, k, k + 3 );
                plan = make_plan( new_order );
                score = calculate_score( plan );
                if( max_score < score ) {
                    max_score = score;
                    best_plan = plan;
                    order = new_order;
                }
            }
        }
    } 
    
    // write answer
    write_output( best_plan );

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
