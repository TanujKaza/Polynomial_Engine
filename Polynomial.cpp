#include<iostream>
#include<simplecpp>
#include<cmath>
#include"Polynomial.h"
#include<algorithm>
using namespace std ;

Polynomial::Polynomial()
{
	m_degree = 20;
	N_O_R = m_degree;
	c = false ;
	b = false ;
	coefficient = new double [m_degree + 1] ;
	root = new double [m_degree + 1] ;
	for ( int i = 0 ; i < (m_degree + 1) ; ++i )
	{
		coefficient[i] = 0 ;
		root[i] = 0 ;
	}
}

//Print Polynomial as per test cases(i.e it prints 1x^1 not x and doesn't print integration constant )
void Polynomial::print()
{
	int j = 0 ;
	for ( int i = 0 ; i < ( m_degree + 1 ) ; ++ i )
	{
		if ( coefficient[i] == 0 )
		{
			j = j + 1 ;
		}
	}
	if (( coefficient[0] != 0 ) && (m_degree == 0))
	{
		cout << coefficient[0] << endl ;
	}
	if (( coefficient[0] != 0 ) && (m_degree != 0))
	{
		cout << coefficient[0] ;
	}
	for ( int i = 1 ; i < ( m_degree ) ; ++i )
	{
		int k = 0 ;
		for ( int h = 0 ; h < i ; ++h )
		{
			if ( coefficient[h] != 0 )
			{
			k = k + 1 ;
			}
		}
		if ( (coefficient[i] != 0) && (k == 0) && (m_degree - j != k))
		{
			cout << coefficient[i] << "x^" << i  ;
		}
		else if ((coefficient[i] != 0)&&(k == 0) && (m_degree - j == k))
		{
			cout << coefficient[i] << "x^" << i  << endl ;
		}
		else if ((coefficient[i] != 0)&&(k != 0)&&(m_degree - j != k) && (coefficient[i] > 0))
		{
			cout << " + " << coefficient[i] << "x^" << i  ;
		}
		else if ((coefficient[i] != 0)&&(k != 0) && (m_degree - j != k) && (coefficient[i] < 0) )
		{
			cout << " - " << -coefficient[i] << "x^" << i  ;
		}
		else if ( (coefficient[i] != 0)  && (k != 0) && (m_degree - j != k)  )
		{
			cout << " - " << "x^" << i  ;
		}
		else if ((coefficient[i] != 0)&&(k != 0) && (m_degree - j == k) && (coefficient[i] > 0) )
		{
			cout << " + " << coefficient[i] << "x^" << i << endl ;
		}
		else if ((coefficient[i] != 0)&&(k != 0)&&(m_degree - j == k) && (coefficient[i] < 0)  )
		{
			cout << " - " << -coefficient[i] << "x^" << i << endl ;
		}
		else if ( (coefficient[i] != 0)  && (k != 0) && (m_degree - j == k) )
		{
			cout << " - " << -coefficient[i] << "x^" << i << endl ;
		}

		else if ( (coefficient[i] != 0) && (k == 0) && (m_degree - j != k) )
		{
			cout << coefficient[i] << "x" ;
		}
		else if ( (coefficient[i] != 0) && (k == 0) && (m_degree - j == k) )
		{
			cout << coefficient[i] << "x" << endl ;
		}
		else if ( (coefficient[i] != 0)  && (k != 0) && (m_degree - j != k) && (coefficient[i] > 0))
		{
			cout << " + " << coefficient[i] << "x" ;
		}
		else if ( (coefficient[i] != 0)  && (k != 0) && (m_degree - j != k) && (coefficient[i] < 0))
		{
			cout << " - " << -coefficient[i] << "x" ;
		}
		else if ( (coefficient[i] != 0) && (k != 0) && (m_degree - j == k) && (coefficient[i] > 0) )
		{
			cout << " + " << coefficient[i] << "x" << endl ;
		}
		else if ( (coefficient[i] != 0)  && (k != 0) && (m_degree - j == k) && (coefficient[i] < 0) )
		{
			cout << " - " << -coefficient[i] << "x" << endl ;
		}

	}
	if ((coefficient[m_degree] != 0)&&(coefficient[m_degree] > 0)&&(m_degree != j) )
	{
		cout << " + " << coefficient[m_degree] << "x^" << m_degree << endl ;
	}
	else if((coefficient[m_degree] != 0)&&(coefficient[m_degree] > 0)&&(m_degree == j))
	{
		cout << coefficient[m_degree] << "x^" << m_degree << endl ;
	}
	else if((coefficient[m_degree]!=0)&&(coefficient[m_degree] < 0)&&(m_degree != j) )
	{
		cout << " - " << -coefficient[m_degree] << "x^" << m_degree << endl ;
	}
	else if ((coefficient[m_degree]!=0)&&(coefficient[m_degree] < 0)&&(m_degree == j) )
	{
		cout << "- " << -coefficient[m_degree] << "x^" << m_degree << endl ;
	}

	else if ( (coefficient[m_degree] != 0)  && (coefficient[m_degree] > 0) && (m_degree != j) )
	{
		cout << " + " << coefficient[m_degree] << "x" << endl ;
	}
	else if ( (coefficient[m_degree] != 0)  && (coefficient[m_degree] > 0) && (m_degree == j) )
	{
		cout << coefficient[m_degree] << "x" << endl ;
	}
	else if ( (coefficient[m_degree] != 0)  && (coefficient[m_degree] < 0) && (m_degree != j) )
	{
		cout << " - " << -coefficient[m_degree] << "x" << endl ;
	}
	else if ( (coefficient[m_degree] != 0)  && (coefficient[m_degree] < 0) && (m_degree == j) )
	{
		cout << "- " << -coefficient[m_degree] << "x" << endl ;
	}

	if ( j == ( m_degree + 1 ) )
	{
		cout << "0" << endl ;
	}
}

