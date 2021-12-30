/*
    mod_inv()
        returns the inverse element of mod
        Author: Keitaro Naruse
        Date:   2021-12-30
        MIT License
*/

#include <iostream>

namespace nrs {
    template < class T >
    T mod_inv( T a, T m ) 
    {
        T b = m, u = 1, v = 0;
        while( b )  {
            T t = a / b;

            a -= t * b;
            u -= t * v; 
            
            //  Swap a and b
            t = a; 
            a = b;
            b = t;

            //  Swap u and v
            t = u; 
            u = v;
            v = t;
        }

        u %= m;
        if( u < 0 ) {
            u += m;
        }

        return( u );
    }
}

//  Test driver
int main()
{
    //  mod P = 7
    int P = 7;
    std::cout << "mod of " << P << std::endl;
    for( int i = 0; i < P; i ++ ) {
        int inv = nrs::mod_inv( i, P );
        if( i * inv % P == 1 ) {
            std::cout << i << " " << inv << std::endl; 
        }
    }
    
    //  mod P = 6
    P = 6;
    std::cout << "mod of " << P << std::endl;
    for( int i = 0; i < P; i ++ ) {
        int inv = nrs::mod_inv( i, P );
        if( i * inv % P == 1 ) {
            std::cout << i << " " << inv << std::endl; 
        }
    }

    return( 0 );
}
