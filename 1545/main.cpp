//решение задачи 1545 : https://acm.timus.ru/problem.aspx?num=1545
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int main()
{
   int N;
    cin >> N;
    char in1,in2,question;
    // задача элементарная, поэтому единственное пояснение - способ хранения словаря
    // ключ - первый символ, значение - вектор соотвктсвующих символу иероглифов
    map<char,vector<char>> vocabuary;
    for(int i=0; i<N ; i++)
    {
        cin >> in1 >> in2;
        vocabuary[in1].emplace_back(in2);
    }
     cin >> question;
    if(vocabuary.count(question) != 0)
    {
        for(const auto& it : vocabuary[question])
            cout << question << it << endl;
    }
}
