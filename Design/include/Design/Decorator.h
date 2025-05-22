#pragma once
#include <iostream>
class Tiger {
public:
    virtual void prey() = 0;
    virtual ~Tiger() = default;
};

class AncientTiger : public Tiger {
public:
    void prey() override
    {
        std::cout << "AncientTiger running" << std::endl;
        std::cout << "AncientTiger prey the food" << std::endl;
    }
};

class AbstractDecorator : public Tiger {
public:
    AbstractDecorator(Tiger* tiger)
        : tiger(tiger)
    {
    }
    void prey() override
    {
        tiger->prey();
    }
    virtual void NewSkill() = 0;
    Tiger* tiger;
};

class NewAgeTiger : public AbstractDecorator {
public:
    NewAgeTiger(Tiger* tiger)
        : AbstractDecorator(tiger)
    {
    }
    void NewSkill() override
    {
        std::cout << "NewAgeTiger has new skill:fly!!!!!!" << std::endl;
    }
    void prey() override
    {
        NewSkill();
        tiger->prey();
    }
};

// 修饰器模式 用于动态的给一个对象添加一些额外的职责
// 动态是因为可以在运行时根据需要添加或删除装饰器，而不是在编译时确定

// 例如，我们可以在运行时决定是否给老虎添加飞行技能
// 区别于继承，如果某一个对象需要新的东西，继承的话，需要新建一个类，旧的对象就不能用了 这导致了类的爆炸
// 但是修饰器模式可以在运行时动态的添加新的功能 旧的对象还可以继续使用
// 0-A（B）-0   从0开始，有AB四个方法，继承的话 就得new一个有A/BB ，原来的0就不能用了，要是想回到0 又得new一个0
// 而修饰器模式可以在0的基础上添加A，0还是0，要是不想要A/BB了，就把A/B去掉，0还是0
// 而多个复合的话，继承就得有A B AB三个子类，随着方法的增多，子类的数量会呈指数级增长
//而修饰器需要多少个方法就有多少个子类，不会呈指数级增长，比如说要从0到A再到AB  0-A(0)-B(0)  0就有了AB两个方法
void example()
{
    Tiger* tiger = new AncientTiger();
    tiger->prey();

    std::cout << "---------------------   " << std::endl;

    // 动态添加飞行技能
    Tiger* decoratedTiger = new NewAgeTiger(tiger);
    decoratedTiger->prey();

    // 如果需要，可以在运行时移除装饰器
    delete decoratedTiger;
    tiger->prey();

    delete tiger;
}
