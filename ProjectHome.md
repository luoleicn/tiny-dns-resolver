众所周知，Unix/Linux系统下面gethostbyname()是不可重入的，就是说当多线程程序都要进行DNS解析时，必须保证同时只能有一个线程在执行gethostbyname()代码，其他线程在函数外等待。当多线程/进程进行大量DNS解析时，如果还调用gethostbyname()方法，显然会成为程序的一个瓶颈。所以我编写一个DNS解析程序，很简单就是基于UDP利用DNS协议发送和解析DNS包。由于代码工作在操作系统的用户态达到了并行的效果。

---

[项目的使用说明](http://code.google.com/p/tiny-dns-resolver/wiki/Wikihowto)

---

作者Email : luoleicn(at)gmail.com