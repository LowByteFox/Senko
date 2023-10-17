#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define PROJECT_NAME "Senko"

size_t writeout(void *ptr, size_t size, size_t nmemb, void *stream) {
    printf("%s\n%d\n%d\n", ptr, size, nmemb);
	return size * nmemb;
}

int main(int argc, char **argv) {
	CURL *curl;

    if(argc != 1) {
        printf("%s takes no arguments.\n", argv[0]);
        return 1;
    }
    printf("This is project %s.\n", PROJECT_NAME);

	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://google.com");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeout);
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
    return 0;
}
