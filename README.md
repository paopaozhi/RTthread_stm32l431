## RT_thread_nano 移植 

| 名称         | 结果        |
| ------------ | ----------- |
| 硬件平台使用 | STM32L431RC |
| 板卡         | 小熊派      |
| 运行环境     | GCC         |
| IDE环境      | CLion       |

移植教程：

1.下载RT_Thread_nano源码包

[下载文档](https://gitee.com/paopaozhi/rtthread_stm32l431/blob/main/Doc/Download.md)

2.使用STM32Cubx生成一个模板工程



3.删除多于文件

4.移植RTOS

5.修改RTconfig文件

6.修改链接文件

7.测试