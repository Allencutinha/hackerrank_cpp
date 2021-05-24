#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void attribute_parser()
{

    int n, q,i;
    cin>>n>>q;
    string temp;
    vector<string> hrml;
    vector<string> quer;
    cin.ignore();

    for(i=0;i<n;i++)
    {
        getline(cin,temp);
        hrml.push_back(temp);
    }
    for(i=0;i<q;i++)
    {
        getline(cin,temp);
        quer.push_back(temp);
    }

    map<string, string> m;
    vector<string> tag;

    for(i=0;i<n;i++)
    {
        temp=hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"' ),temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>' ),temp.end());

        if(temp.substr(0,2)=="</")
        {
            tag.pop_back();
        }
        else
        {
            stringstream ss;
            ss.str("");
            ss<<temp;
            string t1,p1,v1;
            char ch;
            ss>>ch>>t1>>p1>>ch>>v1;
            string temp1="";
            if(tag.size()>0)
            {
                temp1=*tag.rbegin();
                temp1=temp1+"."+t1;
            }
            else
            {
                temp1=t1;
            }
            tag.push_back(temp1);
            m[*tag.rbegin()+"~"+p1]=v1;
            while(ss)
            {
                ss>>p1>>ch>>v1;
                m[*tag.rbegin()+"~"+p1]=v1;
            }
        }

    }

    for(i=0;i<q;i++)
    {
        if (m.find(quer[i]) == m.end())
        {
            cout << "Not Found!\n";
        }
        else
        {
            cout<<m[quer[i]]<<endl;
        }
    }

}

void challenge()
{
    attribute_parser();
}

int main(int argc, char ** argv)
{
    std::string fn;
    if(argc == 1){
        challenge();
    }
    else{
        fn = argv[1];
        std::ofstream out(fn+".output");
        std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
        std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
        challenge();
        out.close();
    }
    return 0;
}
