/*
21. �   ���������   �����������   �������  �����  ��������� �������� ����������, ����������  ���������  ��������  '{', '}'
����  ������  ��������  '(*'  �  '*)'.����������  ����� ���� ���������� ���� � �����.���� ���������� ������� ������  '{',
�� ��� ������ ���� ������� ������ '}'.���������� ����������, ������������ � �������� '(*'  ������  �������������  ��������� '*)'.
���������: 
1) ��������� ������������ ����������� ����������;
2) ����������   ����   �   ��������   �������   ���, ����� �������������  �����������  ������������  ���  ����������   ��
����������  �  �  ��������  ��������������  ��������  �������� ������  ��������  ������.������   ������, �����   �������
���������� ��������� � ���������� (10).

3) ����������, ���� "{" ��� "}" ��� ������
4) ��� ������ ������� ����� ������ � �������
5) ���� ����������� "(* ... *)" ����� �������� �������� �� { }
*/

#include <iostream>
#include <string>
#include <fstream>

#include "Handler.h"
#include "Stack.h"

using namespace std;

const string host = "D:\\Study\\DataStructures\\Labs\\Labs\\_forTest";  //noteBook host

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

    string getCloseSymbol(string line)
    {
        if (line == "{") {
            return "}";
        }
        else if (line == "(*") {
            return "*)";
        }
        return "";
    }

    void checkProgramText() {
        string line;
        ifstream in(host + "\\test.txt"); // Open file to Read        
        ofstream out(host + "\\out.txt"); // Open file to Write
        out.clear();
        int lineNumber = 1;
        init();

        if (in.is_open()) {
            while (getline(in, line)) {
                for (int symbolNumberInLine = 0; symbolNumberInLine < line.length(); symbolNumberInLine++) {
                    string newCommentSymbol = getCommentSymbol(line, symbolNumberInLine);
                    if (newCommentSymbol != "error")
                    {
                        if (newCommentSymbol == "(*" || newCommentSymbol == "{") {                                                   
                            if (isEmpty()) {
                                out << newCommentSymbol;
                            }                            
                            push(lineNumber, symbolNumberInLine, newCommentSymbol);  
                            if (newCommentSymbol == "(*") {
                                symbolNumberInLine++;
                            }
                        }
                        else {
                            if (isEmpty()) {
                                cout << "Error with run program" << endl;
                                cout << "\tSymbol is - " << newCommentSymbol << endl;
                                cout << "\tLine is - " << lineNumber << endl;
                                cout << "\tSymbol number is - " << symbolNumberInLine << endl;                                
                                return;
                            }
                            else if (newCommentSymbol == getCloseSymbol(lookAtHead().commentSymbol))
                            {                                
                                pop();
                                if (isEmpty()) {
                                    out << newCommentSymbol;
                                }
                                if (newCommentSymbol == "*)") {
                                    symbolNumberInLine++;
                                }
                            }
                            else {
                                cout << "Error with run program" << endl;
                                cout << "\tSymbol is - " << newCommentSymbol << endl;
                                cout << "\tLine is - " << lineNumber << endl;
                                cout << "\tSymbol number is - " << symbolNumberInLine << endl;
                                clear();
                                return;
                            }
                        }
                    } else {
                        string test = line.substr(symbolNumberInLine, 1);
                        out << test;
                    }
                }
                out << endl;
                lineNumber++;
            }            
        }
    
        if (!isEmpty()) {
            out.clear();
            cout << "Stack it not empty!!!" << endl;
            while (!isEmpty()) {
                CommentData newChar = pop();
                cout
                    << newChar.commentSymbol
                    << " numberString =  "
                    << newChar.numberOfString
                    << " numberOfPosition = "
                    << newChar.numberOfPositionInString
                    << endl;
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
  
    int main()
    {        
        checkProgramText();
        replaceTextAfterRunProgram();        
    }