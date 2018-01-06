#include <iostream>
#include <string.h>
#include <curl/curl.h>

int main(int argc, char* argv[])
{
  char *name = argv[1];
  CURL *curl = curl_easy_init();
  if(curl)
  {
    CURLcode res;
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0); 
    curl_easy_setopt(curl, CURLOPT_NOBODY, true);
    curl_easy_setopt(curl, CURLOPT_URL, name); 
    res = curl_easy_perform(curl);
    if(res == CURLE_OK)
    {
      char *url = NULL;
      curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);
      if(url)
      {
          printf("Redirect to: %s\n", url);
      }
     
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      printf("Код ответа: %ld\n", response_code);
    }
    else printf( "curl_easy_perform() failed: %s\n", curl_easy_strerror(res) );

    curl_easy_cleanup(curl);
  }
  return 0;
}
