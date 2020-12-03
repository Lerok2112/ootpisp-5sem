#ifndef FACTORY_H
#define FACTORY_H

#include <QListView>
#include <QPushButton>
#include <QTextEdit>
#include <QTextCodec>

#include "mainwindow.h"
#include "ui_mainwindow.h"
//абстрактные и конкретные классы товаров фабрики
/**
 * Каждый отдельный продукт семейства продуктов должен иметь базовый интерфейс.
 * Все вариации продукта должны реализовывать этот интерфейс.
 */
class AbstractMyList {
public:
    virtual ~AbstractMyList() { }
    virtual QListView* UsefulFunctionMyList() const = 0;
};

class ConcreteMyList : public AbstractMyList {
public:
    QListView* UsefulFunctionMyList() const override {
        QListView* myList = new QListView();
        return myList;
    }
};

class AbstractMyInput {
public:
    virtual ~AbstractMyInput() { }
    virtual QTextEdit* UsefulFunctionMyInput() const = 0;
};

class ConcreteMyInput : public AbstractMyInput {
public:
    QTextEdit* UsefulFunctionMyInput() const override {
        QTextEdit* myInput = new QTextEdit();
        myInput->setText("Продукт фабрики Поле Ввода");
        return myInput;
    }
};

class AbstractMyButton {
public:
    virtual ~AbstractMyButton() { }
    virtual QPushButton* UsefulFunctionMyButton() const = 0;
};

class ConcreteMyButton : public AbstractMyButton {
public:
    QPushButton* UsefulFunctionMyButton() const override {
        QPushButton* myButton = new QPushButton();
         myButton->setText("Продукт фабрики Кнопка");
        return myButton;
    }
};

class AbstractMyLanguage {
public:
    virtual ~AbstractMyLanguage() { }
    virtual QTextCodec* UsefulFunctionMyLanguage() const = 0;
};

class ConcreteMyLanguage : public AbstractMyLanguage {
public:
    QTextCodec* UsefulFunctionMyLanguage() const override {
        QTextCodec* myLanguage = QTextCodec::codecForName("cp866"); // russian codek
        return myLanguage;
    }
};

//Абстрактная фабрика задаёт интерфейс создания всех доступных типов продуктов
class AbstractFactory {
public:
    virtual AbstractMyList* CreateMyList() const = 0;
    virtual AbstractMyInput* CreateMyInput() const = 0;
    virtual AbstractMyButton* CreateMyButton() const = 0;
    virtual AbstractMyLanguage* CreateMyLanguage() const = 0;
};

//конкретная фабрика порождает продукты одной из вариаций
class ConcreteFactory : public AbstractFactory {
    ConcreteFactory() { }
public:

    static ConcreteFactory* GetInstance()
    {
       static ConcreteFactory* instance = new ConcreteFactory();
       return instance;
    }

    AbstractMyList* CreateMyList() const override {
        return new ConcreteMyList();
    }

    AbstractMyInput* CreateMyInput() const override {
        return new ConcreteMyInput();
    }

    AbstractMyButton* CreateMyButton() const override {
        return new ConcreteMyButton();
    }

    AbstractMyLanguage* CreateMyLanguage() const override {
        return new ConcreteMyLanguage();
    }
};

#endif // FACTORY_H
