#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK "Adapter 0: on-line\n"
#define NOK "Adapter 0: off-line\n"

int main(int argc, char *argv[]) {

    FILE *fp;
    char power[1023];
    
    if (fp = popen("acpi -a", "r")){
        fgets(power, sizeof(power), fp);
        fclose(fp);
        if(strcmp(NOK,power)==0){
            if ((fp = fopen("/run/systemd/shutdown/scheduled", "r")))
                fclose(fp);
            else{
                system("shutdown -P +10");
                system("echo 1 > /root/.ssched");
            }
        } else if ((strcmp(OK,power)==0) && (fp = fopen("/root/.ssched", "r"))){
            fclose(fp);
            system("rm /root/.ssched");
            system("shutdown -c");
        }
    }else{
        printf("Failed to run command\n");
    }

    return 0;
}
