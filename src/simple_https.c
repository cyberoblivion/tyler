#include <stdio.h>
#include <curl/curl.h>

// Callback function to write the response data
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    size_t total_size = size * nmemb;
    fwrite(ptr, size, nmemb, stdout); // Write response to stdout
    return total_size;
}

int main() {
    CURL *curl;
    CURLcode res;

    // Initialize libcurl
    curl = curl_easy_init();
    if (curl) {
        // Set the URL for the HTTPS request
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com");

        // Enable verbose output (optional, for debugging)
        // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        // Set callback to handle the response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

        // Perform the HTTPS request
        res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Clean up
        curl_easy_cleanup(curl);
    }

    return 0;
}