//Prints Polynomial elegantly(It prints x not 1x^1 and prints integration constant)
void Polynomial::smart_print()
{
	cout << endl ;
	int j = 0 ;
	for ( int i = 0 ; i < ( m_degree + 1 ) ; ++ i )
	{
		if ( coefficient[i] == 0 )
		{
			j = j + 1 ;
		}
	}
	if ( b == true )
	{
		cout << "c + " ;
	}
	if (( coefficient[0] != 0 ) && (m_degree == 0))
	{
		cout << coefficient[0] << endl ;
	}
	if (( coefficient[0] != 0 ) && (m_degree != 0))
	{
		cout << coefficient[0] ;
	}
	for ( int i = 1 ; i < ( m_degree ) ; ++i )
	{
		int k = 0 ;
		for ( int h = 0 ; h < i ; ++h )
		{
			if ( coefficient[h] != 0 )
			{
			k = k + 1 ;
			}
		}
		if ( (coefficient[i] != 0) && (coefficient[i] != 1) && (k == 0) && (m_degree - j != k) && (coefficient[i] != -1) && (i!=1))
		{
			cout << coefficient[i] << "x^" << i  ;
		}
		else if ((coefficient[i] != 0)&&(coefficient[i] != 1)&&(k == 0) && (m_degree - j == k)&&(coefficient[i] != -1) && (i!=1))
		{
			cout << coefficient[i] << "x^" << i  << endl ;
		}
		else if ((coefficient[i] != 0)&&(coefficient[i] != 1)&&(k != 0)&&(m_degree - j != k) && (coefficient[i] > 0) && (i!=1))
		{
			cout << " + " << coefficient[i] << "x^" << i  ;
		}
		else if ((coefficient[i] != 0)&&(coefficient[i] != -1)&&(k != 0) && (m_degree - j != k) && (coefficient[i] < 0) && (i!=1))
		{
			cout << " - " << -coefficient[i] << "x^" << i  ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] == -1) && (k != 0) && (m_degree - j != k) && (i!=1) )
		{
			cout << " - " << "x^" << i  ;
		}
		else if ((coefficient[i] != 0)&&(coefficient[i] != 1)&&(k != 0) && (m_degree - j == k) && (coefficient[i] > 0) && (i!=1))
		{
			cout << " + " << coefficient[i] << "x^" << i << endl ;
		}
		else if ((coefficient[i] != 0)&&(coefficient[i] != -1)&&(k != 0)&&(m_degree - j == k) && (coefficient[i] < 0) && (i!=1) )
		{
			cout << " - " << -coefficient[i] << "x^" << i << endl ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] == -1) && (k != 0) && (m_degree - j == k) && (i!=1))
		{
			cout << " - " << -coefficient[i] << "x^" << i << endl ;
		}
		else if ( (coefficient[i] == 1) && (k == 0) && (m_degree - j != k) && (i!=1) )
		{
			cout << "x^" << i ;
		}
		else if ( (coefficient[i] == 1) && (k == 0) && (m_degree - j == k) && (i!=1))
		{
			cout << "x^" << i << endl ;
		}
		else if ( (coefficient[i] == 1) && (k != 0) && (m_degree - j != k) && (i!=1))
		{
			cout << " + " << "x^" << i ;
		}
		else if ( (coefficient[i] == 1) && (k != 0) && (m_degree - j == k) && (i!=1))
		{
			cout << " + " << "x^" << i << endl ;
		}
		else if ( (coefficient[i] == -1) && (k == 0) && (m_degree - j != k) && (i!=1))
		{
			cout << "- " << "x^" << i ;
		}
		else if ( (coefficient[i] == -1) && (k == 0) && (m_degree - j == k) && (i!=1))
		{
			cout << "- " << "x^" << i << endl ;
		}
		else if ( (coefficient[i] == -1) && (k != 0) && (m_degree - j != k) && (i!=1))
		{
			cout << " - " << "x^" << i ;
		}
		else if ( (coefficient[i] == -1) && (k != 0) && (m_degree - j == k) && (i!=1))
		{
			cout << " - " << "x^" << i << endl ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] != 1) && (k == 0) && (m_degree - j != k) && (coefficient[i] != -1))
		{
			cout << coefficient[i] << "x" ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] != 1) && (k == 0) && (m_degree - j == k) && (coefficient[i] != -1))
		{
			cout << coefficient[i] << "x" << endl ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] != 1) && (k != 0) && (m_degree - j != k) && (coefficient[i] > 0))
		{
			cout << " + " << coefficient[i] << "x" ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] != -1) && (k != 0) && (m_degree - j != k) && (coefficient[i] < 0))
		{
			cout << " - " << -coefficient[i] << "x" ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] == -1) && (k != 0) && (m_degree - j != k) )
		{
			cout << " - " << "x" ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] != 1) && (k != 0) && (m_degree - j == k) && (coefficient[i] > 0) )
		{
			cout << " + " << coefficient[i] << "x" << endl ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] != -1) && (k != 0) && (m_degree - j == k) && (coefficient[i] < 0) )
		{
			cout << " - " << -coefficient[i] << "x" << endl ;
		}
		else if ( (coefficient[i] != 0) && (coefficient[i] == -1) && (k != 0) && (m_degree - j == k) )
		{
			cout << " - " << -coefficient[i] << "x" << endl ;
		}
		else if ( (coefficient[i] == 1) && (k == 0) && (m_degree - j != k) )
		{
			cout << "x" ;
		}
		else if ( (coefficient[i] == 1) && (k == 0) && (m_degree - j == k) )
		{
			cout << "x" << endl ;
		}
		else if ( (coefficient[i] == 1) && (k != 0) && (m_degree - j != k))
		{
			cout << " + " << "x" ;
		}
		else if ( (coefficient[i] == 1) && (k != 0) && (m_degree - j == k))
		{
			cout << " + " << "x" << endl ;
		}
		else if ( (coefficient[i] == -1) && (k == 0) && (m_degree - j != k) )
		{
			cout << "- " << "x" ;
		}
		else if ( (coefficient[i] == -1) && (k == 0) && (m_degree - j == k) )
		{
			cout << "- " << "x" << endl ;
		}
		else if ( (coefficient[i] == -1) && (k != 0) && (m_degree - j != k))
		{
			cout << " - " << "x" ;
		}
		else if ( (coefficient[i] == -1) && (k != 0) && (m_degree - j == k))
		{
			cout << " - " << "x" << endl ;
		}
	}
	if ((coefficient[m_degree] != 0)&&(coefficient[m_degree] != 1)&&(coefficient[m_degree] > 0)&&(m_degree != j)&&(m_degree != 1) )
	{
		cout << " + " << coefficient[m_degree] << "x^" << m_degree << endl ;
	}
	else if((coefficient[m_degree] != 0)&&(coefficient[m_degree] != 1)&&(coefficient[m_degree] > 0)&&(m_degree == j)&&(m_degree != 1) )
	{
		cout << coefficient[m_degree] << "x^" << m_degree << endl ;
	}
	else if((coefficient[m_degree]!=0)&&(coefficient[m_degree] != -1)&&(coefficient[m_degree] < 0)&&(m_degree != j)&&(m_degree != 1) )
	{
		cout << " - " << -coefficient[m_degree] << "x^" << m_degree << endl ;
	}
	else if ((coefficient[m_degree]!=0)&&(coefficient[m_degree] != -1)&&(coefficient[m_degree] < 0)&&(m_degree == j)&&(m_degree != 1) )
	{
		cout << "- " << -coefficient[m_degree] << "x^" << m_degree << endl ;
	}
	else if ( (coefficient[m_degree] == 1) && (m_degree != j) &&(m_degree != 1))
	{
		cout << " + " << "x^" << m_degree << endl ;
	}
	else if ( (coefficient[m_degree] == 1) && (m_degree == j) && (m_degree != 0 ) &&(m_degree != 1))
	{
		cout << "x^" << m_degree << endl ;
	}
	else if ( (coefficient[m_degree] == -1) && (m_degree != j) &&(m_degree != 1))
	{
		cout << " - " << "x^" << m_degree << endl ;
	}
	else if ( (coefficient[m_degree] == -1) && (m_degree == j) && (m_degree != 0) &&(m_degree != 1))
	{
		cout << "- " << "x^" << m_degree << endl ;
	}
	else if ( (coefficient[m_degree] != 0) && (coefficient[m_degree] != 1) && (coefficient[m_degree] > 0) && (m_degree != j) )
	{
		cout << " + " << coefficient[m_degree] << "x" << endl ;
	}
	else if ( (coefficient[m_degree] != 0) && (coefficient[m_degree] != 1) && (coefficient[m_degree] > 0) && (m_degree == j) )
	{
		cout << coefficient[m_degree] << "x" << endl ;
	}
	else if ( (coefficient[m_degree] != 0) && (coefficient[m_degree] != -1) && (coefficient[m_degree] < 0) && (m_degree != j) )
	{
		cout << " - " << -coefficient[m_degree] << "x" << endl ;
	}
	else if ( (coefficient[m_degree] != 0) && (coefficient[m_degree] != -1) && (coefficient[m_degree] < 0) && (m_degree == j) )
	{
		cout << "- " << -coefficient[m_degree] << "x" << endl ;
	}
	else if ( (coefficient[m_degree] == 1) && (m_degree != j) )
	{
		cout << " + " << "x" << endl ;
	}
	else if ( (coefficient[m_degree] == 1) && (m_degree == j) && (m_degree != 0 ) )
	{
		cout << "x" << endl ;
	}
	else if ( (coefficient[m_degree] == -1) && (m_degree != j) )
	{
		cout << " - " << "x" << endl ;
	}
	else if ( (coefficient[m_degree] == -1) && (m_degree == j) && (m_degree != 0) )
	{
		cout << "- " << "x" << endl ;
	}
	if ( j == ( m_degree + 1 ) )
	{
		cout << "0" << endl ;
	}
	if (b == true)
	{
		cout << "Where 'c' is the constant of integration" ;
	}
	cout << endl ;
}

