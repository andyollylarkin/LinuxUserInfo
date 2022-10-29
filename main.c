#include <pwd.h>
#include <stddef.h>
#include <errno.h>
#include <stdio.h>
#include <grp.h>

int main(int argc, char *argv[])
{
    if (argv[1] == NULL || *argv[1] == '\0')
    {
        printf("No username specified\n");
        return 0;
    }
    struct passwd *pwd;
    errno = 0;
    pwd = getpwnam(argv[1]);
    if (pwd == NULL)
    {
        if (errno == 0)
        {
            printf("%s", "Error: no such user\n");
            return 1;
        }
    }
    else
    {
        printf("%s", "Success retrieving:\n");
        printf("Username: %s\n", pwd->pw_name);
        printf("UID: %d\n", pwd->pw_uid);
        printf("GID: %d\n", pwd->pw_gid);
        printf("Home dir: %s\n", pwd->pw_dir);
    }

    return 0;
}
