


#include "pass.h"

#include <stdio.h>  
#include <security/pam_appl.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <string.h>  
#include <iostream>

struct pam_response *reply;  

// //function used to get user input  
int function_conversation(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr)  
{  
    *resp = reply;  
    return PAM_SUCCESS;  
}  

bool is_user_type_right_password(std::string login, std::string pass)
//int authenticate_system(const char *username, const char *password)   
{  
    const char * username = login.c_str();
    const char * password = pass.c_str();
    
    const struct pam_conv local_conversation = { function_conversation, NULL };  
    pam_handle_t *local_auth_handle = NULL; // this gets set by pam_start  

    int retval;  
    retval = pam_start("su", username, &local_conversation, &local_auth_handle);  

    if (retval != PAM_SUCCESS)  
    {  
//            printf("pam_start returned: %d\n ", retval);  
            return false;
    }  

    reply = (struct pam_response *)malloc(sizeof(struct pam_response));  

    reply[0].resp = strdup(password);  
    reply[0].resp_retcode = 0;  
    retval = pam_authenticate(local_auth_handle, 0);
    
    if (retval != PAM_SUCCESS)  
    {  
/*            if (retval == PAM_AUTH_ERR)  
            {  
                    printf("Authentication failure.\n");  
            }  
            else  
            {  
                printf("pam_authenticate returned %d\n", retval);  
            }  */
            return false;
    }  

//    printf("Authenticated.\n");  
    retval = pam_end(local_auth_handle, retval);  

    if (retval != PAM_SUCCESS)  
    {  
//            printf("pam_end returned\n");  
            return false;  
    }  

    return true;  
}

std::string get_login()
{
    return getlogin();
}