//Overloading the arithmetic operator
Polynomial operator+ (const Polynomial &p , const Polynomial &q)
{
	bool g = true ;
	int ma = max ( p.m_degree , q.m_degree ) ;
	int mi = min ( p.m_degree , q.m_degree ) ;
	if ( q.m_degree == ma )
	{
		g = false ;
	}
	Polynomial r (ma) ;
	for ( int i = 0 ; i < ( mi + 1 ) ;i++)
	{
		r.coefficient[i] = p.coefficient[i] + q.coefficient[i] ;
	}
	if ( g )
	{
		for ( int i = (mi + 1) ; i < ( ma + 1 ) ; i++ )
		{
			r.coefficient[i] = p.coefficient[i] ;
		}
	}
	else
	{
		for ( int i = (mi + 1) ; i < ( ma + 1 ) ; i++ )
		{
			r.coefficient[i] = q.coefficient[i] ;
		}
	}
	return r ;
}

//Overloading the multiplication operator
Polynomial operator* (const Polynomial &p , const Polynomial &q)
{
	Polynomial r (p.m_degree + q.m_degree) ;
	for ( int i = 0 ; i < ( r.m_degree + 1 ) ; ++i )
	{
		for ( int a = 0 ; a <= i ; ++a )
		{
			if ( ((i-a) <= q.m_degree) && (a <= p.m_degree) )
			{
				r.coefficient[i] = r.coefficient[i] + ( p.coefficient[a] * q.coefficient[i-a] ) ;
			}
		}
	}
	return r ;
}

