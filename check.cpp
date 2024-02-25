
// package libpam0g-dev

#include <iostream>
#include "pass.h"
#include <string>

// remove old comment
// remove break
// br2 check pull request

int main()
{
    std::cout << get_login() << " login from lib" << std::endl;
    while(true)
    {
	std::cout << "-------------------------------------------------------" << std::endl;
	std::string login, pass;
	std::cout << "type login, pass: " << std::endl;
	std::cin >> pass;
	login = get_login();
	
	if(is_user_type_right_password(login, pass))
	{
	    std::cout << "user type correct pass" << std::endl;
	}
	else
	{
	    std::cout << "user type not correct pass" << std::endl;
	}
    }
    return 0;
}