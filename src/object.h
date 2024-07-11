#include <string>

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
class xchange {
public:
    virtual std::string getStockType() = 0;
    virtual std::string getHolderName() const = 0;
    virtual int getStockCount() const = 0;
    virtual std::string getCurrency() const = 0;
    virtual int getValuePerStock() const = 0;

    virtual void setStockType(const std::string& type) = 0;
    virtual void setHolderName(const std::string& name) = 0;
    virtual void setStockCount(int count) = 0;
    virtual void setCurrency(const std::string& curr) = 0;
    virtual void setValuePerStock(int value) = 0;
};

class xchange_rate  {
public:
    virtual std::string getSource() const { return source; }
    virtual std::string getDestination() const { return destination; }
    virtual double getRatio() const { return ratio; }

    virtual void setSource(const std::string& src) { source = src; }
    virtual void setDestination(const std::string& dest) { destination = dest; }
    virtual void setRatio(double rat) { ratio = rat; }
};

class question {
public:
    virtual std::string getType() const = 0;
    virtual std::string getName() const = 0;
    virtual std::string getCurrency() const = 0;

    virtual void setType(const std::string& qType) = 0;
    virtual void setName(const std::string& qName) = 0;
    virtual void setCurrency(const std::string& curr) = 0;
};
