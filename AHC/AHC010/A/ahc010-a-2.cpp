/**
* @file ahc010-a-2.cpp
* @brief AHC010 Problem A - Loop Lines
* @author Keitaro Naruse
* @date 2022-04-24
* @copyright MIT License
* @details https://atcoder.jp/contests/ahc010/tasks/ahc010_a
*/

// # Solution

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

template< class T >
std::ostream& operator<<( std::ostream& os, const std::pair< T, T >& p )
{
    os << "( " << p.first << ", " << p.second << " ) ";
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< std::vector< T > >& vv )
{
    for( const auto& v : vv ) {
        os << v << std::endl;
    }
    return( os );
}

template< class T >
std::ostream& operator<<( std::ostream& os, const std::vector< T >& v )
{
    for( const auto& k : v ) {
        os << k << " ";
    }
    return( os );
}

bool is_loop( const std::vector< std::vector< int > >& t, const std::vector< std::vector< int > >& p, int i, int j )
{
    for( int h = 0; h < p.size(); h ++ ) {
        for( int w = 0; w < p.at( h ).size(); w ++ ) {
            if( p.at( h ).at( w ) == -1 ) {
                continue;
            }

            if( 0 <= p.at( h ).at( w ) && p.at( h ).at( w ) <= 3 && 
                0 <= t.at( i + h ).at( j + w ) && t.at( i + h ).at( j + w ) <= 5 ) {
                    continue;
            }
            if( 4 <= p.at( h ).at( w ) && p.at( h ).at( w ) <= 5 && 
                4 <= t.at( i + h ).at( j + w ) && t.at( i + h ).at( j + w ) <= 5 ) {
                    continue;
            }

            return( false );
        }
    }
    return( true );
}

void put_loop( std::vector< std::vector< int > >& rails, const std::vector< std::vector< int > >& p, int i, int j )
{
    for( int h = 0; h < p.size(); h ++ ) {
        for( int w = 0; w < p.at( h ).size(); w ++ ) {
            rails.at( i + h ).at( j + w) = p.at( h ).at( w );
        }
    }
}

bool is_empty( const std::vector< std::vector< int > >& rails, const std::vector< std::vector< int > >& p, int i, int j )
{
    for( int h = 0; h < p.size(); h ++ ) {
        for( int w = 0; w < p.at( h ).size(); w ++ ) {
            if( rails.at( i + h ).at( j + w ) != -1 ) {
                return( false );
            }
        }
    }
    return( true );
}

