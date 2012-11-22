#include <iostream>
#include "kestrel_client.h"
 
int main()
{
    std::cout<<("hello world. \n");
    kestrel_client kc;
    char * queueName = "test";
    char * message = "test";
    kc.put(queueName,message,1);
}
