#include <bits/stdc++.h>

// #define DEBUG
using namespace std;

list<stack<string>> piles;

int update()
{
	int idx = 1, updated = 0;
	for (auto target_iter = next(piles.begin()); target_iter != piles.end(); target_iter++, idx++)
	{
		const string &target = target_iter->top();
		int dist = min(idx, 3);
		for (auto iter = prev(target_iter, dist); iter != target_iter; iter++, dist--)
		{
			if (dist == 1 || dist == 3)
			{
				const string &tp = iter->top();
				if (tp[0] == target[0] || tp[1] == target[1])
				{
#ifdef DEBUG
					cout << "[MERGE] " << target << " to " << tp << '\n';
#endif
					iter->push(target);
					target_iter->pop();
					if (target_iter->empty())
					{
						target_iter = prev(piles.erase(target_iter));
						idx -= 1;
					}
					updated = 1;
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
		while (update())
			;
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