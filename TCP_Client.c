#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
<<<<<<< HEAD
#include <netdb.h>
#include <fcntl.h>

int main()
{
    struct addrinfo hints, *res0, *res;
    int err;
    int fd, sock;
    int n, ret;
    char buf[65536];

    int sock_listen;
    struct sockaddr_in addr;
    struct sockaddr_in client;
    socklen_t len;
    int sock_client;

    fd = open("Test_File", O_RDONLY);
    if(fd < 0)
    {
        perror("open");
        return 1;
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_family = PF_UNSPEC;
    if((err = getaddrinfo("127.0.0.1", "12345", &hints, &res0)) != 0)
    {
        printf("error %d : %s\n", err, gai_strerror(err));
        return 1;
    }

    for(res = res0; res != NULL; res = res->ai_next)
    {
        sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if(sock < 0)
        {
            continue;
        }

        if(connect(sock, res->ai_addr, res->ai_addrlen) != 0)
        {
            close(sock);
            continue;
        }

        break;
    }

    freeaddrinfo(res0);
    if (res == NULL)
    {
        printf("failed\n");
        return 1;
    }

    while((n = read(fd, buf, sizeof(buf))) > 0)
    {
        ret = write(sock, buf, n);
        if (ret < 1)
        {
            perror("write");
            break;
        }
    }

    close(sock);
=======
int main()
{
    struct sockaddr_in server;
    int sock;
    char buf[32];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(12345);

    // local host
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr.s_addr);
    connect(sock, (struct sockaddr *)&server, sizeof(server));

    memset(buf, 0, sizeof(buf));
    n = read(sock, buf, sizeof(buf));

    printf("%d, %s\n", n, buf);
    close(sock);

>>>>>>> d430f2621814be048eaaf872550dc2b8876b567c
    return 0;
}
