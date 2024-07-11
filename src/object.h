#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wsign-compare"

class stock_object{
private:
    void *pointer;
public:
    stock_object(){
        pointer = this;
    }
    void *getLifeTimePtr(){
        return pointer;
    }
};