#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include <scsi/sg.h>

int main(int argc, char *argv[])
{
  int fd;

  if (argc != 2) {
    printf("Usage: %s <path to sg device of LTO drive>\n", argv[0]);
    return 1;
  }

  fd = open(argv[1], O_RDWR);

  if (fd < 0) {
    puts("Error!");
    return 1;
  }

  struct sg_io_hdr scsi_cmd;
  unsigned char cmd[] = {0x4D, 0x00, 0x31 | 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x00};
  unsigned char dxfer[36];

  memset(&scsi_cmd, 0, sizeof(scsi_cmd));
  memset(&dxfer, 0, sizeof(dxfer));

  scsi_cmd.interface_id = 'S';
  scsi_cmd.dxfer_direction = SG_DXFER_FROM_DEV;
  scsi_cmd.cmd_len = sizeof(cmd);
  scsi_cmd.cmdp = cmd;
  scsi_cmd.dxfer_len = sizeof(dxfer);
  scsi_cmd.dxferp = dxfer;

  ioctl(fd, SG_IO, &scsi_cmd);

  unsigned int tmp;

  tmp = dxfer[11] | (dxfer[10] << 8) | (dxfer[9] << 16) | (dxfer[8] << 24);
  printf("Remaining (Partition 0): %u MiB / ", tmp);
  tmp = dxfer[27] | (dxfer[26] << 8) | (dxfer[25] << 16) | (dxfer[24] << 24);
  printf("%d MiB\n", tmp);
  tmp = dxfer[19] | (dxfer[18] << 8) | (dxfer[17] << 16) | (dxfer[16] << 24);
  printf("Remaining (Partition 1): %u MiB / ", tmp);
  tmp = dxfer[35] | (dxfer[34] << 8) | (dxfer[33] << 16) | (dxfer[32] << 24);
  printf("%d MiB\n", tmp);

  close(fd);

  return 0;
}
