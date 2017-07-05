# ltocapacity

ltocapacity is "Tape Capacity log page" viewer for LTO tapes using Linux sg driver.

## Tested drive

- HP StorageWorks LTO-4 Ultrium 1760 SCSI

## How to build

```console
$ cd path/to/ltocapacity
$ make
```

## Example (LTO-4)

```console
$ ./ltocapacity /dev/sg10
Remaining: 281214 MiB / 800226 MiB
```

## Reference

HP LTO Ultrium tape drives technical reference manual Volume 3: Host interface guide
http://docs.oracle.com/cd/E19190-01/CRCM2526/CRCM2526.pdf

