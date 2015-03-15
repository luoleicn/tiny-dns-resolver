# 使用说明 #

项目的使用并不复杂，在程序源代码包中提供了一个示例程序test.cpp和一个makefile，用户可以通过示例代码轻松掌握tiny-dns-resolver的应用，你甚至无须任何配置。

当然，你可以通过自己的实际情况对DNS服务器进行选择。本项目使用了4台dns服务器，地址是
"202.97.224.69", "202.97.224.68", "8.8.8.8"和"8.8.4.4"其中前两台服务器是黑龙江省的dns服务器，后两个是google提供的dns服务器[Google Public DNS](http://code.google.com/speed/public-dns/index.html)。

为了选择合适的dns服务器地址，你必须首先修改TinyDNSResolver.h中的
```
enum{DNS_SERVERS= 4	};
```
值为你的实际使用dns数量，如果你错误的把这个值改成大于你实际使用的dns服务器数目将导致致命的错误。
然后修改TinyDNSResolver.cpp中的
```
const char* TinyDNSResolver::DNS_ADDR[DNS_SERVERS] = {"202.97.224.69", "202.97.224.68", "8.8.8.8", "8.8.4.4"};
```
为你实际使用dns服务器的地址。