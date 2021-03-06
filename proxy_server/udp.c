#include <stdio.h> // perror
#include <stdlib.h> // exit, EXIT_FAILURE

#include "./udp.h"
#include "../src/atem.h"

// Creates a UPD socket
int createSocket() {
	const int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == -1) {
		perror("Failed to create socket");
		exit(EXIT_FAILURE);
	}
	return sock;
}

// Creates a socket address struct with address and ATEM port
struct sockaddr_in createAddr(const in_addr_t addr) {
	struct sockaddr_in sockaddr = { 0 };
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = htons(ATEM_PORT);
	sockaddr.sin_addr.s_addr = addr;
	return sockaddr;
}

// Gets the time difference in milliseconds between timestamp and current time
uint16_t getTimeDiff(struct timeval timestamp) {
	// Gets current time
	struct timeval currentTime;
	getTime(&currentTime);

	// Gets millisecond precision difference in time between now and timestamp
	uint16_t diff = 0;
	diff += (currentTime.tv_sec - timestamp.tv_sec) * 1000;
	diff += (currentTime.tv_usec - timestamp.tv_usec) / 1000;
	return diff;
}

// Gets current time
void getTime(struct timeval* timestamp) {
	if (gettimeofday(timestamp, NULL) == -1) {
		perror("Unable to get time of day");
		exit(EXIT_FAILURE);
	}
}
