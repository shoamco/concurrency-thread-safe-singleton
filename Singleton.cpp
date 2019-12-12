#include "Singleton.h"
pthread_mutex_t lock;
 Singleton* volatile Singleton::instance = 0;

 Singleton*  Singleton::getInstance()
{
    sleep(2);

    if (instance == 0)
    {
        pthread_mutex_lock(&lock);
        if (instance == 0) {

            std::cout << "\n*****new  Singleton****\n";
//           instance = new Singleton();
            Singleton* volatile temp = new Singleton; // initialize to temp
            sleep(1);
            instance = temp; // assign temp to pInstance

        }
        pthread_mutex_unlock(&lock);
    }
    else{
        std::cout<<"\n****Already exists****\n";
    }


    return instance;
}

 Singleton::Singleton()
{
//    std::cout<<"in ctor of Singleton\n";
    std::cout<<"\n*****create new  Singleton****\n";


}