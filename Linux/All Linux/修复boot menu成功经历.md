```shell
efibootmgr -c -w -L "ubuntu" -d /dev/nvme0n1 -p 1 -l EFI/ubuntu/grubx64.efi
```

### "ubuntu"-----要添加的启动项名称，自定义
### /dev/nvme0n1------EFI分区所在磁盘（注意是磁盘，不是分区）
### (-p后面的)1--------EFI分区在磁盘的第几个分区就是几
### EFI/ubuntu/grubx64.efi--------添加项的efi文件路径（该文件在EFI分区中，路径为相对于改分区最高级目录(包含`EFI`文件夹)的路径）
