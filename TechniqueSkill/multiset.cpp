#include <iostream>
#include <set>
using namespace std;

// std::multiset<T> objectName;

// 1. dulpicate objects of type key.
// 2. using Red-Black Tree.
// 3. Insertion, Removal, Search have logirathmic complexity.

int main()
{
	multiset<int, greater<int> > mset;
	multiset<int, greater<int> > ::iterator itr;

	mset.insert(40);
	mset.insert(40);
	mset.insert(40);
	mset.insert(30);
	mset.insert(60);
	mset.insert(20);
	mset.insert(50);
	mset.insert(50);
	mset.insert(10);

	cout << "mset : ";
	for (itr = mset.begin(); itr != mset.end(); ++itr)
		cout << *itr << ' ';
	cout << endl;

	cout << "Size : " << mset.size() << endl;

	cout << "[mset.begin(), mset.find(40)) erase\n";
	mset.erase(mset.begin(), mset.find(40));

	cout << "mset : ";
	for (itr = mset.begin(); itr != mset.end(); ++itr)
		cout << *itr << ' ';
	cout << endl;

	cout << "40 counts : " << mset.count(40) << endl;

	cout << "Max-Size : " << mset.max_size() << endl;

	cout << "erase 40\n";
	mset.erase(40);
	cout << "mset : ";
	for (itr = mset.begin(); itr != mset.end(); ++itr)
		cout << *itr << ' ';
	cout << endl;

	mset.clear();

	mset = { 1,2,3,4,5,5,5,3,3,9,10 };
	cout << "mset : ";
	for (itr = mset.begin(); itr != mset.end(); ++itr)
		cout << *itr << ' ';
	cout << endl;

	cout << "lower_bound(5) : " << *mset.lower_bound(5) << endl;
	cout << "upper_bound(5) : " << *mset.upper_bound(5) << endl;
	for (auto i = mset.lower_bound(5); i != mset.upper_bound(5); ++i)
		cout << *i << ' ';
	cout << endl;

	auto p = mset.equal_range(5);
	for (auto i = p.first; i != p.second; ++i)
		cout << *i << ' ';
	cout << endl;
	return 0;
}