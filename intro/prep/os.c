#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
  char boot[512];
  int  fd, j;

  fd = open("./os.bin", O_WRONLY | O_CREAT, 0644);

  /* Loop instruction 

   loop:
     jmp loop

  */
  boot[0] = 0xe9;
  boot[1] = 0xfd;
  boot[2] = 0xff;

  for (j = 3; j < 512 - 2; j++) {
    boot[j] = 0;
  }

  /* End of boot sector. Magic number */
  boot[510] = 0x55;
  boot[511] = 0xaa;

  write(fd, boot, 512);

  close(fd);

  return 0;
}
