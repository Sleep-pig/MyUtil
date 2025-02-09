#pragma once

#include <iostream>
#include <string>
class Human {

public:
    virtual std::string praytoGod() = 0;
    virtual void action(std::string str) = 0;
};

class Fransh : public Human {
public:
    std::string praytoGod() override
    {
        return "Fransh pray to God";
    }
    void action(std::string str) override
    {
        std::cout << "Fransh action after God said:" << str << std::endl;
    }
};

class Armerican : public Human {
public:
    std::string praytoGod() override
    {
        return "Armerican pray to God";
    }
    void action(std::string str) override
    {
        std::cout << "Armerican action after God said:" << str << std::endl;
    }
};

class God {
public:
    void listen(std::string const& word)
    {
        std::cout << "God listen:  " << word << std::endl;
    }

    std::string say()
    {
        return "God say:fxxk";
    }
};

class AbastractAdapter {
public:
    Human* human;
    God* god;
    AbastractAdapter(Human* human, God* god)
        : human(human)
        , god(god)
    {
    }

    virtual void translate_to_god(std::string str) = 0;
    virtual void translate_to_human(std::string str) = 0;
};

class FranshAdapter : public AbastractAdapter {
public:
    FranshAdapter(Human* human, God* god)
        : AbastractAdapter(human, god)
    {
    }

    void translate_to_god(std::string word) override
    {
        god->listen(word);
    }

    void translate_to_human(std::string word) override
    {

        human->action(word);
    }
};

class ArmericanAdapter : public AbastractAdapter {
public:
    ArmericanAdapter(Human* human, God* god)
        : AbastractAdapter(human, god)
    {
    }

    void translate_to_god(std::string word) override
    {

        god->listen(word);
    }

    void translate_to_human(std::string word) override
    {
        human->action(word);
    }
};

void test()
{
    Fransh* fransh = new Fransh();
    Armerican* armerican = new Armerican();
    God* god = new God();
    FranshAdapter* franshAdapter = new FranshAdapter(fransh, god);
    ArmericanAdapter* armericanAdapter = new ArmericanAdapter(armerican, god);
    auto word = fransh->praytoGod();
    franshAdapter->translate_to_god(word);
    auto Godsay = god->say();
    franshAdapter->translate_to_human(Godsay);

    word = armerican->praytoGod();
    armericanAdapter->translate_to_god(word);
    Godsay = god->say();
    armericanAdapter->translate_to_human(word);
    delete fransh;
    delete armerican;
    delete god;
    delete franshAdapter;
    delete armericanAdapter;
}