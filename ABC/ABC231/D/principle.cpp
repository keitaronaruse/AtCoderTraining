/*
    ABC231 Problem D - Neighbors
        https://atcoder.jp/contests/abc231/tasks/abc231_d
        Author: Keitaro Naruse
        Date:   2021-12-11, 2012-12-12
        MIT License
*/

#include <iostream>
#include <vector>
#include <stack>
#include <utility>

// # Solution
// - Make a graph of the numbers as nodes and the constraints as edges  
// - If the degree of any nodes exceed 2, the constraints are not satisfied 
// - If the graph includes n-loops (n > 2), the constraints are not satisfied

int main()
{
    //  Result
    bool isYes = true;

    //  Read N and M
    int N = 0, M = 0;
    std::cin >> N >> M;

    //  Degree of each of the nodes
    std::vector< int > degrees( N, 0 );

    //  Read Ai and Bi and represet them as edges 
    std::vector< std::pair< int, int > > edges( M );
    for( int j = 0; j < M; j ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        // std::cerr << A << " " << B << std::endl;
        A --;
        B --;
        edges.at( j ).first = A;
        edges.at( j ).second = B;
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
    //  Display edges
    for( auto e : edges ) {
        std::cerr << e.first << " " << e.second << std::endl;
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