//Overloading the division operator
//Polynomial l is now global!!!
Polynomial l ;
Polynomial operator/ ( Polynomial &p ,  Polynomial &q)
{
	Polynomial n ;
	if ( p.m_degree < q.m_degree )
	{
		return l;
	}
	else if ( p.m_degree >= q.m_degree )
	{
		Polynomial r = p, a = q ;
		int x = r.m_degree ;
		n.m_degree = r.m_degree - a.m_degree ;
		n.coefficient[n.m_degree] = r.coefficient[r.m_degree] / a.coefficient[a.m_degree] ;
		l = l + n ;
		r = r - n * a ;
		for ( int i = 0 ; (i <= x - 1) ; ++i )
		{
			if ( r.coefficient[x - 1 - i] != 0 )
			{
				r.m_degree = x - 1 - i ;
				return operator/ (r, a) ;
			}
			else
			{
				return l ;
			}
		}
	}
}

//Overloading the remainder operator
Polynomial operator% (Polynomial &p , Polynomial &q)
{
	Polynomial a , b , c ;
	b = p ;
	c = q ;
	a = p / q ;
	return ( b - a * c ) ;
}

//Evaluating the value at a point
double Polynomial::valueAt(double x)
{
	long double sum = 0 ;
	long double i_sum = 0 ;
	long double power = 1 ;
	for ( int i = 0 ; i < m_degree+1 ; ++i )
	{
		i_sum = coefficient[i] * power ;
		power = power * x ;
		sum = sum + i_sum ;
	}
	return sum ;
}

