// решение задачи 1196 https://acm.timus.ru/problem.aspx?num=1196
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
int main() {
  // задача решается бинарным поиском по отсортированному вектору дат
  // преподавателя + несложный предварительный фильтр число записей
  // преподавателя
  int N = 0;
  // минимальные и максимальная значения в списке преподавателя, нужны для
  // предватительного фильтра
  int min = 0, max = 1000000000;
  // список преподавателя, по условиям задачи отсортированный вектор
  vector<int> prepYears;
  cin >> N;
  prepYears.reserve(N);
  int temp;
  for (int i = 0; i < N; i++) {
    //заполнение списка преподавателя
    cin >> temp;
    prepYears.emplace_back(temp);
  }
  // поскольку вектор отсортированный миниммум - первое значение
  min = prepYears.at(0);
  //максимум - последнее
  max = prepYears.at(N - 1);
  //данные студента
  int M = 0, result = 0;
  cin >> M;
  auto endd = prepYears.end();
  auto tlowerB = endd;
  // для каждой даты студента из интервала мин макс используем бинарный поиск по
  // датам преподавателя
  for (int i = 0; i < M; i++) {
    cin >> temp;
    //проверка даты на вхождение интервал
    // без этого простого фильтра не укладываемся в time limit
    if ((temp >= min) && (temp <= max)) {
      // проверка на наличие в списке
      tlowerB = lower_bound(prepYears.begin(), prepYears.end(), temp);
      if (tlowerB != endd && temp == (*tlowerB)) result++;
    }
  }
  cout << result << endl;
}
