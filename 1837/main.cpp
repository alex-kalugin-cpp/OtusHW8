//решение задачи 1837 : https://acm.timus.ru/problem.aspx?num=1837
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <limits>
#include <iomanip>
using namespace std;
//разбиение строки по разделителю
// скопировано с ДЗ2
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}
int main()
{
    // интересная задача, но решение в лоб прошло
    // число команд
    int N;
    string temp;
   // идея была про входным данным построить отношение игрок - игроки из одной команды
   // затем начиная с Isenbaev присваивать всем игрокам числа
    map<string, set<string>> teams;
    // результат игрок - число в виде строки
    map<string, string> result;
    // два временных вектора
    vector<string> currentPlayers,tempCurrentPlayers;
    // искомое число
    int currentLevel = 0;
    cin >> N;
    // грабли #1
    // https://stackoverflow.com/questions/5739937/using-getlinecin-s-after-cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i=0;i<N; ++i)
    {
       // команда
       getline(cin,temp);
       // игроки команды
       vector<string> tempVs = split(temp, ' ');
        //для каждого игрока в мапу помещаем тех, с кем он играл в одной команде
       for(auto it : tempVs)
       {
           // а заодно помещаем в результат, пока со значением по умолчанию
           result[it] = "undefined";
           //shitcode
           // воспользовался тем, что по условиям задачи в команде 3 игрока
           string pl1 = tempVs.at(0);
           string pl2 = tempVs.at(1);
           string pl3 = tempVs.at(2);
           teams[pl1].insert(pl2);
           teams[pl1].insert(pl3);
           teams[pl2].insert(pl1);
           teams[pl2].insert(pl3);
           teams[pl3].insert(pl1);
           teams[pl3].insert(pl2);
       }

    }
    //теперь работаем с нашей мапой teams выставляя числа
    // берем список игроков одного уровня, смотрим с кем они играли и если у них еще число не назначено - назначаем +1 к уровню текущего и формируем список следующего уровня
    if(teams.find("Isenbaev") != teams.end()) // грабли №2 забыл проверить наличие Исенбаева - запорол тест 3
    currentPlayers.push_back("Isenbaev"); // начинаем с легенды с уровнем 0
    while(!currentPlayers.empty())
    {
       // для каждого игрока из списка
      for(auto it: currentPlayers)
      {
          // присваиваем число если не было
          if(result[it] == "undefined")
            result[it] = to_string(currentLevel);
          // проверяем есть ли игрок в рабочей мапе, если нет - значит уже обработан
          auto toDelete = teams.find(it);
          if(toDelete != teams.end())
          {
              // всех сокомандников запоминаем, их будем проверять на следующем цикле
              for(auto it2: toDelete->second)
              {
                tempCurrentPlayers.push_back(it2);
              }
              // игрока удаляем
              teams.erase(toDelete);
          }
      }
      //готовимся к следующему шагу цикла
      currentPlayers.clear();
      //меняем список текущего уровня на список кандидатов на следующий уровень
      currentPlayers.swap(tempCurrentPlayers);
      // увеличиваем число
      currentLevel++;
    }
 // вывод
    for(auto it : result)
        cout << it.first << ' ' << it.second << endl;
    return 0;
}