//Computing the indefinite integral
Polynomial Polynomial::integral()
{
	int k = m_degree + 1 ;
	Polynomial r(k) ;
	for ( int i = 1 ; i < k + 1 ; ++i )
	{
		r.coefficient[i] = coefficient[i - 1] / i ;
	}
	r.b = true ;
	return r ;
}

//Computing the definite integral
double Polynomial::def_integral(double x1 , double x2)
{
	int k = m_degree + 1 ;
	Polynomial r(k) ;
	for ( int i = 1 ; i < k + 1 ; ++i )
	{
		r.coefficient[i] = coefficient[i - 1] / i ;
	}
	double x = r.valueAt(x2) - r.valueAt(x1) ;
	return x ;
}

//Helper function for finding the roots of a polynomial by Bisection Method
double newton_root( Polynomial &p , double xl , double xr )
{
	double epsilon = 1.0e-11 ;
	bool xlispos = (p.valueAt(xl) > 0) ;
	if ( p.valueAt(xl) == 0 && p.valueAt(xr) != 0 )
	{
		return xl ;
	}
	else if ( p.valueAt(xr) == 0 && p.valueAt(xl) != 0 )
	{
		return xr ;
	}
	else if ( p.valueAt(xr) == 0 && p.valueAt(xl) == 0 )
	{
		return xr ;
	}
	else
	{
		while ( (xr - xl) >= epsilon )
		{
			double xm = (xl + xr) / 2 ;
			if(p.valueAt(xm)==0)
			{
                		xr=xm;
                		break;
			}
            		else
			{
				bool xmispos = (p.valueAt(xm) >0) ;
				if ( xlispos == xmispos )
				{
					xl = xm ;
				}
				else
				{
					xr = xm ;
				}
			}
		}
		return xr ;
	}
}

