#include <stdio.h>
#include <string>
#include <curl/curl.h>

using namespace std;

int main(int argc, char* argv[])
{
  string myNum(argv[1]);
  string myMsg(argv[2]);
  string message = "number=" + myNum  + "&message=" + myMsg ;
  CURL *curl;
  CURLcode code;
  
  static const char *postthis = message.c_str();
  //static const char *postthis="number=5306320477&message=\"test\"";
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://textbelt.com/text");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postthis);
 
    // if we don't provide POSTFIELDSIZE, libcurl will strlen() by itself
    // curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)postthis.size());
 
    // Perform the request, res will get the return code
    code = curl_easy_perform(curl);
    // Check for errors
    if(code != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(code));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
  return 0;
}
