#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


#define TEMP "/sys/class/thermal/thermal_zone0/temp"

int main() {

	while(1) {
		int file;
		char buf[255];
		long int temp;
		file = open(TEMP, O_RDONLY);
    			if (file == -1) {
        			perror("Failed to open temperature file");
        			return 1;
    			}

		if (read(file, buf, 255) == -1) {
        		perror("Failed to read temperature file");
        		close(file);
        		return 1;
    		}

		temp = strtol(buf, NULL, 10);
		printf("CPU Temperature: %.2f°C\n", (float)temp / 1000);
		close(file);

		fflush(stdout);
		usleep(500000);
		printf("\033[F");
		printf("\033[K");
	}


	return 0;
}
