#include<iostream>
using namespace std;
class ComplexNumber{
	private:
		float real;
		float imag;
	public:
		ComplexNumber():real(0),imag(0.0){
			cout<<"Default constructor invoked"<<endl;
		}
		ComplexNumber(float r,float img):real(r),imag(img){
			cout<<"Parameterized constructor invoked"<<endl;
		}
		ComplexNumber(const ComplexNumber& c){
			real=c.real;
			imag=c.imag;
			cout<<"Copy constructor invoked"<<endl;
		}
		ComplexNumber& operator=(const ComplexNumber& c){
			if(this!=&c){
				real=c.real;
				imag=c.imag;
			}
			return *this;
		}
		ComplexNumber operator+(const ComplexNumber& other){
			ComplexNumber temp;
			temp.real=real+other.real;
			temp.imag=imag+other.imag;
			return temp;
		}
		ComplexNumber operator-(const ComplexNumber& other){
			ComplexNumber temp;
			temp.real=real-other.real;
			temp.imag=imag-other.imag;
			return temp;
		}
		ComplexNumber operator*(const ComplexNumber& other){
			ComplexNumber temp;
			temp.real=real * other.real - imag * other.imag;
			temp.imag=real * other.imag + imag * other.real;
			return temp;
		}
		bool operator==(const ComplexNumber& other){
			return (real== other.real  && imag==other.imag);
		}
		friend ostream& operator<<(ostream& out,ComplexNumber& other){
			if(other.imag<0){
				out<<other.real<<" - "<<abs(other.imag)<<"i"<<endl;
			}
			else{
				out<<other.real<<" + "<<abs(other.imag)<<"i"<<endl;
			}
			return out;
		}
};
int main(){
	ComplexNumber c1(7,2.5);
	cout<<c1<<endl;
	ComplexNumber c2;
	c2=c1;
	cout<<c2<<endl;
	if(c1==c2){
		cout<<"c1 and c2 are equal"<<endl;
	}
	else{
		cout<<"c1 and c2 are not equal"<<endl;
	}
	ComplexNumber c3;
	c3= c1 + c2;
	cout<<"The value of c1 + c2 is: "<<c3<<endl;
	c3=c1-c2;
	cout<<"The value of c1 - c2 is: "<<c3<<endl;
	c3=c1*c2;
	cout<<"The value of c1 * c2 is: "<<c3<<endl;
	
	return 0;
}