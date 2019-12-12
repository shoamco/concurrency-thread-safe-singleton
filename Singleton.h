//
// Created by shoam on 12/12/19.
//

#ifndef SINGLETONTHREADSAFE_SINGLETON_H
#define SINGLETONTHREADSAFE_SINGLETON_H
#include <unistd.h>
#include <iostream>
class Singleton{

    private:
        /* Here will be the instance stored. */
        static  Singleton* volatile instance;

        /* Private constructor to prevent instancing. */
        Singleton();

    public:
        /* Static access method. */
        static  Singleton* getInstance();
    };


//Singleton* Singleton::instance() {
//    if (pInstance == 0) {
//        Lock lock;
//        if (pInstance == 0) {
//            Singleton* temp = new Singleton; // initialize to temp
//            pInstance = temp; // assign temp to pInstance
//        }
//    }
//    return pInstance;
//}
//Singleton* Singleton::instance () {
//    Singleton* tmp = pInstance;
//    ... // insert memory barrier
//    if (tmp == 0) {
//        Lock lock;
//        tmp = pInstance;
//        if (tmp == 0) {
//            tmp = new Singleton;
//            ... // insert memory barrier
//            pInstance = tmp;
//        }
//    }
//    return tmp;
//}
#endif //SINGLETONTHREADSAFE_SINGLETON_H
