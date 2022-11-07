/*
21. В   некотором   компиляторе   ПАСКАЛя  текст  программы включает примечания, выделенные  фигурными  скобками  '{', '}'
либо  парами  символов  '(*'  и  '*)'.Примечания  могут быть вложенными друг в друга.Если примечание открыто знаком  '{',
то оно должно быть закрыто знаком '}'.Аналогично примечание, начинающееся с символов '(*'  должно  заканчиваться  символами '*)'.
Требуется: 
1) проверить правильность вложенности примечаний;
2) переписать   файл   с   исходным   текстом   так, чтобы отсутствовала  вложенность  комментариев  при  сохранении   их
содержания  и  в  качестве  ограничивающих  символов  остались только  фигурные  скобки.Учесть   случай, когда   символы
примечаний находятся в апострофах (10).

3) обработать, если "{" или "}" это символ
4) при ошибке вывести номер строки и позиции
5) если комментарий "(* ... *)" после парсинга заменить на { }
*/

#include <iostream>
#include <string>
#include <fstream>

#include "Handler.h"
#include "Stack.h"

using namespace std;

//const string host = "D:\\Study\\DataStructures\\Labs\\Labs\\_forTest";  //noteBook host
const string host = "C:\\Games\\forTest";

    string getCommentSymbol(string line, int symbolNumberInLine) {                
        string test = line.substr(symbolNumberInLine, 1);
        if (test == "{") {
            return "{";
        }
        else if (test == "}") {
            return "}";
        }            
        test = line.substr(symbolNumberInLine, 2);
        if (test == "(*") {
            return "(*";
        }
        else if (test == "*)") {
            return "*)";
        }
        return "error";                
    }

    void checkProgramText() {
        string line;
        ifstream in(host + "\\test.txt"); // Open file to Read        
        ofstream out(host + "\\out.txt"); // Open file to Write
        out.clear();
        int lineNumber = 1;


        if (in.is_open()) {
            while (getline(in, line)) {
                for (int symbolNumberInLine = 0; symbolNumberInLine < line.length(); symbolNumberInLine++) {
                    string newCommentSymbol = getCommentSymbol(line, symbolNumberInLine);
                    if (newCommentSymbol != "error")
                        push(lineNumber, symbolNumberInLine, newCommentSymbol);
                }
            }
            lineNumber++;
        }
    

        while (!isEmpty()) {
            CommentData newChar = pop();
            cout 
                << newChar.commentSymbol 
                << " numberString = " 
                << newChar.numberOfString 
                << " numberOfPosition = " 
                << newChar.numberOfPositionInString 
                << endl;

        }
        cout << "endOfStack" << endl;


        in.close();
        out.close();        
    }

    void replaceTextAfterRunProgram() {
        string line;
        ifstream in( host + "\\out.txt" ); // Open file to Read        
        ofstream out( host + "\\result.txt" ); // Open file to Write
    
        out.clear();
        if (in.is_open()) {
            while (getline(in, line)) {
                string newLine;
                newLine = replaceAll(line, "(*", "{");
                newLine = replaceAll(newLine, "*)", "}");
                out << newLine << endl;
            }
        }        
        in.close();
        out.close();
    }
  
    int main()
    {
        checkProgramText();
        replaceTextAfterRunProgram();
        return 1;
    }