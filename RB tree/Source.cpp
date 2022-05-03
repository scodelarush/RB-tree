#include <iostream>
#include "Map.h"
#include "Map.cpp"
#include <list>
#include <string>

using namespace std;

int main() {
	Map <int,int> ar;

	ar.insert(20, 0);
	ar.insert(10, 0);
	ar.insert(30, 0);

	ar.remove(30);

	list<int> keys = ar.getKeys();
	list<int> val = ar.getValues();

	for (auto x : keys) cout << x << " ";
	cout << '\n';
	for (auto x : val) cout << x << " ";
	cout << '\n';
}