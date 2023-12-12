#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sock.h"

Sock::Sock(u_short domain, int type, int proto, int port, u_long dev)
{
    this->addr = {
        sin_family : domain,
        sin_port : htons(port),
        sin_addr : {
            s_addr : htonl(dev),
        },
    };
    memset(this->addr.sin_zero, '\0', sizeof(this->addr.sin_zero));

    printf("initializing socket");
    if ((this->sock = socket(domain, type, proto)) < 0)
        goto err;
    printf("\t\t\t...done\n");

    return;
err:
    perror("\nError: could not initialize Socket\t");
    exit(1);
}