#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curl/curl.h>


char *to_url(char* dest, const char *source){

char* ptr = NULL;

if(!dest){
	if(!(ptr = strdup(source))){
		return NULL;
	}
	}else{
		if((asprintf(&ptr, "%s%s", dest, source)) < 0){
			return NULL;
		}
	}
free(dest);

return ptr;

}


int main(void)
{
  CURL *curl;
  CURLcode res;
  char *sed_query;
  FILE *bodyfile, sed_out;
  static const char *bodyfilename = "body.out";

  bodyfile = fopen(bodyfilename, "wb");

  if(!bodyfile) {
      fclose(bodyfile);
      return -1;
  } 
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "checkip.dyndns.org");
    /* example.com is redirected, so we tell libcurl to follow redirection */ 
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
 
    /* the HTML body will be written to stdout */
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, bodyfile);
    /* Perform the request, res will get the return code */ 
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }

    
  sed_query = strdup("hello !  ");
  sed_query = to_url(sed_query, "ls -lt");
  printf("%s\n", sed_query);

  /*sed_out = popen */
  
  fclose(bodyfile);

printf("End of the program\n");
  return 0;
}
