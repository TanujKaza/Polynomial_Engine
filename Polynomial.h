#include<iostream>
#include<simplecpp>
#include<cmath>
#include<algorithm>
using namespace std ;

class Polynomial
{
	private:
		int m_degree ;
		bool b ;
		double *coefficient ;
		double *root ;
		int N_O_R;
	public:
		Polynomial() ;
		Polynomial(int m_deg);
		Polynomial(Polynomial const &p);
		~Polynomial() ;
		void read() ;
		void print();
		friend Polynomial operator+ (const Polynomial &p , const Polynomial &q) ;
	        Polynomial const operator= (const Polynomial &p ) ;
		friend Polynomial operator- (const Polynomial &p , const Polynomial &q) ;
		friend Polynomial operator* (const Polynomial &p , const Polynomial &q) ;
		friend Polynomial operator/ (Polynomial &p , Polynomial &q) ;
		friend Polynomial operator% (Polynomial &p , Polynomial &q) ;
		friend double newton_root (Polynomial &p , double xl , double xr) ;
		friend void root (Polynomial &p) ;
        void root_all () ;
        void print_root();
		double valueAt(double x) ;
		Polynomial derivative() ;
		Polynomial indef_integral () ;
		double def_integral (double x1 , double x2) ;
		void plot(double xleft , double xright) ;
};


