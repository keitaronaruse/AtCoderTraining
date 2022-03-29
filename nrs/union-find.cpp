/*
    nrs::union-find
        The class of a union-findgraph structure
        Author: Keitaro Naruse
        Date:   2022-01-04
        MIT License
*/

#include <iostream>
#include <vector>

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
            if( x == y ) {
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

int main()
{
    //  Initialize
    const int N = 3;

    //  Union find search instance
    nrs::union_find uf( N );
    
    std::cout << "Connect ( 0, 1 )" << std::endl;
    uf.unite( 0, 1 );
    std::cout << "Is ( 0, 1 ) connected? " << uf.same( 0, 1 ) << std::endl;
    std::cout << "Is ( 0, 2 ) connected? " << uf.same( 0, 2 ) << std::endl;
    std::cout << "Is ( 1, 2 ) connected? " << uf.same( 1, 2 ) << std::endl;

    std::cout << "Connect ( 0, 2 )" << std::endl;
    uf.unite( 0, 2 );
    std::cout << "Is ( 0, 1 ) connected? " << uf.same( 0, 1 ) << std::endl;
    std::cout << "Is ( 0, 2 ) connected? " << uf.same( 0, 2 ) << std::endl;
    std::cout << "Is ( 1, 2 ) connected? " << uf.same( 1, 2 ) << std::endl;

    //  Finalize
    return( 0 );
}
