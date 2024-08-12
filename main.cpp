#include <string>
#include <iostream>
#include "zhtopy.hpp"

int main()
{
    std::string pinyin = ZhToPY::instance()->zhToPY("中文");  // pinyin : "zhongwen"
    std::string jinpin = ZhToPY::instance()->zhToJP("中文");  // jinpin : "ZW"
    std::string shouzimu = ZhToPY::instance()->zhToZM("中文");   // shouzimu: "Z"
    std::string abc = ZhToPY::instance()->zhToZM("abc");   // shouzimu: "a"
    std::string abc1 = ZhToPY::instance()->zhToZM("1");   // shouzimu: "1"

    std::cout << jinpin << std::endl;
    std::cout << shouzimu << std::endl;
    std::cout << abc << std::endl;
    std::cout << abc1 << std::endl;
    return 0;
}
