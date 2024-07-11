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