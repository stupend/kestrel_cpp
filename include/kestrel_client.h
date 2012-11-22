#ifndef KESTREL_CLIENT
#define KESTREL_CLIENT
 
//#include <libmemcached/memcached.hpp>
#include <iostream>
#include <list> 

using namespace std;

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
        // try put
        // success: return
        // fail: retry for N time
        // still fail - drop current server and use the next one.
        return 0;
    }

    void add_server(const char *host,const int port,int weight){
        server svr;
        alive_servers.push_back(svr);
        reset_server_mapping();
    }
 
private:

    int cacl_total_weight(){
        int total = 0;
        list<int>::iterator i;
        for(i=alive_servers.begin(); i != alive_servers.end(); ++i){
            total += i->weight;
        }
        return total;
    }

    void reset_server_mapping(){
        total_weight = cacl_total_weight();
        float ratio = total_weight/100.0;
        
    }

    server * get_candidate_server(){
        if( idx >= MAX_HASH_SIZE ){
            idx = 0;
        }
        server * svr = server_mapping[idx]; 
        idx++;
        return svr;
    }

    void disable_server(server * svr){
        alive_servers.remove(svr);
        dead_servers.push_back(svr);
        reset_server_mapping();
    }

    void reset_server_status(){
        alive_servers.insert(alive_servers.end(),dead_servers.begin(),dead_servers.end());
        dead_servers.clear();
        reset_server_status();
    }
    
    server * server_mapping[100];
    
    list<server*> dead_servers;
    
    list<server*> alive_servers;
    
    int total_weight = 0 ;
};
 
 
#endif// KESTREL_CLIENT
