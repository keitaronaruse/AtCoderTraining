/*
    ABC231 Problem D - Neighbors
        https://atcoder.jp/contests/abc231/tasks/abc231_d
        Author: Keitaro Naruse
        Date:   2021-12-11, 2012-12-12
        MIT License
*/

#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <utility>

int distance( int s, int g, const std::vector< std::set< int > >& adjacent )
{
    //  pair.first = next node
    //  pair.second = disance
    std::stack< std::pair< int, int > > visiting;

    //  Initialize
    if( s == g ) {
        return( 0 );
    }
    for( int n : adjacent.at( s ) ) {
        if( n == g ) {
            return( 1 );
        }
        else {
            visit.push( std::pair< int, int > ( n, 1 ) );
        }
    }

    //  Main
    while( !visiting.empty() ) {
        std::pair< int, int > p = visiting.top();
        visiting.pop();

        for( int n : adjacent.at( p.first ) ) {
            if( n == g ) {
                return( p.second + 1 );
            }
            else {
                    visiting.push( std::pair< int, int > ( n, p.second + 1) );
            }
        }
    }
    
    return( -1 );
}

int main()
{
    //  Result
    bool isYes = true;

    //  Read N and M
    int N = 0, M = 0;
    std::cin >> N >> M;

    //  Degree of each of the nodes
    std::vector< int > degrees( N, 0 );

    //  Read Ai and Bi and represet them as adjacent nodes
    std::vector< std::set< int > > adjacent( N );
    for( int j = 0; j < M; j ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        // std::cerr << A << " " << B << std::endl;
        A --;
        B --;
        //  Debug
        std::cerr << A << "->" << B << "="<< distance( A, B, adjacent ) << std::endl;
        adjacent.at( A ).insert( B );
        adjacent.at( B ).insert( A );
        degrees.at( A ) ++ ;  
        degrees.at( B ) ++ ; 
        //  Condition 1: 
        //  All of the degrees should be 0, 1, 2 -> Do not exceed 2
        if( ( degrees.at( A ) > 2 ) || ( degrees.at( B ) > 2 ) ) {
            isYes = false;
            break;
        }
    }

    //  Debug
    //  Display adjacent nodes
    for( int i = 0; i < N; i ++ ) {
        std::cerr << i << ": "; 
        for( auto v : adjacent.at( i ) ) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
    }

    //  Display degrees
    for( auto d : degrees ) {
        std::cerr << d << " ";
    }
    std::cerr << std::endl;

    //  Display result
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
