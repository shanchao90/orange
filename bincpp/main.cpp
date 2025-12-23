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
        Complex operator--(int){
            --real;
            --image;
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
    if (other.image > 0 && other.real == 0) {
        os << other.image  << 'i'; }
    else if (other.image > 0) {
        os << other.real << '+' <<  other.image  << 'i'; }
    if (other.image == 0) {
        os << other.real; }
    if (other.image < 0 && other.real == 0) {
        os << other.image  << 'i'; }
    else if (other.image < 0) {
        os << other.real <<  other.image  << 'i'; }
    return os;
}  

void friendVisit(People*p){
    cout << "访问" << p->m_House << endl;
    cout << "访问" << p->m_Car << endl;
}


typedef enum{
    STATE_IDLE, //空闲
    STATE_RECEIVING, //接受数据
    STATE_PROCESSING, //处理数据
    STATE_SENDING, //发送 
    STATE_ERROR //错误
}State_t;

typedef State_t (*StateHandler)(void);


bool data_available(){
    return 1;
}


State_t handle_idle(void){
    if (data_available()) {
        return STATE_RECEIVING;
    }
    return STATE_IDLE;
}

bool receive_data(){
    return 1;
}

State_t handle_receiving(void) {
    receive_data();
    return STATE_PROCESSING;
}

State_t handle_processing(void) {
    return STATE_PROCESSING;
}

State_t handle_sending(void) {
    return STATE_SENDING;
}

State_t handle_error(void) {
    return STATE_ERROR;
}

const StateHandler state_table[] = {
    [STATE_IDLE] = handle_idle,
    [STATE_RECEIVING] = handle_receiving,
    [STATE_PROCESSING] = handle_processing,
    [STATE_SENDING] = handle_sending,
    [STATE_ERROR] = handle_error
};

void state_machine_run(void) {
    static State_t current_state = STATE_IDLE;
    current_state = state_table[current_state]();
}




int main(){
   Hero h;
   h.getHp();h.getHp();h.getHp();
   h.printCounter();
   People p;
   friendVisit(&p);
   PeopleFriend pf;
   pf.visit(&p);
   Complex a(0,0); 
   Complex b(0,2);
   Complex c(0,-2); 
   Complex d(1,0);
   Complex e(-1,0);
   Complex f(1,-9);
   Complex g(-1,9);
   cout << a << endl;
   cout << b << endl;
   cout << c << endl;
   cout << d << endl;
   cout << e << endl;
   cout << f << endl;
   cout << g << endl;
   return 0;
}
