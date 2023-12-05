#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string str, key, k;
bool is_first = true;
int qwq = 0;
int ans_add; //第一个需求单词的位置（ans address）
int first_address=0; //指每一个单词开头的位置，提前记录，如果是第一个需求单词就把它记录到ans里
int main()
{
    getline(cin, key);
    getline(cin, str);
    for (int i = 0; i < key.length(); i++)
        key[i] = toupper(key[i]);  //强转大写（小写->大写，大写不变）
    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
//上述两步都转换为小写（tolower）也可以，只需要保证需求单词和字符串大小写一致即可
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            if (k == key) 
            {
                qwq++; //单词数++
                if (is_first) //如果找到的单词是第一个
                {
                    ans_add = first_address; //标记地址
                    is_first = false; //标记第一个已访问
                }
            }
            first_address = i + 1;//下一个单词的开头是空格结束的下一个
            k.clear(); //clear字符串清空操作
        }
        else
            k += str[i]; //string类型的字符串可以实现加法操作，此操作是将str[i]的内容添加到k的后面
    }
    if (is_first)
    {
        cout << "-1" << endl;
    }
    else
        cout << qwq << " " << ans_add << endl;
    return 0;
}
//clear：清空
//toupper：字符串内容全部转为大写（原来的大写不变）
//tolower : 字符串内容全部转为小写（原来的小写不变）