#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
using namespace std;
vector<string>Token1(const string& _text)
{
vector<string>Token2;
stringstream text_break(_text);
string Token3;
int i = 0;
while(text_break >> Token3)
{
i++;
Token2.push_back(Token3);
}
return Token2;
}
class Stmnt
{
public:
enum type_of{
FIRST,SECOND
};
type_of type_of_1_2;
string _identifiers_variable;
string _expression_text;
};
vector<Stmnt>check_logic_code(const vector<string>&Token2)
{
vector<Stmnt> St_mnts;
for( int i = 0; i < Token2.size(); ++i)
{
if(Token2[i] == "print")
{
Stmnt St_mnt;
St_mnt.type_of_1_2 = Stmnt::SECOND;
St_mnt._identifiers_variable = Token2[i+1];
St_mnts.push_back(St_mnt);
i++;
}
else if( i + 1 < Token2.size() && Token2[ i + 1] == "=")
{
Stmnt St_mnt;
St_mnt.type_of_1_2 = Stmnt::FIRST;
St_mnt._identifiers_variable = Token2[i];
St_mnt._expression_text = Token2[i + 2];
St_mnts.push_back(St_mnt);
i = i + 3;
}
}
return St_mnts;
}
// ###############8 - bit assemblt code genertor ###############
string Assembly_Text_Converter(const vector<Stmnt>& St_mnts)
{
string Assembly_text = "";
map<string,int> variables;
int postVarIndex = 0;
for(auto& St_mnt : St_mnts)
{
if(St_mnt.type_of_1_2 == Stmnt::FIRST)
{
if(variables.find(St_mnt._identifiers_variable) == variables.end())
{
variables[St_mnt._identifiers_variable] == postVarIndex++;
}
int varIndex = variables[St_mnt._identifiers_variable];
try{
int values = stoi(St_mnt._expression_text);
Assembly_text = Assembly_text + " MOV A, # " + to_string(values) + "\n";
Assembly_text = Assembly_text + " STD " + to_string(varIndex) +"\n";
}
catch ( const invalid_argument& InArg)
{
if(variables.find(St_mnt._identifiers_variable) == variables.end())
{
cerr << "ERROR: UNDENFINED VARIABLE " << St_mnt._identifiers_variable;
cout << endl;
exit(1);
}
int expressionIndex = variables[St_mnt._expression_text];
Assembly_text = Assembly_text + " LDA " + to_string(expressionIndex);
cout << endl;
Assembly_text = Assembly_text + " STD " + to_string(varIndex);
cout << endl;
}
}
else if( St_mnt.type_of_1_2 == Stmnt::SECOND)
{
if(variables.find(St_mnt._identifiers_variable) == variables.end())
{
cerr <<"ERROR : UNDENFINED VARIABLE " << St_mnt._identifiers_variable;
cout << endl;
exit(1);
}
int varIndex = variables[St_mnt._identifiers_variable];
Assembly_text = Assembly_text + " LDA " + to_string(varIndex) ;
cout << endl;
Assembly_text = Assembly_text + " OUT ";
cout << endl;
}
}
return Assembly_text;
}
int main()
{
string SimpleLanguageCode = R"(
int a ;
int b ;
int c ;
a = 10 ;
b = 20 ;
c = a + b ;
)";
vector<string>Token2 = Token1(SimpleLanguageCode);
vector<Stmnt>St_mnts = check_logic_code(Token2);
string Assembly_Text = Assembly_Text_Converter(St_mnts);
cout << "-------------------------------------------------------";
cout << endl;
cout << "SIMPLE LANGUAGE CODE: " << endl;
cout << "-------------------------------------------------------";
cout << endl;
cout << SimpleLanguageCode;
cout << "-------------------------------------------------------";
cout << endl;
cout << " GENRETED ASSEMBLY CODE: " << endl;
cout << "-------------------------------------------------------";
cout << endl;
cout << Assembly_Text;
ofstream outfile("OutPut.asm");
outfile << Assembly_Text;
outfile.close();
return 0;
}