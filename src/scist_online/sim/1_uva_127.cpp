#include <bits/stdc++.h>

#define DEBUG
using namespace std;

list<stack<string>> piles;

#ifdef DEBUG
void pt_piles()
{
	cout << "Piles:";
	for (const auto &stk : piles)
	{
		cout << ' ' << stk.top() << '(' << stk.size() << ')';
	}
	cout << '\n';
}

#endif

int update()
{
	int updated = 0;
	for (auto target_iter = next(piles.begin()); target_iter != piles.end(); target_iter++)
	{
		const string &target = target_iter->top();
		auto iter = target_iter;
		int dist = 0;
		do
		{
			iter = prev(iter);
			++dist;
		} while (iter != piles.begin() && dist < 3);
		for (; iter != target_iter; iter++, dist--)
		{
			if (dist == 1 || dist == 3)
			{
				const string &tp = iter->top();
				if (tp[0] == target[0] || tp[1] == target[1])
				{
#ifdef DEBUG
					pt_piles();
					cout << "[MERGE] " << target << " to " << tp << '\n';
#endif
					iter->push(target);
					target_iter->pop();
					if (target_iter->empty())
					{
						piles.erase(target_iter);
						target_iter = iter;
					}
					updated = 1;
#ifdef DEBUG
					pt_piles();
#endif
					break;
				}
			}
		}
	}
	return updated;
}

int solve()
{
	piles.clear();
	for (int i = 0; i < 52; i++)
	{
		string str;
		cin >> str;
		if (str.at(0) == '#')
		{
			return 1;
		}
		piles.push_back(stack<string>({str}));
	}
	while (update())
		;
	cout << piles.size() << " pile" << (piles.size() > 1 ? "s" : "") << " remaining: ";
	for (const auto &stk : piles)
	{
		cout << ' ' << stk.size();
	}
	cout << '\n';
	return 0;
}

int main()
{
#ifndef DEBUG
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
	while (!solve())
		;
	return 0;
}