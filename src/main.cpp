#include <iostream>
#include "kestrel_client.h"
 
int main()
{
    std::cout<<("hello world. \n");
    kestrel_client kc;
    kc.put("","",1);
}
