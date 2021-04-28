/* Enter your macros here */

#define FUNCTION(name,op) void name(int &result,int value){result=(value op result)?value:result;}
#define toStr(s) #s
#define INF 10000000
#define foreach(v, i) for (int i = 0; i < v.size(); i++)
#define io(v) cin >> v


