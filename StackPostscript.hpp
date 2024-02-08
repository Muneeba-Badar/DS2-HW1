template <class T>
class StackPostscript{
    public:
        StackPostscript(){} //constructor
        ~StackPostscript(){} //destructor
        
        T add(T x, T y); //addition function
        T sub(T x, T y); //subtract function
        T mul(T x, T y); //multiply function
        T div(T x, T y); //divide function
        T sin(T x); //sin function
        T cos(T x); //cos function
        T mod(T x, T y); //mod function
        T exp(T x, T y); //exponential function
        T sqrt(T x); //square root function

        //havent defined them yet
        T dup(T x, T y); //duplicate the top stack item function
        T exch(T x, T y); //exchange top two stack items function
        T roll(T x, T y); //roll n stack items up j times function
    
};