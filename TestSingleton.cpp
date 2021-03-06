#include "TestSingleton.h"
#include <pthread.h>

#define NumThreads 8

void *test_singleton_without_thread(void *) {
    //new Singleton(); // Won't work
    Singleton *s = Singleton::getInstance(); // Ok
    Singleton *r = Singleton::getInstance();

    /* The addresses will be the same. */
    std::cout << s << std::endl;
    std::cout << r << std::endl;
}

void *create_singleton(void *argv) {
    Singleton *s = Singleton::getInstance();
    std::cout << s << std::endl;
}


void test_singleton_with_thread() {
    pthread_t threads[NumThreads];
    int i = 0;

    for (; i < NumThreads; ++i) {/*create threads for producers*/

        pthread_create(&threads[i], NULL, create_singleton, (void *) i);
    }
    for (i = 0; i < NumThreads; ++i) {/*join to all threads for consumers*/
        pthread_join(threads[i], NULL);

    }
}

