# My_MPV_Qt_demo

[![sOnic9.md.png](https://s3.ax1x.com/2021/01/25/sOnic9.md.png)](https://imgchr.com/i/sOnic9)

mpv是一个基于mplayer和mplayer2改版自由开源且开源的媒体播放器的命令行。它支持多种媒体文件格式、音频和视频编解码器以及字幕类型。它与vlc等库封装差不多，支援二次开发，通过读取和设置属性来处理任务。本篇文章将简单介绍如何使用libmpv和qt来二次开发一个GUI前端。

[![sOnic9.md.png](https://s3.ax1x.com/2021/01/25/sOnic9.md.png)](https://imgchr.com/i/sOnic9)

=====

libmpv功能强大使用简单灵活，因为这个项目涵盖惹目前一般播放器的所有优点(内置ffmpeg解码器、支援ass字幕、支援本地和在线资源解码、支援硬件解码等..)，基于它二次开发你只需要封装它的通用处理接口，就能轻松实现使用这些功能，并且还是跨平台的。

这是一些基于libmpv开发的播放器：https://github.com/mpv-player/mpv/wiki/Applications-using-mpv。

=====

mpv官方提供惹一个基于qt的demo，但官方的例子是将界面和类封装在一起惹，可供参考：https://github.com/confidentFeng/QtAppProject/tree/mpvDemo。

=====

这是我基于qt制作的一个简易mpv播放器：https://github.com/MoeDisk/My_MPV_Qt_demo，代码非常简单，但实现了如下基本功能。

->mpv_create，创建实例。

->mpv_set_option，设置播放句柄。

->mpv_set_property，设置属性。

->mpv_set_option，设置参数。

->mpv_initialize，初始化实例。

->mpv_command_async，拉流。

->mpv_terminate_destroy，释放实例。

你可以基于如下官方提供的手册来为它添加其他功能。

https://mpv.io/manual/master

=====

最后，感谢mpv，https://mpv.io。以后还会继续更新相关博文~

---
@本地磁盘姬

ohayou.aimo.moe

微博：<a href="https://weibo.com/5985522371">@本地磁盘姬碟酱</a>

Twitter：<a href="https://twitter.com/iMoeDisk">本地磁盘姬</a>

知乎：<a href="https://www.zhihu.com/people/amygreen">本地磁盘姬</a>

2021年01月25日

http://ohayou.aimo.moe/blog/2021/01/25/mpvqt1/
