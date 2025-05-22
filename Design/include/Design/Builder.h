#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
class RobotA {
public:
    void addPart(const std::string& part)
    {
        parts.push_back(part);
    }

    void show() const
    {
        for (const auto& part : parts) {
            std::cout << part << std::endl;
        }
    }
    std::vector<std::string> parts;
};

class RobotB {
public:
    void add(const std::string& name, const std::string& part)
    {
        parts.insert({ name, part });
    }

    void show() const
    {
        for (const auto& part : parts) {
            std::cout << part.first << " : " << part.second << std::endl;
        }
    }
    std::map<std::string, std::string> parts;
};

// 有两个类型的机器人，我们需要组装他

class Builder {
public:
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildArm() = 0;
    virtual void buildLeg() = 0;
};

// 两个具体的Builder 一个组装RobotA 一个组装RobotB
class RobotBuilderA : public Builder {
public:
    RobotBuilderA()
    {
        robot = new RobotA();
    }

    void buildHead() override
    {
        robot->addPart("RobotA Head");
    }

    void buildBody() override
    {
        robot->addPart("RobotA Body");
    }

    void buildArm() override
    {
        robot->addPart("RobotA Arm");
    }

    void buildLeg() override
    {
        robot->addPart("RobotA Leg");
    }

    RobotA* getRobot()
    {
        return robot;
    }
    RobotA* robot { nullptr };
};

class RobotBuilderB : public Builder {
public:
    RobotBuilderB()
    {
        robot = new RobotB();
    }

    void buildHead() override
    {
        robot->add("Head", "RobotB Head");
    }

    void buildBody() override
    {
        robot->add("Body", "RobotB Body");
    }

    void buildArm() override
    {
        robot->add("Arm", "RobotB Arm");
    }

    void buildLeg() override
    {
        robot->add("Leg", "RobotB Leg");
    }

    RobotB* getRobot()
    {
        return robot;
    }
    RobotB* robot { nullptr };
};

// 如果需要的话，我们可以定义一个Director类，用于组装机器人，将过程封装起来，并且可以随时更改组装的顺序和个数
class Director {
public:
    Director(Builder* builder)
        : builder(builder)
    {
    }

    void LessHeadbuild()
    {
        builder->buildBody();
        builder->buildArm();
        builder->buildLeg();
    }

    void Fullbuild()
    {
        builder->buildHead();
        builder->buildBody();
        builder->buildArm();
        builder->buildLeg();
    }

    Builder* builder;
};

void test()
{
    RobotBuilderA* robotBuilderA = new RobotBuilderA();
    RobotBuilderB* robotBuilderB = new RobotBuilderB();
    Director* directorA = new Director(robotBuilderA);
    Director* directorB = new Director(robotBuilderB);
    directorA->LessHeadbuild();
    directorB->Fullbuild();
    robotBuilderA->getRobot()->show();
    robotBuilderB->getRobot()->show();
    delete robotBuilderA;
    delete robotBuilderB;
    delete directorA;
    delete directorB;
}