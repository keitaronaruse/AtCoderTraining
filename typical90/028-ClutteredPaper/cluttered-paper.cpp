/*
    028 - Cluttered Paper（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_ab
        Author: Keitaro Naruse
        Date:   2022-01-06
        MIT License
*/

// # Solution

#include <iostream>
#include <vector>
#include <stack>

const bool Debug = true;

int main()
{
    //  Read N
    int N = 0;
    std::cin >> N;
    if( Debug ) {
        std::cerr << N << std::endl;
    }

    //  Make a graph instance
    color_tree t( N );
    
    //  Read A and B
    for( int i = 0; i < N - 1; i ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        if( Debug ) {
            std::cerr << A << " " << B << std::endl;
        }
        A --; B --;
        t.add_edge( A, B ); 
        t.add_edge( B, A );
    }

    //  Main
    int b = 0;
    if( Debug ) {
        std::cerr << "Before DFS" << std::endl;
    }
    t.color_dfs( b );
    if( Debug ) {
        std::cerr << "After DFS" << std::endl;
    }
    
    if( Debug ) {
        for( auto v : t.length ) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
        for( auto v : t.even ) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
        for( auto v : t.odd ) {
            std::cerr << v << " ";
        }
        std::cerr << std::endl;
    }

    //  Display results
    if( t.even.size() > t.odd.size() ) {
        for( int i = 0; i < N / 2; i ++ ) {
            std::cout << t.even.at( i ) + 1 << " ";
        }
        std::cout << std::endl;
    }
    else {
        for( int i = 0; i < N / 2; i ++ ) {
            std::cout << t.odd.at( i ) + 1 << " ";
        }
        std::cout << std::endl;
    }

    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
