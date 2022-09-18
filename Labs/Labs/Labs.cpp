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