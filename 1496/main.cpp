// решение задачи 1496 https://acm.timus.ru/problem.aspx?num=1496
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    // задача простая, храним множество аккаунтов, при добавлении нового проверяем был ли он уже, если да - добавляем в множество спамеров
    int N;
    string tempstr;
    set<string> unique, spamers;
  cin >> N;
    for(int i=0;i<N;++i)
    {
       cin >> tempstr;
        if(unique.count(tempstr) == 1) spamers.insert(tempstr);
            else unique.insert(tempstr);
    }
     for(const auto& item : spamers)
         cout << item << endl;
  return 0;
}

