sudo sh -c 'dumpkeys -k|grep -v Incr_Console|grep -v Decr_Console|grep -v Last_Console|loadkeys'
timedatectl set-local-rtc 0

