#include "Stock.h"
#include "Arr_Queue.h"



int main() {

	Stock a("Google", 1000, 22.5);
	Stock b("Microsoft", 200, 33.6);
	Stock d("Apple", 300 , 44.5);
	Stock e("Apple", 20 , 45.5);
	Stock f("Apple", 40 , 64.5);
	Stock g("Apple", 60 , 84.7);
	Stock h("Apple", 23 , 94.3);
	Stock i("Apple", 50 , 101.3);
	Stock j("Apple", 600 , 254.3);

	Queue* q = new Queue(); 
	q->push(a);
	q->push(b);
	q->push(j);
	q->push(d);
	q->push(e);
	q->push(f);
	q->push(g);
	q->push(h);

	double res = q->calculateSP(j, 555); 

	std::cout << res; 

	return 0; 
}