#include <list>
#include <iostream>

using namespace std;

int main(){
	std::list<int> c0{ 1, 2, 3, 4, 5 };
	printf("c0.begin()=%d, c0.end()=%d\n", c0.begin(), c0.end());
	list<int>::reverse_iterator it;
	int count = 0;
	for (it = c0.rbegin(); it != c0.rend(); it++)count++;
	cout <<"count ="<< count << endl;
	return 0;
}