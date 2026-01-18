#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string name;

    cin >> name;

    cout << "Ваше имя: " << name << endl;

    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);


    tm local_time;
    localtime_s(&local_time, &now_time);

    cout << "\nТекущая дата:" << endl;

    cout << "День.Месяц.Год: "
        << setfill('0') << setw(2) << local_time.tm_mday << "."
        << setfill('0') << setw(2) << (local_time.tm_mon + 1) << "."
        << (local_time.tm_year + 1900) << endl;

    cout << "Дата: "
        << (local_time.tm_year + 1900) << "-"
        << setfill('0') << setw(2) << (local_time.tm_mon + 1) << "-"
        << setfill('0') << setw(2) << local_time.tm_mday << endl;


    const char* months[] = {
        "Января", "Февраля", "Марта", "Апреля", "Мая", "Июня",
        "Июля", "Августа", "Сентября", "Октября", "Ноября", "Декабря"
    };

    const char* weekdays[] = {
        "Воскресенье", "Понедельник", "Вторник", "Среда",
        "Четверг", "Пятница", "Суббота"
    };

    cout << "Полный: "
        << weekdays[local_time.tm_wday] << ", "
        << local_time.tm_mday << " "
        << months[local_time.tm_mon] << " "
        << (local_time.tm_year + 1900) << " года" << endl;

    cout << "Время: "
        << setfill('0') << setw(2) << local_time.tm_hour << ":"
        << setfill('0') << setw(2) << local_time.tm_min << ":"
        << setfill('0') << setw(2) << local_time.tm_sec << endl;

    return 0;
}
