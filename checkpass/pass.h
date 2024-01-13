


#ifndef pass_h
#define pass_h

#include <string>

extern "C" bool is_user_type_right_password(std::string login, std::string password);
extern "C" std::string get_login();

#endif