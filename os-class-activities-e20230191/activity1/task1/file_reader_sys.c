#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[256];

    // 1. Open file
    int fd = open("output.txt", O_RDONLY);

    if (fd < 0) {
        const char *err = "Error opening file\n";
        write(2, err, strlen(err));
        return 1;
    }

    // 2. Read and display content
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytesRead);
    }

    // 3. Close file
    close(fd);

    return 0;
}
