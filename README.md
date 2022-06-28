## RT_thread_nano 移植

| 名称     | 结果          |
|--------|-------------|
| 硬件平台使用 | STM32L431RC |
| 板卡     | 小熊派         |
| 运行环境   | GCC         |
| IDE环境  | CLion       |

移植教程：

1.下载RT_Thread_nano源码包

[下载文档](https://gitee.com/paopaozhi/rtthread_stm32l431/blob/main/Doc/Download.md)

2.使用STM32Cubx生成一个模板工程

选择对应芯片型号即可

**只要修改几处即可**(只贴出图片不在解释，修改至一致即可)

![image-20220628155125345](https://picture.paopaozhiiot.cn//image-20220628155125345.png)

![image-20220628155144403](https://picture.paopaozhiiot.cn//image-20220628155144403.png)

![image-20220628155258467](https://picture.paopaozhiiot.cn//image-20220628155258467.png)

![image-20220628155331658](https://picture.paopaozhiiot.cn//image-20220628155331658.png)

![image-20220628155525303](https://picture.paopaozhiiot.cn//image-20220628155525303.png)

![image-20220628155601442](https://picture.paopaozhiiot.cn//image-20220628155601442.png)

修改完后生成生成工程即可

注意：不要点击打开工程

3.删除多于文件

删除不重要的文件(圈出的文件，请直接删除)

![image-20220628160118623](https://picture.paopaozhiiot.cn//image-20220628160118623.png)

4.移植RTOS

在工程目录新建一个文件夹，用于放RT_Thread的源码

将下载好的源码，复制到RT_Thread文件夹内(圈出的请复制)

![image-20220628160341340](https://picture.paopaozhiiot.cn//image-20220628160341340.png)

进入.\bsp\_template\cubemx_config文件夹中复制文件到工程目录的

![image-20220628162024496](https://picture.paopaozhiiot.cn//image-20220628162024496.png)

进入libcpu文件夹选择合适的配置文件

根据自己芯片选择合适的启动文件(这里我是cortex-m4,所以我会删除多余的文件)(下图只作参考)

![image-20220628163203433](https://picture.paopaozhiiot.cn//image-20220628163203433.png)

![image-20220628163353160](https://picture.paopaozhiiot.cn//image-20220628163353160.png)

![image-20220628163609886](https://picture.paopaozhiiot.cn//image-20220628163609886.png)

5.修改RTconfig文件

使用CLion打开

打开后一般会弹出一个配置面板，如图，我们就随便选择一个即可，因为我们后面要直接配置

![image-20220628162341118](https://picture.paopaozhiiot.cn//image-20220628162341118.png)

等待clion配置工程，一般几秒即可

然后我们修改刚刚的OCD下载配置文件

```cfg
# 使用stling下载
source [find interface/stlink-v2-1.cfg]
# 使用sw接口
transport select hla_swd
# flash大小 
set FLASH_SIZE 0x40000
# 芯片型号 
source [find target/stm32l4x.cfg]
# 下载速度
adapter speed 2000
```

![修改完的图片](https://picture.paopaozhiiot.cn//image-20220628162729480.png)

修改启动文件文件



修改CMakeLists文件



6.修改链接文件

7.测试