 #include<iostream>
 #include<cmath>
 using namespace std;
 int isqrt(float usernum);
 main()
 {
    float usernum;
    int result;
    cout<< "enter a number: ";
    cin>>usernum;
    result = isqrt(usernum);
    cout<<result;

 }
  int isqrt(float usernum)
   {
    int  count = 0;
    while(usernum >= 2)
     {
        usernum = sqrt(usernum);
        count= count + 1;
     }
     return count;
  
   }


  