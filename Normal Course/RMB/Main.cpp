#include <iostream.h>
class RMB
{
private:
	int yuan;
public:
	RMB(int y=0):yuan(y){}
	RMB& operator--(){
		--yuan;
		return *this;
	}

	RMB operator +(RMB rr){return RMB(yuan+rr.yuan);}

	int operator >(RMB rr){return yuan>rr.yuan?1:0;}
	int operator >=(RMB rr){return yuan>=rr.yuan?1:0;}
	int operator ==(RMB rr){return yuan==rr.yuan?1:0;}
	int operator !=(RMB rr){return yuan!=rr.yuan?1:0;}

	friend ostream& operator <<(ostream& out, RMB rr);

	operator int(){return yuan;}
};
ostream& operator <<(ostream& out, RMB rr)
{
	out<<rr.yuan<<"гд"<<endl;
	return out;
}
int main()
{	
	RMB r1(6),r2(9),r3;
	r3=r1+r2;
	--r3;
	cout<<r3<<endl;
	return 0;
}