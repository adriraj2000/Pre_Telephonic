#include <bits/stdc++.h>
using namespace std;

string dayofWeek(string s)
{
    string yy = "";
    for (int i = 0; i < 4; i++)
    {
        yy += s[i];
    }
    int year = stoi(yy);
    int month = 0;
    for (int i = 5; i < 7; i++)
    {
        month = month * pow(10, i - 5) + (s[i] - '0');
    }
    int day = 0;
    for (int i = 8; i <= 9; i++)
    {
        day = day * pow(10, i - 8) + (s[i] - '0');
    }
    int t[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    int val = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
    if (val == 0)
        return "Sun";
    else if (val == 1)
        return "Mon";
    else if (val == 2)
        return "Tue";
    else if (val == 3)
        return "Wed";
    else if (val == 4)
        return "Thu";
    else if (val == 5)
        return "Fri";
    else
        return "Sat";
}

vector<pair<string, int>> func(vector<pair<string, int>> v)
{
    map<string, int> m;
    m["Mon"] = m["Tue"] = m["Wed"] = m["Thu"] = m["Fri"] = m["Sat"] = m["Sun"] = 0;
    for (int i = 0; i < v.size(); i++)
    {
        m[dayofWeek(v[i].first)] += v[i].second;
    }
    if (m["Sat"] == 0)
    {
        m["Sat"] = 2 * m["Sun"] - m["Mon"];
    }
    if (m["Fri"] == 0)
    {
        m["Fri"] = 2 * m["Sat"] - m["Sun"];
    }
    if (m["Thu"] == 0)
    {
        m["Thu"] = 2 * m["Fri"] - m["Sat"];
    }
    if (m["Wed"] == 0)
    {
        m["Wed"] = 2 * m["Thu"] - m["Fri"];
    }
    if (m["Tue"] == 0)
    {
        m["Tue"] = 2 * m["Wed"] - m["Thu"];
    }
    vector<pair<string, int>> ans;
    for (auto el : m)
    {
        ans.push_back({el.first, el.second});
    }
    return ans;
}

int main()
{
    vector<pair<string, int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int sum;
        cin >> sum;
        v.push_back({s, sum});
    }
    vector<pair<string, int>> ans = func(v);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}