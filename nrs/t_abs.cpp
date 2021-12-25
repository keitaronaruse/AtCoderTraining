/*
    t_abs()
        returns the absolute value of the arugument, implmented by template
*/
template < class T >
T t_abs( T a )
{
    return( ( a > 0 )? a : -a );
}

