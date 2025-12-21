#include <iostream>
#include <string>
using namespace std;

class Hero{
    public:
        Hero ():m_Hp(0),getHpCounter(0){}
        int getHp() const {
            getHpCounter++;
            return m_Hp;
        }
        void printCounter() const {
            cout << "Counter:" << getHpCounter << endl;
        }
    private:
        int m_Hp;
        mutable int getHpCounter;
};

class People{
        friend void friendVisit(People *p );
        friend class PeopleFriend;
    public:
        People() {
            m_House = "别墅";
            m_Car = "跑车";
        }
        string m_House;
    private:
        string m_Car;
};

class PeopleFriend {
    public: 
        PeopleFriend(){
        
        }
        void visit(People*p){
            cout << "朋友访问" << p->m_House << endl;
            cout << "朋友访问" << p->m_Car << endl;
        }
};

class Complex{
    friend bool operator==(const Complex &a,const Complex &b);
    friend ostream& operator<<(ostream& os,const Complex &other); 
    public:
        Complex():real(0),image(0){
        
        }
        Complex(int real ,int image) {
            this->real = real;
            this->image = image;
        }
        Complex operator+(const Complex &other)const {
            Complex ret;
            ret.real = this->real + other.real;
            ret.image = this->image + other.image;
            return ret;
        }
        Complex operator-(const Complex &other)const {
            Complex ret;
            ret.real = this->real - other.real;
            ret.image = this->image - other.image;
            return ret;
        } 
        Complex operator*(const Complex &other)const {
            Complex ret;
            ret.real = this->real * other.real - this->image * other.image;
            ret.image = this->image * other.real + other.image * this->real;
            return ret;
        }
        void Print() {
            if (image > 0)
                cout << this->real << '+' <<  this->image  << 'i' << endl;
            if (image == 0)
                cout << this->real << endl;
            if (image < 0)
                cout << this->real <<  this->image  << 'i' << endl;
        }
        
        Complex& operator++(){
            this->real += 1;
            this->image += 1;
            return *this;
        }
        Complex& operator--(){
            this->real -= 1;
            this->image -= 1;
            return *this;
        }
        Complex operator++(int){
            ++real;
            ++image;
            return Complex(real,image); 
        } 
    private:
        int real;
        int image;

};

bool operator==(const Complex &a,const Complex &b) {
    return (a.real == b.real) && (a.image == b.image);
}
 
ostream& operator<<(ostream& os,const Complex &other) {
    if (other.image > 0) {
        os << other.real << '+' <<  other.image  << 'i'; }
    if (other.image == 0) {
        os << other.real; }
    if (other.image < 0) {
        os << other.real <<  other.image  << 'i'; }
    return os;
} 

    

void friendVisit(People*p){
    cout << "访问" << p->m_House << endl;
    cout << "访问" << p->m_Car << endl;
}

int main(){
   Hero h;
   h.getHp();h.getHp();h.getHp();
   h.printCounter();
   People p;
   friendVisit(&p);
   PeopleFriend pf;
   pf.visit(&p);
   Complex a(10,-20); 
   Complex b(1,2);
   Complex c (3,0);
   return 0;
}
