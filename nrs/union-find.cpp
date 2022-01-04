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
        union_find( int n ) : parent( n ) {
            for( int i = 0; i < n; i ++ ) {
                parent.at( i ) = i;
            }
        }
        int root( int x ) {
            if( parent.at( x ) != x ) {
                do {
                    x = parent.at( x );
                } while( parent.at( x ) != x );
            }
            return( x );
        }
        void unite( int x, int y ) {
            int root_x = root( x );
            int root_y = root( y );
            if( root_x == root_y) {
                //  Do nothing
                return;
            }
            else {
                parent.at( root_y ) = root_x;
            }
        }

        bool same( int x, int y ) {
            return( root( x ) == root( y ) );
        }
    private:
        std::vector< int > parent;
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
