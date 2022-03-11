/**
* @file asp008-a-6.cpp
* @brief Asprova 8 Problem A - Automated Painting Line
  @author Keitaro Naruse
* @date 2022-03-11
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
#include <deque>

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

typedef std::pair< int, int > s_c;
typedef std::pair< s_c, s_c > s_c_s_c;

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

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( auto p : v ) {
        os << p << " ";
    }
    return( os );
}

template< class T1, class T2 >
std::ostream& operator<<( std::ostream& os, const std::vector< std::pair< T1, T2 > >& v )
{
    for( auto p : v ) {
        os << "( " << p.first << ", " << p.second << " ) ";
    }
    return( os );
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

std::vector< s_c > analyze_setup_time()
{
    std::vector< int > Asum( S, 0 );
    for( int s1 = 0; s1 < S; s1 ++ ) {
        for( int s2 = 0; s2 < S; s2 ++ ) {
            Asum.at( s1 ) += A.at( s1 ).at( s2 );
        }
    }
    auto s_it = std::min_element( Asum.begin(), Asum.end() );
    int s_min_A = s_it - Asum.begin();

    std::vector< std::pair< int, int > > A_to_index;
    for( int s = 0; s < A.at( s_min_A ).size(); s ++ ) {
        A_to_index.push_back( std::make_pair( A.at( s_min_A ).at( s ), s ) );
    }
    std::sort( A_to_index.begin(), A_to_index.end() );
    std::vector< int > s_order;
    for( auto p : A_to_index ) {
        s_order.push_back( p.second );
    }

    std::vector< int > Bsum( C, 0 );
    for( int c1 = 0; c1 < C; c1 ++ ) {
        for( int c2 = 0; c2 < C; c2 ++ ) {
            Bsum.at( c1 ) += B.at( c1 ).at( c2 );
        }
    }
    auto c_it = std::min_element( Bsum.begin(), Bsum.end() );
    int c_min_B = c_it - Bsum.begin();

    std::vector< std::pair< int, int > > B_to_index;
    for( int c = 0; c < B.at( c_min_B ).size(); c ++ ) {
        B_to_index.push_back( std::make_pair( B.at( c_min_B ).at( c ), c ) );
    }
    std::sort( B_to_index.begin(), B_to_index.end() );
    std::vector< int > c_order;
    for( auto p : B_to_index ) {
        c_order.push_back( p.second );
    }

    std::vector< s_c > order;
    for( auto c : c_order ) {
        for( auto s : s_order ) {
            order.push_back( std::make_pair( s, c ) );
        }
    }
    
    return( order );
}

std::vector< s_c > find_optimal_s_c_order()
{
    //  Find the optimal s-order
    std::vector< int > s_order;
    for( int s = 0; s < S; s ++ ) {
        s_order.push_back( s );
    }

    int min_s_setup_time = 200;
    std::vector< int > min_s_order;
    do {
        int setup_time = 0;
        for( int s = 0; s < S - 1; s ++ ) {
            setup_time += A.at( s_order.at( s ) ).at( s_order.at( s + 1 ) ); 
        }
        if( setup_time < min_s_setup_time ) {
            min_s_setup_time = setup_time;
            min_s_order = s_order;
        }
    } while( std::next_permutation( s_order.begin(), s_order.end() ) );

    std::vector< int > c_order;
    for( int c = 0; c < C; c ++ ) {
        c_order.push_back( c );
    }
    int min_c_setup_time = 400;
    std::vector< int > min_c_order;
    do {
        int setup_time = 0;
        for( int c = 0; c < C - 1; c ++ ) {
            setup_time += B.at( c_order.at( c ) ).at( c_order.at( c + 1 ) ); 
        }
        if( setup_time < min_c_setup_time ) {
            min_c_setup_time = setup_time;
            min_c_order = c_order;
        }
    } while( std::next_permutation( c_order.begin(), c_order.end() ) );

    std::vector< s_c > order;
    for( int c = 0; c < C; c ++ ) {
        for( int s = 0; s < S; s ++ ) {
            order.push_back( std::make_pair( s_order.at( s ), c_order.at( c ) ) );
        }
    }
    return( order );
}

std::vector< std::pair< int, int > > make_min_X_plan( const std::vector< std::pair< int, int > >& s_c_order )
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

std::vector< std::pair< int, int > > make_min_L_plan( const std::vector< std::pair< int, int > >& s_c_order )
{
    //  Ns,c = [ 0, 5000 ]: The number of products
    std::vector< std::vector< int > > n = N;

    std::vector< std::pair< int, int > > plan;
    std::vector< int > hanger_on_hook( H, -1 );
    std::vector< int > hangers_available = K;
    int pos = 0, prev_s = -1, prev_c = -1;

    std::deque< s_c > s_c_memory;
    for( auto sc : s_c_order ) {
        s_c_memory.push_back( sc );
    }

    while( !s_c_memory.empty() ) {
        s_c sc = s_c_memory.front();
        int s = sc.first;
        int c = sc.second;

        //  No production required
        if( n.at( s ).at( c ) == 0 ) {
            s_c_memory.pop_front();
            continue;
        }

        // need this amount of empty hooks
        const int setup = ( prev_s == -1 ) ? 0 : std::max( A.at( prev_s ).at( s ), B.at( prev_c ).at( c ) );
        for( int i = 0; i < setup; i ++ ) {
            plan.push_back( std::make_pair( -2, 0 ) );
            ( ++ pos ) %= H;
        }

        // put (s, c)
        while( n.at( s ).at( c ) != 0 ) {
            if( hanger_on_hook.at( pos ) != s && hangers_available.at( s ) == 0 ) {
                //  Skip and go to next order
                s_c_memory.pop_front();
                s_c n_sc = s_c_memory.front();
                s_c_memory.push_front( sc );
                s_c_memory.push_front( n_sc );
                s_c_memory.push_front( sc );
            }
            else {
                plan.push_back( std::make_pair( s, c ) );
                n.at( s ).at( c ) -- ;
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
        s_c_memory.pop_front();
    }

    return( plan );
}

int main()
{
    //  Read input
    read_input();

    //  Main
    // std::vector< s_c > order = make_C_S_order();
    std::vector< s_c > order = find_optimal_s_c_order();
    std::vector< std::pair< int, int > > X_plan = make_min_X_plan( order );
    // std::vector< std::pair< int, int > > L_plan = make_min_L_plan( order );
    std::vector< std::pair< int, int > > best_plan = X_plan;
    
    int max_score = calculate_score( best_plan );
    for( int k = 10; k >= 2; k -= 1 ) {
        for( int i = 1; i < S * C - k; i ++ ) {
            std::vector< s_c > new_order = two_opt( order, i, i + k - 1 );
            X_plan = make_min_X_plan( new_order );
            int score = calculate_score( X_plan );
            if( max_score < score ) {
                max_score = score;
                best_plan = X_plan;
                order = new_order;
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
