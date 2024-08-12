# zhtopy
Chinese pinyin to the first letter

中文字符串转首字母,主要是为了进行排序


示例
```
    std::string pinyin = ZhToPY::instance()->zhToPY("中文");  // pinyin : "zhongwen"
    std::string jinpin = ZhToPY::instance()->zhToJP("中文");  // jinpin : "ZW"
    std::string shouzimu = ZhToPY::instance()->zhToZM("中文");   // shouzimu: "Z"
    std::string abc = ZhToPY::instance()->zhToZM("abc");   // shouzimu: "a"
    std::string abc1 = ZhToPY::instance()->zhToZM("1");   // shouzimu: "1"  
```

用于容器排序
```
bool cmp(const std::string& a, const std::string& b) {
    return ZhToPY::instance()->zhToPY(a) < ZhToPY::instance()->zhToPY(b);
}
```

默认情况的输出:
- 上海 2
- 北京 1
- 广州 3
- 深圳 4

```
    std::map<std::string, int> cities;
    cities["北京"] = 1;
    cities["上海"] = 2;
    cities["广州"] = 3;
    cities["深圳"] = 4;
    for (auto &city : cities)
    {
        std::cout << city.first << " " << city.second << std::endl;
    }
```

排序情况的输出:
- 北京 1
- 广州 3
- 上海 2
- 深圳 4

``` 
    std::map<std::string, int, decltype(&cmp)> cities(&cmp);
    cities["北京"] = 1;
    cities["上海"] = 2;
    cities["广州"] = 3;
    cities["深圳"] = 4;
    for (auto &city : cities)
    {
        std::cout << city.first << " " << city.second << std::endl;
    }
```