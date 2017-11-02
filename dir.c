#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>



int main(){ 
  DIR* d = opendir(".");

  printf("\nDirectories:\n");
  struct dirent* next;
  while(next = readdir(d)){
    if((*next).d_type != DT_REG){
      printf("%s\n",(*next).d_name);
    }
  }

  closedir(d);

  d = opendir(".");

  printf("\nFiles:\n");
  while(next = readdir(d)){
    if((*next).d_type == DT_REG){
      printf("%s\n",(*next).d_name);
    }
  }

  closedir(d);

  d = opendir(".");
  printf("\nTotal directory size:\n");
  int bytes = 0;
  struct stat file;
  while(next = readdir(d)){
    stat((*next).d_name,&file);
    bytes += file.st_size;
  }
  printf("%d\n",bytes);

  closedir(d);


  return 0;
}
