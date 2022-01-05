/*
    012 - Red Painting（★4）
        https://atcoder.jp/contests/typical90/tasks/typical90_l
        Author: Keitaro Naruse
        Date:   2021-01-04, 2022-01-05
        MIT License
*/

// # Solution
// - When adding a node, make an edge if a node exists at either of four neighbors
// - Connection is checked by Union Find

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
int H = 0;
int W = 0;
int Q = 0;

int id( int h, int w )
{
    return( h * W + w );
}

int main()
{
    //  Read H and W
    std::cin >> H >> W;
    if( Debug ) {
        std::cerr << H << " " << W << std::endl;
    }
    //  Read Q
    std::cin >> Q;
    if( Debug ) {
        std::cerr << Q << std::endl;
    }

    //  Make union-find tree
    const int N = id( H - 1, W - 1 ) + 1;
    if( Debug ) {
        std::cerr << N << std::endl;
    }
    std::vector< bool > color( N, false );
    nrs::union_find uf( N );

    //  Main
    //  Read queries and 
    for( int i = 0; i < Q; i ++ ) {
        int t = 0;
        std::cin >> t;
        if( t == 1 ) {
            int r = 0, c = 0;
            std::cin >> r >> c;
            if( Debug ) {
                std::cerr << t << " " << r << " " << c << std::endl;;
            }

            r --; c --;
            color.at( id( r, c ) ) = true;
            for( int v = -1; v <= 1; v += 2 ) {
                if( ( 0 <= ( r + v ) ) && ( ( r + v ) < H ) ) {
                    if( color.at( id( r + v, c ) ) ) {
                        uf.unite( id( r, c ), id( r + v, c ) );
                    }
                }
            }
            for( int u = -1; u <= 1; u += 2 ) {
                if( ( 0 <= ( c + u ) ) && ( ( c + u ) < W ) ) {
                    if( color.at( id( r, c + u ) ) ) {
                        uf.unite( id( r, c ), id( r, c + u ) );
                    }
                }
            }
        }
        else if( t == 2 ) {
            int ra = 0, ca = 0, rb = 0, cb = 0;
            std::cin >> ra >> ca >> rb >> cb;
            if( Debug ) {
                std::cerr << t << " " << ra << " " << ca << " " << rb << " " << cb << std::endl;
            }
            ra --; ca --; rb --; cb --;
            if( color.at( id( ra, ca ) ) && color.at( id( rb, cb ) ) 
            && uf.same( id( ra, ca ), id( rb, cb ) ) ) {
                std::cout << "Yes" << std::endl;
            }
            else {
                std::cout << "No" << std::endl;
            }
        }
    }
    
    //  Finalize
    if( Debug ) {
        std::cerr << "Normally terminated." << std::endl;
    }

    return( 0 );
}
