/*
    ABC231 Problem D - Neighbors
        https://atcoder.jp/contests/abc231/tasks/abc231_d
        Author: Keitaro Naruse
        Date:   2021-12-11
        MIT License
*/

#include <iostream>
#include <vector>
#include <set>

int main()
{
    //  Read N and M
    int N = 0, M = 0;
    std::cin >> N >> M;
    //  Debug
    // std::cerr << N << " " << M << std::endl;

    //  Read Ai and Bi
    std::vector< std::set< int > > constraints( N );
    
    for( int j = 0; j < M; j ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        // std::cerr << A << " " << B << std::endl;
        constraints.at( A - 1 ).insert( B - 1 ); 
        constraints.at( B - 1 ).insert( A - 1 ); 
    }
    int num_node_odd_degree = 0;
    for( int i = 0; i < N; i ++ ) {
        int deg_i = constraints.at( i ).size();
        for( int j = 0; j < N; j ++ ) {
            constraints.at( i ).find( j );
        }
    }
    
    if( num_node_odd_degree == 2 ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
