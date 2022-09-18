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

const string host = "D:\\Study\\DataStructures\\Labs\\Labs\\_forTest";

    void checkProgramText() {
        string line;
        ifstream in( host + "\\test.txt" ); // Open file to Read        
        ofstream out( host + "\\out.txt" ); // Open file to Write
        out.clear();
        int lineNumber = 1;

        if (in.is_open()) {
            while (getline(in, line)) {                
                for (int i = 0; i < line.length(); i++) {
                    switch (line[i]) {
                    case '{':
                        if (!isEmpty()) {

                        }
                        
                        break;
                    case '}':
                        if (!isEmpty()) {
                            pop();
                        }
                        else {
                            ;
                        }
                        break;
                    }                    
                }

                lineNumber++;
            }
        }
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

    void getErrorsToConsole() {
        cout << "Program is not correct!" << endl;
        while (!isEmpty()) {
            try {
                CommentData var = pop();
                cout << var.numberOfString << " - " << var.numberOfPositionInString << endl;
            }
            catch (exception ex) {
                cout << ex.what() << endl;
            }            
        }
    }
  
    int main()
    {
        checkProgramText();
        replaceTextAfterRunProgram();
        getErrorsToConsole();              
    }