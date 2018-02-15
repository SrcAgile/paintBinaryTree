#ifndef COUNTER_H
#define COUNTER_H
static int count=0;
int getCount();
void clearCount();


int getCount(){
	return ++count;
}
void clearCount(){
	count=0;
}
#endif