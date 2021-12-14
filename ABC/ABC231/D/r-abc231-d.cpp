/*
    ABC231 Problem D - Neighbors
        https://atcoder.jp/contests/abc231/tasks/abc231_d

        Union find by 
        https://qiita.com/ofutonton/items/c17dfd33fc542c222396
        Author: Keitaro Naruse
        Date:   2012-12-14
        MIT License
*/

#include <iostream>
#include <vector>

// # Solution
// - Make a graph of the number as nodes and the constraints as edges  
// - Condition 1: The graph should not include any loop
// - Condition 2: The degrees should not exceeds 2

class UnionFind {
public:
    UnionFind( int n ) : parent( n ) {
        for( int i = 0; i < n; i ++ ) {
            parent.at( i ) = i;
        }
    }

    int root( int x ) {
        if( parent.at( x ) == x ) {
            return( x );
        }
        return( root( parent.at( x ) ) );
    }

    void unite( int x, int y ) {
        int root_x = root( x );
        int root_y = root( y );
        if( root_x == root_y) {
            //  Do nothing
            return;
        }
        else {
            parent.at( root_x ) = root_y;
        }
    }

    bool same( int x, int y ) {
        int root_x = root( x );
        int root_y = root( y );
        return( root_x == root_y );
    }
private:
    std::vector< int > parent;
};

int main()
{
    //  Initialize
    int N = 0, M = 0;
    std::cin >> N >> M;

    //  Union find search instance
    UnionFind uf( N );
    
    //  Result
    bool isYes = true;

    //  Read Ai and Bi and store them as adjacent nodes
    std::vector< int > degrees( N, 0 );
    for( int j = 0; j < M ; j ++ ) {
        int A, B;
        std::cin >> A >> B;
        int a = A - 1, b = B - 1;

        //  Condition 1
        if( uf.same( a, b ) ) {
            isYes = false;
            break;
        }
        else {
            //  Condition 2
            uf.unite( a, b );
            degrees.at( a ) ++;
            degrees.at( b ) ++;
            if( ( degrees.at( a ) > 2 ) || ( degrees.at( b ) > 2 ) ) {
                isYes = false;
                break;
            }
        }
    }

    //  Display result
    if( isYes ) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

    //  Finalize
    return( 0 );
}
