#ifndef BUILDER_H
#define BUILDER_H

#include "robot.h"
#include<QLabel>

class RobotBuilder
{
public:
    virtual void returnName() = 0;
    virtual void BuildHead() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildEngine() = 0;
    virtual Robot* GetResult() = 0;

    virtual ~RobotBuilder() { }
};

class Robot_1_Builder : public RobotBuilder
{
    Robot* robot;

public:
    Robot_1_Builder()
    {
        robot = new Robot();
    }
    void returnName()override{
        Name *name=new Name;
        name->name="ROBOT_1";
        robot->AddModule(name);
    }
    void BuildBody() override
    {
        Body* body = new Body();
        body->code = "BODY";
        body->material = "ЖЕЛЕЗО";
        robot->AddModule(body);
    }

    void BuildHead() override
    {
        Head* head = new Head();
        head->code = "HEAD";
        head->visability = 11.5;
        robot->AddModule(head);
    }

    void BuildEngine() override
    {
        Engine* engine = new Engine();
        engine->code = "ENGINE";
        engine->type = "ЦЕЛЬНЫЙ";
        robot->AddModule(engine);
    }

    Robot* GetResult() override
    {
        return robot;
    }

    ~Robot_1_Builder() override
    {
        delete robot;
    }
};

class Robot_2_Builder : public RobotBuilder
{
    Robot* robot;

public:
    Robot_2_Builder()
    {
        robot = new Robot();
        //robot->name="QWQW";

    }
    void returnName()override{
        Name *name=new Name;
        name->name="ROBOT_2";
        robot->AddModule(name);
    }
    void BuildBody() override
    {
        Body* body = new Body();
        body->code = "BODY";
        body->material = "ЖЕЛЕЗО";
        robot->AddModule(body);
    }

    void BuildHead() override
    {
        Head* head = new Head();
        head->code = "HEAD";
        head->visability = 11.5;
        robot->AddModule(head);
    }

    void BuildEngine() override
    {
        Engine* engine = new Engine();
        engine->code = "ENGINE";
        engine->type = "V-ОБРАЗНЫЙ";
        robot->AddModule(engine);
    }

    Robot* GetResult() override
    {
        return robot;
    }

    ~Robot_2_Builder() override
    {
        delete robot;
    }
};

class Engineer
{
    RobotBuilder* builder;

public:
    Engineer(RobotBuilder* builder)
    {
        this->builder = builder;
    }

    void Construct()
    {
        builder->returnName();
        builder->BuildBody();
        builder->BuildHead();
        builder->BuildEngine();
    }
};

#endif // BUILDER_H
