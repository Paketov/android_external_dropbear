
#pragma once

#include <stdbool.h>
#include <string.h>


void cust_init_log(const char* path_to_log);

bool cust_setup_conn();

bool cust_response_client_addr(const char* address);

bool cust_response_login_pass(const char* address, const char* login, const char* pass);

bool cust_response_shell_run(const char* address, const char* cmd, const char* user_shell);

void cust_close();
