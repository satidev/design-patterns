#ifndef SINGLETON_H
#define SINGLETON_H

namespace Iglberger
{
struct Singleton final
{
private:
    Singleton(){}
public:
    static Singleton& getInstance(){
        static Singleton inst{};
        return inst;
    }

    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const &) = delete;
    Singleton(Singleton &&) = delete;
    Singleton& operator=(Singleton &&) = delete;


};

void singletonEx();

}// Iglberger namespace.

#endif //SINGLETON_H