#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string str, key, k;
bool is_first = true;
int qwq = 0;
int ans_add; //��һ�����󵥴ʵ�λ�ã�ans address��
int first_address=0; //ָÿһ�����ʿ�ͷ��λ�ã���ǰ��¼������ǵ�һ�����󵥴ʾͰ�����¼��ans��
int main()
{
    getline(cin, key);
    getline(cin, str);
    for (int i = 0; i < key.length(); i++)
        key[i] = toupper(key[i]);  //ǿת��д��Сд->��д����д���䣩
    for (int i = 0; i < str.length(); i++)
        str[i] = toupper(str[i]);
//����������ת��ΪСд��tolower��Ҳ���ԣ�ֻ��Ҫ��֤���󵥴ʺ��ַ�����Сдһ�¼���
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            if (k == key) 
            {
                qwq++; //������++
                if (is_first) //����ҵ��ĵ����ǵ�һ��
                {
                    ans_add = first_address; //��ǵ�ַ
                    is_first = false; //��ǵ�һ���ѷ���
                }
            }
            first_address = i + 1;//��һ�����ʵĿ�ͷ�ǿո��������һ��
            k.clear(); //clear�ַ�����ղ���
        }
        else
            k += str[i]; //string���͵��ַ�������ʵ�ּӷ��������˲����ǽ�str[i]��������ӵ�k�ĺ���
    }
    if (is_first)
    {
        cout << "-1" << endl;
    }
    else
        cout << qwq << " " << ans_add << endl;
    return 0;
}
//clear�����
//toupper���ַ�������ȫ��תΪ��д��ԭ���Ĵ�д���䣩
//tolower : �ַ�������ȫ��תΪСд��ԭ����Сд���䣩