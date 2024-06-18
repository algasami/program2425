/**
 * Implementation of Tarjan's Algorithm in CPP
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <memory>

struct node
{
    int key;
    std::vector<node *> v;

    node(int key) : key(key)
    {
        v.reserve(100); // speeds up stuff so you don't have to allocate memory too often
        std::cout << "Constructor Called!" << std::endl;
    }

    node(const node &t) : v(t.v), key(t.key)
    {
        std::cout << "Copy Constructor Called!" << std::endl;
    }

    node(node &&t) : v(std::move(t.v)), key(t.key)
    {
        std::cout << "Move Constructor Called!" << std::endl;
    }

    ~node()
    {
    }
};

void tarjan(const node &current, const node &parent, int &time, std::unordered_set<const node *> &visited, std::unordered_map<const node *, int> &discovery, std::unordered_map<const node *, int> &lowpoint, std::unordered_set<const node *> &aps)
{
    time++;
    size_t children = 0;
    bool isroot = &current == &parent;

    visited.insert(&current);
    discovery[&current] = lowpoint[&current] = time;

    for (const node *const adj_ptr : current.v)
    {
        if (visited.find(adj_ptr) == visited.end()) // not visited
        {
            children++;
            tarjan(*adj_ptr, current, time, visited, discovery, lowpoint, aps);
            lowpoint[&current] = std::min(lowpoint[&current], lowpoint[adj_ptr]);
            if (!isroot && lowpoint[adj_ptr] >= discovery[&current])
            {
                aps.insert(&current);
            }
        }
        else
        {
            lowpoint[&current] = std::min(lowpoint[&current], discovery[adj_ptr]);
        }
    }

    if (isroot && children >= 2)
    {
        aps.insert(&current);
    }
}

int main()
{
    std::vector<node> node_pool;
    node_pool.reserve(100);
    size_t amount;
    std::cin >> amount;
    for (size_t i = 0; i < amount; i++)
    {
        node_pool.push_back(node(static_cast<int>(i)));
    }
    int a, b;
    while (std::cin >> a >> b)
    {
        if (a == -1 || b == -1 || a >= amount || b >= amount)
        {
            break;
        }
        node_pool.at(a).v.push_back(&node_pool.at(b));
        node_pool.at(b).v.push_back(&node_pool.at(a));
    }

    std::unordered_set<const node *> visited;
    std::unordered_map<const node *, int> discovery, lowpoint;
    std::unordered_set<const node *> aps;
    int time = 0;

    for (const auto &node : node_pool)
    {
        if (visited.find(&node) == visited.end())
        {
            tarjan(node, node, time, visited, discovery, lowpoint, aps);
        }
    }
    for (const auto ptr : aps)
    {
        std::cout << ptr->key << std::endl;
    }
    return 0;
}