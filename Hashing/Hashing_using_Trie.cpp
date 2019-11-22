#define ll long long
#include <iostream>
using namespace std;

const int TRIE_NODE_MAXLEN = 1e5;
const int ALPHABET_COUNT = 2;
struct Trie
{
    bool end;
    int next[ALPHABET_COUNT];
};

int trie_count;
Trie trie_pool[TRIE_NODE_MAXLEN];

int get_node()
{
    trie_count++;
    for (int i = 0; i < ALPHABET_COUNT; i++)
    {
        trie_pool[trie_count].next[i] = -1;
    }
    trie_pool[trie_count].end = false;
    return trie_count;
}

void insert_trie(int node, string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - '0';
        if (trie_pool[node].next[index] == -1)
        {
            trie_pool[node].next[index] = get_node();
        }
        node = trie_pool[node].next[index];
    }
    trie_pool[node].end = true;
}

bool find(int node, string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - '0';
        if (trie_pool[node].next[index] == -1)
        {
            return false;
        }
        node = trie_pool[node].next[index];
    }
    return trie_pool[node].end;
}

int get_hash(string s)
{
    const int m = 1e9;
    const int p = 31;
    ll hash_val = 0;
    ll p_pow = 1;

    for (int i = 0; i < s.size(); i++)
    {
        hash_val = (hash_val + p_pow * (s[i] - 'a' + 1)) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_val;
}

string dec_to_bin(ll num)
{
    string bin = "";
    while (num > 0)
    {
        bin += (num & 1) ? '1' : '0';
        num >>= 1;
    }
    return bin;
}

void init()
{
    trie_count = 0;
    for (int i = 0; i < ALPHABET_COUNT; i++)
    {
        trie_pool[0].next[i] = -1;
    }
    trie_pool[0].end = false;
}

int main()
{
    init();
    string dict[] = {"hello", "world", "test", "a", "aa", "aaa", "adadetetrete"};
    int length = sizeof(dict) / sizeof(dict[0]);
    for (int i = 0; i < length; i++)
    {
        ll hash_val = get_hash(dict[i]);
        string bin = dec_to_bin(hash_val);
        insert_trie(0, bin);
    }
    string test_dict[] = {"hello", "aa", "aaaa", "adadet"};
    length = sizeof(test_dict) / sizeof(test_dict[0]);
    for (int i = 0; i < length; i++)
    {
        ll hash_val = get_hash(test_dict[i]);
        string bin = dec_to_bin(hash_val);
        cout << ((find(0, bin)) ? "found" : "not found") << endl;
    }
    return 0;
}