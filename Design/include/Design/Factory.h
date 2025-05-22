// Factory.h
#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <memory>
#include <string>

// 中国产品基类
class ChinaProduct {
public:
    virtual ~ChinaProduct() = default;
    virtual void use() const = 0;
};

// 中国具体产品A
class ConcreteProductA : public ChinaProduct {
public:
    void use() const override
    {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

// 中国具体产品B
class ConcreteProductB : public ChinaProduct {
public:
    void use() const override
    {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

// 工厂类
class Factory { // 简单工厂类，根据传入的参数创建不同的产品
                // 客户端只需要知道产品的类型即可，不直接依赖具体产品
public:
    std::unique_ptr<ChinaProduct> createProduct(const std::string& type)
    {
        if (type == "A") {
            return std::make_unique<ConcreteProductA>();
        } else if (type == "B") {
            return std::make_unique<ConcreteProductB>();
        } else {
            return nullptr;
        }
    }
};

class FactoryFunBase { // 工厂方法类，为每个产品提供一个具体工厂类
                       // 客户端直接调用具体工厂，不直接依赖具体产品
public:
    virtual std::unique_ptr<ChinaProduct> createProduct() = 0;
};

class ConcreteFactoryA : public FactoryFunBase {
public:
    std::unique_ptr<ChinaProduct> createProduct() override
    {
        return std::make_unique<ConcreteProductA>();
    }
};

class ConcreteFactoryB : public FactoryFunBase {
public:
    std::unique_ptr<ChinaProduct> createProduct() override
    {
        return std::make_unique<ConcreteProductB>();
    }
};

//简单工厂和工厂方法只适用于单一产品族，当产品族增加时，需要增加工厂类，不符合开闭原则





// 美国产品基类
class USAProduct {
public:
    virtual ~USAProduct() = default;
    virtual void use() const = 0;
};

// 美国具体产品A
class USAConcreteProductA : public USAProduct {
public:
    void use() const override
    {
        std::cout << "Using ConcreteProductA" << std::endl;
    }
};

// 美国具体产品B
class USAConcreteProductB : public USAProduct {
public:
    void use() const override
    {
        std::cout << "Using ConcreteProductB" << std::endl;
    }
};

class AbstractFactory { // 抽象工厂类，为每个产品族的相同种产品提供一个具体工厂类
                        // 例如有中国产品族和美国产品族 中国产品族有A和B两种产品 美国产品族有A和B两种产品
                        // 提供一个A工厂可以生产中国产品族的A产品和美国产品族的A产品
                        // 提供一个B工厂可以生产中国产品族的B产品和美国产品族的B产品

public:
    virtual std::unique_ptr<ChinaProduct> createCNProductA() = 0;
    virtual std::unique_ptr<USAProduct> createUSAProductB() = 0;
};

class ConcreteproductAFactory : public AbstractFactory {
public:
    std::unique_ptr<ChinaProduct> createCNProductA() override
    {
        return std::make_unique<ConcreteProductA>();
    }
    std::unique_ptr<USAProduct> createUSAProductB() override
    {
        return std::make_unique<USAConcreteProductB>();
    }
};

class ConcreteproductBFactory : public AbstractFactory {
public:
    std::unique_ptr<ChinaProduct> createCNProductA() override
    {
        return std::make_unique<ConcreteProductA>();
    }
    std::unique_ptr<USAProduct> createUSAProductB() override
    {
        return std::make_unique<USAConcreteProductB>();
    }
};

#endif // FACTORY_H