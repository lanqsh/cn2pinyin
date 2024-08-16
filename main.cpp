#include <string>
#include <map>
#include <iostream>
#include "zhtopy.hpp"

bool cmp(const std::string& a, const std::string& b) {
    return ZhToPY::instance()->zhToPY(a) < ZhToPY::instance()->zhToPY(b);
}

int main()
{
    std::string pinyin = ZhToPY::instance()->zhToPY("中文");  // "zhongwen"
    std::string jinpin = ZhToPY::instance()->zhToJP("中文");  // "ZW"
    std::string shouzimu = ZhToPY::instance()->zhToZM("中文");   // "Z"
    std::string abc = ZhToPY::instance()->zhToZM("abc");   // "a"
    std::string num = ZhToPY::instance()->zhToZM("1");   // "1"

    std::cout << pinyin << std::endl;
    std::cout << jinpin << std::endl;
    std::cout << shouzimu << std::endl;
    std::cout << abc << std::endl;
    std::cout << num << std::endl;

    // case default
    std::cout << "default:" << std::endl;
    {
        std::map<std::string, int> cities;
        cities["北京"] = 1;
        cities["上海"] = 2;
        cities["广州"] = 3;
        cities["深圳"] = 4;
        for (auto &city : cities)
        {
          std::cout << city.first << " " << city.second << std::endl;
        }
    }

    // case order by first letter
    std::cout << "order by first letter:" << std::endl;
    {
        std::map<std::string, int, decltype(&cmp)> cities(&cmp);
        cities["北京"] = 1;
        cities["上海"] = 2;
        cities["广州"] = 3;
        cities["深圳"] = 4;
        for (auto &city : cities)
        {
          std::cout << city.first << " " << city.second << std::endl;
        }
    }

    return 0;
}
