#include<iostream>
using namespace std;
main()
{
            bool flag = true;
            int i = 0;
            int count = 0;
            string mainstring = "abcdefghabcabc";
            string substring = "abc";
            while(i < mainstring.Length)
            {
                for(int j = 0; j < substring.Length; j++)
                {
                    if(mainstring[i+j] != substring[j])
                    {
                        flag = false;
                        break;
                    }
                   i = i + j;
                }
                if(flag)
                {
                    count++;
                }
            }
           cout<<count;
}