int main()
{
    //  Constant
    const int N = 30;
    //  Read tij
    std::vector< std::vector< int > > t( N, std::vector< int >( N, 0 ) );

    for( int i = 0; i < N; i ++ ) {
        std::string s;
        std::cin >> s;
        for( int j = 0; j < N; j ++ ) {
            t.at( i ).at( j ) = s.at( j ) - '0';
        }
    }
    //  Main
    std::vector< std::vector< int > > rails( N, std::vector<int>( N, -1 ) );
    std::vector< std::pair< int, int > > m;
    int num_loops = 0;

    //  Find 55 loop
    std::vector< std::vector< int > > p55 = {
        {  2,  1,  2,  1, -1 },
        {  3,  5,  0,  3,  1 },
        {  2,  0, -1,  2,  0 },
        {  3,  1,  2,  5,  1 },
        { -1,  3,  0,  3,  0 },
    };
    if( num_loops < 2 ) {
        for( int i = 0; i < N - 4; i ++ ) {
            for( int j = 0; j < N - 4; j ++ ) {
                if( is_loop( t, p55, i, j ) ) {
                    m.push_back( std::make_pair( i, j) );
                }
            }
        }
        //  Put the solution
        for( int k = 1; k < m.size(); k ++ ) {
            if( is_empty( rails, p55, m.at( k ).first, m.at( k ).second ) ) {
                put_loop( rails, p55, m.at( k ).first, m.at( k ).second );
                num_loops ++;
                if( num_loops >= 2 ) {
                    break;
                }
            }
        }
    }

    //  Find 37 loop
    std::vector< std::vector< int > > p37 = {
        {  2,  1,  2,  1,  2,  1, -1 },
        {  3,  5,  4,  5,  4,  5,  1 },
        { -1,  3,  0,  3,  0,  3,  0 }
    };
    if( num_loops < 2 ) {
        m.clear();
        for( int i = 0; i < N - 2; i ++ ) {
            for( int j = 0; j < N - 6; j ++ ) {
                if( is_loop( t, p37, i, j ) ) {
                    m.push_back( std::make_pair( i, j ) );
                }
            }
        }
        //  Put the solution
        for( int k = 0; k < m.size(); k ++ ) {
            if( is_empty( rails, p37, m.at( k ).first, m.at( k ).second ) ) {
                put_loop( rails, p37, m.at( 1 ).first, m.at( k ).second );
                num_loops ++;
                if( num_loops >= 2 ) {
                    break;
                }
            }
        }
    }

    //  Find 73 loop
    std::vector< std::vector< int > > p73 = {
        { -1,  2,  1 },
        {  2,  4,  0 },
        {  3,  5,  1 },
        {  2,  4,  0 },
        {  3,  5,  1 },
        {  2,  4,  0 },
        {  3,  0, -1 },
    };
    if( num_loops < 2 ) {
        m.clear();
        for( int i = 0; i < N - 6; i ++ ) {
            for( int j = 0; j < N - 2; j ++ ) {
                if( is_loop( t, p73, i, j ) ) {
                    m.push_back( std::make_pair( i, j ) );
                }
            }
        }
        //  Put the solution
        for( int k = 0; k < m.size(); k ++ ) {
            if( is_empty( rails, p73, m.at( k ).first, m.at( k ).second ) ) {
                put_loop( rails, p73, m.at( k ).first, m.at( k ).second );
                num_loops ++;
                if( num_loops >= 2 ) {
                    break;
                }
            }
        }
    }

    //  Find 35 loop
    std::vector< std::vector< int > > p35 = {
        {  2,  1,  2,  1, -1 },
        {  3,  5,  4,  5,  1 },
        { -1,  3,  0,  3,  0 }
    };
    if( num_loops < 2 ) {
        m.clear();
        for( int i = 0; i < N - 2; i ++ ) {
            for( int j = 0; j < N - 4; j ++ ) {
                if( is_loop( t, p35, i, j ) ) {
                    m.push_back( std::make_pair( i, j ) );
                }
            }
        }
        //  Put the solution
        for( int k = 0; k < m.size(); k ++ ) {
            if( is_empty( rails, p35, m.at( k ).first, m.at( k ).second ) ) {
                put_loop( rails, p35, m.at( k ).first, m.at( k ).second );
                num_loops ++;
                if( num_loops >= 2 ) {
                    break;
                }
            }
        }
    }

    //  Find 53 loop
    std::vector< std::vector< int > > p53 = {
        { -1,  2,  1 },
        {  2,  4,  0 },
        {  3,  5,  1 },
        {  2,  4,  0 },
        {  3,  0, -1 },
    };
    if( num_loops < 2 ) {
        m.clear();
        for( int i = 0; i < N - 4; i ++ ) {
            for( int j = 0; j < N - 2; j ++ ) {
                if( is_loop( t, p53, i, j ) ) {
                    m.push_back( std::make_pair( i, j ) );
                }
            }
        }
        //  Put the solution
        for( int k = 0; k < m.size(); k ++ ) {
            if( is_empty( rails, p53, m.at( k ).first, m.at( k ).second ) ) {
                put_loop( rails, p53, m.at( k ).first, m.at( k ).second );
                num_loops ++;
                if( num_loops >= 2 ) {
                    break;
                }
            }
        }
    }


    //  Find 33a loop
    std::vector< std::vector< int > > p33a = {
        {  2,  1, -1 },
        {  3,  5,  1 },
        { -1,  3,  0 }
    };
    if( num_loops < 2 ) {
        m.clear();
        for( int i = 0; i < N - 2; i ++ ) {
            for( int j = 0; j < N - 2; j ++ ) {
                if( is_loop( t, p33a, i, j ) ) {
                    m.push_back( std::make_pair( i, j ) );
                }
            }
        }
        //  Put the solution
        for( int k = 0; k < m.size(); k ++ ) {
            if( is_empty( rails, p33a, m.at( k ).first, m.at( k ).second ) ) {
                put_loop( rails, p33a, m.at( k ).first, m.at( k ).second );
                num_loops ++;
                if( num_loops >= 2 ) {
                    break;
                }
            }
        }
    }

    //  Find 33b loop
    std::vector< std::vector< int > > p33b = {
        { -1,  2,  1 },
        {  2,  4,  0 },
        {  3,  0, -1 }
    };
    if( num_loops < 2 ) {
        m.clear();
        for( int i = 0; i < N - 2; i ++ ) {
            for( int j = 0; j < N - 2; j ++ ) {
                if( is_loop( t, p33b, i, j ) ) {
                    m.push_back( std::make_pair( i, j ) );
                }
            }
        }
        //  Put the solution
        for( int k = 0; k < m.size(); k ++ ) {
            if( is_empty( rails, p33b, m.at( k ).first, m.at( k ).second ) ) {
                put_loop( rails, p33b, m.at( k ).first, m.at( k ).second );
                num_loops ++;
                if( num_loops >= 2 ) {
                    break;
                }
            }
        }
    }

    //  Output the solution
    for( int i = 0; i < N; i ++ ) {
        for( int j = 0; j < N; j ++ ) {
            if( rails.at( i ).at( j ) == -1 ) {
                std::cout << "0";
            }
            else if( rails.at( i ).at( j ) == t.at( i ).at( j ) ){
                std::cout << "0";
            }
            else if( rails.at( i ).at( j ) == 4 ) {
                std::cout << "1";
            }
            else if( rails.at( i ).at( j ) == 5 ) {
                std::cout << "1";
            }
            else {
                if( t.at( i ).at( j ) == 4 ) {
                    if( rails.at( i ).at( j ) == 0 || rails.at( i ).at( j ) == 2 ) {
                        std::cout << "0";
                    }
                    else {
                        std::cout << "1";
                    }
                }
                else if( t.at( i ).at( j ) == 5 ) {
                    if( rails.at( i ).at( j ) == 1 || rails.at( i ).at( j ) == 3 ) {
                        std::cout << "0";
                    }
                    else {
                        std::cout << "1";
                    }
                }
                else if( rails.at( i ).at( j ) - t.at( i ).at( j ) >= 0 ) {
                    std::cout << rails.at( i ).at( j ) - t.at( i ).at( j );
                }
                else {
                    std::cout << rails.at( i ).at( j ) - t.at( i ).at( j ) + 4;
                }
            }
        }
    }
    std::cout << std::endl;

    //  Finalize
    return( 0 );
}
