#include <iostream>
#include <string>
#include <map>
#include <cmath>
using namespace std;
class HashTable
{
private:
	map <string, long long> HashTab;
	int mod;
	
public:
	HashTable(int size)
	{
		mod = size;
	}
 
int BigMod(string num,int dev)
{
	if (num == "0")
		throw std::string("Division by zero!");
 
	if (num == "0" || dev == 1)
		return 0;
 
	if (num.length() < 9) {
		long res = stol(num) % dev;
		return res;
	}
 
	int tmp=dev;
	size_t length = num.length();
	size_t index = 0;
	int mod2 =dev;
	std::string v="0";
 
	while (stoi(v) < tmp && index < length)
		v += num[index++];
 
	do {
		if (stoi(v) >= tmp) {
 
				v =to_string(stol(v) % dev);
			
		}
 
		if (index <= length) {
			mod2 = stoi(v);
			v += num[index++];
		}
	} while (index <= length);
 
	if (mod2== 0)
		return 0;
 
	return mod2;
}
long long GetHash(string s)
{
	long long ind;
	int a;
	string str;
	string::size_type sz=0;
	for (size_t i = 0; i < s.length(); ++i)
	{
		 a=s[i];
		 str += to_string(a);
 
	}
	ind = BigMod(str, mod);
	if(search(ind)) return find(ind);
	else
	return ind;
}
int find (int n)
{ 
	int temp = n;
	for (auto it = HashTab.begin(); it != HashTab.end(); it++)
	{
		if (n == mod) break;
		if (it->second == n) return find(++n);
		
	}
	if (n == mod)
	{
		n = 0;
		for (auto it = HashTab.begin(); it != HashTab.end(); it++)
		{
			if(n==temp) throw std::string("Хеш таблица переполнена");
			if (it->second == n) return search(n++);
 
		}
	}
	return n;
}
bool search(int n)
{
	for (auto it = HashTab.begin(); it != HashTab.end(); it++)
	{
		
		if (it->second == n) return true;
 
	}
	return false;
}
bool Add(string str)
{
	if (HashTab.size() >= mod) return false;
	else {
		HashTab[str] = GetHash(str);
		return true;
	}
}
void Show()
{
	for (auto it=HashTab.begin(); it!= HashTab.end(); it++)
	{
		cout <<it->first<< ": " << it->second<< endl;
	}
}
};
