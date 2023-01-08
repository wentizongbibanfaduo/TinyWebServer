魔改 TinyWebServer日记

# TinyWebServer简介

TinyWebServer是github上 9.1k start的C++轻量级Web服务器。

[github传送门](https://github.com/qinguoyi/TinyWebServer)

适用于入门学习web服务器实践网络编程，技术栈涉及以下几点：
- 使用 线程池 + 非阻塞socket + epoll(ET和LT均实现) + 事件处理(Reactor和模拟Proactor均实现) 的并发模型
- 使用状态机解析HTTP请求报文，支持解析GET和POST请求
- 访问服务器数据库实现web端用户注册、登录功能，可以请求服务器图片和视频文件
- 实现同步/异步日志系统，记录服务器运行状态


# 个人输出
尝试对于TinyWebServer进行编译优化、代码重构

> 查看commit web 记录需要登录gitee，提供账户用于面试
> 
> 账号： wentizongbibanfaduo02 
>
> 密码： asd123..


- 使用docker打包编译环境

    commit id: e0c1a0b3c0b3f5c149f5823b7bcf74874ed7f338

    [commit web](https://gitee.com/wentizongbibanfaduo/TinyWebServer/commit/e0c1a0b3c0b3f5c149f5823b7bcf74874ed7f338)

- 使用cmake代替makefile
  
  commit id: de2687806a15059d85017e78004446a9b7028968
  
  [commit web](https://gitee.com/wentizongbibanfaduo/TinyWebServer/commit/de2687806a15059d85017e78004446a9b7028968)
    