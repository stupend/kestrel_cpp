#ifndef KESTREL_CLIENT
#define KESTREL_CLIENT
 
//#include <libmemcached/memcached.hpp>
#include <iostream>
 
class server{
public:
    int put(char * queueName,char * data,int timeout){
    }

private:
    int weight;
};

class kestrel_client{
public:
    int put(char * queueName,char * data,int timeout){
        using namespace std;
        cout<<"put"<<endl;
        // get a random 
    }

    int add_server(const char*host,const int port,int weight){
        
    }
 
private:
    int disable_server(){}
    int enable_server(){}
 
    server * disable_servers[10];
    server * available_servers[10];
};
 
 
#endif// KESTREL_CLIENT
