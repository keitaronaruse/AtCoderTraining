/*
    ABC231 Problem D - Neighbors
        https://atcoder.jp/contests/abc231/tasks/abc231_d

        Union find by 
        https://qiita.com/ofutonton/items/c17dfd33fc542c222396
        Author: Keitaro Naruse
        Date:   2021-12-11, 2021-12-14, 2022-01-10
        MIT License
*/

#include <iostream>
#include <vector>

// # Solution
// - Make a graph of the number as nodes and the constraints as edges  
// - Condition 1: The graph should not include any loop
// - Condition 2: The degrees should not exceeds 2

namespace nrs {
    class union_find {
    public:
        union_find( int n ) : parent( n ), rank( n ) {
            for( int i = 0; i < n; i ++ ) {
                parent.at( i ) = i;
                rank.at( i ) = 0;
            }
        }
        int root( int x ) {
            if( parent.at( x ) == x ) {
                return( x );
            }
            else {
                return( parent.at( x ) = root( parent.at( x ) ) );
            }
        }
        void unite( int x, int y ) {
            x = root( x );
            y = root( y );
            if( x == y) {
                //  Do nothing
                return;
            }
            else {
                if( rank.at( x ) < rank.at( y ) ) {
                    parent.at( x ) = y;
                }
                else {
                    parent.at( y ) = x;
                    if( rank.at( x ) == rank.at( y ) ) {
                        rank.at( x ) ++;
                    }
                }
            }
        }

        bool same( int x, int y ) {
            return( root( x ) == root( y ) );
        }
    private:
        std::vector< int > parent;
        std::vector< int > rank;
    };
}

const bool Debug = false;

int main()
{
    //  Initialize
    int N = 0, M = 0;
    std::cin >> N >> M;
    if( Debug ) {
        std::cerr << N << " " << M << std::endl;
    }

    //  Union find search instance
    nrs::union_find uf( N );
    
    //  Result
    bool isYes = true;

    //  Read Ai and Bi and store them as adjacent nodes
    std::vector< int > degrees( N, 0 );
    for( int j = 0; j < M ; j ++ ) {
        int A = 0, B = 0;
        std::cin >> A >> B;
        if( Debug ) {
            std::cerr << A << " " << B << std::endl;
        }
        A --;
        B --;

        //  Condition 1
        if( uf.same( A, B ) ) {
            isYes = false;
            break;
        }
        else {
            //  Condition 2
            uf.unite( A, B );
            degrees.at( A ) ++;
            degrees.at( B ) ++;
            if( ( degrees.at( A ) > 2 ) || ( degrees.at( B ) > 2 ) ) {
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
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }
    return( 0 );
}
