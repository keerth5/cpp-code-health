#include <iostream>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <curl/curl.h>

// BAD: Disabling certificate validation (violation)
void bad_example() {
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        std::cerr << "Failed to create SSL context" << std::endl;
        return;
    }

    // Disables all certificate verification — insecure
    SSL_CTX_set_verify(ctx, SSL_VERIFY_NONE, NULL);

    std::cout << "BAD example: SSL verification disabled" << std::endl;

    SSL_CTX_free(ctx);
}

// GOOD: Proper certificate validation
void good_example() {
    SSL_CTX* ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) {
        std::cerr << "Failed to create SSL context" << std::endl;
        return;
    }

    // Enable certificate verification with proper callback or default
    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);
    SSL_CTX_set_default_verify_paths(ctx); // Use system CA certs

    std::cout << "GOOD example: SSL verification enabled" << std::endl;

    SSL_CTX_free(ctx);
}

// Example using libcurl
void curl_bad_example() {
    CURL* curl = curl_easy_init();
    if(curl) {
        // Disable peer verification — insecure
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        std::cout << "BAD example: curl SSL verification disabled" << std::endl;
        curl_easy_cleanup(curl);
    }
}

void curl_good_example() {
    CURL* curl = curl_easy_init();
    if(curl) {
        // Enable peer verification — secure
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        curl_easy_setopt(curl, CURLOPT_CAINFO, "/etc/ssl/certs/ca-certificates.crt");
        std::cout << "GOOD example: curl SSL verification enabled" << std::endl;
        curl_easy_cleanup(curl);
    }
}

int main() {
    bad_example();
    good_example();

    curl_bad_example();
    curl_good_example();

    return 0;
}
