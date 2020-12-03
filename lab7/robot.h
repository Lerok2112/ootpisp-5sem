#ifndef ROBOT_H
#define ROBOT_H

#include <QString>
#include <QVector>

struct Module
{
    QString code;

    virtual QString ToString()
    {
        return "часть: " + code;
    }
};
struct Name : Module
{
    QString name;

    QString ToString() override
    {
        QString result= Module::ToString();

        return  "имя робота: " + name;
    }
};

struct Engine : Module
{
    QString type;

    QString ToString() override
    {
        QString result = Module::ToString();

        return result + "   тип движка: " + type;
    }
};

struct Head : Module
{
    double visability;

    QString ToString() override
    {
        QString result = Module::ToString();
        return result + "   вес головы: " + QString::number(visability);
    }
};

struct Body : Module
{
    QString material;

    QString ToString() override
    {
        QString result = Module::ToString();
        return result + "   материал изг: " + material;
    }
};

class Robot
{
    QVector<Module*>* modules;
    //public: QString name;

public:
    Robot()
    {
        modules = new QVector<Module*>();
    }

    void AddModule(Module* module)
    {
        modules->push_back(module);
    }
    QString GetInformation()
    {
        QString result;

        for (auto m : *modules)
        {
            result += m->ToString() + "\n";
        }

        return result;
    }

    ~Robot()
    {
        delete modules;
    }
};

#endif // ROBOT_H
