echo off

echo uploading %1 to DFU mode
dfu-util-static.exe  -l -D %1 -R
echo finished, re-plug OKBB to rest
