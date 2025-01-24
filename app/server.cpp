#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <unistd.h>
#include <string>
#include <arpa/inet.h>

using std::string;

class myuser
{
	private:
		int ID;
		string password;
	public:

};

class data
{
	private:
		int ID;
		string title;
		string line;
		string column[];
	public:

};


int main()
{
	int sockfd = ::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (sockfd < 0)
	{
		printf("create socket error:errno=%d errmsg=%s",errno,strerror(errno));
		return 1;
	}
	else
	{
		printf("create socket success!");
	}

	string ip = "127.0.0.1";
	int port = 8080;

	struct sockaddr_in sockaddr;
	std::memset(&sockaddr,0,sizeof(sockaddr));
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_addr.s_addr = inet_addr(ip.c_str());
	sockaddr.sin_port = htons(port);
	if (::bind(sockfd,(struct sockaddr *)&sockaddr,sizeof(sockaddr)) < 0 )
	{
		printf("socket bind error: errno=%d errmsg=%s",errno,strerror(errno));
		return 1;
	}
	else
	{
		printf("socket bind success: ip=%s port=%d",ip.c_str(),port);
	}

	if (::listen(sockfd,1024) < 0)
	{
		printf("socket listen error:errno=%d errmsg=%s",errno,strerror(errno));
		return 1;
	}
	else
	{
		printf("socket listening ...");
	}

	while (true)
	{
		int connfd = ::accept(sockfd,nullptr,nullptr);
		if (connfd < 0)
		{
			printf("socket accept error:errno=%d errmsg=%s",errno,strerror(errno));
			return 1;
		}



	char buf[1024] = {0};

	size_t len = ::recv(connfd, buf,sizeof(buf),0);
	printf("recv: connfd=%d msg=%s",connfd,buf);

	::send(connfd, buf,len,0);

	}

		
	::close(sockfd);
	return 0;
}
