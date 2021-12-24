#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

vector<string> expr;
class deque {
	vector<string> Queue;
public:
	void input(const vector<string> expr)
	{
		if (expr[0] == "size")
			cout << size() << endl;
		else if (expr[0] == "empty")
			cout << empty() << endl;
		else if (expr[0] == "front")
			cout << front() << endl;
		else if (expr[0] == "rear")
			cout << rear() << endl;
		else if (expr[0] == "add")
			addPos(expr);
		else if (expr[0] == "delete")
			delPos(expr);
	}
	void addPos(const vector<string> expr)
	{
		if (expr[1] == "front")
		{
			Queue.insert(Queue.begin(), expr[2]);
		}
		else if (expr[1] == "rear")
		{
			Queue.push_back(expr[2]);
		}
	}
	void delPos(const vector<string> expr)
	{
		if (Queue.empty() == true)
		{
			cout << "empty" << endl;
		}
		else {
			if (expr[1] == "front")
			{
				string str = Queue.front();
				Queue.erase(Queue.begin());
				cout << str << endl;
			}
			else if (expr[1] == "rear")
			{
				string str = Queue.back();
				Queue.pop_back();
				cout << str << endl;
			}
		}
	}
	int size()
	{
		int a;
		if (Queue.empty() == true)		
			a = 0;
		else {
			a = Queue.size();
		}
		return a;
	}
	string empty()
	{
		string a;
		if (Queue.empty() == true)
			a = "empty";
		else
			a = "not empty";

		return a;
	}
	string front()
	{
		string a;
		if (Queue.size() == 0)
			a = "empty";
		else
			a = Queue.front();
		return a;
	}
	string rear()
	{
		string a;
		if (Queue.size() == 0)		
			a = "empty";		
		else
			a = Queue.back();
		return a;
	}
};

int main()
{
	int num = 0;
	cin >> num;
	cin.ignore();
	deque d;

	string line, token;
	for (int i = 0; i < num; i++)
	{
		getline(cin, line);
		stringstream ss(line);

		while (getline(ss, token, ' '))
			expr.push_back(token);
		d.input(expr);
		expr.clear();
	}


	return 0;
}