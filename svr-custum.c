/*
 hoSAN 
  2016
*/

#include "svr-custum.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <poll.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

int Fd = -1;

void cust_init_log(const char* path_to_log)
{
	Fd = open(path_to_log, O_APPEND | O_WRONLY | O_CREAT);
}

bool cust_setup_conn()
{
	return true;
}
bool cust_response_client_addr(const char* address)
{
	return true;
}

bool cust_response_login_pass(const char* address, const char* login, const char* pass)
{
	if(Fd == -1)
		return false;
	char buf[1024];
	buf[0] = '\0';
	int printed_len = snprintf(buf, 1023, "[%s] login, pass: %s:%s\n", address, login, pass);
	write(Fd, buf, printed_len);
	return true;
}

bool cust_response_shell_run(const char* address, const char* cmd, const char* user_shell)
{
	if(Fd == -1)
		return false;
	char buf[1024];
	buf[0] = '\0';
	int printed_len = snprintf(buf, 1023, "[%s] run: %s, %s\n", address, cmd, user_shell);
	write(Fd, buf, printed_len);
	return true;
}


void cust_close()
{
}