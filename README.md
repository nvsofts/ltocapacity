# ltocapacity

ltocapacity is "Tape Capacity log page" viewer for LTO tapes using Linux sg driver.

## Tested drive

- HP StorageWorks LTO-4 Ultrium 1760 SCSI
- IBM Half High LTO-5 Tape Drive

## How to build

```console
$ cd path/to/ltocapacity
$ make
```

## Example (LTO-5 with LTFS)

```console
$ ./ltocapacity /dev/sg0
Remaining (Partition 0): 36233 MiB / 36239 MiB
Remaining (Partition 1): 1377102 MiB / 1377105 MiB
```

## Reference

HP LTO Ultrium tape drives technical reference manual Volume 3: Host interface guide
http://docs.oracle.com/cd/E19190-01/CRCM2526/CRCM2526.pdf

IBM TotalStorage LTO Ultrium Tape Drive SCSI Reference
https://www-01.ibm.com/support/docview.wss?uid=ssg1S7003556&aid=1