//Main function for finding the roots
void root ( Polynomial &p )
{
	Polynomial derivative[p.m_degree - 1] ;
	int r_degree = p.m_degree ;
	if ( r_degree == 1 )
	{
		derivative[0].root[0] = -derivative[0].coefficient[0] / derivative[0].coefficient[1] ;
	}
	for ( int i = 0 ; i <= (r_degree - 2) ; ++i )
	{
		derivative[i] = p ;
		p = p.derivative() ;
	}
	double c = derivative[r_degree - 2].coefficient[0] ;
	double b = derivative[r_degree - 2].coefficient[1] ;
	double a = derivative[r_degree - 2].coefficient[2] ;
	double x1 = (-b - sqrt ( b * b - 4 * a * c )) / ( 2 * a ) ;
	double x2 = (-b + sqrt ( b * b - 4 * a * c )) / ( 2 * a ) ;
	if ( x1 > x2 )
	{
		swap( x1 , x2 ) ;
	}
	derivative[r_degree -2].root[0] = x1 ;
	derivative[r_degree -2].root[1] = x2 ;
	for (int i = 3 ; i < r_degree + 1 ; ++ i)
	{
		double newx = x1 - 10 ;
		while ( true )
		{
			if  ( derivative[r_degree - i].valueAt(x1) * derivative[r_degree - i].valueAt(newx) <= 0 )
			{
				derivative[r_degree - i].root[0] = newton_root(derivative[r_degree - i],newx,x1) ;
				break ;
			}
			else
			{
				newx = newx - 10 ;
			}
		}
		newx = x2 + 10 ;
		while ( true )
		{
			if  ( derivative[r_degree - i].valueAt(x2) * derivative[r_degree - i].valueAt(newx) <= 0 )
			{
				derivative[r_degree - i].root[i - 1] = newton_root(derivative[r_degree - i],x2,newx) ;
				break ;
			}
			else
			{
				newx = newx + 10 ;
			}
		}
		int h = i ;
		while ( h > 2 )
		{
			x1 = derivative[r_degree - i + 1].root[h - 3] ;
			x2 = derivative[r_degree - i + 1].root[h - 2] ;
			derivative[r_degree - i].root[h - 2] = newton_root(derivative[r_degree - i],x1,x2) ;
			h = h - 1 ;
		}
		x1 = derivative[r_degree - i].root[0] ;
		x2 = derivative[r_degree - i].root[i - 1] ;
	}
	for (int i = 0 ; i < r_degree ; ++i )
	{
		if ( derivative[0].root[i] != 0 )
		{
			cout << "Root " << (i + 1) << " is : " << derivative[0].root[i] << endl ;
		}
		else
		{
			cout << "Root " << (i + 1) << " is : " << "0" << endl ;
		}
	}
}

