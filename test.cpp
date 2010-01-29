#include <iostream>  
#include <fstream>  
#include "TinyDNSResolver.h"  
#include <pthread.h>
#include <stdlib.h>
using namespace std;  


void* thread_work(void* t)
{

	char * domain = "www.chinarank.org.cn";  
	char ip[16] = { '\0'} ;  
	int id = (int)t;
	TinyDNSResolver tr;  
	if (!tr.resolve(domain, ip, id)) {  
		cout << " dns resolve failed domain : "<<domain << endl;  
	}else{  
		cout<<"domain : "<<domain<<endl;  
		cout<<"ip     : "<<ip<<endl;  
	}  

	return NULL;
}
int main() {  
	pthread_t threads[4];

	int rc;
	void* status;
	for(int i=0; i<4; i++)
	{
		rc = pthread_create(&threads[i], NULL, thread_work, (void*)i);
		if(rc)
		{
			cout << "Create threads Error!" << endl;
			exit(-1);
		}
	}



	for(int i=0; i<4; i++)
	{
		rc = pthread_join(threads[i], &status);
		if(rc)
		{
			cout << "EORROR: return code from pthread_join is " << rc << endl;
			exit(-1);
		}
		cout << "Main: compeleted join with thread" << i << "having a status of" << (long int)status << endl;
	}

	return 0;  
}  
