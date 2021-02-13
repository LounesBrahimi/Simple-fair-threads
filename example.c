#include <stdio.h>
#include "fthread.h"

void hello(){

	while(1){
		printf("Hello ");
		ft_thread_cooperate();
	}
}

void world(){

	while(1){
		printf("World ");
		ft_thread_cooperate();
	}
}

void welcome(){

	while(1){
		printf("Welcome!\n");
		ft_thread_cooperate();
	}
}

int main(){
	ft_scheduler_t scheduler = ft_scheduler_create();
	
	ft_thread_create(scheduler, hello, NULL, NULL);
	ft_thread_create(scheduler, world, NULL, NULL);
	ft_thread_create(scheduler, welcome, NULL, NULL);
	
	ft_scheduler_start(scheduler);
	
	ft_exit();
	return 0;
}
