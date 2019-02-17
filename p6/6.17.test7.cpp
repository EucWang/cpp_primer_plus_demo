#include <iostream>
#include <string>
#include <cctype>

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    // 在拉丁字母中，A、E、I、O、U通常都是元音字母
    //其他的除Y和W是半元音字母以外的都是辅音字母

    int count_vowels; //以元音字母开头的单词数
    int count_consonants; //以辅音字母开头的单词数
    int count_other;
    // char tmp[32];
    string tmp;

    cout << "Enter words (q to exit): " << endl;
    while(cin >> tmp){
        if (tmp == "q") {
            break;
        }

        if(!isalpha(tmp[0])){
            count_other++;
        }else {
            switch (tmp[0])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    count_vowels++;
                    break;
                case 'y':
                case 'Y':
                case 'w':
                case 'W':
                    count_other++;
                break;
                default:
                    count_consonants++;
                    break;
            }
        }
    }
    
    cout << count_vowels << " words begining with vowels.\n"
        << count_consonants << " words begining with consonants.\n"
        << count_other << " words others.\n";
    
    cout<<endl;
    return 0;
}
