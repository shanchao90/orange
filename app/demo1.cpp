#include "public.h"
#include "myapi.h"

using namespace std;

int main(int argc,char *argv[],char *envp[])
{
	func();
	AA a;
	a.show();
	BB b;
	b.show();
	
	if (argc!=4)
	{
		cout <<"需要三个参数，空格间隔。\n";
		return -1;
	}
	
	cout << "第一个参数：" << argv[1] << endl;
	cout << "第二个参数：" << argv[2] << endl;
	cout << "第三个参数：" << argv[3] << endl;
	cout << "一共有" << argc << "个参数。\n";
	
	for(int ii=0;ii<argc;++ii)
	{
		cout << "第" << ii << "个参数是" << argv[ii] << endl;
	}	
	return 0;
}
