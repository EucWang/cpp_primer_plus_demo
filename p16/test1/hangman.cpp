// 16.3 hangman.cpp  some string methods

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>

#include "str1.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::tolower;

const int  NUM = 26;

const string wordlist[NUM] = {
    "apiary", "beetle", "cereal", 
    "danger", "ensign", "florid",
    "garage", "health", "insult",
    "jackal", "keeper", "loaner",
    "manage", "nonce", "onset",
    "plaid", "quilt", "remote",
    "stolid", "train", "useful",
    "valid", "whence", "xenon",
    "yearn", "zippy"};

int main_hangerman(){
    // cout << "main_hangerman";

    std::srand(std::time(0));  //随机数种子

    char play;
    cout << "Will you play a word game?<y/n>";
    cin >> play;
    play = tolower(play);

    while(play == 'y') {
        string target = wordlist[std::rand() % NUM];  //从数组中随机得到一个字符串
        int length = target.length();   //得到字符串长度
        
        string attempt(length, '-');   //猜测过程中到临时字符串
        string badchars;               //猜错的字符拼接结果
        int guesses = 6;  //只能猜6次
        cout << "Guess my secret word. It has " << length 
            << " letters, and you guess\n"
            << "one letter at a time. you get " << guesses
            << " wrong guessses.\n";

        cout << "Your word: " << attempt << endl;
        while(guesses > 0 && attempt != target) {
            char letter;
            cout << "Guess a letter: " ;
            cin >> letter;
            if(badchars.find(letter) != string::npos 
                || attempt.find(letter) != string::npos) {
                cout << "You already guessed that. Try again.\n";
                continue;
            }

            int loc = target.find(letter);   //在字符串中查找某个字符
            if(loc == string::npos) {        //判断是否找到了
                cout << "Oh, bad guess!\n";
                --guesses;
                badchars += letter;    //拼接字符串
            } else {
                cout << "Good guess!\n";
                attempt[loc] = letter;
                loc = target.find(letter, loc+1);   //从字符串第n个位置开始查找，得到索引值
                while(loc != string::npos) {
                    attempt[loc] = letter;
                    loc = target.find(letter, loc+1);
                }
            }

            cout << "Your word: " << attempt << endl;
            if(attempt != target) {
                if(badchars.length() > 0) {
                    cout << "Bad choices: " << badchars << endl;
                }
                cout << guesses << " bad guesses left\n";
            }
        }

        if(guesses > 0) {
            cout << "That's right!\n";
        } else {
            cout << "Sorry, the word is " << target << ".\n";
        }

        cout << "Will you play another?<y/n>";
        cin >> play;
        play = tolower(play);
    }

    cout << "Bye!\n";
    return 0;
}