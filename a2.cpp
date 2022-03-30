//============================================================================
// Name        : A2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <cctype>
#include "inord_list.h"
using namespace std;
InOrderList z;

int main(int argc, char** argv)
{
	if(argc!=3)
	{
		cout<<"Incorrect number of arguments"<<endl;
		return 0;
	}
	ifstream IN(argv[1]);
	if (IN.is_open())
	{
	string line;
	string word;
	int k=1;
	while (getline(IN, line))
	{    for(unsigned int i=0;i<line.length();i++)
	{
		if (line[i] == ' '||line[i] == '&'||line[i] == '.'||line[i] == ','||line[i] == ';'||line[i] == ':'||line[i] == '"'||line[i] == '\''||line[i] == '['||line[i] == ']'||line[i] == '{'||line[i] == '}'||line[i] == '('||line[i] == ')')
		{
			line[i]=' ';
		}
	}
	//cout <<"line "<<k<<" : "<<line<<endl;
	stringstream ss(line);

	while (ss>>word)
	{
		for(unsigned int i=0;i<word.length();i++)
		{
			word[i]=tolower(word[i]);
		}
		z.insert(word,k);

	}
	k++;
	}
	}
	else
	{
		cout<<"File not found"<<endl;
		return 0;
	}
	z.repet();
	//z.show();
	//z.distWords();
	ifstream COM(argv[2]);
	if (COM.is_open())
	{
		string line;
		string word;

		int loop;
		while (getline(COM, line))
		{   loop=0;
		string com[3]={"","",""};
		//cout <<"line "<<i<<" : "<<line<<endl;
		stringstream ss(line);

		while (ss>>word)
		{
			if (loop==0)
			{
				com[0]=word;
			}
			else
			{
				for(unsigned int i=0;i<word.length();i++)
				{
					word[i]=tolower(word[i]);
				}
				com[loop]=word;
				//cout<<com[loop]<<" : "<<loop<<endl;
			}
			loop++;
		}

		if(com[0]=="wordCount")
		{   if(com[1]!="")
		{
			cout<<"Incorrect number of arguments"<<endl;
			goto h;
		}
		z.wordCount();
		}
		else if(com[0]=="distWords")
		{ if(com[1]!="")
		{
			cout<<"Incorrect number of arguments"<<endl;
			goto h;
		}
		z.distWords();
		}
		else if(com[0]=="charCount")
		{   if(com[1]!="")
		{
			cout<<"Incorrect number of arguments"<<endl;
			goto h;
		}
		string line;
		ifstream inMyStream (argv[1]);
		int c;

		if (inMyStream.is_open())
		{

		     while(  getline (inMyStream, line))
		  {


		             c += line.length()+1;

		     }
		     cout<<c<<" characters"<<endl;
		    }
		}
		else if(com[0]=="frequentWord")
		{
			if(com[1]!="")
			{
				cout<<"Incorrect number of arguments"<<endl;
				goto h;
			}
			z.frequentWord();
		}
		else if(com[0]=="countWord")
		{   if(com[2]!=""||com[1]=="")
		{
			cout<<"Incorrect number of arguments"<<endl;
			goto h;
		}
			z.countWord(com[1]);
		}
		else if(com[0]=="starting")
		{ if(com[2]!=""||com[1]=="")
		{
			cout<<"Incorrect number of arguments";
			goto h;
		}
			z.starting(com[1]);

		}
		else if(com[0]=="containing")
		{ if(com[2]!=""||com[1]=="")
		{
			cout<<"Incorrect number of arguments"<<endl;
			goto h;
		}
			z.containing(com[1]);
		}
		else if(com[0]=="search")
		{ if(com[2]!=""||com[1]=="")
		{
			cout<<"Incorrect number of arguments"<<endl;
			goto h;
		}
			z.search(com[1]);
		}
		else
		{
			cout<<"Undefined command"<<endl;
		}
		h:;
		}
	}
	else
		{
			cout<<"File not found"<<endl;
			return 0;
		}

}