//Plotting the graph of a Polynomial within the ranges (-55,-30),(55,30)
void Polynomial::plot(double xleft , double xright)
{
	initCanvas("Graph Plotter" , 1400 , 700) ;
	int i = -700 ;
	while ( i <= 700 )
	{
		Line ly(700 + i , 0 , 700 + i , 700) ;
		ly.setFill(false) ;
		ly.setColor(COLOR(0,255,0)) ;
		ly.imprint() ;
		i = i + 10 ;
	}
	i = -350 ;
	while ( i <= 350 )
	{
		Line lx(0 , 350 + i , 1400 , 350 + i) ;
		lx.setFill(false) ;
		lx.setColor(COLOR(0,255,0)) ;
		lx.imprint() ;
		i = i + 10 ;
	}
	i = -700 ;
	while ( i <= 700 )
	{ 
		Line ly(700 + i , 0 , 700 + i , 700) ;
		ly.setFill(false) ;
		ly.setColor(COLOR(0,150,0)) ;
		ly.imprint() ;
		i = i +50 ;
	}
	i = -350 ;
	while ( i <= 350 )
	{
		Line lx(0 , 350 + i , 1400 , 350 + i) ;
		lx.setFill(false) ;
		lx.setColor(COLOR(0,150,0)) ;
		lx.imprint() ;
		i = i + 50 ;
	}
	i = 10 ;
	while ( i > 0 )
	{
		Line midx(10 , 350 , 1380 , 350) , midy(650 , 10 , 650 , 690) ;
		midx.setColor(COLOR("black")) ;
		midy.setColor(COLOR("black")) ;
		midx.imprint() ;
		midy.imprint() ;
		i = i - 1 ;
	}
	Line arrow1(10 , 350 , 17 , 343) , arrow2(10 , 350 ,17 , 357) ;
	Line arrow3(1380 , 350 , 1373 , 343 ) , arrow4(1380 , 350 , 1373 , 357 ) ;
	Line arrow5(650 , 10 , 643 , 17 ) , arrow6 ( 650 , 10 , 657 , 17) ;
	Line arrow7(650 , 690 , 643 , 683) , arrow8 ( 650 , 690 , 657 , 683) ;
        double x = xleft , dx = 0.1 , ymax = valueAt(xleft) , ymin = valueAt(xright) ;
      	while( x <= xright) 
	{
        	if(valueAt(x) > ymax)
		{
			ymax = valueAt(x);
		}
                if(valueAt(x)<ymin) 
		{
			ymin = valueAt(x);
		}
                x = x + dx ;
        }
	Text t(670 , 360 , "(0,0)") ;
	Text t1(680 , 10 , "Y-AXIS") ;
	Text t2(1270 , 360 , "X-AXIS") ;
	i = -55 ; 
	while ( i < 60 )
	{
		if ( i != 0 )
		{
			Text t3(650 + 10 * i , 360 , i) ;
			t3.imprint() ;
		}
		i = i + 5 ;
	}
	i = -30 ;
	while ( i < 35 )
	{
		if ( i != 0 )
		{
			Text t4(640 , 360 - 10 * i , i ) ;
			t4.imprint() ;
		}
		i = i + 5 ;
	}
	Text t5 (1100 , 10 , "SCALE:") , t6 (1175 , 25 , "ON X-AXIS : 10 PIXELS = 1 UNIT") ;
	Text t7 (1175 , 40 , "ON Y-AXIS : 10 PIXELS = 1 UNIT") ;
	Rectangle r (1175 , 28 , 210 , 50) ;
	x = xleft ;
	while ( (xleft <= x) && (x < xright) )
	{
		if ( abs(valueAt(x)) <= 75 ) 
		{
			if ( (x + dx) <= xright)
			{
				Line l(650 + 10 * x , 350 - 10 * valueAt(x) , 650 + 10 * (x + dx) , 350 - 10 * valueAt(x + dx)) ;
				l.imprint() ;
			}
			else
			{
				Line l(650 + 10 * x , 350 - 10 * valueAt(x) , 650 + 10 * (xright) , 350 - 10 * valueAt(xright)) ;
				l.imprint() ;
			}
		}
		else
		{
			x = x + dx ;
			continue ;
		}
		x = x + dx ;
	}
	getClick() ;
}

