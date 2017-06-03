/*
 * =====================================================================================
 *
 *       Filename:  malloc_show_addr.c
 *
 *    Description:  monitor malloc
 *
 *        Version:  1.0
 *        Created:  2017年06月03日 星期六 04時34分32秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
//#define _GNU_SOURCE
#define __USE_GNU
#include <dlfcn.h>

static void *(*real_malloc)(size_t) = NULL;
static void *(*real_free)(void *) = NULL;

void *malloc( size_t size)
{
  void *p;
  if(real_malloc == NULL)
  {
      real_malloc = dlsym(RTLD_NEXT, "malloc");
      if(real_malloc == NULL)
      fprintf(stderr, "Error in `dlsym`: %s \n", dlerror());
  }
  p = real_malloc(size);
  fprintf(stderr, "malloc size: %ld \n", size);
  fprintf(stderr, "malloc addr: %p \n", p);

  return p;

}

void free(void *ptr)
{
    if(real_free == NULL)
    {
        real_free = dlsym(RTLD_NEXT, "free");
        if(real_free == NULL)
        fprintf(stderr, "Error in `dlsym`: %s \n", dlerror());
    }
    fprintf(stderr, "free addr: %p \n", ptr);

    real_free(ptr);

}
