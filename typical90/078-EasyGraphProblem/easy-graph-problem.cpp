/*
    078 - Easy Graph Problem（★2） 
        https://atcoder.jp/contests/typical90/tasks/typical90_bz
        Author: Keitaro Naruse
        Date:   2021-12-02
        MIT License
*/

// # Solution
// - For each node, store adjacent nodes in list
// - Store all of the nodes in vector

#include <iostream>
#include <vector>
#include <list>

int main()
{
    //  Read N, M
    int N = 0, M = 0;
    std::cin >> N >> M;
    //  Debug
    // std::cerr << N << " " << M << std::endl;

    //  Read ai and bi
    std::vector< std::list< int > > adjacent_nodes( N + 1 );
    for( int i = 0; i != M; i ++ ) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        //  Debug
        // std::cerr << a << " " << b << std::endl;
        //  Since a bidirectional edge is given, add an adjacent node to the both nodes
        adjacent_nodes.at( a ). push_back( b );
        adjacent_nodes.at( b ). push_back( a );
    }
    
    //  Main
    int num_satisfied_nodes = 0;
    for( int i = 1; i != N + 1; i ++ ) {
        int num_smaller_nodes = 0;
        for( const auto& adj_node : adjacent_nodes.at( i ) ) {
            if( adj_node < i ) {
                num_smaller_nodes ++;
            }
        }
        if( num_smaller_nodes == 1 ) {
            num_satisfied_nodes ++;
        }
    }
    //  Debug
    //  Display the adjacent nodes of all of the nodes
    // for( size_t i = 1; i != N + 1; i ++ ) {
    //     std::cerr << i << ": ";
    //     for( const auto& adj_node : adjacent_nodes.at( i ) ) {
    //         std::cerr << adj_node << " ";
    //     }
    //     std::cerr << std::endl;
    // }

    //  Display result
    std::cout << num_satisfied_nodes << std::endl;

    //  Finalize
    //  Debug
    // std::cerr << "Normally terminated." << std::endl;
    return( 0 );
}
