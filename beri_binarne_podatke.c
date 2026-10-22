
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "uporaba: %s datoteka\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 2;
    }

    char oznaka[7];
    int n = read(fd, oznaka, sizeof oznaka);
    if (n == -1) {
        perror("read");
        close(fd);
        return 3;
    }
    if (n != sizeof oznaka || memcmp(oznaka, "ushort", sizeof oznaka) != 0) {
    fprintf(stderr, "neznan tip podatkov\n");
    close(fd);
    return 4;
}

    unsigned short v;
    while ((n = read(fd, &v, sizeof v)) == sizeof v) {
        printf("%hu;\n", v);
    }
    if (n == -1) {
        perror("read");
        close(fd);
        return 3;
    }
   if (n != 0) {
    fprintf(stderr, "nepopolna vrednost na koncu zbirke\n");
}
    close(fd);
    return 0;
}