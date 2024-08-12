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
