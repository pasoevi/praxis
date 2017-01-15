/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 1998 - 2013, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/
#include <ctype.h>
#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <unistd.h>

const char *argp_program_version = "geturl 0.01";
const char *argp_program_bug_address = "mail@essayer.info";

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream);

int main(int argc, char **argv)
{
  short verbose = 0;
  char *filename = NULL;
  FILE *pagefile;
  char *help = "geturl -o filename url\n";
  int c, index;
  opterr = 0;
  char *target_url;

  
  while((c = getopt(argc, argv, "vho:")) !=  -1)
    switch(c)
      {
      case 'v':
	verbose = 1;
	break;
      case 'o':
	filename = optarg;
	break;
      case 'h':
	puts(help);
	return 0;
	break;
      case '?':
	if(optopt == 'o')
	  fprintf(stderr, "Option -%c requires an argument.\n", optopt);
	else if(isprint(optopt))
	  fprintf(stderr, "Unknown option `-%c'.\n", optopt);
	else
	  fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
	return 1;
      default:
	abort();
      }


    

  target_url = argv[optind];

  CURL *curl;
  CURLcode res;

  
  /* Read a URL at a time (for later use when reading a list of urls
   from file 
  int bytes_read;
  size_t nbytes = 100;

  

  target_url = (char *)malloc(nbytes + 1);
  bytes_read = getline(&target_url, &nbytes, stdin);

  if(nbytes == -1)
    {
      puts("Error occured");
      return -1;
    }
  
  */

  curl_global_init(CURL_GLOBAL_ALL);

  curl = curl_easy_init();
  if(curl) {

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl = curl_easy_init();

    /* set URL to get here */
    curl_easy_setopt(curl, CURLOPT_URL, target_url);

    /* Switch on full protocol/debug output while testing */
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

    /* disable progress meter, set to 0L to enable and disable debug output */
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);

    /* send all data to this function  */
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    pagefile = fopen(filename, "wb");
    if (pagefile) {
      /* write the page body to this file handle. CURLOPT_FILE is also known as
       CURLOPT_WRITEDATA*/
      curl_easy_setopt(curl, CURLOPT_FILE, pagefile);

      /* Perform the request, res will get the return code */
      res = curl_easy_perform(curl);

      fclose(pagefile);
    }




    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
  size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}
